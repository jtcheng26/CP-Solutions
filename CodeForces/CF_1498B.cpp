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

int n, w;
int a[100001];

bool cmp(int a, int b) {
  return a > b;
}

int solve() {
  int res = 1;
  sort(a, a+n, cmp);
  priority_queue<int> pq;
  pq.push(w);
  for (int i=0;i<n;i++) {
    //cout << a[i] << "\n";
    int top = pq.top();
    if (top < a[i]) {
      pq.push(w - a[i]);
      res++;
    } else {
      pq.pop();
      pq.push(top - a[i]);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> w;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << "\n";
  }
  return 0;
}
