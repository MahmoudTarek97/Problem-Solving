/*************************************************/
/**                                             **/
/**   UVa 00378 - Intersecting Lines.cpp        **/
/**   Credits to Mahmoud Tarek Samir            **/
/**   Ma7moud.tarek97@gmail.com                 **/
/**                                             **/
/*************************************************/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <complex>
#include <algorithm>
#include <vector>
using namespace std;

const double PI = acos(-1.0);
const double EPS = (1e-8);

typedef complex<double> point;

#define X real()
#define Y imag()

//we can rewrite any of the following as functions
#define angle(a)        (atan2((a).imag(), (a).real()))
#define vec(a,b)        ((b)-(a))
#define length(a)       (hypot((a).imag(), (a).real()))     //avoid sqrt() to avoid overflow
#define normalize(a)    (a)/length(a)   // a unit vector of vector a
// if dot(a,b) = 0 -> a prep b
#define dot(a,b)        ( (conj(a)*(b)).real() )
// if cross(a,b) = 0 -> a parallel b
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

// Test : Is point C on line A-B
// A <----- xC ----> B
bool isCollinear(point a, point b, point c)
{
    return fabs( cross(b-a,c-a) ) < EPS;
}

// In 2D , two lines must be parallel or intersected
// To check if 2 lines are parallel
// cross(line1,line2) must be < EPS
bool parallel(point p0, point p1, point q0, point q1)
{
    if(fabs(cross(p1-p0,q1-q0))<EPS)    return true;
    return false;
}
// NOTE : if they parallel they might be identical
// if one point on a line is on the other line
// they are identical
bool identical(point p0, point p1, point q0, point q1)
{
    if(isCollinear(q0,q1,p0))   return true;
    return false;
}

// Intersection point Calculation of two Lines (must be intersected)
point intersectLines(point p0, point p1, point q0, point q1)
{
    point u = p1 - p0;
    point v = q1 - q0;
    point w = p0 - q0;

    // get the intersect parameter for p0p1 line
    double sI = cross(v,w) / cross(u,v);
    point intersect = p0 + sI*u;
    return intersect;
}

int main()
{
    int t;
    cin >> t;
    vector<point> points(4);
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while(t--)
    {
        double x,y;
        cin >> x >> y;
        points[0].real(x);
        points[0].imag(y);
        for(int i=1; i<4; i++)
        {
            cin >> x >> y;
            points[i].real(x);
            points[i].imag(y);
        }
        if(parallel(points[0],points[1],points[2],points[3]))
        {
            if(identical(points[0],points[1],points[2],points[3]))
                cout << "LINE" << endl;
            else
                cout << "NONE" << endl;
        }
        else
        {
            point intersect = intersectLines(points[0],points[1],points[2],points[3]);
            printf("POINT %0.2lf %0.2lf\n",intersect.X,intersect.Y);
        }

    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
