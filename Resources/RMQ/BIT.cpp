/*
  Binary-Indexed Trees/Fenwick Trees
  - Slightly faster and more memory efficient that segment tree
  - Only supports reversible operations (ex. sum, xor)
*/
template<class T> struct BIT {
  vector<T> bit;
  void init(int n) {
    bit.assign(n, 0);
  }
  T query(int r) {
    T res = 0;
    for (; r >= 0;r = (r & (r + 1)) - 1)
      res += bit[r];
    return res;
  }
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
  void upd(int idx, T d) {
    for (; idx < bit.size(); idx = idx | (idx + 1))
      bit[idx] += d;
  }
};

/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1],
 * and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};
