/**********************************************/
/**                                          **/
/**   UVa 10991 - Region.cpp                 **/
/**   Credits to Mahmoud Tarek Samir         **/
/**   Ma7moud.tarek97@gmail.com              **/
/**                                          **/
/**********************************************/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <complex>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

const double PI = acos(-1);
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
    return acos( fixAngle( (b*b+c*c-a*a)/(2*b*c) ) );
}


//              c1
//              *
//         r1 * B * r1
//    a     *       *     c
//        +...........+
//   r2 *   .        .  *  r3
//    * C     .    .    A *
//c2* * * * * * + * * * * * *  c3
//       r2            r3
//              b
int main()
{
    int t;
    cin >> t;
    cout << fixed << setprecision(6);
    double r1,r2,r3;
    while(t--)
    {
        cin >> r1 >> r2 >> r3;
        double a=r1+r2,b=r2+r3,c=r3+r1;
        double A = getAngle_A_abc(a,b,c),B = getAngle_A_abc(b,a,c),C = getAngle_A_abc(c,a,b);
        double circle1_area=PI*r1*r1, circle2_area=PI*r2*r2, circle3_area=PI*r3*r3;
        double triangleArea = 0.5 * a * b * sin(C);
        double sectorA_area = circle3_area*A/(2*PI),sectorB_area = circle1_area*B/(2*PI),sectorC_area = circle2_area*C/(2*PI);
        cout << triangleArea-(sectorA_area+sectorB_area+sectorC_area) << endl;
    }
    return 0;
}
