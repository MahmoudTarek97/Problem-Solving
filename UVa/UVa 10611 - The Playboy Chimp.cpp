/****************************************************/
/**                                                **/
/**   UVa 10611 - The Playboy Chimp.cpp            **/
/**   Credits to Mahmoud Tarek Samir               **/
/**   Ma7moud.tarek97@gmail.com                    **/
/**                                                **/
/****************************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int A[50010];

// return value of first element greater than target
// otherwise -1
int up(int start,int end,int target)
{
    while(start<=end)
    {
        int mid=(start+end)/2;

        if(A[mid]<=target)
            start=mid+1;
        else
            end=mid-1;
    }
    if(start>n-1)        return -1;
    return A[start];
}

// return value of first element less than target
// otherwise -1
int down(int start,int end,int target)
{
    while(start<=end)
    {
        int mid=(start+end)/2;

        if(A[mid]<target)
            start=mid+1;
        else
            end=mid-1;
    }
    if(end<0)       return -1;
    return A[end];
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++) // 1 <= n <= 50000
        cin >> A[i];
    int Q;
    cin >> Q;
    while(Q--)      // 1 <= Q <= 25000
    {
        int q;
        cin >> q;
        int min=down(0,n-1,q);
        int max=up(0,n-1,q);
        if(min==-1)
            cout << 'X' << " ";
        else
            //cout << A[lower_bound(A,A+n,q)-A-1] << " ";
            cout <<  min << " ";
        if(max==-1)
            cout << 'X' << endl;
        else
            //cout << A[upper_bound(A,A+n,q)-A] << endl;
            cout <<  max << endl;
    }
    return 0;
}
