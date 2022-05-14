#include<bits/stdc++.h>
using namespace std;

using cvi = const vector<int>&;
using vs = vector<string>;
using vvs = vector<vs>;
using vi = vector<int>;
using umii = unordered_map<int,int>; 

int dp[301];


bool get(const string& s, const unordered_set<string>& dict, int st) {
	if(dp[st] != -1) return dp[st];
	if(st==s.size()) return true;
    //auto it = dict.begin();
    auto end = dict.end();
    //while(it != dict.end()) cout << *it++ << " "; cout << endl;
    for(int i = st; i < s.size(); ++i) {
    	if(dict.find(s.substr(st,i-st+1)) != end && get(s,dict,i+1)) {
    		return dp[st] = true;
    	}  
    }
    return dp[st] = false;
}

int main() {
	//string s = "catsssanddogs";
	for(int i = 0; i < 301; ++i) {
		dp[i] = -1;
	}
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	unordered_set<string> dict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	//cout << s.substr(1,1);
	cout << get(s, dict, 0);
	return 0;
}
