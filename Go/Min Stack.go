// 16ms, 93.62%; 7.5MB, 100.00%
type MinStack struct {
	min, stack []int
	mlen, slen int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{stack: make([]int, 0, 1), min: make([]int, 0, 1)}
}

func (this *MinStack) Push(x int) {
	if this.mlen == 0 || this.min[this.mlen-1] >= x {
		this.min = append(this.min, x)
		this.mlen++
	}
	this.stack = append(this.stack, x)
	this.slen++

}

func (this *MinStack) Pop() {
	if this.min[this.mlen-1] == this.stack[this.slen-1] {
		this.min = this.min[:this.mlen-1]
		this.mlen--
	}
	this.stack = this.stack[:this.slen-1]
	this.slen--

}

func (this *MinStack) Top() int {
	return this.stack[this.slen-1]
}

func (this *MinStack) GetMin() int {
	return this.min[this.mlen-1]
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
