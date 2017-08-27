/**************************************************************************/
/**                                                                      **/
/**   UVa 00478 - Points in Figures: Rectangles, Circles, Triangles.cpp  **/
/**   Credits to Mahmoud Tarek Samir                                     **/
/**   Ma7moud.tarek97@gmail.com                                          **/
/**                                                                      **/
/**************************************************************************/
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

bool inside_circle(point c, double r, point p)
{
    return dcomp(length(p-c),r) == -1;
}

bool inside_rectangle(point leftTop, point rightBottom, point p)
{
    return (p.X > leftTop.X) && (p.X < rightBottom.X) && (p.Y > rightBottom.Y) && (p.Y < leftTop.Y);
}

bool inside_triangle(point a, point b, point c, point p)
{
    point centroid((a.X+b.X+c.X)/3.0,(a.Y,b.Y,c.Y)/3.0);
    return !Seg_Seg_Intersect(centroid,p,a,b) && !Seg_Seg_Intersect(centroid,p,b,c) && !Seg_Seg_Intersect(centroid,p,c,a);

}

int main()
{
    char typeCh;
    typeCh = getchar();
    vector<vector<point> > fig(10,vector<point> (3));
    vector<int> type(0);       // 0 for circle , 1 for rectangle , 2 for triangle
    int fig_cnt=0,pnt_cnt=0;
    while(typeCh != '*')
    {
        if(typeCh == 'c')
        {
            type.push_back(0);
            double x,y,r;
            cin >> x >> y >> r;
            fig[fig_cnt][0]=point(x,y);
            fig[fig_cnt][1]=point(r,0);
        }
        else if(typeCh== 'r')
        {
            type.push_back(1);
            double xleft,ytop,xright,ybottom;
            cin >> xleft >> ytop >> xright >> ybottom;
            fig[fig_cnt][0]=point(xleft,ytop);
            fig[fig_cnt][1]=point(xright,ybottom);
        }
        else
        {
            type.push_back(2);
            double x1,y1,x2,y2,x3,y3;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            fig[fig_cnt][0]=point(x1,y1);
            fig[fig_cnt][1]=point(x2,y2);
            fig[fig_cnt][2]=point(x3,y3);
        }
        getchar();      // end of line
        typeCh = getchar();
        fig_cnt++;
    }
    double x,y;
    cin >> x >> y;
    while(!((dcomp(x,9999.9)==0) && (dcomp(y,9999.9)==0)))
    {
        bool exist = false;
        for(int i=0; i<fig_cnt; i++)
        {
            if(type[i]==0)
            {
                if(inside_circle(fig[i][0],fig[i][1].X,point(x,y)))
                {
                    printf("Point %d is contained in figure %d\n",pnt_cnt+1,i+1);
                    exist=true;
                }
            }
            else if(type[i]==1)
            {
                if(inside_rectangle(fig[i][0],fig[i][1],point(x,y)))
                {
                    printf("Point %d is contained in figure %d\n",pnt_cnt+1,i+1);
                    exist=true;
                }
            }
            else
            {
                if(inside_triangle(fig[i][0],fig[i][1],fig[i][2],point(x,y)))
                {
                    printf("Point %d is contained in figure %d\n",pnt_cnt+1,i+1);
                    exist=true;
                }
            }
        }
        if(!exist)      printf("Point %d is not contained in any figure\n",pnt_cnt+1);
        cin >> x >> y;
        pnt_cnt++;
    }
    return 0;
}
