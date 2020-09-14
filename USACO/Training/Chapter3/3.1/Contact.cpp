/*
   LANG: C++11
   PROG: contact
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int a, b, n;
string s = "";
map<int, vector<string> > ans;
map<string, int> cnts;

bool cmp(string a, string b) {
  if (a.size() != b.size()) return a.size() < b.size();
  return a < b;
}

int set_str(string sch, int len, int dig) {
  if (dig > len) {
    cnts[sch] = 0;
    return 0;
  }
  int res = 0;
  res += set_str(sch + "0", len, dig+1);
  res += set_str(sch + "1", len, dig+1);
  return res;
}

void precompute() {
  for (int i=a;i<=b;i++) {
    set_str("", i, 1);
  }
  //cout << "strs set" << endl;
  for (int i=0;i<=s.length();i++) {
    vector<string> bucket;
    ans[i] = bucket;
  }
  //cout << "buckets set" << endl;
}

int solve() {
  precompute();
  for (int i=a;i<=b;i++) {
    if (i > s.length()) break;
    for (int j=0;j<=s.length()-i;j++) {
      cnts[s.substr(j, i)]++;
    }
  }
  for (auto const& it : cnts) {
    //cout << it.second << " " << it.first << endl;
    ans[it.second].push_back(it.first);
  }
  //cout << "done" << endl;
  return 0;
}

int main() {
  ofstream cout ("contact.out");
  ifstream cin ("contact.in");
  cin >> a >> b >> n;
  string line;
  getline(cin, line);
  do {
    getline(cin, line);
    s += line;
  } while (!line.empty());
  solve();
  int cnt = 0;
  for (auto it=ans.rbegin();it!=ans.rend();it++) {
    if (it->second.size() == 0 || it->first == 0) continue;
    cnt++;
    cout << it->first << endl;
    int i = 0;
    sort(it->second.begin(), it->second.end(), cmp);
    while (i < it->second.size()) {
      int j;
      for (j = i;j<min(5+i, (int)it->second.size()-1);j++) {
          cout << it->second[j] << " ";
      }
      cout << it->second[j] << endl;
      i+=6;
      //cout << i << endl;
    }
    if (cnt == n) break;
  }
  return 0;
}
