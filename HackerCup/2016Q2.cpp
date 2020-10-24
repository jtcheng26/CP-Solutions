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
string s[2];
int seg[2][1003];

int solve() {
  int res = 0;
  int cur = 1;
  for (int r=0;r<2;r++) {
    for (int i=1;i<=n;i++) {
      if (s[r].substr(i-1, 1) == ".") {
        seg[r][i] = cur;
      } else {
        seg[r][i] = 0; cur++;
      }
    }
    cur++;
  }
  seg[0][0] = seg[1][0] = seg[0][n+1] = seg[1][n+1] = 0;
  /*
  for (int r=0;r<2;r++) {
    for (int i=1;i<=n;i++) {
      cout << seg[r][i];
    }
    cout << endl;
  }
  */
  int cover[2003] = {0};
  for (int r=0;r<2;r++) {
    for (int i=1;i<=n;i++) {
      if (seg[r][i] > 0) {
        //cout << i << " " << s[r][i-1] << endl;
        if (seg[r][i-1] == 0 && seg[r][i+1] == 0) {
          if (r == 0 && (seg[r+1][i] == 0 || (seg[r+1][i-1] == 0 && seg[r+1][i+1] == 0))) res++;
          else if (r == 1 && seg[r-1][i] == 0) res++;
          else if (r == 0 && seg[r+1][i] != 0 && cover[seg[r+1][i]] > 0) res++;
          else if (r == 1 && seg[r-1][i] != 0 && cover[seg[r-1][i]] > 0) res++;
          else if (r == 0) cover[seg[r+1][i]]++;
          else if (r == 1) cover[seg[r-1][i]]++;
          continue;
        }
        //cout << "r" << res+1 << endl;
        res++; int temp = seg[r][i];
        while (seg[r][i] == temp && i<=n+1) i++;
        i--;
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream fin ("security_input.txt");
  ofstream fout ("2016Q2.txt");
  int t;
  fin >> t;//
  for (int c=1;c<=t;c++) {
    fin >> n;
    for (int i=0;i<2;i++)
      fin >> s[i];
    fout << "Case #" << c << ": " << solve() << endl;
  }
  return 0;
}
