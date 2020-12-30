// 0ms, 100.00%; 8.4MB, 75.00%
class Solution
{
public:
    string complexNumberMultiply(const string &a, const string &b)
    {
        int pa = a.find('+'), pb = b.find('+');
        int a1 = stoi(a.substr(0, pa)), a2 = stoi(a.substr(pa + 1, a.size() - pa - 2));
        int b1 = stoi(b.substr(0, pb)), b2 = stoi(b.substr(pb + 1, b.size() - pb - 2));
        int x = a1 * b1 - a2 * b2, y = a1 * b2 + a2 * b1;
        return to_string(x) + '+' + to_string(y) + 'i';
    }
};
