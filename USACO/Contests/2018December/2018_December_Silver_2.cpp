#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

struct cow {
  int start;
  int end;
  int senior;
};

int n;
cow cows[100001];

bool cmp(cow a, cow b) {
  return a.start < b.start;
}

int solve() {
  sort(cows, cows+n, cmp);
  int res = 0;
  priority_queue<pair<int, int> > pq; // cow seniority, end time
  pq.push(mp(cows[0].senior, 0));
  int i = 0;
  for (i=1;i<n;i++) {
    if (cows[i].start == cows[i-1].start)
      pq.push(mp(cows[i].senior, i));
    else break;
  }
  int end = 0;
  while (i < n) {
    int top = pq.top().second; pq.pop();
    //cout << top << endl;
    if (cows[top].start >= end) {
      end = cows[top].start + cows[top].end;
    } else {
      res = max(res, end - cows[top].start);
      end = end + cows[top].end;
    }
    while (i < n && (cows[i].start <= end || pq.empty())) {
      pq.push(mp(cows[i].senior, i));
      i++;
    }
  }
  return res;
}

int main() {
  ofstream cout ("convention2.out");
  ifstream cin ("convention2.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> cows[i].start >> cows[i].end;
    cows[i].senior = n - i;
  }
  cout << solve() << endl;
  return 0;
}
