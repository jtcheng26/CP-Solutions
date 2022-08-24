#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int n;
string a, b;

vector<string> solve() {
  vector<string> res;
  for (int i=0;i<n;i++) {
    string ans = "";
    for (int j=0;j<n;j++) {
        if (i == j) {
          ans += "Y";
        } else {
          bool flag = true;
          if (i - j < 0) {
            for (int k=i;k<j;k++) {
              if (b.substr(k, 1) == "N" || a.substr(k+1, 1) == "N")
                flag = false;
            }
          } else {
            for (int k=i;k>j;k--) {
              if (b.substr(k, 1) == "N" || a.substr(k-1, 1) == "N")
                flag = false;
            }
          }
          if (!flag)
            ans += "N";
          else
            ans += "Y";
        }
    }
    res.push_back(ans);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream fin ("travel_final.txt");
  ofstream fout ("2020Q1_final.txt");
  int t;
  fin >> t;//
  for (int i=1;i<=t;i++) {
    fin >> n >> a >> b;
    fout << "Case #" << i << ": " << endl;//
    vector<string> res = solve();
    for (int i=0;i<res.size();i++) {
      fout << res[i] << endl;
    }
  }
  return 0;
}
