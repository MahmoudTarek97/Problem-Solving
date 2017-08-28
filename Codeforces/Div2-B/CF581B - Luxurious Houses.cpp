/*********************************************/
/**                                         **/
/**   CF581B - Luxurious Houses.cpp         **/
/**   Credits to Mahmoud Tarek Samir        **/
/**   Ma7moud.tarek97@gmail.com             **/
/**                                         **/
/*********************************************/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[n];
    for(int i=0; i<n; i++)
        cin >> h[i];
    vector<int> ans;
    int max_h=h[n-1];
    ans.push_back(0);
    for(int i=n-2; i>=0; i--)
    {
        if(max_h+1-h[i]<0)
            ans.push_back(0);
        else
            ans.push_back(max_h+1-h[i]);
        max_h=max(max_h,h[i]);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
