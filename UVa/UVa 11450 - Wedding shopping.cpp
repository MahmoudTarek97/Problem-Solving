#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int max_cost=-1000000;

//DP solution (memoization - Top-down)(Accepted)
int shop(vector<vector<int> > &price,int g,int M,int current_money,int saved[210][25])
{
    if(current_money<0)
        return -1000000;
    if(g==price.size())
        return M-current_money;     //the maximum cost
    if(saved[current_money][g]!=0)
        return saved[current_money][g];
    int ans=-100000;
    for(int i=0; i<price[g].size(); i++)
    {
        ans=max(ans,shop(price,g+1,M,current_money-price[g][i],saved));
    }
    saved[current_money][g]=ans;
    return ans;
}

//recursive backtracking solution (TLE)
int shopTLE(vector<vector<int> > &price,int g,int M,int current_money)
{
    if(current_money<0)
        return -1000000;
    if(g==price.size())
        return M-current_money;     //the maximum cost
    int ans=-10000;
    for(int i=0; i<price[g].size(); i++)
    {
        ans = max(ans,shopTLE(price,g+1,M,current_money-price[g][i]));
    }
    return ans;
}

int main()
{
    int N;  //#test cases
    cin >> N;
    int M,C;
    for(int i=0; i<N; i++)
    {
        cin >> M >> C;
        vector<vector<int> > price(C,vector<int>());
        int A;
        for(int j=0; j<C; j++)
        {
            cin >> A;
            int a;
            for(int k=0; k<A; k++)
            {
                cin >> a;
                price[j].push_back(a);
            }
        }
        int saved[210][25]= {};
        int ans = shop(price,0,M,M,saved);
        if(ans<0)
            cout << "no solution" << endl;
        else
            cout << ans << endl;
        max_cost=-1000000;
    }
    return 0;
}
