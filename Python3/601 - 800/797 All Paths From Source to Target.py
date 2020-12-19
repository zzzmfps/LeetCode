# 104ms, 78.97%; 14MB, 100.00%
class Solution: # simply translated from cpp version
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        res, dest = [], len(graph) - 1
        st, trace = [[0]], []
        while st:
            choice = st[-1][-1]
            trace.append(choice)
            if choice != dest and graph[choice]:
                st.append(graph[choice][:])
            else:
                if choice == dest: res.append(trace[:])
                while st and len(st[-1]) == 1:
                    st.pop()
                    trace.pop()
                if st:
                    st[-1].pop()
                    trace.pop()
        return res
