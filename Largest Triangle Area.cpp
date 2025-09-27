class Solution {
private:
    struct Point {
        int x, y;
        bool operator<(const Point& p) const {
            return x < p.x || (x == p.x && y < p.y);
        }
    };

    long long cross(const Point& O, const Point& A, const Point& B) {
        return 1LL * (A.x - O.x) * (B.y - O.y) -
               1LL * (A.y - O.y) * (B.x - O.x);
    }

    vector<Point> convexHull(vector<Point>& pts) {
        int n = pts.size(), k = 0;
        if (n <= 1)
            return pts;

        sort(pts.begin(), pts.end());
        vector<Point> hull(2 * n);

        for (int i = 0; i < n; i++) {
            while (k >= 2 && cross(hull[k - 2], hull[k - 1], pts[i]) <= 0)
                k--;
            hull[k++] = pts[i];
        }

        for (int i = n - 2, t = k + 1; i >= 0; i--) {
            while (k >= t && cross(hull[k - 2], hull[k - 1], pts[i]) <= 0)
                k--;
            hull[k++] = pts[i];
        }

        hull.resize(k - 1);
        return hull;
    }

public:
    double largestTriangleArea(vector<vector<int>>& points) {
        vector<Point> pts;
        for (const auto& p : points) {
            pts.push_back({p[0], p[1]});
        }
        vector<Point> hull = convexHull(pts);

        long long max_twice_area = 0;
        int n = hull.size();

        if (n < 3) {

            return 0;
        }

        for (int i = 0; i < n; i++) {
            int k = (i + 2) % n;
            for (int j = i + 1; j < n; j++) {
                while (abs(cross(hull[i], hull[j], hull[k])) <
                       abs(cross(hull[i], hull[j], hull[(k + 1) % n]))) {
                    k = (k + 1) % n;
                }
                max_twice_area =
                    max(max_twice_area, abs(cross(hull[i], hull[j], hull[k])));
            }
        }
        return max_twice_area / 2.0;;
    }
};
