// 4ms, 82.37%; 8.6MB, 100.00%
class Solution
{
private:
    const string arr1[5] = { "", "", "Thousand", "Million", "Billion" };
    const string arr2[10] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    const string arr3[10] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    const string arr4[10] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

public:
    string numberToWords(int num)
    {
        if (num == 0) return "Zero";
        
        string strNum = to_string(num);
        int tmp = strNum.size() % 3;
        if (tmp > 0) strNum = string(3 - tmp, '0') + strNum;

        string res = "";
        for (int i = 0, size = strNum.size(); i < size; i += 3) {
            tmp = res.size();
            int x = strNum[i] - 48, y = strNum[i + 1] - 48, z = strNum[i + 2] - 48;
            if (x > 0) res += arr2[x] + " Hundred ";
            if (y == 1) {
                res += arr3[z] + " ";
            } else {
                if (y > 1) res += arr4[y] + " ";
                if (z > 0) res += arr2[z] + " ";
            }
            if (tmp != res.size()) {
                tmp = (size - i) / 3;
                if (tmp > 1) res += arr1[tmp] + " ";
            }
        }
        res.pop_back();
        return res;
    }
};
