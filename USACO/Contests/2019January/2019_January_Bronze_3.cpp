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
vector<string> chars[101];

int solve() {
  int ans = 0;
  for (int i=0;i<n;i++) {
    int res = 0; int sim = 0;
    for (int j=0;j<n;j++) {
      if (i == j) continue;
      for (int a=0;a<chars[i].size();a++) {
        for (int b=0;b<chars[j].size();b++) {
          if (chars[i][a] == chars[j][b])
            res++;
        }
      }
      sim = max(sim, res);
      res = 0;
    }
    ans = max(ans, sim);
  }
  return ans + 1;
}

int main() {
  ofstream cout ("guess.out");
  ifstream cin ("guess.in");
  cin >> n; string c; int a;
  for (int i=0;i<n;i++) {
    cin >> c; cin >> a;
    for (int j=0;j<a;j++) {
      cin >> c;
      chars[i].push_back(c);
    }
  }
  cout << solve() << endl;
  return 0;
}
