#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long getSquenceSize(long n)
{
    int x = 0;
    
    for (long i = 0; n > 1; i++)
    {
        if (n % 2)
            n = 3 * n + 1; 
        else
            n /= 2;
        x++;   
    }
    return (x);
}    

int main() {
    int n, x;
    vector<int> v, res;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    
    x = *max_element(v.begin(), v.end());
    // get Sequence size for every number smaller or equal x
    for (int i = 1; i <= x; i++)
        res.push_back(getSquenceSize(i));
    
    vector<int> v_sort = v, res2;
    sort(v_sort.begin(), v_sort.end());


    // find max
    auto it = max_element(res.begin(), res.begin() + v_sort[0]);
    it = find_end(res.begin(), res.begin() + v_sort[0], it, it + 1);
    res2.push_back(distance(res.begin(), it + 1));

    auto tmp = it;
    for (int i = 1; i < n; i++)
    {
        it = max_element(res.begin() + v_sort[i - 1], res.begin() + v_sort[i]);
        if (*tmp > *it)
            it = tmp;
        else 
        {
            it = find_end(res.begin() + v_sort[i - 1], res.begin() + v_sort[i], it, it + 1);
            tmp = it;        
        }
        res2.push_back(distance(res.begin(), it + 1));
        while (i < (n - 1) && v[i] == v[i + 1]) {
            i++;
            res2.push_back(distance(res.begin(), it + 1));
        }
    }    
    
    // print result
    for (int i = 0; i < n; i++)
    {
        it = find(v_sort.begin(), v_sort.end(), v[i]);
        cout << res2[distance(v_sort.begin(), it)] << endl;
    }
    
    return 0;
}
