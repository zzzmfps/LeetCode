// 0ms, 100.00%; 37.1MB, 6.02%
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> lli = new ArrayList<List<Integer>>();
        for (int i = 0; i < numRows; ++i) {
            List<Integer> row = new ArrayList<>();
            row.add(1);
            for (int j = 1; j < i; ++j) {
                row.add(lli.get(i - 1).get(j - 1) + lli.get(i - 1).get(j));
            }
            if (i > 0) {
                row.add(1);
            }
            lli.add(row);
        }
        return lli;
    }
}
