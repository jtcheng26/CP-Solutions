#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int n, a;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  string fi = "First"; string se = "Second";
  for (int c=0;c<n;c++) {
    cin >> a;
    int piles[a]; int first = -1; string res;
    for (int i=0;i<a;i++) {
      cin >> piles[i];
      if (piles[i] > 1 && first == -1)
        first = i;
    }
    if (first == -1)
      res = a % 2 == 0 ? se : fi;
    else
      res = first % 2 == 0 ? fi : se;
    cout << res << endl;
  }
  return 0;
}
