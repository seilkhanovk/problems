/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 vector<Node*> neighbors;
 
 Node() {}
 
 Node(int _val, vector<Node*> _neighbors) {
 val = _val;
 neighbors = _neighbors;
 }
 };
 */
class Solution {
public:
    
    bool visited[109];
    map<int, Node*> mp;
    Node* cloneGraph(Node* node) {
        
        Node* ans = new Node(node->val);
        mp[node->val] = ans;
        
        queue<Node*> q;
        q.push(node);
        visited[node->val] = true;
        vector<int> g[109];
        while (!q.empty()) {
            Node* u = q.front(); q.pop();
            for (auto v: u->neighbors) {
                g[u->val].push_back(v->val);
                if (!visited[v->val]) {
                    Node* x = new Node(v->val);
                    
                    mp[u->val]->neighbors.push_back(x);
                    
                    mp[x->val] = x;
                    
                    q.push(v);
                    visited[v->val] = true;
                }else
                    mp[u->val]->neighbors.push_back(mp[v->val]);
            }
        }
        return ans;
    }
};
