#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int Arr[n][n];
    //calculate cumulative sum while reading input
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> Arr[i][j];
            if(i>0)
                Arr[i][j]+=Arr[i-1][j];
            if(j>0)
                Arr[i][j]+=Arr[i][j-1];
            if(i>0 && j>0)
                Arr[i][j]-=Arr[i-1][j-1];
        }

    }
    int max_sum=-1300000;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int x=i; x<n; x++)
            {
                for(int y=j; y<n; y++)
                {
                    int rec_sum=Arr[x][y];
                    if (i > 0)
                        rec_sum -= Arr[i - 1][y];
                    if (j > 0)
                        rec_sum -= Arr[x][j - 1];
                    if (i > 0 && j > 0)
                        rec_sum += Arr[i - 1][j - 1];

                    max_sum=max(max_sum,rec_sum);
                }
            }
        }
    }
    cout << max_sum << endl;
    return 0;
}
