// Problem : https://leetcode.com/problems/course-schedule-ii/submissions/

const int MX = 10000;
class Solution {
    vector<int> graph[MX];
    int a[MX];
    vector<int> ans;
public:
    bool dfs(int i) {
        if(a[i] == 1) return true;
        a[i] = 1;
        for(int v : graph[i]) {
            if(a[v] != 2)
                if(dfs(v))
                    return true;
        }
        ans.push_back(i);
        a[i] = 2;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        for(int i = 0; i < preq.size(); ++i) {
            graph[preq[i][0]].push_back(preq[i][1]);
        }
        for(int i = 0; i < n; ++i) {
            if(a[i] != 2 && dfs(i)) {
                return {};
            }
        }
        //vector<int> ans;
        //while(!stk.empty()) ans.push_back(stk.top()), stk.pop();
        return ans;
    }
    
};
