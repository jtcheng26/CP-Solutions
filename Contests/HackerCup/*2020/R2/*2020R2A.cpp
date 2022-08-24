#include <iostream>
#include <fstream>
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

int n, k;
ll s[1000001];
ll x[1000001];
ll y[1000001];
ll as, bs, cs, ds;
ll ax, bx, cx, dx;
ll ay, by, cy, dy;

ll solve() {
  ll res = 0;
  ll cnt = 0;
  ll minCnt = 0;
  ll maxCnt = 0;
  for (int i=0;i<n;i++) {
    cnt += s[i];
    minCnt += x[i];
    maxCnt += x[i] + y[i];
  }
  if (cnt < minCnt || cnt > maxCnt) return -1;
  ll hasToGain = 0;
  ll hasToLose = 0;
  // min gets subtracted, remaining are taken from available
  // if there are enough people, there will always be enough available
  for (int i=0;i<n;i++) {
    if (s[i] < x[i]) {
      hasToLose += x[i] - s[i];
    }
    else if (s[i] > x[i] + y[i]) {
      hasToGain += s[i] - (x[i] + y[i]);
    }
  }
  //cout << hasToGain << " " << hasToLose << endl;
  return max(hasToGain, hasToLose);
}

void gen() {
  for (int i=k;i<n;i++) {
    s[i] = (as * s[i-2] + bs * s[i-1] + cs) % ds;
    x[i] = (ax * x[i-2] + bx * x[i-1] + cx) % dx;
    y[i] = (ay * y[i-2] + by * y[i-1] + cy) % dy;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("capastaty_input.txt");
  ofstream cout ("2020R2A.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    cin >> n >> k;
    for (int i=0;i<k;i++) cin >> s[i];
    cin >> as >> bs >> cs >> ds;
    for (int i=0;i<k;i++) cin >> x[i];
    cin >> ax >> bx >> cx >> dx;
    for (int i=0;i<k;i++) cin >> y[i];
    cin >> ay >> by >> cy >> dy;
    gen();
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
