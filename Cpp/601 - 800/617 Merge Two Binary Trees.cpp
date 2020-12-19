// 52ms, 53.07%; 25.6MB, 5.55%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    { // will change structure and data of the given two trees
        if (!t1 && !t2) return nullptr;
        if (!t1 || !t2) return (t1 ? t1 : t2);
        t1->val += t2->val;
        stack<TreeNode *> st1, st2;
        st1.push(t1), st2.push(t2);
        while (!st1.empty()) {
            auto node1 = st1.top(), node2 = st2.top();
            st1.pop(), st2.pop();
            helper(node1->left, node2->left, st1, st2);
            helper(node1->right, node2->right, st1, st2);
        }
        return t1;
    }

private:
    void helper(TreeNode *&node1, TreeNode *node2, stack<TreeNode *> &st1, stack<TreeNode *> &st2)
    {
        if (node1 && node2) {
            node1->val += node2->val;
            st1.push(node1);
            st2.push(node2);
        } else if (node2) {
            node1 = node2;
        }
    }
};
