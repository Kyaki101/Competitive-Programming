#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) & ~(1ULL << (i)))
#define DEBUG(n) cout << #n << " = " << n << endl
#define MSET(arr, x, n) (memset(arr, x, (n) * sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define F second
#define S first
#define PB push_back
#define ll long long
typedef vector<ll> vll;

const int MAX = 2e5 + 20, MOD = 1e9 + 7;

void solve() {
  ll n;
  cin >> n;
  vll a(n), c(n);
  for (auto &i : a) {
      cin >> i;
  }
  for (auto &i : c) {
    cin >> i;
  }

  vll dp(n);
  for(int i = 0; i < n; i++) {
      dp[i] = c[i];
      for(int j = i - 1; j > -1; j--) {
          if(a[j] <= a[i]) dp[i] = max(dp[i], c[i] + dp[j]);
      }
  }

  ll full = accumulate(ALL(c), 0LL);
  ll ans = (1LL << 60);

  for(auto i : dp) {
      ans = min(full - i, ans);
  }
  cout << ans << endl;

}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
