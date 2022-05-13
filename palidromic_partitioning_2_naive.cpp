#include<bits/stdc++.h>
using namespace std;

using cvi = const vector<int>&;
using vs = vector<string>;
using vvs = vector<vs>;

vvs ansS;

bool isPlain(int i, int j, const string& str) {
	bool ans = true;
	while(i < j) {
		ans &= str[i++] == str[j--];
	}
	return ans;
}	

string getStr(const string& str, int I, int j) {
	string ans = "";
	for (int i = I; i <= j; ++i)
	{
		ans += str[i];
	}
	return ans;
}


int get(int s, int e, const string& str) {
	if(s == e || isPlain(s, e, str)) {
		return 0;
	}
	int mn = INT_MAX;
	for (int i = s; i <= e; ++i) {
		if(isPlain(s, i , str)) {
			mn = min(mn, 1 + get(i+1, e, str));
		}
	}
	return mn;
}


int main() {
	string s = "ababbbabbababa";
	//cout << isPalin("aabbbasdf", 0, 0);
	int n = s.size();
	vs v;
	//cout << getStr(s, 0,1) << endl;
	cout << get(0, n-1, s);
	return 0;
}
