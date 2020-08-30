// 3ms, 71.24%
static int x = []() {
    ios_base::sync_with_stdio(false);  // toggles off the synchronization
    cin.tie(nullptr);                  // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  private:
    vector<string> res;
    vector<string> cur;

  public:
    vector<string> fullJustify(const vector<string> &words, int maxWidth)
    {
        auto push_str = [this, maxWidth](string &&sep) {
            int end = cur.size();
            string head(cur[0]);
            for (int i = 1; i < end; ++i) head += sep + cur[i];
            head += string(maxWidth - head.size(), ' ');
            res.push_back(head);
        };
        int length = 0;
        for (const auto &w : words) {
            int wlen = w.size(), clen = cur.size(), diff = maxWidth - length;
            if (wlen + clen > diff) {
                int space_blocks = clen == 1 ? 1 : clen - 1;
                int spaces = diff / space_blocks, left = diff - space_blocks * spaces;
                for (int i = 0; i < left; ++i) cur[i] += string(1, ' ');
                push_str(string(spaces, ' '));
                cur.clear();
                length = 0;
            }
            cur.push_back(w);
            length += wlen;
        }
        push_str(" ");
        return res;
    }
};
