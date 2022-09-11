// P : https://leetcode.com/problems/longest-happy-prefix/
class Solution {
public:
    int dp[100001];
    string solve(string s) {
	int n = s.size();
	dp[0] = 0;
	int i = 0, j = 1;
	while(j < n) {
		while(s[i] == s[j]) {
			dp[j++] =  ++i;
		}
		while(i && s[i] != s[j]) {
			i = dp[i-1];
		}
		if(s[i] != s[j]) {
			dp[j] = 0;
			j++;
		}
	}
	int l = dp[n-1];
	string t = "";
	for(int i = 0; i < l; ++i) {
		t += s[i];
	}
	return t;
}
    string longestPrefix(string s) {
        return solve(s);
    }
};
