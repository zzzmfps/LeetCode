// 20ms, 93.65%; 19.5MB, 100.00%
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root) return nullptr;
        queue<Node *> q;
        q.push(root);
        while (true) {
            if (!q.front()->left) break;
            for (int i = 0, size = q.size(); i < size; ++i) {
                if (i) q.back()->next = q.front()->left;
                q.push(q.front()->left);
                q.back()->next = q.front()->right;
                q.push(q.front()->right);
                q.pop();
            }
        }
        return root;
    }
};
