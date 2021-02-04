// 8ms, 100.0%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int smallestDistancePair(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int size = nums.size(), low = 0, high = nums.back() - nums.front();
		while(low < high) {
			int count = 0, mid = low + (high - low) / 2;
			for(int i = 0, j = 1; i < size - 1; ++i) {
				while(j < size && nums[j] - nums[i] <= mid) ++j;
				count += j - i - 1;
			}
			count < k ? low = mid + 1 : high = mid;
		}
		return low;
	}
};
