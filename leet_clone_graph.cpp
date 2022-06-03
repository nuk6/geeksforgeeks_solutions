// P : https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    void clone(Node* head) {
        Node* cp = new Node(head->val);
        mp[head] = cp;
        for(auto it : head->neighbors) {
            if(mp.find(it) != mp.end()) {
                cp->neighbors.push_back(mp[it]);
            } else {
                clone(it);
                cp->neighbors.push_back(mp[it]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        clone(node);
        return mp[node];
    }
};
