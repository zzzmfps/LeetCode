// 6ms, 31.93%
class Solution {
public:
    bool checkRecord(const string &s) {
        int total_A = 0, conti_L = 0;
        for (auto c : s) {
            if (c == 'L') {
                conti_L += 1;
                if (conti_L > 2) return false;
            }
            else {
                conti_L = 0;
                if (c == 'A') {
                    total_A += 1;
                    if (total_A > 1) return false;
                }
            }
        }
        return true;
    }
};
