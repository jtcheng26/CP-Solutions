#include <iostream>
 
using namespace std;
 
int main()
{
    int n; int c;
    cin >> n; cin >> c;
    int last; int x; int max_diff=0;
    cin >> last;
    for (int i=1;i<n;i++) {
        cin >> x;
        if (last - x > max_diff)
            max_diff = last-x;
        last = x;
    }
    cout << ((max_diff - c > 0) ? (max_diff - c) : 0);
}
