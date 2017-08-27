/*************************************************/
/**                                             **/
/**   UVa 00191 - Intersection.cpp              **/
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

// where is c relative to a-b ?
// CCW = +1 => angle > 0 or collinear but c after b
// CW  = -1 => angle < 0 or collinear but c before a
// Undefined = 0 => collinear and c in range[a,b]
int ccw(point a, point b, point c)
{
    point v1(b-a);
    point v2(c-a);
    if( cross(v1,v2) > +EPS)    return +1;
    if( cross(v1,v2) < -EPS)    return -1;
    if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
        return -1;
    if (norm(v1) < norm(v2) - EPS)
        return +1;
    return 0;
}

bool Seg_Seg_Intersect(point p1, point p2, point p3, point p4)
{
    // special case handling if a segment is just a point
    bool x = (p1 == p2), y = (p3==p4);
    if(x && y)  return p1 == p3;
    if(x)   return ccw(p3, p4, p1) == 0;
    if(y)   return ccw(p1, p2, p3) == 0;

    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

bool in_rectangle(point left_top,point right_bottom,point p)
{
    if(p.X>left_top.X && p.X<right_bottom.X && p.Y>right_bottom.Y && p.Y<left_top.Y)
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        double xstart,ystart,xend,yend,xleft_tmp,ytop_tmp,xright_tmp,ybottom_tmp;
        cin >> xstart >> ystart >> xend >> yend;
        point st(xstart,ystart),ed(xend,yend);
        cin >> xleft_tmp >> ytop_tmp >> xright_tmp >> ybottom_tmp;
        double xleft=min(xleft_tmp,xright_tmp),xright=max(xleft_tmp,xright_tmp);
        double ytop=max(ytop_tmp,ybottom_tmp),ybottom=min(ytop_tmp,ybottom_tmp);
        point a(xleft,ytop),b(xright,ytop),c(xright,ybottom),d(xleft,ybottom);
        if(Seg_Seg_Intersect(st,ed,a,b) || Seg_Seg_Intersect(st,ed,b,c) || Seg_Seg_Intersect(st,ed,c,d) || Seg_Seg_Intersect(st,ed,d,a))
            cout << "T" << endl;
        else if(in_rectangle(a,c,st) && in_rectangle(a,c,ed))
            cout << "T" << endl;
        else
            cout << "F" << endl;
    }
    return 0;
}
