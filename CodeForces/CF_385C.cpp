#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
#define MAX 10000000

using namespace std;

bool prime[MAX+1]={false};
int counts[MAX+1]={0};
int answer[MAX+1]={0};

// finds all primes from 2 to limit
void make_primes() {
    int limit = sqrt((double)MAX);
    for (int i = 0; i <= MAX; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 2; i <= limit; i++){
        if (prime[i]){
            for (int k = MAX / i, j = i*k; k >= i; k--, j -= i){
                if (prime[k])
                    prime[j] = false;
            }
        }
    }
}

// counts the number of primes that are a multiple of input x
void get_counts() {
    for (int i=2;i<=MAX;i++) {
        if (prime[i]) {
            for (int j=i;j<=MAX;j+=i) {
                answer[i] += counts[j];
            }
        }
    }
    for (int i=1;i<=MAX;i++) { // cumulative counts so that an interval can be found by subtracting
        answer[i] += answer[i-1];
    }
}

int solve(int l, int r) {
    if (r > MAX)
        r = MAX;
    if (l > MAX)
        return 0;
    return answer[r] - answer[l-1]; // cumulative total between r and l
}

int main()
{
    int n; int x; int m; int l; int r;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> x;
        counts[x]++;
    }
    cin >> m;
    make_primes();
    get_counts();
    for (int j=0;j<m;j++) {
        cin >> l; cin >> r;
        int res = solve(l, r);
        cout << res << "\n";
    }
}
