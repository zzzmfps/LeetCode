// 24ms, 99.76%; 24.4MB, 54.37%
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
	vector<int> findMode(TreeNode *root)
	{
        vector<int> ret;
        if(!root) return ret;
        
		unordered_map<int, int> rec;
		stack<TreeNode *> tmp;
		tmp.push(root);
		int maxCnt = 0;
		while(!tmp.empty()) {
			TreeNode *t = tmp.top();
			tmp.pop();
			maxCnt = max(maxCnt, ++rec[t->val]);
			if(t->left) tmp.push(t->left);
			if(t->right) tmp.push(t->right);
		}
		
		for(const auto &p : rec)
			if(p.second == maxCnt) ret.push_back(p.first);
		return ret;
	}
};
