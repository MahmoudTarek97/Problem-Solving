/*********************************************/
/**                                         **/
/**   CF469B - Chat Online.cpp              **/
/**   Credits to Mahmoud Tarek Samir        **/
/**   Ma7moud.tarek97@gmail.com             **/
/**                                         **/
/*********************************************/

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

bool can_chat(int a,int b,int c,int d){
    bool ch1= (c>=a && d<=b) || (c>=a && c<=b && d>=b && d>=a);
    bool ch2= (a>=c && b<=d) || (a>=c && a<=d && b>=d && b>=c);
    return (ch1 || ch2);
}
int main()
{
    int p,q,l,r;
    cin >> p >> q >> l >> r;
    int a[p];
    int b[p];
    int c[q];
    int d[q];
    for(int i=0; i<p; i++)
    {
        cin >> a[i] >> b[i];
    }
    for(int i=0; i<q; i++)
    {
        cin >> c[i] >> d[i];
    }
    vector<bool> suitable_t(1010,false);
    for(int t=l; t<=r; t++)     //0 <= l <= r <= 1000
    {
        for(int i=0; i<p; i++)
        {
            for(int j=0; j<q; j++)
            {
                if(can_chat(a[i],b[i],c[j]+t,d[j]+t))
                {
                    suitable_t[t]=true;
                }
            }
        }
    }
    int count=0;
    for(int i=0; i<1010; i++)
        if(suitable_t[i])
            count++;
    cout << count << endl;
    return 0;
}
