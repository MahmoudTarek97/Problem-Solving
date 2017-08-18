#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


void Visit(int n, char Arr[][100], int Vis[][100], int x, int y)
{
    Vis[x][y]=1;

     if(x+1<n &&  Vis[x+1][y]==0 && Arr[x+1][y]!='.')
    {
        Visit(n,Arr,Vis,x+1,y);
    }

    if(x-1>=0 &&  Vis[x-1][y]==0 && Arr[x-1][y]!='.')
    {
        Visit(n,Arr,Vis,x-1,y);
    }

    if(y+1<n && Vis[x][y+1]==0 && Arr[x][y+1]!='.')
    {
        Visit(n,Arr,Vis,x,y+1);
    }

    if(y-1>=0 && Vis[x][y-1]==0 && Arr[x][y-1]!='.')
    {
        Visit(n,Arr,Vis,x,y-1);
    }
}

int main()
{
    int t;
    cin >> t;
    for(int k=0; k<t; k++)
    {
        int n;
        cin >> n;
        char Arr[100][100];
        int Vis[100][100]= {};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> Arr[i][j];
            }
        }
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(Arr[i][j]=='x' && Vis[i][j]==0)
                {
                    Visit(n,Arr,Vis,i,j);
                    count++;
                }
            }

        }
        cout << "Case " << k+1 << ": " << count << endl;
    }
    return 0;
}
