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
        queue<Node*> nodes;
        Node* newNode = new Node(node->val);
        oldToNew[node] = newNode;
        nodes.push(node);

        while (!nodes.empty()) {
            Node* currNode = nodes.front();
            nodes.pop();

            for (Node* neighbour : currNode->neighbors) {
                if (!oldToNew.count(neighbour)) {
                    oldToNew[neighbour] = new Node(neighbour->val);
                    nodes.push(neighbour);
                }
                oldToNew[currNode]->neighbors.push_back(oldToNew[neighbour]);

        }

    }

    return oldToNew[node];
    }
};
