// 16ms, 99.66%; 8.9MB, 100.0%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if(nums.empty()) return 0;

		int cur = nums[0], count = 1, removed = 0;
		for(int i = 1, size = nums.size(); i < size; ++i) {
			if(nums[i] == cur) {
				if(++count > 2) {
					++removed;
				} else {
					nums[i - removed] = nums[i];
				}
			} else {
				cur = nums[i], count = 1;
				nums[i - removed] = nums[i];
			}
		}
		return nums.size() - removed;
	}
};
