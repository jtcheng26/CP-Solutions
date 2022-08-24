#include <iostream>

using namespace std;

void solve(int r, int c)
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (i == 0 && j == 0)
      {
        cout << "..";
        continue;
      }
      cout << "+-";
    }
    cout << "+"
         << "\n";
    for (int j = 0; j < c; j++)
    {
      if (i == 0 && j == 0)
      {
        cout << "..";
        continue;
      }
      cout << "|.";
    }
    cout << "|"
         << "\n";
  }
  for (int j = 0; j < c; j++)
  {
    cout << "+-";
  }
  cout << "+"
       << "\n";
}

int main()
{
  int t;
  int a, b;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    cin >> a >> b;
    cout << "Case #" << i << ":"
         << "\n";
    solve(a, b);
  }
}