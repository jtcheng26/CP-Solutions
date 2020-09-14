/*
  Various segment tree implementations.
*/
/*
Tree 1:
  range max w/ index (probably for greedily deleting max element)
  input is an array, common usage is for subtree queries
  initial tree can be converted to euler tour array which is then used for the segment tree.
*/
struct SegTree {
  int sum;
  int n;
  vector<pair<int, int> > maxs;

  void init(int* arr, int rng_size) {
    int sz = 1; n = rng_size + 1;
    while (sz < n) sz *= 2;
    maxs.resize(sz * 2);
    build(arr, 0, 0, n);
  }
  // r is inclusive
  void build(int* arr, int index, int l, int r) {
    if (r - l == 1) { if (l < (ll) n) maxs[index] = mp(arr[l], l); return; }
    int mid = (l + r) / 2;
    int lchild = 2 * index + 1;
    int rchild = 2 * index + 2;
    build(arr, lchild, l, mid); // left child
    build(arr, rchild, mid, r); // right child
    maxs[index] = max(maxs[lchild], maxs[rchild]);
  }

  void ptUpdate(int rngIndex, int index, ll value, int l, int r) {
    if (rngIndex > r - 1 || rngIndex < l) return;
    if (r - l == 1) { maxs[index].F = value; return; }
    int mid = (l + r) / 2;
    ptUpdate(rngIndex, 2 * index + 1, value, l, mid);
    ptUpdate(rngIndex, 2 * index + 2, value, mid, r);
    maxs[index] = max(maxs[2 * index + 1], maxs[2 * index + 2]);
  }

  void ptUpdate(int index, ll value) { ptUpdate(index, 0, value, 0, n); }

  pair<int, int> maxQ(int rngl, int rngr, int index, int l, int r) {
    if (rngr < l || rngl >= r) return make_pair(-1, 0);
    if (rngr >= r - 1 && rngl <= l) return maxs[index];
    int mid = (l + r) / 2;
    pair<int, int> lmid = maxQ(rngl, rngr, 2 * index + 1, l, mid);
    pair<int, int> rmid = maxQ(rngl, rngr, 2 * index + 2, mid, r);
    return max(lmid, rmid);
  }

  pair<int, int> maxQ(int l, int r) { return maxQ(l, r, 0, 0, n); }
};

/*
Tree 2:
  shorter, slightly more efficient segment tree
  credit: AI.Cash on Codeforces
  ideal for implementing sweep line in 10^6 coordinate grid
*/
struct SegTree {
  int n = 1000001;  // array size
  int t[2000002] = {0};

  void init() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
  }

  void ptUpdate(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
  }

  ll rngSum(int l, int r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += t[l++];
      if (r&1) res += t[--r];
    }
    return res;
  }
};
