#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define MAXC 1000000

typedef long long ll;

using namespace std;

ll dp[301][301];
ll pie[301][301];
int n, m;

ll solve() {
  priority_queue<ll, vector<ll>, greater<int> > q;
  ll res = 0;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      //cout << pie[i][j] << endl;
      pie[i][j] += (1 + 2 * (j-1));
      //cout << 1 + 2 * (j-1) << endl;
      //cout << pie[i][j] << " " << j << endl;
      q.push(pie[i][j]);
    }
    //cout << q.top() << endl;
    res += q.top();
    q.pop();
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream fin ("pie_progress_input.txt");
  ofstream fout ("2017R1A.txt");
  int t;
  fin >> t;//
  for (int c=1;c<=t;c++) {
    fin >> n >> m;
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++) {
        fin >> pie[i][j];
      }
      sort(pie[i]+1, pie[i] + m + 1);
    }
    fout << "Case #" << c << ": " << solve() << endl;//
  }
  return 0;
}
