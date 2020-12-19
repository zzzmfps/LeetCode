# 244ms, 68.22%
class MyCalendar:
    def __init__(self):
        self.booked = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """

        def find_prev(val):  # not equal
            beg, end = 0, len(self.booked) - 1
            while beg < end:
                mid = (beg + end + 1) // 2
                if self.booked[mid][0] < val:
                    beg = mid
                else:
                    end = mid - 1
            return beg if beg == end and self.booked[beg][0] < val else -1

        idx = find_prev(start)
        if idx != -1 and self.booked[idx][1] > start or idx != find_prev(end):
            return False
        self.booked.insert(idx + 1, [start, end])
        return True

    
# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
