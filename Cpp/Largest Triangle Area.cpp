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
        return abs((p2[0] - p1[0]) * (p3[1] - p1[1]) - (p3[0] - p1[0]) * (p2[1] - p1[1]));
    }
};
