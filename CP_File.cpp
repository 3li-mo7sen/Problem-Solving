#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <array>
#include <bitset>
#include <utility>
#include <tuple>
#include <cmath>
#include <numeric>
#include <iterator>
#include <functional>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <forward_list>
#include <valarray>
#include <complex>
#include <random>
#include <chrono>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cassert>
#include <ctime>
#include <ratio>
#include <type_traits>
#include <exception>
#include <stdexcept>
#include <cfenv>
#include <cstddef>
#include <concepts>
#include <ranges>
#include <optional>
using ll = long long;
using namespace std;
int find_last_ru(string s)
{
    int idx = -1;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'r' && s[i + 1] == 'u')
        {
            idx = i;
        }
    }
    return idx;
}
void Messi()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void _3li()
{
    int n; cin >> n;
    vector<int>v(n + 6, 0);

    //ss.resize(n + 1);
    //cout << ss << endl;

    for (int i = 1; i <= n; i++) cin >> v[i];
    string s; cin >> s;// 1 2 5 3 4 6
    s = "0" + s; //       0 0 1 1 1 0
    vector<int>pref(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + (s[i] == '1' ? 1 : 0);
    }
 /*   for (int i = 1; i < n; i++)
    {
        cout << pref[i] << " ";
    }*/
    //cout << pref[n] << endl;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == i)continue;
        int l = min(i,v[i]);
        int r = max(i, v[i]);
        int sum = pref[r ] - pref[l - 1];
		cout << sum << " " << l << " " << r << endl;
        if (sum < r - l + 1)
        {

            cout << "NO\n";
            return;
        }
    }
    //// cout << s << endl;

    cout << "YES\n";

}
void tests()
{
    ll t;
    cin >> t;
    while (t--)
    {
        _3li();
    }
}
void solve_with_tests(bool there_are_tests)
{
    if (there_are_tests)
        tests();
    else
        _3li();
}

int main()
{
    Messi();
    solve_with_tests(0);
    return 0;
}