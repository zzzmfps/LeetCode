// 14ms, 99.72%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        int area1, area2, area3;
        area1 = abs(A - C) * abs(B - D);
        area2 = abs(E - G) * abs(F - H);
        if (C < E || G < A || D < F || H < B) {
            area3 = 0;
        } else {
            int x[] = {A, C, E, G};
            int y[] = {B, D, F, H};
            sort(x, x + 4);
            sort(y, y + 4);
            area3 = (x[2] - x[1]) * (y[2] - y[1]);
        }
        return area1 + area2 - area3;
    }
};
