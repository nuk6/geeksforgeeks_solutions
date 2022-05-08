// Problem : https://codeforces.com/problemset/problem/1601/B

#include<bits/stdc++.h>
using namespace std;

int dp[10001];
int src[10001];

using cvi = const vector<int>&;

void get(cvi a, cvi b) {
	queue<int> q;
	int n= a.size();
	q.push(n-1);
	int mn = INT_MAX;
	bool found = false;
	while(!q.empty()) {
		int idx = q.front(); q.pop();
		for(int i = 1; i <= a[idx]; ++i) {
			if(idx-i < mn && idx-i >= 0) {
				dp[idx-i] = dp[idx] + 1;
				src[idx-i] = idx;
				q.push(idx-i+b[idx-i]);
				mn = idx - i;
			} else if(idx-i < 0) {
				//cout << "here" << endl;
				found = true;
				cout << dp[idx]+1 << endl;
				cout << idx << " " << src[idx] << " " << src[src[idx]] << endl;
				break;
			}
		}
	}
	if(!found)
		cout << -1 << endl; 
}

int main() {
	vector<int> a{0, 1, 2, 3, 5, 5, 6, 7, 8, 5};
	vector<int> b{9, 8, 7, 1, 5, 4, 3, 2, 0, 0};
	get(a,b);
	return 0;
}
