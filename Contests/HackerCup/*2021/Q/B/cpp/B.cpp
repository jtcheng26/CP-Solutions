#include <iostream>
#include <fstream>
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

struct xocount
{
	int xs;
	int os;
};

struct data
{
	vector<xocount> rows;
	vector<xocount> cols;
};

int n;
char a[51][51];
int row[51];
int col[51];

data precomp()
{
	data res;
	for (int i = 0; i < n; i++)
	{
		res.rows.pb(xocount());
		res.cols.pb(xocount());
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 'X')
				res.rows[i].xs++;
			if (a[j][i] == 'X')
				res.cols[i].xs++;
			if (a[i][j] == 'O')
				res.rows[i].os++;
			if (a[j][i] == 'O')
				res.cols[i].os++;
		}
		// cout << res.rows[i].xs << " " << res.rows[i].os << "\n";
		// cout << res.cols[i].xs << " " << res.cols[i].os << "\n";
	}
	return res;
}

pair<int, int> solve()
{
	data res = precomp();
	int best = INF;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (res.rows[i].os == 0)
		{
			if (n - res.rows[i].xs == best)
				cnt++;
			else if (n - res.rows[i].xs < best)
			{
				best = n - res.rows[i].xs;
				cnt = 1;
			}
		}
		if (res.cols[i].os == 0)
		{
			if (n - res.cols[i].xs == best)
				cnt++;
			else if (n - res.cols[i].xs < best)
			{
				best = n - res.cols[i].xs;
				cnt = 1;
			}
		}
	}
	if (best == INF)
		return mp(-1, -1);
	if (best == 1)
	{
		int sub = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] == '.' && res.rows[i].xs == n - 1 && res.cols[j].xs == n - 1)
					sub++;
			}
		}
		return mp(1, cnt - sub);
	}
	return mp(best, cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			row[i] = col[i] = 0;
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		pair<int, int> res = solve();
		if (res.F == -1)
			cout << "Case #" << z << ": "
					 << "Impossible"
					 << "\n";
		else
			cout << "Case #" << z << ": " << res.F << " " << res.S << "\n";
	}
	return 0;
}