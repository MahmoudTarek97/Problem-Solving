/*************************************************************/
/**                                                         **/
/**   CF600B - Queries about less or equal elements.cpp     **/
/**   Credits to Mahmoud Tarek Samir                        **/
/**   Ma7moud.tarek97@gmail.com                             **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

// return index of first element not greater than target
// otherwise -1
int down(int A[],int start,int end,int target)
{
    while(start<=end)
    {
        int mid=(start+end)/2;

        if(A[mid]<=target)
            start=mid+1;
        else
            end=mid-1;
    }
    if(end<0)       return -1;
    return end;
}


int main()
{
    int n,m;
    cin >> n >> m;
    int A[n];
    for(int i=0; i<n; i++)
        cin >> A[i];
    sort(A,A+n);
    int q;
    for(int i=0; i<m; i++)
    {
        cin >> q;
        cout << down(A,0,n-1,q)+1 << " ";
    }
    cout << endl;
    return 0;
}
