// 2ms, 34.21%; 34.5MB, 100.00%
class Solution {
    public int minAddToMakeValid(String S) {
        Stack<Character> st = new Stack<Character>();
        for (int i = 0, size = S.length(); i < size; ++i) {
            if (!st.empty() && st.peek() == '(' && S.charAt(i) == ')') {
                st.pop();
            } else {
                st.push(S.charAt(i));
            }
        }
        return st.size();
    }
}
