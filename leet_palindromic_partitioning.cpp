// https://leetcode.com/problems/palindrome-partitioning/

//using namespace std;
using vs = vector<string>;
using vvs = vector<vs>;


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


void get(int s, int e, const string& str, vs& v, vvs& ans) {
	if(s == str.size()) {
		cout << "Base case\n";//using namespace std;
using vs = vector<string>;
using vvs = vector<vs>;


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


void get(int s, int e, const string& str, vs& v, vvs& ans) {
	if(s == str.size()) {
		cout << "Base case\n";
		for(auto it: v) {
			cout << it << " | ";
		}
		cout << v.size();
		cout << endl;
		ans.push_back(v);
		//v.clear();
	}
	for (int i = s; i <= e; ++i) {
		if(isPlain(s, i , str)) {
			v.push_back(getStr(str, s, i));
			get(i+1, e, str, v, ans);
            v.pop_back();
		}
	}
}

class Solution {
public:
    vvs partition(string s) {
        int n = s.size();
	    vs v;
        vvs ans;
	    //cout << getStr(s, 0,1) << endl;
	    get(0, n-1, s, v, ans);
        return ans;
    }
};
		for(auto it: v) {
			cout << it << " | ";
		}
		cout << v.size();
		cout << endl;
		ans.push_back(v);
		//v.clear();
	}
	for (int i = s; i <= e; ++i) {
		if(isPlain(s, i , str)) {
			v.push_back(getStr(str, s, i));
			get(i+1, e, str, v, ans);
            v.pop_back();
		}
	}
}

class Solution {
public:
    vvs partition(string s) {
        int n = s.size();
	    vs v;
        vvs ans;
	    //cout << getStr(s, 0,1) << endl;
	    get(0, n-1, s, v, ans);
        return ans;
    }
};
