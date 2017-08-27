/***********************************************/
/**                                           **/
/**   UVa 00460 - Overlapping Rectangles.cpp  **/
/**   Credits to Mahmoud Tarek Samir          **/
/**   Ma7moud.tarek97@gmail.com               **/
/**                                           **/
/***********************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int f_x1,f_y1,f_x2,f_y2;
    int s_x1,s_y1,s_x2,s_y2;
    for(int i=0;i<t;i++)
    {
        cin >> f_x1 >> f_y1 >> f_x2 >> f_y2;
        cin >> s_x1 >> s_y1 >> s_x2 >> s_y2;
        int x1,y1,x2,y2;
        if((( x1=max(f_x1,s_x1) ) < ( x2=min(f_x2,s_x2) )) && (( y1=max(f_y1,s_y1) ) < ( y2=min(f_y2,s_y2) )))
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        else
            cout << "No Overlap" << endl;
        if(i!=t-1)
            cout << endl;
    }
    return 0;
}
