// P : https://leetcode.com/problems/k-similar-strings/
class Solution {
public:
    void swap(char &a, char& b) {
	char t = a;
	a = b;
	b = t;
}

int solve(int st, string s, string t) {
	int mn = 9999;
	//cout << "S = " << s << " T = " << t << endl;
    int n = s.size();
    if(st >= n) return 0;
	if(s[st] == t[st]) { 
		//cout << "S = " << s << " T = " << t << endl;
		return solve(st+1, s, t);
	}
	for(int i = st+1; i < n; ++i) {
		if(t[st] == s[i] && t[i] == s[st] && s[i] != t[i]) {
			swap(s[st], s[i]);
			return 1 + solve(st+1, s, t);
		}
		if(t[st] == s[i] && s[i] != t[i]) {
			swap(s[st], s[i]);
			mn = min(mn, 1 + solve(st+1, s, t));
			swap(s[st], s[i]);
		}
	}
	return mn;
}
    int kSimilarity(string s1, string s2) {
        int res = solve(0, s1, s2);
        if(res > 999) return -1;
        return res;
    }
};
