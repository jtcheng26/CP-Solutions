/*
   LANG: C++14
   PROG: friday
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int day[7];
int num[12] = {12, 43, 71, 102, 132, 163, 193, 224, 255, 285, 316, 346};
int leap[12] = {12, 43, 72, 103, 133, 164, 194, 225, 256, 286, 317, 347};

void solve(int n) {
  int start_day = 2; bool leapyr;
  for (int i=0;i<n;i++) {
    leapyr = false;
    if ((1900 + i) % 4 == 0 && ((1900 + i) % 100 != 0 || (1900 + i)% 400 == 0))
      leapyr = true;
    for (int j=0;j<12;j++) {
      if (leapyr)
        day[(start_day + leap[j]) % 7]++;
      else
        day[(start_day + num[j]) % 7]++;
    }
    if (leapyr)
      start_day = (366 + start_day) % 7;
    else
      start_day = (365 + start_day) % 7;
  }
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    fin >> n;
    solve(n);
    for (int i=0;i<6;i++) {
      fout << day[i] << " ";
    }
    fout << day[6] << endl;
    return 0;
}
