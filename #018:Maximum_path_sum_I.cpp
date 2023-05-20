#include <vector>
#include <iostream>
using namespace std;


short maximumTotal(vector<vector<short>> v, short i, short j, short n)
{
    short x, y;
    
    if (i == n || j == n)
        return 0;
    x = (v[i][j] + maximumTotal(v, i + 1, j, n));
    y = (v[i][j] + maximumTotal(v, i + 1, j + 1, n));
    return (x * (x > y) + y * (x <= y));
}

int main() 
{
    short                   q, n, x;
    vector<short>           tmp;
    vector<vector<short>>   v;
    
    cin >> q;
    for (short i = 0; i < q; i++)
    {
        cin >> n;
        for (short j = 0; j < n; j++) {
            for (short k = 0; k <= j; k++) {
                cin >> x;
                tmp.push_back(x);
            }
            v.push_back(tmp);
            tmp.clear();
        }
        cout << maximumTotal(v, 0, 0, n) << endl;
        v.clear();
    }
    return 0;
}
