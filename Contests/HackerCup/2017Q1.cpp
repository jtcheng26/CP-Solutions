#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#define PI 3.14159265

typedef long long ll;

using namespace std;

int p, x, y;

string solve() {
  string res = "white"; double ang;
  if (p == 0) return res;
  if (x == 50 && y == 50 && p > 0) return "black";
  if (x > 50 && y == 50) ang = 90;
  else if (x < 50 && y == 50) ang = 270;
  else
    ang = (atan((double)abs(50.0 - (double)x) / (double)abs(50.0 - (double)y)) * 180.0 / PI);
  if (x > 50 && y < 50) ang = 180 - ang;
  if (x < 50 && y < 50) ang = 180 + ang;
  if (x < 50 && y > 50) ang = 360 - ang;
  if (sqrt(pow(abs(50 - x), 2) + pow(abs(50 - y), 2)) <= 50.0) {
    if (ang <= ((double)p / 100.0) * 360) res = "black";
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream fin ("progress_pie_input.txt");
  ofstream fout ("2017Q1.txt");
  int t;
  fin >> t;//
  for (int i=1;i<=t;i++) {
    fin >> p >> x >> y;
    fout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
