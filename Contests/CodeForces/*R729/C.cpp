#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

ll n;
vector<ll> bruh;

ll solve()
{
  ll res = n % MOD;
  for (ll i=0;i<bruh.size();i++) {
    res = (res + (n / bruh[i]) % MOD) % MOD;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll prod = 1;
  for (ll i=1;i<19;i++) {
    prod *= i;
    bruh.pb(prod);
  }
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    cout << solve() << "\n";
  }
  return 0;
}