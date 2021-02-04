// 3ms, 56.62%
class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        int count = 0;
        bool is_in_segment = s.front() == ' ' ? false : true;
        for (auto ch : s)
            if (is_in_segment) {    // this brace is necessary
                if (ch == ' ') {    // ensure 'else' not mismatch with this 'if'
                    count += 1;
                    is_in_segment = false;
                }
            }
            else if (ch != ' ')
                is_in_segment = true;
        return s.back() == ' ' ? count : count + 1;
    }
};
