#include <iostream>

using namespace std;

int GCD(int a,int b)
{
    if(b==0)    return a;
    return GCD(b,a%b);

}

//O(N^2 * logN) , 2<= N <=500
int main()
{
    int N;
    cin >> N;
    while(N!=0)
    {
        int G=0;
        for(int i=1; i<N; i++)
        {
            for(int j=i+1; j<=N; j++)
            {
                G+=GCD(j,i);
            }
        }
        cout << G << "\n";
        cin >> N;
    }
    return 0;
}
