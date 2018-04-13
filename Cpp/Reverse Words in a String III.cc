// 25ms, 52.53%
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
            iss >> temp;
            res += string(temp.rbegin(), temp.rend());
            if (iss.eof())
                return res;
            else
                res += " ";
        }
    }
};
