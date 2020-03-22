// 20ms, 10.43%; 42MB, 5.26%
class Solution {
    public String countAndSay(int n) {
        String res = "1";
        while (--n > 0) {
            String tmp = "";
            Character last = res.charAt(0);
            int count = 1;
            for (int i = 1; i < res.length(); ++i) {
                if (res.charAt(i) != last) {
                    tmp += String.valueOf(count) + last;
                    last = res.charAt(i);
                    count = 1;
                } else {
                    count += 1;
                }
            }
            res = tmp + String.valueOf(count) + last;
        }
        return res;
    }
}
