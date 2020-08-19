#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n;
int arr[100001];
vector<pair<int, int> > pairs;

int solve() {
  int non = 0;
  int res = 0;
  sort(arr, arr+n);
  int cnt = 1;
  for (int i=1;i<n;i++) {
    if (arr[i] == arr[i-1]) cnt++;
    else {
      if (cnt == 1) {
        non++;
        continue;
      }
      pair<int, int> p(arr[i-1], cnt);
      pairs.push_back(p);
      cnt = 1;
    }
  }
  if (cnt > 1) {
    pair<int, int> p(arr[n-1], cnt);
    pairs.push_back(p);
  } else {
    non++;
  }
  //cout << non << endl;
  for (int i=1;i<n;i++) {
    int need = 0; int j;
    if (pairs.size() > i) continue;
    for (int k=1;k*i <= n;k++) {
      //cout << k << " ";
      need += i - pairs.size();
      //cout << need << endl;
      for (int j=0;j<pairs.size();j++) {
        if (k > pairs[j].second) need++;
      }
    }
    //cout << endl;
    if (need <= non) {
      //cout << i << " " << need << " " << endl;
      res = i-1;
    }
    else break;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    pairs.clear();
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> arr[i];
    }
    cout << solve() << endl;
  }
  return 0;
}
