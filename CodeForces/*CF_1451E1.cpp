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

int n;

int getXOR(int a, int b) {
  cout << "XOR " << a << " " << b << endl;
  int res;
  cin >> res;
  return res;
}
int getAND(int a, int b) {
  cout << "AND " << a << " " << b << endl;
  int res;
  cin >> res;
  return res;
}

void solve() {
  int xorV[n+1];
  int andV[4];
  for (int i=2;i<=n;i++) {
    xorV[i] = getXOR(1, i);
  }
  andV[2] = getAND(1, 2);
  andV[3] = getAND(1, 3);
  int res[n+1];
  int ORofANDS = andV[2] | andV[3];
  int ANDofXORS = xorV[2] & xorV[3];
  int ANDofOTHER2 = getAND(2, 3);
  int num = ANDofXORS ^ ANDofOTHER2;
  res[1] = ORofANDS | num;
  for (int i=2;i<=n;i++) {
    res[i] = res[1] ^ xorV[i];
  }
  cout << "! ";
  for (int i=1;i<=n;i++) {
    cout << res[i] << (i == n ? "" : " ");
  }
  cout << endl;
}

int main() {
  cin >> n;
  solve();
  return 0;
}
