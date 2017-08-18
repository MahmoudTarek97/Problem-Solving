/*********************************************/
/**                                         **/
/**   CF-327B-Hungry Sequence.cpp           **/
/**   Credits to Mahmoud Tarek Samir        **/
/**   Ma7moud.tarek97@gmail.com             **/
/**                                         **/
/*********************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    //each number divides by itself and 1 and  maybe some number <= sqrt(this number)
    //so we need to generate a seq satisfy that first*first < last
    //given problem constrains :  1 <= n <= 10^5 , 1 <= a <= 10^7
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cout << 3*n+i << " " ;
    cout << endl;
    return 0;
}
