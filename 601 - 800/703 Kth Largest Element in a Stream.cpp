// 28ms, 100.00%; 19.3MB, 100.00%
auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class KthLargest
{
private:
    vector<int> arr;

public:
    KthLargest(int k, const vector<int> &nums)
    {
        copy(nums.begin(), nums.end(), back_inserter(arr));
        make_heap(arr.begin(), arr.end(), greater<int>());
        if (arr.size() < k) {
            arr.push_back(INT_MIN);
            push_heap(arr.begin(), arr.end(), greater<int>());
        } else {
            while (arr.size() > k) {
                pop_heap(arr.begin(), arr.end(), greater<int>());
                arr.pop_back();
            }
        }
    }

    int add(int val)
    {
        if (val > arr[0]) {
            pop_heap(arr.begin(), arr.end(), greater<int>());
            arr.back() = val;
            push_heap(arr.begin(), arr.end(), greater<int>());
        }
        return arr[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
