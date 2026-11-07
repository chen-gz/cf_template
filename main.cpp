#include <algorithm>
#include <bit>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <ios>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define mod 1000000007
#define int long long
#define N 100006
// #define mod 998244353
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> next(n + 1, vector<int>(10, n));

    vector<int> cur(10, n);
    for (int i = n - 1; i >= 0; i--) {
        cur[s[i] - '0'] = i;
        for (int j = 0; j < 10; j++) {
            next[i][j] = cur[j];
        }
    }
    vector<int> diff(n, 0);
    int f_or = 0;
    int sub = 0;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        // find next 2,0,2,
        int v = next[i][2];
        v = next[v][0];
        v = next[v][2];
        int five = next[v][5];
        int six = next[v][6];
        if (five < six) {
            diff[five + 1] = -1;
            diff[six] = 1;
            sub += six - five;
        }
        f_or += diff[i];
        sub += f_or;
        int cur = (i + 1) * (n - i);
        ans[i] = cur - sub;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#ifdef DEBUG
    freopen("./input.txt", "r", stdin);
#endif
    int t;
    std::cin >> t;
    while (t--) {
#ifdef DEBUG
        static int test_num = 1;
        std::cout << "test case: " << test_num++ << std::endl;
#endif
        solve();
    }
    return 0;
}
