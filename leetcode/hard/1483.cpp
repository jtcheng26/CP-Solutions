// I don't actually know binary lifting yet so this is just a weird horizontal binary subtree search haha.
// Awful memory usage but it works. Gotta brush up on tree algorithms.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

class TreeAncestor
{
public:
  vector<int> adj[50001];
  int depth[50001];           // depth of node i
  vector<int> atDepth[50001]; // nodes at depth i
  int idx[50001];             // index of node in preorder traversal
  pair<int, int> rng[50001];  // ranges of preorder indexes in subtree
  int num;
  TreeAncestor(int n, vector<int> &parent)
  {
    num = n;
    for (int i = 1; i < n; i++)
    {
      adj[parent[i]].push_back(i);
    }

    dfs(0, -1, 0, 0);
  }

  int dfs(int node, int parent, int i, int d)
  {
    int l = i;
    int r = l;
    depth[node] = d;
    atDepth[d].push_back(node);
    idx[node] = i;
    for (int child : adj[node])
    {
      if (child == parent)
        continue;
      r = dfs(child, node, r + 1, d + 1);
    }

    rng[node].first = l;
    rng[node].second = r;

    return r;
  }

  void constructorTest()
  {
    cout << "depth:"
         << "\n";
    for (int i = 0; i < num; i++)
    {
      cout << depth[i] << " ";
    }
    cout << "\n";

    cout << "idx:"
         << "\n";
    for (int i = 0; i < num; i++)
    {
      cout << idx[i] << " ";
    }
    cout << "\n";

    cout << "rng:"
         << "\n";
    for (int i = 0; i < num; i++)
    {
      cout << "(" << rng[i].first << ", " << rng[i].second << ") ";
    }
    cout << "\n";

    cout << "atDepth:"
         << "\n";
    for (int i = 0; i < num; i++)
    {
      if (atDepth[i].empty())
        break;
      cout << i << ": ";
      for (int j : atDepth[i])
      {
        cout << j << ", ";
      }
      cout << "\n";
    }
  }

  int getKthAncestor(int node, int k)
  {
    int kDepth = depth[node] - k;

    if (kDepth < 0)
      return -1;

    int l = 0;
    int r = atDepth[kDepth].size();

    while (l < r)
    {
      int mid = (l + r) / 2;

      int candidate = atDepth[kDepth][mid];

      if (rng[candidate].first <= idx[node] && idx[node] <= rng[candidate].second)
      {
        return candidate;
      }
      else if (idx[node] < rng[candidate].first)
      {
        r = mid;
      }
      else
      {
        l = mid + 1;
      }
    }
    return -1;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> p(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }
  TreeAncestor tree(n, p);
  // tree.constructorTest();
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int node, k;
    cin >> node >> k;
    cout << tree.getKthAncestor(node, k) << "\n";
  }

  return 0;
}
