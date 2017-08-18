/*********************************************/
/**                                         **/
/**   CF-714B-Filya and Homework.cpp        **/
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
    int a;
    vector<int> num(0);
    while(n--)
    {
        cin >> a;
        if(num.size()>3)
        {
            cout << "NO" << endl;
            return 0;
        }
        bool exist=false;
        for(int i=0; i<num.size(); i++)
        {
            if(num[i]==a)
            {
                exist=true;
                break;
            }

        }
        if(!exist)
            num.push_back(a);
    }
    sort(num.begin(),num.end());
    if(num.size()==1 || num.size()==2 || (num.size()==3 && num[2]-num[1]==num[1]-num[0]))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
