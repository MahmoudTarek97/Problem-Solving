#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


void Visit(int rows, int columns, char Arr[][8], int Vis[][8], int x, int y, int count, char word[6])
{
    Vis[x][y]==1;
    if(count==6)
    {
        if(x-1>=0 &&  Vis[x-1][y]==0 && Arr[x-1][y]=='#')
        {
            cout << "forth" ;
        }

        if(y+1<columns && Vis[x][y+1]==0 && Arr[x][y+1]=='#')
        {
            cout << "right" ;
        }

        if(y-1>=0 && Vis[x][y-1]==0 && Arr[x][y-1]=='#')
        {
            cout << "left" ;
        }
    }
    if(x-1>=0 &&  Vis[x-1][y]==0 && Arr[x-1][y]==word[count])
    {
        cout << "forth" << " ";
        Visit(rows,columns,Arr,Vis,x-1,y,count+1,word);
    }

    if(y+1<columns && Vis[x][y+1]==0 && Arr[x][y+1]==word[count])
    {
        cout << "right" << " ";
        Visit(rows,columns,Arr,Vis,x,y+1,count+1,word);
    }

    if(y-1>=0 && Vis[x][y-1]==0 && Arr[x][y-1]==word[count])
    {
        cout << "left" << " ";
        Visit(rows,columns,Arr,Vis,x,y-1,count+1,word);
    }
}

int main()
{
    int t;
    cin >> t;
    for(int k=0; k<t; k++)
    {
        int m; // rows
        int n; // columns
        cin >> m >> n;
        char Arr[8][8];
        int Vis[8][8]= {};
        char word[]="IEHOVA";
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> Arr[i][j];
            }
        }
        int count=0;
        for(int i=0; i<n; i++)
        {
            if(Arr[m-1][i]=='@')
                Visit(m,n,Arr,Vis,m-1,i,count,word);
        }
        cout << endl;
    }

    return 0;
}
