/*
   LANG: C++14
   PROG: milk2
*/

#include <iostream>
#include <fstream>
#include <string>
#include <utility>

using namespace std;

int n;

struct fshift {
  int start;
  int end;
};

bool check(fshift arr[], int t) {
  for (int i=0;i<n;i++) {
    fshift sft = arr[i];
    if (sft.start <= t && t < sft.end)
      return true;
  }
  return false;
}

pair<int, int> solve(fshift arr[]) {
  int max = 0; int min = 10000000;
  for (int i=0;i<n;i++) {
    if (arr[i].end > max)
      max = arr[i].end;
    if (arr[i].start < min)
      min = arr[i].start;
  }
  pair<int, int> res (0, 0);
  int on_count = 0; int off_count = 0;
  for (int i=min;i<max;i++) {
    if (check(arr, i)) {
      if (on_count == 0) {
        if (res.second < off_count)
          res.second = off_count;
        off_count = 0;
      }
      on_count++;
    }
    else {
      if (off_count == 0) {
        if (res.first < on_count)
          res.first = on_count;
        on_count = 0;
      }
      off_count++;
    }
  }
  if (on_count > res.first)
    res.first = on_count;
  if (off_count > res.second)
    res.second = off_count;
  return res;
}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    fin >> n;
    fshift arr[n];
    for (int i=0;i<n;i++) {
      fshift sft;
      fin >> sft.start >> sft.end;
      arr[i] = sft;
    }
    pair<int, int> res = solve(arr);
    fout << res.first << " " << res.second << endl;
    return 0;
}
