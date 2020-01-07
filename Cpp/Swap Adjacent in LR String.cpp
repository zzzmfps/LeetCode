// 8ms, 93.24%; 9.2MB, 100.00%
class Solution
{
public:
    bool canTransform(const string &start, const string &end)
    {
        // 'R' moves to right in "RXXX" and 'L' to left in "XXXL"
        // then it comes to be "XXRX" and "LXXX" or something likewise
        // thus the relative order of 'R' and 'L' remains
        int p1 = 0, p2 = 0, length = start.size();
        while (true) {
            while (p1 < length && start[p1] == 'X') ++p1;
            while (p2 < length && end[p2] == 'X') ++p2;
            if (p1 == length || p2 == length) break;
            if (start[p1] != end[p2] || end[p2] == 'R' && p1 > p2 || end[p2] == 'L' && p1 < p2) return false;
            ++p1, ++p2;
        }
        return p1 == p2;
    }
};
