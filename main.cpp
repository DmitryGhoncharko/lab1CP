#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
    int x, y;
};

Point p0;

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool compare(Point p1, Point p2) {
    int orient = orientation(p0, p1, p2);
    if (orient == 0) {
        return (std::pow(p1.x - p0.x, 2) + std::pow(p1.y - p0.y, 2)) <
               (std::pow(p2.x - p0.x, 2) + std::pow(p2.y - p0.y, 2));
    }
    return (orient == 2);
}

std::vector<Point> convexHull(std::vector<Point>& points) {
    int ymin = points[0].y, min = 0;
    for (size_t i = 1; i < points.size(); i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }
    std::swap(points[0], points[min]);
    p0 = points[0];

    std::sort(points.begin() + 1, points.end(), compare);

    std::vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);

    for (size_t i = 3; i < points.size(); i++) {
        while (orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    std::vector<Point> points = {
            {0, 3}, {1, 1}, {2, 2}, {4, 4},
            {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };

    std::vector<Point> convexHullPoints = convexHull(points);

    std::cout << "Points on the Convex Hull:\n";
    for (const auto& point : convexHullPoints) {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}
