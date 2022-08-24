#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, m;
vector<int> a[52];
vector<int> adj[52];
int parent[52];
int open[52];

bool solve()
{
  bool res = true;
  for (int i = 0; i < m; i++)
  {
    stack<int> st;
    for (int j = 0; j < a[i].size(); j++)
    {
      int k = a[i][j];
      if (open[k] == 2)
      { // shape closed already
        cout << "1"
             << "\n";
        return false;
      }
      if (st.empty() && parent[k] != -1 && parent[k] != k)
      {
        // should have parent
        cout << "2"
             << " " << i << " " << j
             << "\n";
        return false;
      }
      else if (st.empty() && parent[k] == -1)
        parent[k] = k;
      else if (!st.empty())
      {
        if (k != st.top() && open[k] == 1)
        {
          // shape intersects other
          cout << "3"
               << "\n";
          return false;
        }
        else if (k != st.top()) // new layer
        {
          if (parent[k] == -1) // first time seeing
            parent[k] = st.top();
          else if (parent[k] != st.top())
          {
            // wrong parent
            cout << "4"
                 << "\n";
            return false;
          }
        }
      }
      if (!st.empty() && st.top() == k) // closing shape
        st.pop();
      else
        st.push(k);
      open[k] = 1;
    }
    for (int j = 1; j <= n; j++)
    {
      if (open[j] == 0)
        open[j] = 2;
      else if (open[j] == 1)
        open[j] = 0;
    }
  }
  return res;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
      adj[i].clear();
      parent[i] = -1;
      open[i] = -1;
    }
    for (int i = 0; i < m; i++)
    {
      a[i].clear();
      int k;
      cin >> k;
      for (int j = 0; j < k; j++)
      {
        int lol;
        cin >> lol;
        a[i].pb(lol);
      }
    }
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}