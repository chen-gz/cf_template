#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <set>
#include <tuple>
#include <map>
#include <vector>
using namespace std;
#define int long long
// #define mod 1000000007

#define N 500005

void solve() {
    int n, k;
    cin >> n >> k;  
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    for(int i=0;i<k;i++){
        if (cnt[i] == 0) {
            ans++;
        }
    }
    if (ans < cnt[k]) {
        ans += cnt[k] - ans;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef DEBUG
    freopen("./input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
#ifdef DEBUG
        static int test_num = 1;
        cout << "test case: " << test_num++ << endl;
#endif
        solve();
    }
}