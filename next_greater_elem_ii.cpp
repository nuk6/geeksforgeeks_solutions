// P : https://leetcode.com/problems/next-greater-element-ii/
class Solution {
public:
    using cvi = const vector<int>&;
    vector<int> solve(cvi a) {
        int n = a.size();
        stack<int> s;
        vector<int> ans(n);
        s.push(n);
        for(int i = n-1; i >= 0; --i) {
            while(!s.empty() && s.top() < n && a[s.top()] <= a[i]) s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n; ++i) a.push_back(a[i]);
        vector<int> t_ans = solve(a);
        vector<int> ans;
        for(int i = 0;i < n; ++i) {
            if(t_ans[i] == 2*n) ans.push_back(-1);
            else ans.push_back(a[t_ans[i]%n]);
        }
        for(auto it : ans) cout << it << " "; cout << endl;
        return ans;
    }
};
