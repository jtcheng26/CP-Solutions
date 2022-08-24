#include <iostream>
#include <vector>

using namespace std;

int n, c;
int need;
vector<int> res;

void rev(int l, int r) {
  for (int k=0;k<(r-l+1)/2;k++) {
      int temp = res[l+k];
      res[l+k] = res[r-k];
      res[r-k] = temp;
  }
}

void go(int l, int r) { // inclusive
  //cout << l << " " << r << " " << need << "\n";
  if (need <= 0) return;
  if (l >= r) return;
  for (int i=r;i>l;i--) {
    if (need - (i - l) >= 0) {
      need -= (i - l);
      rev(l, i);
      if (res[r] < res[l])
        go(l, i-1);
      else
        go(l+1, i);
      break;
    }
  }
}

vector<int> solve() {
    res.clear();
    if (c < n - 1 || c > (n * (n + 1)) / 2 - 1) {
      res.clear();
      return res;
    }
    for (int i=0;i<n;i++) {
      res.push_back(i+1);
    }
    need = c - (n - 1);
    //cout << need << "\n";
    go(0, n-1);
    return res;
}

int main() {
    int t;
    cin >> t;
    for (int z=1;z<=t;z++) {
        cin >> n >> c;
        cout << "Case #" << z << ": ";
        vector<int> ans = solve();
        if (ans.empty())
          cout << "IMPOSSIBLE" << "\n";
        else {
          for (int a : ans) {
            cout << a << " ";
          }
          cout << "\n";
        }
    }
}
