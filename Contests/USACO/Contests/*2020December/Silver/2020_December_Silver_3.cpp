#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF 1000000007

typedef long long ll;

using namespace std;

struct cow {
  char direction;
  int x, y;
  int idx;
};

int n;
cow cows[1001];
int ans[1001];
int len[1001];

bool cmp(cow a, cow b) {
  if (a.direction == 'N' && b.direction == 'E') return true;
  else if (a.direction == 'E' && b.direction == 'N') return false;
  if (a.direction == 'N')
    return a.x < b.x;
  else
    return a.y < b.y;
}

void solve() {
  for (int i=0;i<n;i++) {
    len[i] = INF;
    ans[i] = 0;
  }
  sort(cows, cows+n, cmp);
  for (int i=0;i<n;i++) {
    if (cows[i].direction == 'N') {
      for (int j=0;j<n;j++) {
        if (cows[j].direction == 'N') continue;
        if (cows[j].y > cows[i].y && cows[j].x < cows[i].x) {
          if (cows[i].x - cows[j].x < cows[j].y - cows[i].y) {
            if (cows[j].x + len[cows[j].idx] < cows[i].x) continue;
            len[cows[i].idx] = cows[j].y - cows[i].y;
            ans[cows[j].idx]++;
            ans[cows[j].idx] += ans[cows[i].idx];
            break;
          } else if (cows[i].x - cows[j].x > cows[j].y - cows[i].y && len[cows[j].idx] == INF) {
            len[cows[j].idx] = cows[i].x - cows[j].x;
            ans[cows[i].idx]++;
            ans[cows[i].idx] += ans[cows[j].idx];
          }
        }
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> cows[i].direction >> cows[i].x >> cows[i].y;
    cows[i].idx = i;
  }
  solve();
  for (int i=0;i<n;i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
