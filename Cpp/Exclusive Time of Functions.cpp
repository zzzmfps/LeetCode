// 12ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    vector<int> exclusiveTime(int n, const vector<string> &logs)
    {
        vector<int> times;
        times.resize(n);

        stack<int> st;
        st.push(getFunctionId(logs.front()));
        int lastTime = getTimeStamp(logs.front());
        for (int i = 1, num = logs.size(); i < num; ++i) {
            auto &x = logs[i];
            int curFunc = getFunctionId(x), curTime = getTimeStamp(x);
            if (getFunctionState(x)) {  // start
                times[st.top()] += curTime - lastTime;
                st.push(curFunc);
                lastTime = curTime;
            } else {  // end
                times[curFunc] += curTime - lastTime + 1;
                st.pop();
                lastTime = curTime + 1;
            }
        }
        return times;
    }

  private:
    int getFunctionId(const string &s)
    {
        int x = s.find(':');
        return stoi(s.substr(0, x));
    }

    bool getFunctionState(const string &s)
    {
        int x = s.find(':');
        return (s[x + 1] == 's' ? true : false);
    }

    int getTimeStamp(const string &s)
    {
        int x = s.rfind(':');
        return stoi(s.substr(x + 1));
    }
};
