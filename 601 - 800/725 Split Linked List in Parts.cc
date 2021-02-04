// 8ms, 100.0%; 9.6MB, 32.88%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
	vector<ListNode *> splitListToParts(ListNode *root, int k)
	{
		if(!root || k == 0) return vector<ListNode *>(k, nullptr);

		int listLen = getListLength(root);
		int partLen = listLen / k;
		int leftNum = listLen - k * partLen;

		vector<ListNode *> res;
		res.reserve(k);
		for(int i = 0, end1 = min(k, listLen) - 1; i < end1; ++i) {
			res.push_back(root);
			for(int j = 0, end2 = partLen - (i < leftNum ? 0 : 1); j < end2; ++j) root = root->next;
			auto tmp = root->next;
			root->next = nullptr;
			root = tmp;
		}
		res.push_back(root);
		for(int i = 0, end = max(0, k - listLen); i < end; ++i) res.push_back(nullptr);

		return res;
	}
    
private:
	int getListLength(ListNode *root)
	{
		int ret = 0;
		while(root) {
			root = root->next;
			++ret;
		}
		return ret;
	}
};
