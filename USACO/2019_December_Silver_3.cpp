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

ll n, m;
bool milk[100001] = {false}; // false: H true: G
vector<int> conn[100001];
int comp[100001];

void bfs(int r, int c) {
  queue<int> q;
  q.push(r);
  while (q.size() > 0) {
    //cout << "sdf" << endl;
    int i = q.front();
    comp[i] = c;
    for (int j=0;j<conn[i].size();j++) {
      if (comp[conn[i][j]] != c && milk[conn[i][j]] == milk[i])
        q.push(conn[i][j]);
    }
    q.pop();
  }
}

void solve() {
  int c = 1;
  for (int i=0;i<=n;i++) comp[i] = -2;
  for (int i=1;i<=n;i++) {
    if (comp[i] == -2) {
      comp[i] = -1;
      bfs(i, c++);
    }
  }
  //for (int i=0;i<=n;i++) cout << comp[i] << endl;
}

bool happy(int be, int en, int t) {
  //cout << comp[be] << " " << comp[en] << endl;
  if (comp[be] != comp[en]) return true;
  else if (milk[be] == t) return true;
  return false;
}

int main() {
  ofstream fout ("milkvisits.out");
  ifstream fin ("milkvisits.in");
  fin >> n >> m;
  string s;
  fin >> s;
  for (int i=1;i<=n;i++) {
    if (s.substr(i-1, 1) == "H") milk[i] = false;
    else milk[i] = true;
  }
  for (int i=0;i<n-1;i++) {
    int a, b;
    fin >> a >> b;
    conn[a].push_back(b);
    conn[b].push_back(a);
  }
  solve();
  string res = "";
  for (int i=0;i<m;i++) {
    int be, en, t;
    fin >> be >> en >> s;
    if (s == "H") t = 0;
    else t = 1;
    if (happy(be, en, t)) res += "1";
    else res += "0";
  }
  fout << res << endl;
  return 0;
}
