/***********************************************/
/**                                           **/
/**   CF127A - Wasted Time.cpp                **/
/**   Credits to Mahmoud Tarek Samir          **/
/**   Ma7moud.tarek97@gmail.com               **/
/**                                           **/
/***********************************************/

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

double length(double x1,double y1,double x2,double y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) ;
}

int main()
{
    int n,k;
    cin >> n >> k;
    int x[n];
    int y[n];
    for(int i=0; i<n; i++)
    {
        cin >> x[i] >> y[i];
    }
    double sign_length=0;
    for(int i=1; i<n; i++)
    {
        sign_length+=length(x[i-1],y[i-1],x[i],y[i]);
    }
    printf("%lf\n",sign_length*k/50.0);
    return 0;
}
