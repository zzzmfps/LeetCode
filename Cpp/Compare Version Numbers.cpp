// 4ms, 58.30%; 8.5MB, 78.26%
class Solution
{
public:
    int compareVersion(const string &version1, const string &version2)
    {
        int len1 = version1.size(), len2 = version2.size();
        int idx1 = 0, idx2 = 0;
        while (idx1 < len1 && idx2 < len2) {
            int _idx1 = version1.find('.', idx1), _idx2 = version2.find('.', idx2);
            if (_idx1 == string::npos) _idx1 = len1;
            if (_idx2 == string::npos) _idx2 = len2;
            int num1 = stoi(version1.substr(idx1, _idx1 - idx1));
            int num2 = stoi(version2.substr(idx2, _idx2 - idx2));
            if (num1 != num2) return (num1 > num2 ? 1 : -1);
            idx1 = _idx1 + 1, idx2 = _idx2 + 1;
        }
        if (idx1 > len1) {
            while (idx2 < len2) {
                int _idx2 = version2.find('.', idx2);
                if (_idx2 == string::npos) _idx2 = len2;
                int num2 = stoi(version2.substr(idx2, _idx2 - idx2));
                if (num2) return -1;
                idx2 = _idx2 + 1;
            }
        } else {
            while (idx1 < len1) {
                int _idx1 = version1.find('.', idx1);
                if (_idx1 == string::npos) _idx1 = len1;
                int num1 = stoi(version1.substr(idx1, _idx1 - idx1));
                if (num1) return 1;
                idx1 = _idx1 + 1;
            }
        }
        return 0;
    }
};
