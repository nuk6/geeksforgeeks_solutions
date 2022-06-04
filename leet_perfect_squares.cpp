// P : https://leetcode.com/problems/perfect-squares/submissions/
class Solution {
public:
    int dp[99999];
    void f(int n){
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= n; ++i) {
		int mn = i;
		for(int j = 1;  i-j*j >= 0; j++) {
			mn = min(mn, 1 + dp[i-(j*j)]);
		}
		dp[i] = mn;
	}
}
    int numSquares(int n) {
        f(n);
       return dp[n]; 
    }
};
