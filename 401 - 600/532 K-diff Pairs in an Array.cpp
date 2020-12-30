// 20ms, 100.0%; 9.9MB, 99.17%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int findPairs(vector<int> &nums, int k)
	{
		if(nums.empty()) return 0;
		sort(nums.begin(), nums.end());
		int res = 0, i = 0, j = 1, size = nums.size();
		int lasti = nums[0], lastj = lasti - 1;
		while(j < size) {
			int tmp = nums[j] - nums[i];
			if(tmp == k) {
				if(nums[i] != lasti || nums[j] != lastj) {
					lasti = nums[i], lastj = nums[j];
					++res;
				}
				++i, ++j;
			} else if(tmp < k) {
				++j;
			} else {
				++i;
				if(i == j) ++j;
			}
		}
		return res;
	}
};
