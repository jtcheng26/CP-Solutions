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

pair<int, int> solve(fshift arr[]) {
  pair<int, int> res (0, 0);
  int start, end = 0;
  start = arr[0].start; end = arr[0].end;
  for (int i=1;i<n;i++) {
    fshift sft = arr[i];
      if (arr[i].start > end) {
        if (end - start > res.first)
          res.first = end - start;
        start = arr[i].start;
        if (start - end > res.second)
          res.second = start - end;
        end = arr[i].end;
      } else if (arr[i].end > end)
        end = arr[i].end;
    }
    if (end - start > res.first)
      res.first = end - start;
    return res;
}

int main() {
    //ofstream fout ("milk2.out");
    //ifstream fin ("milk2.in");
    cin >> n;
    fshift arr[n];
    for (int i=0;i<n;i++) {
      fshift sft;
      cin >> sft.start >> sft.end;
      arr[i] = sft;
    }
    pair<int, int> res = solve(arr);
    cout << res.first << " " << res.second << endl;
    return 0;
}
