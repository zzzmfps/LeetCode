// 5ms, 56.64%; 41.3MB, 10.15%
class MinStack {
    private Stack<Integer> st = new Stack<>();
    private Stack<Integer> stMin = new Stack<>();

    public MinStack() {
    }

    public void push(int x) {
        st.addElement(x);
        if (stMin.isEmpty() || stMin.peek() >= x) {
            stMin.addElement(x);
        }
    }

    public void pop() {
        int pop = st.pop();
        if (pop == stMin.peek()) {
            stMin.pop();
        }
    }

    public int top() {
        return st.peek();
    }

    public int getMin() {
        return stMin.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
