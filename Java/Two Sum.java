// 1ms, 99.89%; 41.7MB, 5.65%
class Solution {
    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> rec = new HashMap<Integer, Integer>();
        int[] index = { 0, 0 };
        for (int i = 0; i < nums.length; ++i) {
            if (rec.containsKey(nums[i])) {
                index[0] = rec.get(nums[i]);
                index[1] = i;
                break;
            }
            rec.put(target - nums[i], i);
        }
        return index;
    }
}
