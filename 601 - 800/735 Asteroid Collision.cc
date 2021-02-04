// 12ms, 98.48%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int pos, neg = 0, size = asteroids.size();
        while (findNextPair(asteroids, pos, neg)) {
            do {
                int sum = asteroids[pos] + asteroids[neg];
                if (sum == 0) {
                    asteroids[pos--] = asteroids[neg++] = 0;
                } else if (sum > 0) {
                    asteroids[neg++] = 0;
                } else {
                    asteroids[pos--] = 0;
                }
                while (pos > 0 && asteroids[pos] == 0) --pos;
            } while (pos >= 0 && neg < size && asteroids[pos] > 0 && asteroids[neg] < 0);
        }
        asteroids.resize(distance(asteroids.begin(), remove(asteroids.begin(), asteroids.end(), 0)));
        return asteroids;
    }

  private:
    bool findNextPair(const vector<int> &asteroids, int &x, int &y)
    {
        for (int i = y, end = asteroids.size() - 1; i < end; ++i) {
            if (asteroids[i] > 0 && asteroids[i + 1] < 0) {
                x = i, y = i + 1;
                return true;
            }
        }
        return false;
    }
};
