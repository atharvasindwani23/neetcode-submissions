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
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        unordered_map<Node*, Node*> oldToNew;
        oldToNew[node] = new Node(node->val);
        queue<Node*> nodes;
        nodes.push(node);
        while (!nodes.empty()) {
            Node* curr = nodes.front();
            nodes.pop();
            for (Node* neighbor : curr->neighbors) {
                if (!oldToNew.count(neighbor)) {
                    oldToNew[neighbor] = new Node(neighbor->val);
                    nodes.push(neighbor);
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[neighbor]);
            }
        }
        return oldToNew[node];
    }
};
