// Problem : https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int get(string s) {
	if(!s.size() || s[0] == '0') return 0;
	int n = s.size();
	int dp[n];
	for(int i=0;i<n;++i) dp[i] = 0;
	dp[0] = 1;
	for(int i = 1; i < n; ++i) {
		int num = stoi(s.substr(i-1,2));
		if(s[i] != '0') {
			int a = dp[i-1] ;
		int b = 0;
			if(num >= 1 && num <= 26 && s[i-1] != '0') {
			 b = (i-2 >= 0) ? dp[i-2] : 1;
			}
			dp[i] = a + b;
		} else if(num >= 1 && num <= 26) {
			dp[i] += (i-2 >= 0) ? dp[i-2] : 1;
		} else {
			return 0;
		}
	}
	return dp[n-1];
}
    int numDecodings(string s) {
            return get(s);
    }
};
