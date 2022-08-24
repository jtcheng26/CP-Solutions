// Really simple, just annoying dealing with pointers.
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

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  int idx[10001];
  int numComponents(ListNode *head, vector<int> &nums)
  {
    int i = 0;
    for (int i : nums)
    {
      idx[i] = 1;
    }
    int ans = 0;
    bool str = false;
    do
    {
      if (!idx[head->val] && str)
      {
        str = false;
      }
      else if (idx[head->val] && !str)
      {
        str = true;
        ans++;
      }
      head = head->next;
    } while (head != nullptr);

    return ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  ListNode head;
  cin >> head.val;
  ListNode *curr = &head;
  for (int i = 0; i < n - 1; i++)
  {
    // ListNode node;
    int j;
    cin >> j;
    // (*curr).next = &node;
    // curr = &node;
    // cout << (curr->next->val) << "\n";
    // cout << (head.next->val) << "\n";
  }

  head = ListNode(0);
  ListNode n2 = ListNode(1);
  ListNode n3 = ListNode(2);
  ListNode n4 = ListNode(3);
  ListNode n5 = ListNode(4);
  head.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;
  vector<int> nums(m, 0);
  for (int i = 0; i < m; i++)
  {
    cin >> nums[i];
  }
  Solution sol;
  cout << sol.numComponents(&head, nums) << "\n";
  return 0;
}
