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

using namespace std;

int n;
string s[2];
int dist[2000001];

int solve() {
  queue<int> q;
  int st[2];
  int curr = 1;
  st[0] = 0;
  st[1] = 0;
  for (int i=0;i<=2000000;i++) {
    dist[i] = -1;
  }
  for (int j=s[0].length()-1;j>=0;j--) {
    st[0] += (s[0][j] - '0') * curr;
    curr *= 2;
  }
  curr = 1;
  for (int j=s[1].length()-1;j>=0;j--) {
    st[1] += (s[1][j] - '0') * curr;
    curr *= 2;
  }
  q.push(st[0]);
  dist[st[0]] = 0;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    int nxt = 0;
    bool flag = false;
    for (int j=25;j>=0;j--) {
      if ((1 << j) & top) {
        flag = true;
      } else if (flag) {
        nxt |= (1 << j);
      }
    }
    if (top == 0) nxt = 1;
    int nxt2 = top * 2;
    if (top == st[1]) return dist[top];
    if (nxt >= 0 && nxt <= 2000000 && dist[nxt] == -1) {
      q.push(nxt);
      dist[nxt] = dist[top] + 1;
    }
    if (nxt2 >= 0 && nxt2 <= 2000000 && dist[nxt2] == -1) {
      q.push(nxt2);
      dist[nxt2] = dist[top] + 1;
    }
  }
  return dist[st[1]];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  for (int z=1;z<=t;z++) {
    cin >> s[0] >> s[1];
    int ans = solve();
    cout << "Case #" << z << ": " << (ans == -1 ? "IMPOSSIBLE" : to_string(ans)) << "\n";
  }
  return 0;
}