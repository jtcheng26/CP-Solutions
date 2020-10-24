#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m;
int a[131073];
int tree[131073];

void build(int* arr, int l, int r, int index, int depth) {
  if (r - l == 1) {
    tree[index] = arr[l];
    return;
  }
  int mid = (l + r) / 2;
  build(arr, l, mid, 2 * index + 1, depth + 1);
  build(arr, mid, r, 2 * index + 2, depth + 1);
  int left = tree[2 * index + 1];
  int right = tree[2 * index + 2];
  if (n % 2 == 0) {
    if (depth % 2 == 0)
      tree[index] = left | right;
    else
      tree[index] = left ^ right;
  } else {
    if (depth % 2 == 0)
      tree[index] = left ^ right;
    else
      tree[index] = left | right;
  }
  //cout << "lr " << left << " " << right << endl;
  //cout << index << " " << tree[index] << endl;
}

void update(int l, int r, int index, int depth, int goal, int val) {
  if (goal > r - 1 || goal < l) return;
  if (r - l == 1) {
    tree[index] = val;
    return;
  }
  int mid = (l + r) / 2;
  update(l, mid, 2 * index + 1, depth+1, goal, val);
  update(mid, r, 2 * index + 2, depth+1, goal, val);
  int left = tree[2 * index + 1];
  int right = tree[2 * index + 2];
  if (n % 2 == 0) {
    if (depth % 2 == 0)
      tree[index] = left | right;
    else
      tree[index] = left ^ right;
  } else {
    if (depth % 2 == 0)
      tree[index] = left ^ right;
    else
      tree[index] = left | right;
  }
}

int update(int idx, int val) {
  update(0, 1<<n, 0, 1, idx, val);
  return tree[0];
}

int solve() {
  build(a, 0, 1<<n, 0, 1);
  return tree[0];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i=0;i<1<<n;i++) cin >> a[i];
  solve();
  for (int i=0;i<m;i++) {
    int p, b;
    cin >> p >> b;
    cout << update(p-1, b) << "\n";
  }
  return 0;
}
