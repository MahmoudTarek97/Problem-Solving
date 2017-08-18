/*********************************************/
/**                                         **/
/**   SPOJ - AGGRCOW.cpp                    **/
/**   Credits to Mahmoud Tarek Samir        **/
/**   Ma7moud.tarek97@gmail.com             **/
/**                                         **/
/*********************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,c;
//O(n)
bool min_distance(ll stalls[],ll distance,ll c)
{
    ll count=1;
    ll last_x=0;
    for(ll i=1; i<n; i++)
    {
        if(stalls[i]-stalls[last_x]>=distance)
        {
            last_x=i;
            count++;
        }

    }
    return (count >= c);
}

ll largestMinDistance(ll stalls[],ll start,ll end,ll target)
{
    while(start<=end)
    {
        ll mid=start+(end-start)/2;

        if(min_distance(stalls,mid,c))
            start=mid+1;
        else
            end=mid-1;
    }
    return end;

}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        ll stalls[n];
        for(int i=0; i<n; i++)
            cin >> stalls[i];
        sort(stalls,stalls+n);
        cout << largestMinDistance(stalls,1,stalls[n-1]-stalls[0],c) << endl;
        //cout << min_distance(stalls,1) << endl;
    }
    return 0;
}
