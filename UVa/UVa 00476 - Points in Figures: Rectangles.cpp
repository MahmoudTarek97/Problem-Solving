/******************************************************/
/**                                                  **/
/**   UVa 00476 - Points in Figures: Rectangles.cpp  **/
/**   Credits to Mahmoud Tarek Samir                 **/
/**   Ma7moud.tarek97@gmail.com                      **/
/**                                                  **/
/******************************************************/

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    vector<double> Tri_x1(0);
    vector<double> Tri_y1(0);
    vector<double> Tri_x2(0);
    vector<double> Tri_y2(0);
    char ch = getchar();
    double x1,y1,x2,y2;
    while(ch=='r')
    {
        scanf("%lf %lf %lf %lf",&x1,&y2,&x2,&y1);
        Tri_x1.push_back(x1);
        Tri_y1.push_back(y1);
        Tri_x2.push_back(x2);
        Tri_y2.push_back(y2);
        getchar();
        ch =getchar();
    }
    double x,y;
    scanf("%lf %lf",&x,&y);
    int count=1;
    while(!(x==9999.9 && y==9999.9))
    {
        bool in_figures=false;
        for(int i=0; i<Tri_x1.size(); i++)
        {
            if(x<Tri_x2[i] && x>Tri_x1[i] && y<Tri_y2[i] && y>Tri_y1[i])
            {
                in_figures=true;
                printf("Point %d is contained in figure %d\n",count,i+1);
            }
        }
        if(!in_figures)
            printf("Point %d is not contained in any figure\n",count);
        scanf("%lf %lf",&x,&y);
        count++;
    }
    return 0;
}
