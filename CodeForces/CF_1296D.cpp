#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, a, b, k;
int monsters[200001];

int solve() {
  int res = 0;
  int cost[n]; // cost to win each monster
  int sum = a + b;
  for (int i=0;i<n;i++) {
    if (monsters[i] % sum == 0) cost[i] = (monsters[i] - (monsters[i] - b) + a - 1) / a;
    else {
      cost[i] = (monsters[i] - sum * (monsters[i] / sum) + a - 1) / a - 1;
    }
  }
  sort(cost, cost+n);
  int cnt = 0;
  for (int i=0;i<n;i++) {
    //cout << i << ": " << cost[i] << endl;
    cnt += cost[i];
    if (cnt > k) break;
    res++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> a >> b >> k;
  for (int i=0;i<n;i++) cin >> monsters[i];
  cout << solve() << endl;
  return 0;
}
