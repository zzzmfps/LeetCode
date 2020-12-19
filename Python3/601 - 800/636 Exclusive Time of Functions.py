# 84ms, 27.83%
class Solution:
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """

        times, stack = [0] * n, []
        last_time = 0

        for log in logs:
            cur_id, state, cur_time = log.split(':')
            cur_id, cur_time = int(cur_id), int(cur_time)
            if state == 's':
                if stack: times[stack[-1]] += cur_time - last_time
                stack.append(cur_id)
                last_time = cur_time
            else:
                times[stack.pop()] += cur_time - last_time + 1
                last_time = cur_time + 1
        return times
