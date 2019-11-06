#include "iheaders.h"
string tos(vector<string> a){
    string t = "";
    for (size_t i = 0; i < a.size(); i++)
    {
        t += a[i];
    }
    return t;
}

vector<string> tovs(string s){
    vector<string> t;
    for (size_t i = 0; i < s.size(); i++)
    {
        t.push_back(s.substr(i,1));
    }
    return t;
}
string rev(string& s){
    int n = s.size();
    for (size_t i = 0; i < (n/2); i++)
    {
       char t = s[n-i-1];
       s[n-i-1] = s[i];
        s[i] = t;
    }
    return s;
}

vector<string> getShrunkArray(vector<string> vs, int k) {

	vector<string> ans;
	string s = tos(vs);

    stack<char> C;
	stack<int> F;
	int n = s.size();
	string t;
	for (size_t i = 0; i < n; i++)
	{
		if(C.empty()){
			C.push(s[i]);
			F.push(1);
		} else {
			if(s[i] != C.top() && F.top() >= k){
				char ch = C.top();
				while(C.top() == ch) C.pop(),F.pop();
			}
			if(C.size() && s[i] == C.top()){
				C.push(s[i]);
				F.push(F.top()+1);
			} else {
				C.push(s[i]);
				F.push(1);
			}
		}
		
	}
	while(!C.empty()) t += C.top(),C.pop();
	rev(t);
	return tovs(t);
}

int main(){
	string s = "aaaaa";
	vector<string> str,res;
	for (size_t i = 0; i < s.size(); i++)
	{
		str.push_back(s.substr(i,1));
	}
	res = getShrunkArray(str,2);
	for(auto it : res){
		cout << it << "  ";
	}
	return 0;
}
