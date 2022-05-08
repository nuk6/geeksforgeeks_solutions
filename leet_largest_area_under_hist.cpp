
// Problem : https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> left(n), right(n);
	stack<int> stk, rstk;
	stk.push(-1);

	for(int i = 0; i < n; ++i) {
		while(stk.top() != -1 && a[stk.top()] >= a[i]) stk.pop();
		left[i] = stk.top();
		stk.push(i);
	}
	//while(!stk.empty()) stk.pop();
	//cout << endl << stk.size() << endl;
	rstk.push(n);
	for(int i = n-1; i >= 0; --i) {
		while(rstk.top() != n && a[rstk.top()] >= a[i]) rstk.pop();
		right[i] = rstk.top();
		rstk.push(i);
	}
	int mx = -1;
	for(int i = 0; i < n; ++i) {
		mx = max(mx, a[i]*(right[i]-left[i]-1));
	}
        return mx; 
    }
};
