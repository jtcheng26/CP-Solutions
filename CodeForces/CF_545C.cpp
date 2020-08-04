#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

struct timb {
  ll x, h, dl, dr;
};

ll n;
timb arr[100001];
bool tipped_left[100001];
bool tipped_right[100001];

void set_dists() {
  arr[0].dl = -1;
  for (int i=1;i<n-1;i++) {
    arr[i].dl = arr[i].x - arr[i-1].x;
    arr[i].dr = arr[i+1].x - arr[i].x;
  }
  arr[n-1].dr = -1;
}

ll solve() {
  if (n == 1) return 1;
  ll res = 2;
  tipped_left[0] = true; tipped_right[n-1] = true;
  for (int i=1;i<n-1;i++) {
    //cout << arr[i].dl << " " << arr[i].dr << endl;
    if (tipped_right[i-1]) {
      if (arr[i].dl > arr[i-1].h + arr[i].h) {
        tipped_left[i] = true;
        res++;
      } else {
        if (arr[i].dr > arr[i].h) {
          tipped_right[i] = true;
          res++;
        }
      }
    }
    else {
      if (arr[i].dl > arr[i].h)  {
        tipped_left[i] = true;
        res++;
      } else {
        if (arr[i].dr > arr[i].h) {
          tipped_right[i] = true;
          res++;
        }
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    timb t;
    cin >> t.x >> t.h;
    arr[i] = t;
  }
  set_dists();
  cout << solve() << endl;
  return 0;
}
