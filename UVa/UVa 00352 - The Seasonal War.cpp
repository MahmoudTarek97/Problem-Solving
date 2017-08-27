#include <iostream>
#include <stdio.h>
#define MAX_LEN 30

using namespace std;

void Visit(int n,char Arr[][MAX_LEN], int Vis[][MAX_LEN], int x, int y)
{
    //A DFS Algorithm Implementation
    Vis[x][y]=1;

    if(x-1>=0&&y-1>=0&&Vis[x-1][y-1]==0&&Arr[x-1][y-1]=='1')
        Visit(n,Arr,Vis,x-1,y-1);


    if(x-1>=0&&Vis[x-1][y]==0&&Arr[x-1][y]=='1')
        Visit(n,Arr,Vis,x-1,y);


    if(x-1>=0&&y+1<n&&Vis[x-1][y+1]==0&&Arr[x-1][y+1]=='1')
        Visit(n,Arr,Vis,x-1,y+1);

    if(y-1>=0&&Vis[x][y-1]==0&&Arr[x][y-1]=='1')
        Visit(n,Arr,Vis,x,y-1);

    if(y+1<n&&Vis[x][y+1]==0&&Arr[x][y+1]=='1')
        Visit(n,Arr,Vis,x,y+1);

    if(x+1<n&&y-1>=0&&Vis[x+1][y-1]==0&&Arr[x+1][y-1]=='1')
        Visit(n,Arr,Vis,x+1,y-1);

    if(x+1<n&&Vis[x+1][y]==0&&Arr[x+1][y]=='1')
        Visit(n,Arr,Vis,x+1,y);

    if(x+1<n&&y+1<n&&Vis[x+1][y+1]==0&&Arr[x+1][y+1]=='1')
        Visit(n,Arr,Vis,x+1,y+1);

}

int main()
{
    int n,t=1;
    while(scanf("%d",&n)==1)
    {
        char Arr[MAX_LEN][MAX_LEN];
        int Vis[MAX_LEN][MAX_LEN]= {};
        for(int i=0; i<n; i++)
        {
            cin >> Arr[i];
        }
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(Arr[i][j]=='1' && Vis[i][j]==0)
                {
                    Visit(n,Arr,Vis,i,j);
                    count++;
                }
            }
        }
        cout << "Image number " <<t<< " contains " <<count<< " war eagles." << endl;
        t++;
    }


    return 0;
}
