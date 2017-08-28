/*********************************************/
/**                                         **/
/**   CF424B - Megacity.cpp                 **/
/**   Credits to Mahmoud Tarek Samir        **/
/**   Ma7moud.tarek97@gmail.com             **/
/**                                         **/
/*********************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
const double EPS=1e-9;
int n,s;

double radius(int x,int y)
{
    return sqrt(x*x + y*y);
}

//O(n)
bool megacity(int x[],int y[],int p[],double r)
{
    long long population=s;
    for(int i=0; i<n; i++)
    {
        if(radius(x[i],y[i])<=r)
            population+=p[i];
    }
    return (population >= 1000000);
}

double min_r(int x[],int y[],int p[],double start,double end)
{
    while(fabs(end-start)>EPS)
    {
        double mid=start+(end-start)/2;
        if(megacity(x,y,p,mid))
            end=mid;
        else
            start=mid;

    }
    if(start>=15000)    return -1;
    return start;

}

int main()
{
    cin >>n >>s;
    int x[n];
    int y[n];
    int p[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d",&x[i],&y[i],&p[i]);
    }
    double ans;
    if((ans=min_r(x,y,p,0.0,20000.0))!=-1)
        printf("%0.9lf\n",ans);
    else
        printf("-1\n");

    return 0;
}
