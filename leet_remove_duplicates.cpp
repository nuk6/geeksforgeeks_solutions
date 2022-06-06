// P : https://leetcode.com/problems/remove-duplicate-letters/
class Solution {
public:
    string solve(string s) {
	int n = s.size();
	stack<int> stk;
	unordered_map<char,bool> vis;
	unordered_map<char, int> freq;
	for(int i = 0; i < n; ++i) {
		freq[s[i]]++;
	}
	//for(auto it : freq) cout << it.first << "-> " << it.second << endl;
	for(int i = 0; i < n; ++i) {
		if(!vis[s[i]]) {
			while((!stk.empty()) && (s[stk.top()] > s[i]) && freq[s[stk.top()]] > 1) {
				freq[s[stk.top()]]--;
				vis[s[stk.top()]] = false;
				//cout << "Popping .." << s[stk.top()] << endl;
				stk.pop();
			}
			stk.push(i);
			//cout << "Pushing..." << s[i] << endl;
			vis[s[i]] = true;
		} else {
            freq[s[i]]--;
        }
	}
	string t = "";
	while(!stk.empty()) { 
		t += s[stk.top()];
		stk.pop();
	}
	reverse(t.begin(), t.end());
	return t;
}
    string removeDuplicateLetters(string s) {
        return solve(s);
    }
};
