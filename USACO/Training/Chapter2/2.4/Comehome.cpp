/*
   LANG: C++14
   PROG: comehome
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

ll n;
vector<pair<int, int> > adj[52];
int root = 25; // Z

string decode = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

pair<int, int> solve() {
  pair<int, int> ans(0, INFI);
  int dist[52];
  vector<int> visits;
  bool visited[52];
  for (int i=0;i<52;i++) {
    dist[i] = INFI;
    visited[i] = false;
  }
  dist[root] = 0; visits.push_back(1);
  while (visits.size() > 0) {
    int v = 53; int m = INFI; int j;
    for (j=0;j<52;j++) {
      if (!visited[j] && dist[j] < m && adj[j].size() > 0) {
        m = dist[j];
        v = j;
      }
    }
    if (v == 53) break;
    //cout << v << endl;
    visits.pop_back();
    visited[v] = true;
    for (int i=0;i<adj[v].size();i++) {
      if (visited[adj[v][i].first]) continue;
      dist[adj[v][i].first] = min(dist[adj[v][i].first], dist[v] + adj[v][i].second);
      visits.push_back(1);
    }
  }
  for (int i=0;i<52;i++) {
    //cout << dist[i] << endl;
    if (i < 25 && dist[i] < ans.second) {
      //cout << dist[i] << endl;
      ans.second = dist[i];
      ans.first = i;
    }
  }
  return ans;
}

int main() {
  ofstream cout ("comehome.out");
  ifstream cin ("comehome.in");
  cin >> n; string s;
  getline(cin, s);
  for (int i=0;i<n;i++) {
    string a; pair<int, int> p(0, 0);
    getline(cin, a);
    p.second = stoi(a.substr(4));
    int be = decode.find(a.substr(0, 1));
    int en = decode.find(a.substr(2, 1));
    //cout << be << " " << en << endl;
    p.first = en;
    adj[be].push_back(p);
    p.first = be;
    adj[en].push_back(p);
  }
  pair<int, int> res = solve();
  cout << decode[res.first] << " " << res.second << endl;
  return 0;
}
