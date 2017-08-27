/*********************************************************/
/**                                                     **/
/**   UVa 10432 - Polygon Inside A Circle.cpp           **/
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

int main()
{
    cout << fixed << setprecision(3);
    double r,n;
    while(cin >> r >> n)
    {
        double TriangleArea = 0.5 * r * r * sin(2*PI/n);
        double PolygonArea = n * TriangleArea;
        cout << PolygonArea << endl;
    }
    return 0;
}
