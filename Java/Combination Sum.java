// 3ms, 81.92%; 39.5MB, 82.57%
class Solution {
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new LinkedList<>();
        LinkedList<Integer> tmp = new LinkedList<>();
        dfs(candidates, target, res, tmp, 0);
        return res;
    }

    private static void dfs(int[] candidates, int target, List<List<Integer>> res, LinkedList<Integer> tmp, int index) {
        while (index < candidates.length && candidates[index] <= target) {
            tmp.offerLast(candidates[index]);
            if (candidates[index] == target) {
                res.add(List.copyOf(tmp));
                tmp.pollLast();
                break;
            } else {
                dfs(candidates, target - candidates[index], res, tmp, index++);
            }
            tmp.pollLast();
        }
    }
}
