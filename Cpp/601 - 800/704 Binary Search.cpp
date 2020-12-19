// 28ms, 95.92%; 11MB, 95.54%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int search(const vector<int> &nums, int target)
	{
		int i = 0, j = nums.size() - 1;
		while(i <= j) {
			int mid = i + (j - i) / 2;
			if(nums[mid] == target) return mid;
			if(nums[mid] > target) {
				j = mid - 1;
			} else {
				i = mid + 1;
			}
		}
		return -1;
	}
};
