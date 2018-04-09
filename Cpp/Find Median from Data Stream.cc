// 126ms, 99.88%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class MedianFinder
{
  private:
    priority_queue<int> lhalf;
    priority_queue<int, vector<int>, greater<int>> rhalf;

  public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (lhalf.empty() || num < lhalf.top())
            lhalf.push(num);
        else
            rhalf.push(num);
        int size_diff = lhalf.size() - rhalf.size();
        if (size_diff > 1)
        {
            rhalf.push(lhalf.top());
            lhalf.pop();
        }
        else if (size_diff < -1)
        {
            lhalf.push(rhalf.top());
            rhalf.pop();
        }
    }

    double findMedian()
    {
        int size_diff = lhalf.size() - rhalf.size();
        if (size_diff == 0)
            return (lhalf.top() + rhalf.top()) / 2.0;
        return size_diff > 0 ? lhalf.top() : rhalf.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
