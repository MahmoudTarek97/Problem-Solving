/***********************************************/
/**                                           **/
/**   CF514A - Chewbacca and Number.cpp       **/
/**   Credits to Mahmoud Tarek Samir          **/
/**   Ma7moud.tarek97@gmail.com               **/
/**                                           **/
/***********************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    string num;
    cin >> num;
    char s=num[0];
    for(int i=0; i<num.length(); i++)
    {
        if(num[i]=='5')
            num[i]='4';
        else if(num[i]=='6')
            num[i]='3';
        else if(num[i]=='7')
            num[i]='2';
        else if(num[i]=='8')
            num[i]='1';
        else if(num[i]=='9' && i!=0)
            num[i]='0';
    }
    bool leading=true;
    for(int i=0; i<num.length(); i++)
    {
        if(num[i]=='0' && leading)
            continue;
        if(num[i]!='0' && leading)
        {
            leading=false;
        }
        if(!leading)
        {
            cout << num[i];
        }
    }
    cout << endl;
    return 0;
}
