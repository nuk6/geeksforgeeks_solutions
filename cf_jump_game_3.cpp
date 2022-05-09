#include<bits/stdc++.h>
using namespace std;

int dp[10001];
int src[10001];

using cvi = const vector<int>&;

int get(cvi a, cvi b) {
	queue<int> q;
	int n = a.size();
	q.push(n-1);
	int mn = INT_MAX;
	bool found = false;
	while(!q.empty()) {
		int idx = q.front(); q.pop();
		for(int i = 1; i <= a[idx]; ++i) {
			int curr = idx-i;
			if(curr < mn && curr > 0) {
				dp[curr] = dp[idx]+1;
				src[curr] = idx;
				int y = min(curr+b[curr], n-1);
				dp[y] = dp[curr];
				q.push(y);
				mn = curr;
			} else if(curr < 0) {
				for (int j = 0; j < n; ++j)
				{
					cout << dp[j] << " ";
				}
				cout << endl;
				for (int j = 0; j < n; ++j)
				{
					cout << src[j] << " ";
				}
				return idx;
			}
		}
	}
	return -1; 
}

int main() {
	vector<int> a{0, 1, 2, 3, 5, 5, 6, 7, 8, 5};
	vector<int> b{9, 8, 7, 1, 5, 4, 3, 2, 0, 0};
	int ans = get(a,b);
	if(ans != -1) {
		cout << dp[ans]+1;
		cout << 0;
		while(!src[ans]) {
			cout << src[ans];
			ans = src[ans];
		}
	}
	else cout << -1;
	cout << endl <<ans;
	return 0;
}
