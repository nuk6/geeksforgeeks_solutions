// Problem : https://leetcode.com/problems/subarray-sum-equals-k/

using cvi = const vector<int>&;
using vs = vector<string>;
using vvs = vector<vs>;
using vi = vector<int>;
using umii = unordered_map<int,int>; 

class Solution {
public:
    int get(const vi& v, int k) {
	umii freq;
	int count = 0;
	int n = v.size();
	int pref_sum[n];
	pref_sum[0] = v[0];
	for(int i = 1; i < n; ++i) {
		pref_sum[i] = v[i] + pref_sum[i-1];
	}
	if(v[0] == k) count++;
	freq[v[0]]++;
	freq[0]++;
	for(int i = 1; i < n; ++i) {
		count += freq[pref_sum[i]-k];
		freq[pref_sum[i]]++;
	}
	return count;
}
    int subarraySum(vector<int>& v, int k) {
        return get(v,k);
    }
};
