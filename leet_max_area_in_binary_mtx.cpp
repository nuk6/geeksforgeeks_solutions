
// Problem : https://leetcode.com/problems/maximal-rectangle/

int dp[201][201];
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mtx) {
        int n = mtx[0].size();
	int m = mtx.size();
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			if(mtx[i][j] == '1') {
				dp[i][j] = j?dp[i][j-1]+1 : 1;
			} else {
				dp[i][j] = 0;
			}
		}
	}
	/* Debug
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}*/
	int mx = INT_MIN;
	for(int j = 0; j < n; ++j) {
		stack<int> top_stk;
		top_stk.push(-1);
		vector<int> top(m);
		for(int i = 0; i < m; ++i) {
			while(top_stk.top() != -1 && dp[top_stk.top()][j] >= dp[i][j]) top_stk.pop();
			top[i] = top_stk.top();
			top_stk.push(i);
		}
		stack<int> down_stk;
		down_stk.push(m);
		vector<int> down(m);
		for(int i = m-1; i >= 0; --i) {
			while(down_stk.top() != m && dp[down_stk.top()][j] >= dp[i][j]) down_stk.pop();
			down[i] = down_stk.top();
			down_stk.push(i);
		}
		//for (int i = 0; i < m; ++i) cout << top[i] << " | "; cout  << endl;
		//for (int i = 0; i < m; ++i) cout << down[i] << " | "; cout  << endl;
		for (int i = 0; i < m; ++i)
		{
			mx = max(mx, dp[i][j] * (down[i] - top[i] -1));
		}
		//cout << "MX = " << mx << endl;
	}
	return mx;
    }
};
