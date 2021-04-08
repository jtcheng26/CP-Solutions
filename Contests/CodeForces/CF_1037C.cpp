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
char a[1000001];
char b[1000001];

int solve() {
  int res = 0;
  for (int i=1;i<n;i++) {
    if (a[i] != b[i] && a[i-1] != b[i-1] && a[i] == b[i-1] && a[i-1] == b[i]) {
      a[i-1] = b[i-1];
      a[i] = b[i];
      res++;
      //cout << a[i] << " " << b[i] << endl;
    }
  }
  for (int i=0;i<n;i++) {
    //cout << a[i] << " " << b[i] << endl;
    if (a[i] != b[i]) res++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++)
    cin >> a[i];
  for (int i=0;i<n;i++)
    cin >> b[i];
  cout << solve() << endl;
  return 0;
}
