#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int             res;
    short           n;
    string          str;
    vector<string>  v;
    
    cin >> n;
    for (short i = 0; i < n; i++) 
    {
        cin >> str;
        v.push_back(str);
    }
    sort (v.begin(), v.end());
    cin >> n;
    for (short i = 0; i < n; i++) 
    {
        cin >> str;
        res = 0;
        for (short j = 0; j < str.size(); j++)
            res += str[j] - 64;
        res *= distance(v.begin(), find(v.begin(), v.end(), str)) + 1;
        cout << res << endl;
    }
    return 0;
}
