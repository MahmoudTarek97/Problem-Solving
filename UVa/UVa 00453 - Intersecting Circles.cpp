/*********************************************************/
/**                                                     **/
/**   UVa 00453 - Intersecting Circles.cpp              **/
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
#include <iomanip>
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

bool pointsComp(point a, point b)
{
    if (real(a) == real(b))
        return imag(a) < imag(b);
    return real(a) < real(b);
}

double fixAngle(double A)
{
    if(A>1) return 1;
    else if(A<-1)   return -1;
    return A;
}

//Cos Rule
//a^2=b^2 + c^2 - 2*b*c*cos(A)
double getAngle_A_abc(double a,double b,double c)
{
    return acos( fixAngle( (b*b+c*c-a*a)/(2.0*b*c) ) );
}

// There are 8 cases for intersection
vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2)
{
    // Handle infinity case first: same center/radius and r > 0
    if (same(c1, c2) && dcomp(r1, r2) == 0 && dcomp(r1, 0) > 0)
        return vector<point>(3, c1);    // infinity 2 same circles (not points) , 3 is indicator for infinity points

    // Compute 2 intersection case and handle 0, 1, 2 cases
    double ang1 = angle(c2 - c1), ang2 = getAngle_A_abc(r2, r1, length(c2 - c1));

    if(std::isnan(ang2)) // if r1 or d = 0 => nan in getAngle_A_abc (/0)
        ang2 = 0; // fix corruption

    vector<point> v(1, polar(r1, ang1 + ang2) + c1);

    // if point NOT on the 2 circles = no intersection
    if((dcomp(dot(v[0]-c1, v[0]-c1), r1*r1) != 0) ||
            (dcomp(dot(v[0]-c2, v[0]-c2), r2*r2) != 0) )
        return vector<point>();

    v.push_back(polar(r1, ang1 - ang2) + c1);
    if(same(v[0], v[1]))  // if same, then 1 intersection only
        v.pop_back();
    return v;
}

int main()
{
    cout << fixed << setprecision(3);
    double x1,y1,r1,x2,y2,r2;
    while(cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2)
    {
        vector<point> points = intersectCircleCircle(point(x1,y1),r1,point(x2,y2),r2);
        sort(points.begin(),points.end(),pointsComp);
        if(points.size()==0)
            cout << "NO INTERSECTION" << endl;
        else if(points.size()==3)
            cout << "THE CIRCLES ARE THE SAME" << endl;
        else
        {
            for(int i=0; i<points.size(); i++)
            {
                cout << "(" << (fabs(points[i].X) < 1e-4 ? fabs(points[i].X) : points[i].X);
                cout << "," << (fabs(points[i].Y) < 1e-4 ? fabs(points[i].Y) : points[i].Y) << ")";
            }

            cout << endl;
        }
    }
    return 0;
}
