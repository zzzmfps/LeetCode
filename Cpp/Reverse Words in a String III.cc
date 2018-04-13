// 13ms, 99.30%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  public:
    string reverseWords(const string &s)
    {
        if (s.empty())
            return "";
        string res = "", temp = "";
        istringstream iss(s);
        while (true)
        {
            iss >> temp; // input
            res += string(temp.rbegin(), temp.rend());
            if (iss.eof())
                return res;
            else
                res += " ";
        }
    }
};
