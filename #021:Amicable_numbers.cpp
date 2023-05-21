#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull ;

ull sumOfDivisors(int n)
{
    int i = 2;
    ull sum = 1;
    
    for (; i < sqrt(n); i++)
    {
        if (!(n % i))
            sum += i + n / i;
    }  
    if (!(n % i))
        sum += i;  
    return (sum);
}

int main() {
    int q, n, j, k;
    ull sum = 0, x[2];
    vector<int> amicables, wait_list, v, v_sort, res;

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> n;
        v.push_back(n);
    }
    
    v_sort = v;
    sort(v_sort.begin(), v_sort.end());
    
    j = 220;
    for (int i = 0; i < q; i++)
    {
        n = v_sort[i];
        for (; j < n; j++)
        {
            sort (wait_list.begin(), wait_list.end());
            for (k = 0; k < wait_list.size() && wait_list[k] < n; k++) {
                sum += wait_list[k];
                amicables.push_back(wait_list[k]);
            }
            if (k)
                wait_list.erase(wait_list.begin(), wait_list.begin() + k);
            if (find(amicables.begin(), amicables.end(), j) == amicables.end())
            {
                x[0] = sumOfDivisors(j);
                x[1] = sumOfDivisors(x[0]);
                if ((x[0] != x[1]) && (x[1] == j))
                {
                    sum += x[1];
                    if (x[0] < n)
                    {
                        sum += x[0];
                        amicables.push_back(x[0]);
                    }
                    else  
                        wait_list.push_back(x[0]);
                }
            }
        }
        res.push_back(sum);
    }
    
    for (int i = 0; i < q; i++)
        cout << res[distance(v_sort.begin(), find(v_sort.begin(), v_sort.end(), v[i]))] << endl;
    return 0;
}
