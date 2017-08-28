/***********************************************/
/**                                           **/
/**   CF270A - Fancy Fence.cpp                **/
/**   Credits to Mahmoud Tarek Samir          **/
/**   Ma7moud.tarek97@gmail.com               **/
/**                                           **/
/***********************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    bool angles[200];
    for(int i=0; i<200; i++)
        angles[i]=false;
    for(int n=3; ((n-2)*180)/n < 179; n++)
    {
        if((((n-2)*180)%n)==0)
            angles[(((n-2)*180)/n)]=true;
    }
    angles[179]=true;
    int t,a;
    cin >> t;
    while(t--)
    {
        cin >> a;
        if(angles[a])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
