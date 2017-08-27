/*********************************************************/
/**                                                     **/
/**   UVa 00438 - The Circumference of the Circle.cpp   **/
/**   Credits to Mahmoud Tarek Samir                    **/
/**   Ma7moud.tarek97@gmail.com                         **/
/**                                                     **/
/*********************************************************/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <complex>
#include <algorithm>
#include <vector>
using namespace std;

const double PI = 3.141592653589793;
const double EPS = (1e-8);

typedef complex<double> point;

#define X real()
#define Y imag()

//we can rewrite any of the following as functions
#define angle(a)        (atan2((a).imag(), (a).real()))
#define vec(a,b)        ((b)-(a))
#define length(a)       (hypot((a).imag(), (a).real()))     //avoid sqrt() to avoid overflow
#define normalize(a)    (a)/length(a)   // a unit vector of vector a
// if dot(a,b) > 0 ==> angle > 90
// if dot(a,b) = 0 ==> a prep b
// if dot(a,b) < 0 ==> angle < 90
#define dot(a,b)        ( (conj(a)*(b)).real() )
// if cross(a,b) > 0 ==> angle from a to b is convex (CCW)
// if cross(a,b) = 0 ==> a parallel b
// if cross(a,b) < 0 ==> angle from a to b is concave (CW)
// calculate magnitude of cross product
#define cross(a,b)      ( (conj(a)*(b)).imag() )
// rotate vector around origin with angle ccw
#define rotate0(p,ang)  ((p)*exp(point(0,ang)))
// rotate vector around specific point with angle ccw
// Generalization for last rotate0
#define rotateA(p,ang,about)    (rotate0(vec(about,p),ang)+about)
// reflect vector v around vector m from origin
#define reflect0(v,m)   (conj((v)/(m))*(m))
// boolean function to test if 2 vectors are the same (have the same length and angle)
#define same(p1,p2)             (dot(vec(p1,p2),vec(p1,p2)) < EPS)

// a = b -> 0
// a < b -> -1
// a > b -> 1
int dcomp(double a, double b)
{
    return fabs(a-b) <= EPS ? 0 : a < b ? -1 : 1;
}

// Intersection point Calculation
bool intersectLines(point p0, point p1, point q0, point q1, point &intersect)
{
    point u = p1 - p0;
    point v = q1 - q0;
    point w = p0 - q0;
    if(fabs(cross(u,v))<EPS) return false;    // parallel or identical

    // get the intersect parameter for p0p1 segment
    double sI = cross(v,w) / cross(u,v);

    // get the intersect parameter for q0q1 segment
    //double tI = cross(u,w) / cross(u,v);

    intersect = p0 + sI*u;
    // intersect = q0 + tI*v;
    return true;
}

// we can create infinite circles passes with 1 or 2 points
// we can't create any circle passes with 3 collinear points
// Given 3 points , Draw a circle passes with the 3 points (find its center and radius)
// Our Approach : Bisectors method
// depends on mathematical fact (The perpendicular bisectors of two chords meet at the center )
// draw two lines (chords) from three then draw two perpendicular lines from medians of the two chords
// then find intersection point (center of circle)
pair<double,point> findCircle(point p1, point p2, point p3)
{
    // create two vectors (chords)
    point v1 = p2-p1, v2 = p2-p3;
    // create two medians
    point m1=(p1+p2)*0.5, m2=(p2+p3)*0.5;
    // create two perpendicular vectors on chords
    point pv1(v1.Y,-v1.X), pv2(v2.Y,-v2.X);
    // find the second point on prep vectors (first point is median)
    point end1 = m1+pv1, end2 = m2+pv2;
    // find intersection point (center)
    point center;
    intersectLines(m1,end1,m2,end2,center);

    return make_pair( length(p1-center),center);
}

int main()
{
    double x1,y1,x2,y2,x3,y3;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        pair<double,point> circle = findCircle(point(x1,y1),point(x2,y2),point(x3,y3));
        double r = circle.first;
        printf("%0.2lf\n",2*PI*r);
    }
    return 0;
}
