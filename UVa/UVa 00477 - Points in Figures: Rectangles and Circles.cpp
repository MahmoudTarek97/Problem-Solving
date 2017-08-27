/******************************************************************/
/**                                                              **/
/**   UVa 00477 - Points in Figures: Rectangles and Circles.cpp  **/
/**   Credits to Mahmoud Tarek Samir                             **/
/**   Ma7moud.tarek97@gmail.com                                  **/
/**                                                              **/
/******************************************************************/
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

bool inside_circle(point c, double r, point p)
{
    return dcomp(length(p-c),r) == -1;
}

bool inside_rectangle(point leftTop, point rightBottom, point p)
{
    return (p.X > leftTop.X) && (p.X < rightBottom.X) && (p.Y > rightBottom.Y) && (p.Y < leftTop.Y);
}

int main()
{
    char type;
    type = getchar();
    vector<pair<point,point > > fig;
    // for circle pair<point(x,y), point(r,0)>
    // for rectangle pair<point(xleft,ytop),point(xrigth,ybottom)>
    vector<bool> is_circle(0);       // 1 for circle , 0 for rectangle
    while(type != '*')
    {
        if(type == 'c')
        {
            is_circle.push_back(true);
            double x,y,r;
            cin >> x >> y >> r;
            fig.push_back(make_pair(point(x,y),point(r,0)));
        }
        else
        {
            is_circle.push_back(false);
            double xleft,ytop,xright,ybottom;
            cin >> xleft >> ytop >> xright >> ybottom;
            fig.push_back(make_pair(point(xleft,ytop),point(xright,ybottom)));
        }
        getchar();      // end of line
        type = getchar();
    }
    double x,y;
    cin >> x >> y;
    int cnt=0;
    while(!((dcomp(x,9999.9)==0) && (dcomp(y,9999.9)==0)))
    {
        bool exist = false;
        for(int i=0; i<fig.size(); i++)
        {
            if(is_circle[i])
            {
                if(inside_circle(fig[i].first,fig[i].second.X,point(x,y)))
                {
                    printf("Point %d is contained in figure %d\n",cnt+1,i+1);
                    exist=true;
                }
            }
            else if(inside_rectangle(fig[i].first,fig[i].second,point(x,y)))
            {
                printf("Point %d is contained in figure %d\n",cnt+1,i+1);
                exist=true;
            }
        }
        if(!exist)      printf("Point %d is not contained in any figure\n",cnt+1);
        cin >> x >> y;
        cnt++;
    }
    return 0;
}
