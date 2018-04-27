// 44ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class MyCalendar
{
  private:
    map<int, int, greater<int>> booked;

  public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        // lower_bound(x): find the first elem >= x (if less) || <= x (if greater)
        // upper_bound(x): find the first elem >  x (if less) || <  x (if greater)
        auto it = booked.upper_bound(start);
        if (it != booked.end() && it->second > start || it != booked.upper_bound(end))
            return false;
        booked[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
