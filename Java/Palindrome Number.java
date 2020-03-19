// 10ms, 25.42%; 40.5MB, 5.02%
class Solution {
    public boolean isPalindrome(int x) {
        StringBuilder s1 = new StringBuilder(String.valueOf(x));
        StringBuilder s2 = new StringBuilder(s1).reverse();
        return s1.compareTo(s2) == 0;
    }
}
