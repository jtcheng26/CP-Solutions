#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int n;
int arr[51] = {0};
int ppl[51];

int solve() {
  int res = 0;
  for (int i=1;i<=2*n;i++) {
    int b[n+1];
    for (int m=0;m<=n;m++) b[m] = arr[m];
    int c = 0;
    for (int j=0;j<n;j++) {
      if (i - ppl[j] > 0 && i - ppl[j] <= n && b[ppl[j]] > 0 && b[i-ppl[j]] > 0) {
        if (i-ppl[j] == ppl[j]) {
          if (b[ppl[j]] < 2) continue;
        }
        c++; b[i-ppl[j]]--; b[ppl[j]]--;
        //cout << i << " " << ppl[j] << " " << i-ppl[j] << endl;
        //cout << i << " " << b[ppl[j]] << " " << b[i-ppl[j]] << endl;
      }
    }
    //if (c > res) cout << i << "i" << endl;
    res = max(res, c);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i=0;i<=50;i++) arr[i] = 0;
    cin >> n;
    for (int i=0;i<n;i++) {
      int j;
      cin >> j;
      ppl[i] = j;
      arr[j]++;
    }
    cout << solve() << endl;
  }
  return 0;
}
