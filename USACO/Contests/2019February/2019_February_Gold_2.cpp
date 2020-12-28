#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF 1000000007

typedef long long ll;

using namespace std;

int n;
int a[100001];
deque<int> stacks[100001]; // deque to access bottom of each
pair<int, int> range[100001]; // range of values that can be added to each
stack<int> done; // plates that must be popped before new plates can be added

// find the stack to add num to (return -1 if none found)
int binSch(int l, int r, int num) {
  r++; // inclusive r
  while (l < r) {
    int mid = (l + r) / 2;
    if (num > range[mid].F && num < range[mid].S)
      return mid;
    if (num < range[mid].F)
      r = mid;
    else
      l = mid + 1;
  }
  return -1;
}

// pop from stacks while top < num
int popUntil(int l, int r, int num) {
  if (stacks[l].size() == 0) return l;
  int top = 0;
  int idx = l;
  while (top < num) {
    if (stacks[idx].empty()) {
      idx++;
      if (idx > r) {
        stacks[idx].push_front(num);
        range[idx] = mp(0, num);
        top = num;
      }
    }
    else {
      top = stacks[idx].front();
      if (top > num) {
        stacks[idx].push_front(num);
        range[idx].F = 0;
        range[idx].S = num;
      } else {
        stacks[idx].pop_front();
        done.push(top);
      }
    }
  }
  return idx;
}

void resetTests() {
  int curr = 1;
  int prev = 0;
  for (int i=0;i<10;i++) {
    stacks[i].clear();
    for (int j=0;j<5;j++) {
      stacks[i].push_front(curr++);
    }
    range[i] = mp(prev, stacks[i].front());
    prev = stacks[i].back();
    curr += 10;
  }
}

int test() {
  resetTests();
  cout << "binSch tests" << "\n";
  cout << "should be -1: " << binSch(0, 0, 6) << "\n";
  cout << "should be 0: " << binSch(0, 0, 4) << "\n";
  cout << "should be 1: " << binSch(0, 4, 10) << "\n";
  cout << "popUntil tests" << "\n";
  cout << "should be 0: " << popUntil(0, 4, 2) << "\n";
  resetTests();
  cout << "should be 1: " << popUntil(0, 4, 17) << "\n";
  resetTests();
  cout << "should be 3: " << popUntil(0, 4, 49) << "\n";
}

int solve() {
  int l = 0, r = 0; // inclusive
  range[l] = mp(0, INF);
  for (int i=0;i<n;i++) {
    if (done.size() > 0 && a[i] < done.top()) return i;
    int stack = binSch(l, r, a[i]);
    if (stack == -1) {
      l = popUntil(l, r, a[i]);
      r = max(l, r);
    } else {
      r = max(r, stack);
      stacks[stack].push_front(a[i]);
      range[stack].S = a[i];
      if (stacks[stack].size() == 1) {
        r++;
        range[stack+1] = mp(a[i], INF);
      }
    }
  }
  return n;
}

int main() {
  ofstream cout ("dishes.out");
  ifstream cin ("dishes.in");
  //test();
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve() << endl;
  return 0;
}
