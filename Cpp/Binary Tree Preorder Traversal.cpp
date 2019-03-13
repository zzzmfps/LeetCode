// 4ms, 100.0%; 9.4MB, 28.47%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	vector<int> preorderTraversal(TreeNode *root)
	{
		if(!root) return vector<int>();
		vector<int> res;
		stack<TreeNode *> st;
		st.push(root);
		while(!st.empty()) {
			auto ptr = st.top();
			st.pop();
			while(ptr) {
				res.push_back(ptr->val);
				st.push(ptr->right);
				ptr = ptr->left;
			}
		}
		return res;
	}
};
