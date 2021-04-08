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

ll n;
map<int, int> p;
vector<int> len;
int cnt[100001] = {0};
int four[100001];
int two[100001];
vector<int> fours;
vector<int> twos;

void compute() {
  for (int i=0;i<100001;i++) {
    int four = cnt[i] / 4;
    for (int j=0;j<four;j++) fours.push_back(1);
    int two = (cnt[i] - (4 * four)) / 2;
    for (int j=0;j<two;j++) twos.push_back(1);
    //cout << four << " " << two << endl;
  }
}

bool solve() {
  return fours.size() > 1 || (fours.size() > 0 && twos.size() > 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t; string s;
  cin >> n;
  for (int i=0;i<n;i++) {
    int l;
    cin >> l;
    cnt[l]++;
    if (p.find(l) == p.end()) {
      p[l] = 1;
      len.push_back(l);
    }
    else p[l]++;
  }
  cin >> t;
  getline(cin, s);
  compute();
  while (t--) {
    string s;
    getline(cin, s);
    int k = stoi(s.substr(2));
    //cout << k << endl;
    if (s[0] == '+') {
      cnt[k]++;
      if (cnt[k] % 4 == 0) {
        fours.push_back(1);
        twos.pop_back();
      }
      else if (cnt[k] % 2 == 0) twos.push_back(1);
    } else {
      if (cnt[k] % 4 == 0) {
        fours.pop_back();
        twos.push_back(1);
      }
      else if (cnt[k] % 2 == 0) twos.pop_back();
      cnt[k]--;
    }
    cout << (solve() ? "YES" : "NO") << endl;

  }
  return 0;
}
