
class Solution {
    vector<string> ans;
char c_arr[16];
    void gen(int N, int o, int c) {
	if(o + c == N) {
		string s = "";
		for (int i = 0; i < o+c; ++i)
		{
			s.append(string(1, c_arr[i]));
			//cout << c_arr[i];
		}
		//cout << endl;
		ans.push_back(s);
	}
	if(o < N/2) {
		c_arr[o+c] = '(';
		gen(N, o + 1, c);
	}
	if(c < o) {
		c_arr[o+c] = ')';
		gen(N, o, c + 1);
	}
}
    
public:
    vector<string> generateParenthesis(int n) {
        //vector<string> ans;
        gen(2*n, 0, 0);
        return ans;
    }
};
