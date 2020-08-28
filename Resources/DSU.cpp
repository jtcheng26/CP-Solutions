/*
  Disjoint Set Union implementations.
*/

/*
  Simple DSU with find and union operations.
  Credit to cp-algorithms website authors.
*/
struct DSU {
  vector<int> sz;
  vector<int> parent;

  void build(int size) {
    sz.resize(size + 1);
    parent.resize(size + 1);
  }

  int find_set(int v) {
    if (v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);
  }

  void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
  }

  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (sz[a] < sz[b])
        swap(a, b);
      parent[b] = a;
      sz[a] += sz[b];
    }
  }
};
