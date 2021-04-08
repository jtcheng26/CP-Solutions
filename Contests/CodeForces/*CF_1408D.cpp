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

struct pt {
  int x, y;
};

int n, m;
pt robbers[2001];
pt lights[2001];

int solve() {
  int res = 2000002;
  int sfx[1000001] = {0};
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      if (lights[j].x >= robbers[i].x && lights[j].y >= robbers[i].y) {
        int x = max(0, lights[j].x - robbers[i].x);
        sfx[x] = max(sfx[x], lights[j].y - robbers[i].y + 1);
      }
    }
  }
  for (int i=999999;i>=0;i--) {
    sfx[i] = max(sfx[i+1], sfx[i]);
    //cout << sfx[i] << endl;
    res = min(res, sfx[i] + i);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    cin >> robbers[i].x >> robbers[i].y;
  }
  for (int i=0;i<m;i++) {
    cin >> lights[i].x >> lights[i].y;
  }
  cout << solve() << "\n";
  return 0;
}
