/*
  Binary-Indexed Trees/Fenwick Trees
  - Slightly faster and more memory efficient that segment tree
  - Only supports reversible operations (ex. sum, xor)
*/
struct BIT {
  vector<int> bit;
  void init(int n) {
    bit.assign(n, 0);
  }
  int sum(int r) {
    int res = 0;
    for (; r >= 0;r = (r & (r + 1)) - 1)
      res += bit[r];
    return res;
  }
  int sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
  void add(int idx, int d) {
    for (; idx < bit.size(); idx = idx | (idx + 1))
      bit[idx] += d;
  }
};
