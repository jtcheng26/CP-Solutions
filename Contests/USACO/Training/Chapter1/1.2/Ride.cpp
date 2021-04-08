/*
  LANG: C++14
  PROG: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string solve(string c, string g) {
  string decode = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int n = c.length();
  int k = g.length();
  int cn = 1, gn = 1;
  for (int i=0;i<n;i++) {
    cn *= (decode.find(c.substr(i, 1), 0) + 1);
  }
  for (int i=0;i<k;i++) {
    gn *= (decode.find(g.substr(i, 1), 0) + 1);
  }
  if (cn % 47 == gn % 47)
    return "GO";
  else
    return "STAY";
}

int main() {
    ifstream fin ("ride.in");
    ofstream fout ("ride.out");
    string c, g;
    fin >> c; fin >> g;
    string result = solve(c, g);
    fout << result << endl;
    return 0;
}
