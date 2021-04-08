#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

struct fav {
  int n;
  int ice[5];
};

bool operator< (const fav &a, const fav &b)
{
  for (int j=0; j<5; j++) {
    if (a.ice[j] < b.ice[j]) return true;
    if (a.ice[j] > b.ice[j]) return false;
  }
  return false;
}

ll n;
int add[6] = {-1, 1, -1, 1, -1, 1};
fav cows[50001];
map<fav, int> subsets;
fav curr;

void set_subsets(int index, int lim, int cnt, int cow) {
  if (index == 5 && cnt == lim) {
    fav f;
    f.n = lim;
    int c = 0;
    for (int i=0;i<5;i++)
      if (curr.ice[i] == 1)
        f.ice[c++] = cows[cow].ice[i];
    for (int i=c;i<5;i++)
      f.ice[i] = 0;
    subsets[f]++;
    //for (int i=0;i<5;i++)
      //cout << f.ice[i] << (i == 4 ? "\n" : " ");
    return;
  } else if (index == 5) return;
  curr.ice[index] = 0;
  set_subsets(index+1, lim, cnt, cow);
  if (cnt < lim) {
    curr.ice[index] = 1;
    set_subsets(index+1, lim, cnt+1, cow);
  }
}

ll solve() {
  ll res = (n * (n - 1)) / 2;
  ll cnt = 0;
  for (auto sub : subsets) {
    //cout << sub.second << endl;
    cnt += add[sub.F.n] * (ll) ((ll)sub.second * ((ll)sub.second - 1)) / 2;
  }
  //cout << res << " " << cnt << endl;
  return res - cnt;
}

int main() {
  ofstream cout ("cowpatibility.out");
  ifstream cin ("cowpatibility.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    for (int j=0;j<5;j++) {
      int v;
      cin >> v;
      cows[i].ice[j] = v;
    }
    sort(cows[i].ice, cows[i].ice+5);
    for (int k=1;k<=5;k++) set_subsets(0, k, 0, i);
  }
  cout << solve() << endl;
  return 0;
}
