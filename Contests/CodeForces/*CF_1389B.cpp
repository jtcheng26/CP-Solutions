#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n, k, z;

ll solve(int* arr) {
  if (n == 1) return 0;
  ll res = 0;
  for (int i=0;i<=z;i++) {
    ll score = 0;
    int max_l = 0;
    //dp[i][0] = scores[k-2*i];
    for (int j=0;j<k-2*i+1;j++) {
      //cout << k-(2*i) << endl;
      if (j < n-1)
        max_l = max(max_l, arr[j] + arr[j+1]);
      score += arr[j];
      //cout << dp[i][j] << endl;
    }
    res = max(res, score + max_l * i);
  }
  //cout << " M " << m << " z " << mz << endl;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t, a;
  cin >> t;
  for (int i=0;i<t;i++) {
    cin >> n >> k >> z;
    int arr[n];
    for (int j=0;j<n;j++) {
      cin >> arr[j];
    }
    cout << solve(arr) << endl;
  }
  return 0;
}
