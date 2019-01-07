// 4ms, 93.80%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double maxArea = 0.0;
        int pts = points.size();
        for (int i = 0; i < pts - 2; ++i)
            for (int j = i + 1; j < pts - 1; ++j)
                for (int k = j + 1; k < pts; ++k) maxArea = max(maxArea, getArea(points, i, j, k));
        return maxArea;
    }

  private:
    double getArea(vector<vector<int>> &points, int i, int j, int k)
    {
        auto &p1 = points[i], &p2 = points[j], &p3 = points[k];  // A, B, C
        double l1, l2, fa, fb, fc;                               // |AB|, h, factor (a,b,c) in eq aX + bY + c = 0
        double deltaX = p2[0] - p1[0], deltaY = p1[1] - p2[1];
        l1 = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
        if (deltaY == 0) {
            fa = 0, fb = 1;
        } else {
            fa = 1, fb = deltaX / deltaY;
        }
        fc = -(fa * p1[0] + fb * p1[1]);
        l2 = abs(fa * p3[0] + fb * p3[1] + fc) / sqrt(fa * fa + fb * fb);
        return 0.5 * l1 * l2;
    }
};
