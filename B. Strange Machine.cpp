#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <chrono>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <complex>
#include <numeric>
#include <array>
#include <climits>
#include <cfloat>
#include <sstream>
#include <locale>
#include <codecvt>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>
#include <type_traits>
#include <memory>
#include <variant>
#include <any>
#include <regex>
using namespace std;
using ll = long long;
#define Messi ios::sync_with_stdio(false); cin.tie(nullptr);

void _3li()
{
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ll> ra(q);
    for (int i = 0; i < q; i++) cin >> ra[i];

    int cnt_b = 0;
    for (auto c : s) if (c == 'B') cnt_b++;

    if (cnt_b == 0)
    {
        for (int i = 0; i < q; i++)
        {
            cout << ra[i];
            if (i < q - 1) cout << " ";
        }
        cout << "\n";
        return;
    }

    vector<ll> na(n), nb(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            na[i] = 0;
            nb[i] = i;
        }
        else
        {
            int c = 0;
            int j = i;
            while (s[j] == 'A')
            {
                c++;
                j = (j + 1) % n;
            }
            na[i] = c;
            nb[i] = j;
        }
    }

    for (int i = 0; i < q; i++)
    {
        ll cura = ra[i];
        ll steps = 0;
        ll curmachine = 0;

        while (cura > 0)
        {
            char c = s[curmachine];
            if (c == 'B')
            {
                cura /= 2;
                steps++;
                curmachine = (curmachine + 1) % n;
            }
            else
            {
                int k = na[curmachine];
                int nb_index = nb[curmachine];
                if (cura <= k)
                {
                    steps += cura;
                    cura = 0;
                }
                else
                {
                    cura -= k;
                    steps += k;
                    curmachine = nb_index;
                    cura /= 2;
                    steps++;
                    curmachine = (curmachine + 1) % n;
                }
            }
        }
        cout << steps;
        if (i < q - 1) cout << "\n";
    }
    cout << "\n";
}

int main()
{
    // freopen("neat.in", "r", stdin);
    // freopen("neat.out", "w", stdout);
    Messi;
    int t = 1;
    cin >> t;
    while (t--)
    {
        _3li();
    }
    return 0;
}
