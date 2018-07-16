// 4ms, 98.82%
static int x = []() {
    ios_base::sync_with_stdio(false);  // toggles off the synchronization
    cin.tie(nullptr);                  // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  public:
    string fractionAddition(const string &expression)
    {
        istringstream iss(expression);
        int A = 0, B = 1, a, b;
        char skip;
        while (iss >> a >> skip >> b) {
            A = a * B + A * b;
            B *= b;
            /* <numeric>
            ** C++17 ** <numeric>
            int std::gcd(int, int): greatest common divisor
            int std::lcm(int, int): least common multiple
            both guaranteed to return positive integer.
            ** C++14 or older ** <algorithm>
            int std::__gcd(int m, int n)
            will return a negative integer if m < 0. 'std::__lcm' does not exist
            */
            int g = gcd(A, B);
            A /= g;
            B /= g;
        }
        return to_string(A) + '/' + to_string(B);
    }
};
