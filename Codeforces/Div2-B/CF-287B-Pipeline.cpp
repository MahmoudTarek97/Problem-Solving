/*********************************************/
/**                                         **/
/**   CF-287B-Pipeline.cpp                  **/
/**   Credits to Mahmoud Tarek Samir        **/
/**   Ma7moud.tarek97@gmail.com             **/
/**                                         **/
/*********************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll k;

/*
test case
input
8 4
output
-1

ans in range [1,3] = [1,k-1]
if ans = 1
    pipes = 4 = k = 1*k - 0
if ans =2
    pipes = 6 = k-1 + k-1 = 2*k - 2
if ans = 3
    pipes = 7 = k-1 + k-2 + k-2 = 3*k - 5
if ans = i
    pipes = i*k - (ith term in seq : 0,2,5,9,14,..)

=> ith term in this seq = (1/2) (i^2 + i - 2)
*/

ll pipes(ll i,ll k)
{
    // pipes = i*k - (ith term is seq : 0,2,5,9,14,..)
    ll Pipes=i*k-((i*i + i - 2)/2);      //if i = 0 -> Pipes = 1
    return Pipes;
}


ll up(ll start, ll end, ll target)
{
    while(start<=end)
    {
        ll mid=(start+end)/2;

        if(pipes(mid,k)==target)
            return mid;
        else if(pipes(mid,k)<target)
            start=mid+1;
        else
            end=mid-1;
    }
    if(start>k-1)   return -1;
    return start;
}

int main()
{
    ll n;
    cin >> n >> k;
    cout << up(0,k-1,n) << endl;
    return 0;
}
