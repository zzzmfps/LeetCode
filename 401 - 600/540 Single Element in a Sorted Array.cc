// 4ms, 100.0%; 9.3MB, 65.71%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int singleNonDuplicate(const vector<int>& nums)
	{
		int i = 0, j = nums.size() - 1;
		while(i < j) {
			int mid = (i + (j - i) / 2) | 1;
			if(nums[mid - 1] == nums[mid]) {
				i = mid + 1;
			} else {
				j = mid - 1;
			}
		}
		return nums[i];
	}
};
