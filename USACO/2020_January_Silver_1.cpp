#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

typedef long long ll;

using namespace std;

int n, k;
int b[1001];
int m = 0;

bool cmp(int a, int b) {
  return a > b;
}

int max_ans(int min_half) {
  int cnt = 0; int res = 0;
  int avail[n];
  for (int i=0;i<n;i++) avail[i] = b[i];
  for (int i=0;i<n;i++) { // fill buckets with >= min_half until k / 2 filled
    if (cnt == k / 2) break;
    while (avail[i] >= min_half && cnt < k / 2) {
      avail[i] -= min_half;
      cnt++;
    }
  }
  //cout << min_half << endl;
  //for (int i=0;i<n;i++) cout << avail[i] << " ";
  //cout << endl;
  priority_queue<int> pq;
  if (cnt < k / 2) return 0;
  for (int i=0;i<n;i++) {
    if (avail[i] > 0) pq.push(avail[i]);
  }
  cnt = 0;
  while (pq.size() > 0 && cnt < k - k / 2) { // fill max remaining
    if (pq.top() >= min_half) {
      int a = pq.top();
      while (a >= min_half && cnt < k - k / 2) {
        res += min_half;
        a -= min_half;
        cnt++;
      }
      pq.pop();
      if (a > 0) pq.push(a);
    }
    else {
      res += pq.top();
      pq.pop();
      cnt++;
    }
  }
  if (cnt < k - k / 2) return 0;
  //cout << res << endl;
  return res;
}

int sch() {
  int ans = 0;
  for (int i=1;i<=m;i++) {
    ans = max(ans, max_ans(i));
  }
  return ans;
}

int solve() {
  sort(b, b+n, cmp);
  m = b[0];
  return sch();
}

int main() {
  ofstream cout ("berries.out");
  ifstream cin ("berries.in");
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    cin >> b[i];
  }
  cout << solve() << endl;
  return 0;
}
