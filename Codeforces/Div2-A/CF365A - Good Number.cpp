/***********************************************/
/**                                           **/
/**   CF365A - Good Number.cpp                **/
/**   Credits to Mahmoud Tarek Samir          **/
/**   Ma7moud.tarek97@gmail.com               **/
/**                                           **/
/***********************************************/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
bool num[10];

bool k_good(int a, int k)
{
    while(a!=0)         //  O(10)
    {
        num[a%10]=true;
        a=a/10;
    }
    for(int i=0; i<=k; i++)
    {
        if(num[i]==false)
            return false;
    }
    return true;
}

int main()
{
    int n,k,a,count=0;
    cin >> n >> k;
    while(n--)      // n <= 100
    {
        for(int i=0; i<=9; i++)
        {
            num[i]=false;
        }
        cin >> a;
        if(k_good(a,k))
            count++;
    }
    cout << count << endl;
    return 0;
}
