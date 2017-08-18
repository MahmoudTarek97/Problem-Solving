#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while(N!=0){
        int Arr[N];
        for(int i=0;i<N;i++){
            cin >> Arr[i];
        }
        int sum=0,ans=0;
        for (int i = 0; i < N; i++)
        {
            sum += Arr[i]; // we greedily extend this running sum
            ans = max(ans, sum); // we keep the maximum RSQ overall
            if (sum < 0) sum = 0; // but we reset the running sum
        } // if it ever dips below 0
        if(ans>0)
            printf("The maximum winning streak is %d.\n",ans);
        else
            printf("Losing streak.\n");
        cin >> N;
    }
    return 0;
}
