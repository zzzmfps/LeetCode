// 260ms, 94.79%; 56.4MB, 100.00%
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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> ascending; // result
        stack<TreeNode *> st1, st2;
        // add two redundant pointers as sentinels, avoid second while-loop
        TreeNode *head1 = new TreeNode(INT_MAX), *head2 = new TreeNode(INT_MAX);
        head1->left = root1, head2->left = root2;
        while (head1) st1.push(head1), head1 = head1->left;
        while (head2) st2.push(head2), head2 = head2->left;

        while (!st1.empty() && !st2.empty()) {
            auto &st = (st1.top()->val < st2.top()->val ? st1 : st2);
            ascending.push_back(st.top()->val);
            auto tmp = st.top()->right;
            st.pop();
            while (tmp) st.push(tmp), tmp = tmp->left;
        }
        ascending.pop_back(); // pop an INT_MAX
        return ascending;
    }
};
