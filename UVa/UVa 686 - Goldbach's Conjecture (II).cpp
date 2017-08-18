#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <bitset>
using namespace std;

bitset<40000> is_prime;
vector<int> primes;
// O(n * log (log (n)))
void sieve(long long n)
{
    is_prime.set();                                      // set all bits to 1
    is_prime[0] = 0;
    is_prime[1] = 0;                                     // except index 0 and 1
    for (long long i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            // cross out multiples of i starting from i * i!
            for (long long j = i * i; j <= n; j += i)
                is_prime[j] = 0;
            primes.push_back(i);
        }
    }

}


int main()
{
    sieve(40000);       //O(nlog(log(n)))
    int n;
    cin >> n;
    while(n!=0)        //4 <= n < 32768
    {
        int count=0;
        for(int i=0; primes[i]<=n; i++)  //O(#primes<=n) ~ O(n/ln(n))
        {
            if(is_prime[n-primes[i]])
            {
                if(primes[i]==n-primes[i])      count+=2;
                else            count++;
                //cout << primes[i] << " " << n-primes[i] <<  endl;
            }
        }
        cout << count/2 << endl;
        cin >> n;
    }
    return 0;
}
