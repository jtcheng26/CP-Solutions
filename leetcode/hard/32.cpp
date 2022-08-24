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

class Solution
{
public:
  int longestValidParentheses(string s)
  {
    int ans = 0;
    int n = s.length();

    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
      if (s[i] == '(')
      {
        st.push(i);
      }
      else
      {
        if (st.size() == 1)
        {
          st.pop();
          st.push(i);
        }
        else
        {
          st.pop();
          ans = max(ans, i - st.top());
        }
      }
    }

    return ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  Solution sol;
  cout << sol.longestValidParentheses(s) << "\n";
  return 0;
}
