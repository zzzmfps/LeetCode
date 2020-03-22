// 3ms, 14.18%; 39.5MB, 5.06%
class Solution {
    public boolean isValid(String s) {
        if ((s.length() & 1) == 1) {
            return false;
        }
        Stack<Character> st = new Stack<Character>();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                char c2 = (c == ')' ? '(' : c == '}' ? '{' : '[');
                if (st.isEmpty() || st.lastElement() != c2) {
                    return false;
                }
                st.pop();
            }
        }
        return st.isEmpty();
    }
}
