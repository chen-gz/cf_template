#include <algorithm>
#include <bit>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

// #define mod 1000000007
#define int long long
#define N 100006
#define mod 998244353
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n), c(n), pre_sum(n);
    for (auto &v : a) cin >> v;
    for (auto &v : c) cin >> v;
    pre_sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre_sum[i] += pre_sum[i - 1] + a[i];
    }
    int pre_zero_pos = 0;
    int pre_sum_base = 0;
    for (int i = 1; i < n; i++) {
        if (c[i] > c[i - 1]) {
            // ccurent value should > c[i] - c[i-1]
            int increase = c[i] - c[i - 1];
            if (a[i] < increase) {
                cout << -1 << endl;
                return;
            }
            // c[i] = a[pre_zero_pos] + pre_sum[i] + pre_sum_base
            pre_sum_base -= a[pre_zero_pos];
            a[pre_zero_pos] = c[i] - pre_sum[i] - pre_sum_base;
            pre_sum_base += a[pre_zero_pos];
        } else {
            if (s[i] == '0') {
                pre_zero_pos = i;
            }
            int cur_sum = pre_sum[i] + pre_sum_base;
            if (cur_sum > c[i]) {
                a[pre_zero_pos] -= (cur_sum - c[i]);
                pre_sum_base -= (cur_sum - c[i]);
            }
        }
    }
    // last round to check ;
    pre_sum[0] = a[0];
    int cur_max = pre_sum[0];
    if (cur_max != c[0]) cout << "-1" << endl;
    for (int i = 1; i < n; i++) {
        pre_sum[i] += pre_sum[i - 1];
        cur_max = max(cur_max, pre_sum[i]);
        if (cur_max != c[i]) cout << -1 << endl;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
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
