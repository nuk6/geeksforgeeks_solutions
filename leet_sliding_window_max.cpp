
//Q : https://leetcode.com/problems/sliding-window-maximum/submissions/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
    vector<int> ans;
    int n = a.size();
    if(n == 0) return ans;
    deque<int> dq;
    for(int i = 0; i < min(n,k); ++i){
        while(!dq.empty() && a[i] > a[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    ans.push_back(a[dq.front()]);
    for(int i = k; i < n; ++i){
        while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
        while(!dq.empty() && a[i] > a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        ans.push_back(a[dq.front()]);
    }
        return ans;
    }
    
};
