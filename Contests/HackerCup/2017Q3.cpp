#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

struct dice {
  string s; int min; int max; int rolls;
};

int h, s;
dice arr[10];
float dp[401][21];
int x, y, z;

void parse_dice(int i) {
  int j = 0; string s = arr[i].s;
  while (s.substr(j, 1) != "d") j++;
  int rolls = stoi(s.substr(0, j));
  int d = j;
  int sides; int z = 0;
  while (s.substr(j, 1) != "+" && s.substr(j, 1) != "-" && j < s.length()) j++;
  if (j < s.length()) {
    sides = stoi(s.substr(d+1, j-d));
    if (s.substr(j, 1) == "-")
      z = -1 * stoi(s.substr(j+1));
    else
      z = stoi(s.substr(j+1));
  } else
    sides = stoi(s.substr(d+1));
  arr[i].min = 1 + z;
  arr[i].max = sides + z;
  arr[i].rolls = rolls;
  cout << arr[i].min << " " << arr[i].max << endl;
}

float dpf(ll d, ll k) {
  if (k == 0) return 1;
  else if (d == 0) return 0;
  dp[d][k] = 0;
  for (int i=1;i<=y;i++) {
    dp[d][k] += dpf(d-1, k - i);
  }
  return (float)(1.0 / (float)y) * dp[d][k];
}

double solve() {
  double res = 0;
  for (int i=0;i<s;i++) {
    ll cnt = 0;
    if (arr[i].max + z < h) continue;
    x = arr[i].rolls; y = arr[i].max;
    double prob = dpf(arr[i].rolls, h - z);
    res = prob;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //ifstream fin ("test.out");
  //ofstream fout ("2020Q1.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    cin >> h >> s;
    for (int j=0;j<s;j++) {
      cin >> arr[j].s;
      parse_dice(j);
    }
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
