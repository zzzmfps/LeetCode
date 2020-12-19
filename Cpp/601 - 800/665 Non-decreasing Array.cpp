// 16ms, 100.0%; 10.5MB, 98.94%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	bool checkPossibility(vector<int> &nums)
	{
		bool flag = false;
		for(int i = 1, size = nums.size(); i < size; ++i) {
			if(nums[i] >= nums[i - 1]) continue;
			if(flag) return false;
			flag = true;
            if(i > 1 && nums[i] < nums[i - 2]) nums[i] = nums[i - 1];
		}
		return true;
	}
};
