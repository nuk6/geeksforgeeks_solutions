
// Problem : https://leetcode.com/problems/palindrome-partitioning-ii/submissions/

int dp[2001][2001];
int is_palin_dp[2001][2001];
class Solution {
public:
    void createisPalin(const string& s) {
	int n = s.size();
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) 
	 		is_palin_dp[i][j] = -1;
	}

	for(int i = 0; i < n; ++i) is_palin_dp[i][i] = true; 

	for(int l = 2; l <= n; ++l) {
		for(int i = 0; i+l-1 < n; ++i) {
			is_palin_dp[i][i+l-1] = s[i] == s[i+l-1] && ( (l!=2)? is_palin_dp[i+1][i+l-2] : true );
		}
	}
	
}
    int get(int s, int e, const string& str) {
	if(s == e || is_palin_dp[s][e]) {
		return dp[s][e] = 0;
	}
	if(dp[s][e] != -1) {
		return dp[s][e];
	}
	int mn = INT_MAX;
	for(int i = s; i <= e; ++i) {
		if(is_palin_dp[s][i]) {
			mn = min(mn, 1 + get(i+1, e, str));
		}
	}
	return dp[s][e] = mn;
}
    int minCut(string s) {
        int n = s.size();
        for(int i = 0; i < n; ++i) {
		    for(int j = 0; j < n; ++j) 
	 		    dp[i][j] = -1;
	    }
        createisPalin(s);
        return get(0, n-1, s);
    }
};
