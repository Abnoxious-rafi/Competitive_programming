#include <iostream>
#include <vector>
using namespace std;

const int N = 1e7 + 10;
vector<long long> prime(N, 1), lowest_prime(N, 0), highest_prime(N);

void sieve()
{
    long long i = 2;
    prime[0] = prime[1] = 0;
    for (int i = 2; i < N; i++)
    {
        if (prime[i] == 1)
        {
            lowest_prime[i] = highest_prime[i] = i;
            for (long long j = i * 2; j < N; j += i)
            {
                prime[j] = 0;
                highest_prime[j] = i;
                if (lowest_prime[j] == 0)
                    lowest_prime[j] = i;
            }
        }
    }
}
int main()
{
    sieve();
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << "prime " << prime[x] << endl
             << "highest_prime " << highest_prime[x] << endl
             << "lowest_prime " << lowest_prime[x] << endl;
        vector<long long> prime_factors;
        while (x > 1)
        {
            long long prime_factor = highest_prime[x];
            while (x % prime_factor == 0)
            {
                x /= prime_factor;
                prime_factors.push_back(prime_factor);
            }
        }
        cout<<"Prime factors are : ";
        for (auto it : prime_factors)
            cout << it << " ";
        cout << endl;
    }
}