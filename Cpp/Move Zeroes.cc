# 17ms, 32.85%
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int ins_index = 0, end = nums.size();
        while (nums[ins_index] != 0) ++ins_index;
        int trav = ins_index + 1;
        while (trav < end) {
            if (nums[trav] != 0)
                swap(nums[trav], nums[ins_index++]);
            ++trav;
        }
    }
};
