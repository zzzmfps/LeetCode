// 3ms, 15.16%; 38.3MB, 6.06%
class Solution {
    private static HashMap<Integer, Boolean> cache = new HashMap<>();

    public static boolean isHappy(int n) {
        HashSet<Integer> tmp = new HashSet<>();
        boolean mark = true;
        while (n > 1) {
            if (cache.containsKey(n)) {
                mark = cache.get(n);
                break;
            }
            if (tmp.contains(n)) {
                mark = false;
                break;
            }
            tmp.add(n);
            n = convert(n);
        }
        for (Integer val : tmp) {
            cache.put(val, mark);
        }
        return mark;
    }

    private static int convert(int n) {
        String nStr = String.valueOf(n);
        int ret = 0;
        for (int i = 0; i < nStr.length(); ++i) {
            ret += Math.pow(nStr.charAt(i) - 48, 2.0);
        }
        return ret;
    }
}
