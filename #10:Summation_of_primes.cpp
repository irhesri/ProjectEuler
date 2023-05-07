#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool    isPrime(int n)
{
    for (int i = 3; i <= sqrt(n); i++)
    {
        if (!(n % i))
            return (0);
    }
    return (1);
}

vector<int> primes(int n)
{
    vector<int> v;
    
    v.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (isPrime(i))
            v.push_back(i);
    }
    return (v);
}

int main(){
    int t, n, np, x;
    vector<int> p, N;

    // get input
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        cin >> n;
        N.push_back(n);
    }

    // get the primes <= biggest input 
    x = N[distance(N.begin(), max_element(N.begin(), N.end()))];
    p = primes(x);
    np = p.size();
    
    // store summation of primes
    vector<long> sum(np);
    sum[0] = 2;
    for (int i = 1; i < np; i++)
        sum[i] = sum[i - 1] + p[i]; 

    // get output
    vector<int> N_uniq = N;
    sort(N_uniq.begin(), N_uniq.end());
    N_uniq.erase(unique(N_uniq.begin(), N_uniq.end() ), N_uniq.end());
    n = N_uniq.size();
    
    vector<long> res(n, -1);
    
    int j = 1;
    for (int i = 0; i < n; i++)
    {
        for (; j < np; j++)
        {
            if (N_uniq[i] < p[j])
            {
                res[i] = sum[j - 1];
                break ;
            }
        }
    }
    res[n - 1] = sum[np - 1];
    for (int i = 0; i < t; i++)
    {
        auto it = find(N_uniq.begin(), N_uniq.end(), N[i]);
        x = distance(N_uniq.begin(), it);
        cout << res[x] << endl;
        while ((i < (t - 1)) && (N[i] == N[i + 1])) 
        {
            i++;
            cout << res[x] << endl;
        }
    }
    return 0;
}
