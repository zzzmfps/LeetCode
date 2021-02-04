// 8ms, 78.01%; 8.7MB, 100.00%
class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int P)
    {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1;
        int point = 0;
        while (true) {
            while (i <= j && tokens[i] <= P) {
                P -= tokens[i++];
                point += 1;
            }
            if (i >= j || point == 0) break;
            P += tokens[j--];
            point -= 1;
        }
        return point;
    }
};
