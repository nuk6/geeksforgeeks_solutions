
// Q: https://leetcode.com/problems/k-closest-points-to-origin/

int rad(int a, int b){
        return((a*a)+(b*b));
    }
struct comp{
    bool operator()(const pair<int,int>& a, const pair<int,int> &b){
        return (rad(a.first,a.second) < rad(b.first,b.second));
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& v, int k) {
        vector<vector<int> > ans;
        int n = v.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        for(int i = 0; i < k; ++i){
            pq.push(make_pair(v[i][0],v[i][1]));
        }
        for(int i = k; i < n; ++i){
            int cRad = rad(pq.top().first, pq.top().second);
            if(rad(v[i][0],v[i][1]) < cRad){
                pq.pop();
                pq.push(make_pair(v[i][0],v[i][1]));
            }
        }
        while(pq.size()){
            ans.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
        return ans;
    }
};
