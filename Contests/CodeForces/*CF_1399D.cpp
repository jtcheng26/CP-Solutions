#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

typedef long long ll;

using namespace std;

ll n;
int arr[200001];
int ans[200001] = {0};

int solve() {
  int res = 0;
  queue<int> q[2];
  for (int i=0;i<n;i++) {
    if (q[!arr[i]].size() > 0) {
      ans[i] = ans[q[!arr[i]].front()];
      q[!arr[i]].pop();
      q[arr[i]].push(i);
    } else {
      res++;
      ans[i] = res;
      q[arr[i]].push(i);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> n;
    cin >> s;
    for (int i=0;i<n;i++) {
      arr[i] = stoi(s.substr(i, 1));
    }
    cout << solve() << endl;
    for (int i=0;i<n;i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
