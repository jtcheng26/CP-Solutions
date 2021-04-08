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

int n, l;
int a[100001];

double solve() {
  double res = 0;
  double times[2][n+2];
  int speed = 1;
  int prev = 0;
  times[0][0] = 0;
  a[0] = 0;
  a[n+1] = l;
  for (int i=1;i<=n;i++) {
    times[0][i] = times[0][i-1] + ((double)a[i] - (double)prev) / (double)speed;
    prev = a[i];
    speed++;
  }
  times[0][n+1] = times[0][n] + ((double)l - (double)a[n]) / (double)speed;
  speed = 1;
  prev = l;
  times[1][n+1] = 0;
  for (int i=n;i>0;i--) {
    times[1][i] = times[1][i+1] + ((double)prev - (double)a[i]) / (double)speed;
    prev = a[i];
    speed++;
  }
  times[1][0] = times[1][1] + ((double)a[0] - 0.0) / (double)speed;
  double minDist = 1000000007;
  int minLeft = 0;
  int l, r;
  for (int i=1;i<=n+1;i++) {
    if (times[0][i] >= times[1][i]) {
      l = i-1;
      r = i;
      break;
    }
  }
  //cout <<l << " " << r << endl;
  double locRight = a[r] - (times[0][l] - times[1][r]) * (n + 1 - r + 1);
  //cout << locRight << endl;
  //cout << a[r] << " " << a[l] << endl;
  //cout << times[0][l] << " " << times[1][r] << endl;
  res = times[0][l] + (double)(locRight - a[l]) / (double)((l + 1) + (n + 1 - r + 1));
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> l;
    for (int i=1;i<=n;i++) cin >> a[i];
    cout << fixed << showpoint;
    //cout << setprecision(6);
    cout << solve() << endl;
  }
  return 0;
}
