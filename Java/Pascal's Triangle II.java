// 1ms, 76.65%; 37MB, 6.17%
class Solution {
    public static List<Integer> getRow(int rowIndex) {
        List<Integer> res = Arrays.asList(1);
        for (int i = 0; i < rowIndex; ++i) {
            List<Integer> tmp = new ArrayList<>(Arrays.asList(1));
            for (int j = 1; j <= i; ++j) {
                tmp.add(res.get(j - 1) + res.get(j));
            }
            tmp.add(1);
            res = tmp;
        }
        return res;
    }
}
