#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
//#include <chrono>

#define INFI 1000000007
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;
//using namespace std::chrono;

ll n, m, k, s;

ll p[1000001];
ll q[1000001];
ll leftDist[1000001];
ll rightDist[1000001];

// dist(a, b) = sumDists - leftDist(a) - rightDist(b)

ll distq(int a, int b) {
  return abs(q[a] - q[b]);
}

ll distp(int a, int b) { // dist from person a to cluster b
  return abs(q[b] - p[a]);
}

ll bin_sch(ll l, ll r, ll i, ll d) {
  //cout << l << " " << r << endl;
  ll ans = -1;
  if (distp(i, r) <= d) return r;
  //if (distp(i, l) > d) return -1;
  while (l < r) {
    //cout << l << " " << r << endl;
    ll mid = (l + r) / 2;
    //cout << mid << endl;
    if (distp(i, mid) > d && p[i] < q[mid])
      r = mid;
    else {
      l = mid + 1;
      ans = mid;
    }
  }
  //cout << "a " << ans << endl;
  return ans;
}

ll rbin_sch(ll r, ll l, ll i, ll d) {
  //cout << l << " " << r << endl;
  ll ans = -1;
  if (distp(i, l) <= d) return l;
  //if (distp(i, r) > d) return -1;
  while (r > l) {
    //cout << l << " " << r << endl;
    ll mid = (l + r) / 2;
    //cout << mid << endl;
    if (distp(i, mid) > d && p[i] > q[mid])
      r = mid;
    else {
      l = mid + 1;
      ans = mid;
    }
  }
  return ans;
}

bool valid(ll seconds) {
  ll left = 0; ll right = m-1;
  ll covered = 0;
  deque<ll> dq;
  for (int i=0;i<m;i++) dq.push_back(i);
  for (int i=0;i<n && dq.size() > 0;i++) {
    left = dq.front(); right = dq.back();
    //cout << dq.front() << " " << dq.back() << endl;
    ll dLeft = distp(i, left);
    ll dRight = distp(i, right);
    ll left_res; ll right_res;
    // how far right can we go if we go all the way left
    if (seconds >= dLeft && q[left] <= p[i])
      left_res = max(seconds - 2 * dLeft, ((seconds - dLeft) / 2));
    // how far left we can go if we go all the way right
    if (seconds >= dRight && q[right] >= p[i])
      right_res = max(seconds - 2 * dRight, ((seconds - dRight) / 2));
    if (q[left] > p[i])
      left_res = seconds;
    if (q[right] < p[i])
      right_res = seconds;
    //cout << "dist left: " << dLeft << " dist right: " << dRight << endl;
    if (seconds < dLeft) continue;
    //cout << "i: " << i << " lres: " << left_res << " rres: " << right_res << endl;
    // rightmost index that can be removed if we get eveyrthing on left
    ll left_cov = bin_sch(left, right, i, left_res);
    // leftmost index that can be removed if we get everything on right
    ll right_cov = rbin_sch(dq.back(), left, i, right_res);
    //cout << "can go right: " << left_cov << " can go left: " << right_cov << endl;
    if (left_cov >= 0) {
      //cout << "U" << p[i] << " " << *upper_bound(q, q+m, p[i]) << endl;
      while (dq.size() > 0 && dq.front() >= left && q[dq.front()] <= p[i]) {
        dq.pop_front();
      }
      while (dq.size() > 0 && dq.front() <= left_cov) dq.pop_front();

    }

    else if (right_cov > left_cov && right_cov >= 0) {
      while (dq.size() > 0 && dq.back() <= right && q[dq.back()] >= p[i]) {
        dq.pop_back();
      }
      while (dq.size() > 0 && dq.back() >= right_cov) dq.pop_back();
    }

  }
  //cout << "sz " << dq.size() << endl;
  return dq.size() == 0;
}

ll solve() {
  //auto start = high_resolution_clock::now();
  ll res = 0;
  ll sLim = 750000000;
  //cout << sumDists << endl;
  ll l = 0; ll r = sLim;
  while (l < r) {
    ll mid  = (l + r) / 2;
    //cout << mid << endl;
    if (valid(mid)) {
      r = mid;
      res = mid;
    } else
      l = mid + 1;
  }
  /*
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "time: " << duration.count() << "ms";
  */
  return res;
}

void gen(ll aP, ll bP, ll cP, ll dP, ll aQ, ll bQ, ll cQ, ll dQ) {
  for (int i=k;i<n;i++) {
    ll pi = ((aP * p[i-2] + bP*p[i-1] + cP) % dP) + 1;
    p[i] = pi;
  }
  for (int i=k;i<m;i++) {
    ll qi = ((aQ * q[i-2] + bQ*q[i-1] + cQ) % dQ) + 1;
    q[i] = qi;
  }
  sort(q, q+m);
  sort(p, p+n);
  //cout << "gen" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("dislodging_logs_input.txt");
  ofstream cout ("2020R1B.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    ll aP, bP, cP, dP, aQ, bQ, cQ, dQ;
    cin >> n >> m >> k >> s;
    for (int j=0;j<k;j++) cin >> p[j];
    cin >> aP >> bP >> cP >> dP;
    for (int j=0;j<k;j++) cin >> q[j];
    cin >> aQ >> bQ >> cQ >> dQ;
    gen(aP, bP, cP, dP, aQ, bQ, cQ, dQ);
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
