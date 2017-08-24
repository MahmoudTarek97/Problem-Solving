/************************************************/
/**                                            **/
/**   UVa 10242 - Fourth Point !!.cpp          **/
/**   Credits to Mahmoud Tarek Samir           **/
/**   Ma7moud.tarek97@gmail.com                **/
/**                                            **/
/************************************************/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <complex>
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


int main()
{
    double x,y;
    while(cin >> x >> y)
    {
        vector<point> points(0);
        point mutual;
        points.push_back(point(x,y));
        for(int i=0; i<3; i++)
        {
            cin >> x >> y;
            bool exist=false;
            for(unsigned int j=0; j<points.size(); j++)
            {
                if(dcomp(x,points[j].X)==0 && dcomp(y,points[j].Y)==0)
                {
                    exist=true;
                    mutual.real(x);
                    mutual.imag(y);
                    points.erase(points.begin()+j);
                }
            }
            if(!exist)
                points.push_back(point(x,y));
        }
        point fourth=vec(mutual,points[0])+points[1];
        printf("%0.3lf %0.3lf\n",fourth.X,fourth.Y);
    }
    return 0;
}
