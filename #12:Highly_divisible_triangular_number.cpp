#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int getNumberOfDivisors(long n)
{
    int divisors = 0;
    
    for (long i = 1; i < sqrt(n); i++)
    {
        if (!(n % i))
            divisors += 2;
    }
    if (ceil(sqrt(n)) == floor(sqrt(n)))
        divisors++;
    return (divisors);
}

void    triangleNumber(vector<int> v, int size)
{
    long        tmp, size_uniq;
    int         n, sum;
    vector<int> v_uniq = v;
    vector<long>    res;    

    sort (v_uniq.begin(), v_uniq.end());
    v_uniq.erase(unique(v_uniq.begin(), v_uniq.end()), v_uniq.end());
    size_uniq = v_uniq.size();
    
    n = 1;
    sum = 0;
    for (int i = 0; i < size_uniq; i++)
    {
        tmp = 0;
        while (tmp <= v_uniq[i]) {
            sum += n;
            tmp = getNumberOfDivisors(sum);
            n++;
        }
        res.push_back(sum);
        sum -= --n;
    }
    
    for (int i = 0; i < size; i++)
    {
        auto it = find(v_uniq.begin(), v_uniq.end(), v[i]);
        n = distance(v_uniq.begin(), it);
        cout << res[n] << endl;
    }
}

int main() {
    int         n, x;
    vector<int> input;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        input.push_back(x);
    }
    triangleNumber(input, n);
    return 0;
}
