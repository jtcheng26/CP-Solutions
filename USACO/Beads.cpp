/*
   LANG: C++14
   PROB: beads
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int splitb(string a) {
  int total=0; string c = "n";
  int i;
  for (i=0;i<a.length();i++) {
    string bead = a.substr(i, 1);
    if (bead == "w")
      continue;
    else {
      if (c == "n") {
        c = bead;
        continue;
      } else if (bead != c) {
        break;
      }
    }
  }
  c = "n";
  total += i;
  int lim = i;
  for (i=a.length()-1;i>=lim;i--) {
    string bead = a.substr(i, 1);
    if (bead == "w")
      continue;
    else {
      if (c == "n") {
        c = bead;
        continue;
      } else if (bead != c) {
        break;
      }
    }
  }
  total += (a.length() - i - 1);
  return total;
}

int solve(int n, string b) {
  int max = 0; int len = b.length();
  for (int i=0;i<len;i++) {
    string a = b.substr(i, len - i) + b.substr(0, i);
    int res = splitb(a);
    cout << res << " " << a << "\n";
    if (res > max)
      max = res;
  }
  return max;
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n; string b;
    fin >> n; fin >> b;
    fout << solve(n, b) << endl;
    return 0;
}
