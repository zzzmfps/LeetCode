// 13ms, 52.56%
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;
        
        int len1 = num1.size(), len2 = num2.size();
        int end = (len1 > len2 ? len1 : len2) - 1;
        int dif = len1 - len2;
        if (dif > 0)
            num2 = string(dif, '0') + num2;
        else
            num1 = string(-dif, '0') + num1;
        int carry = 0;
        string res = "";
        for (int i = 0; i <= end; ++i) {
            int tmp = num1[end - i] + num2[end - i] - 96 + carry;
            if (tmp > 9)
                tmp -= 10, carry = 1;
            else
                carry = 0;
            res += to_string(tmp);
        }
        if (carry) res += '1';
        return string(res.rbegin(), res.rend());
    }
};
