// 148ms, 98.91%; 33.7MB, 5.52%
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
private:
	int depth = 0;

public:
	int maxDepth(Node *root)
	{
		if(!root) return depth;
		stack<Node *> st;
		st.push(root);
		while(!st.empty()) {
			++depth;
			stack<Node *> tmp;
			while(!st.empty()) {
				auto ptr = st.top();
				st.pop();
				for(auto p : ptr->children) tmp.push(p);
			}
			st.swap(tmp);
		}
		return depth;
	}
};
