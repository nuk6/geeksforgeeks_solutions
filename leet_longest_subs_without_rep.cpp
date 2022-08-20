// P : https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using cvi = const vi&;
using cvs = const vector<string>&;
using pii = pair<int,int>;

int solve(string s) {
	 int n = s.size();
	 if(n == 1) return n;
	 unordered_map<char, int> last_idx;
	 int x = 0, mx = 0;
	 last_idx[s[0]] = 0;
	 for(int i = 1; i < n; ++i) {
	 	if(last_idx.find(s[i]) == last_idx.end() || last_idx[s[i]] < x) {
	 		mx = max(mx, i-x+1);
	 	} else {
	 		x = last_idx[s[i]]+1;
	 		mx = max(mx, i-x+1);
	 	}
	 	last_idx[s[i]] = i;
	 }
	 return mx;
}

int main() {
	cout << "Hii....\n";
	string s = "pwwkew"; 
	cout << solve(s);
	return 0;
}
