#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long    max_(long a, long b)
{  
    return (a * (a > b) + b * (a <= b));
}

void    Pythagorean_triplets(vector<int> v, int t)
{
    int a, b, c, b2, c2, bc, _b_c;
    int x = v[distance(v.begin(), max_element(v.begin(), v.end()))], x_2;
    
    vector<int> v_uniq = v;
    sort(v_uniq.begin(), v_uniq.end());
    v_uniq.erase( unique( v_uniq.begin(), v_uniq.end() ), v_uniq.end() );

    int n = v_uniq.size();
    vector<long> res(n, -1);
    
    x_2 = floor(x / 2);
    for (c = x_2; c > 0; c--)
    {
        c2 = c * c;
        for (b = x_2 - 1; b > 0; b--)
        {
            b2 = b * b;
            if (floor(sqrt(c2 - b2)) != ceil(sqrt(c2 - b2)))
                continue ;
            bc = b * c;
            _b_c = -b -c;
            for (int i = n - 1; i >= 0; i--)
            {
                a = v_uniq[i] + _b_c;
                if (a <= 0)
                    break ;
                if ((a * a + b2) == c2)
                    res[i] = max_(res[i], a * bc);
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        auto it = find(v_uniq.begin(), v_uniq.end(), v[i]);
        x = distance(v_uniq.begin(), it);
        cout << res[x] << endl;
        while ((i < (t - 1)) && (v[i] == v[i + 1])) 
        {
            i++;
            cout << res[x] << endl;
        }
    }
}

int main(){
    int t;
    vector<int> v;
    
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        v.push_back(n);    
    }
    Pythagorean_triplets(v, t);
    return 0;
}
