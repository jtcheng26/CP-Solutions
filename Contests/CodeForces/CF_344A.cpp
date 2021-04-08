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

int solve() {
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n; int m; int res=0;
  int last;
  cin >> last;
  for(int i=1;i<n;i++) {
    cin >> m;
    if (m != last)
      res++;
    last = m;
  }
  cout << res+1 << endl;
  return 0;
}
