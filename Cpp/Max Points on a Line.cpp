// 12ms, 97.58%; 10.4MB, 43.68%
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int maxPoints(const vector<Point>& points)
    {
        int size = points.size();
        if(size < 3) return size;
        int res = 2;
        for(int i = 0; i < size - res; ++i) {
            map<pair<int, int>, int> tmp;
            int cur = 0, same = 0;
            for(int j = i + 1; j < size; ++j) {
                int x_diff = points[i].x - points[j].x;
                int y_diff = points[i].y - points[j].y;
                if(x_diff == 0 && y_diff == 0) {
                    ++same;
                } else {
                    int d = (x_diff && y_diff) ? gcd(x_diff, y_diff) : (x_diff) ? x_diff : y_diff;
                    cur = max(cur, ++tmp[make_pair(x_diff / d, y_diff / d)]);
                }
            }
            res = max(res, 1 + cur + same);
        }
        return res;
    }

private:
    int gcd(int a, int b)
    {
        return a == 0 ? b : gcd(b % a, a);
    }
};
