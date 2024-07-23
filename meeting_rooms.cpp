#include <bits/stdc++.h>
using namespace std;

struct event {
	int s;
	int e;
	int i;
};

int solve(int k, vector<vector<int>>&& m) {
	sort(m.begin(), m.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
	});
	map<int, int> occurance;
	priority_queue<int> avl_rooms;

	priority_queue<event, vector<event>, decltype([](event& e1, event& e2){
		if (e1.e == e2.e) return e1.i > e2.i;
		else return e1.e > e2.e;
	})> m_rooms;

	int n = m.size();

	for(int i = 0; i < n; ++i) {
		if (i < k) {
			m_rooms.push(event{m[i][0], m[i][1], i});
			occurance[i]++;
			continue;
		} 
		int start = m[i][0];
		while(!m_rooms.empty() && m_rooms.top().e < start) {
			event e = m_rooms.top();
			m_rooms.pop();
			avl_rooms.push(e.i);
		}
		if (!avl_rooms.empty()) {
			int r_id = avl_rooms.top();
			avl_rooms.pop();
			occurance[r_id]++;
			continue;
		}
		if (!m_rooms.empty()) {
			event e = m_rooms.top();
			m_rooms.pop();
			m_rooms.push(event{m[i][0], m[i][1], e.i});
			occurance[e.i]++;
		}
	}
	int ans = -1;
	int mx_o = -1;
	for(auto&[k,v] : occurance) {
		cout << "rid = " << k << " freq = " << v << endl;
		if (v > mx_o) {
			mx_o = v;
			ans = k;
		}
	}
	return ans;
}

int main() {
	cout << solve(3, {{1,20},{2,10},{3,5},{4,9},{6,8}});
	return 0;
}


