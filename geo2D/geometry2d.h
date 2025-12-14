#pragma once
#include <cmath>
#include <limits>
#include <stdexcept>

namespace geom2d {

static const double EPS = 1e-9;

/* =========================
   Point
   ========================= */
struct Point {
    double x;
    double y;

    Point() : x(0), y(0) {}
    Point(double x_, double y_) : x(x_), y(y_) {}
};

/* =========================
   Line: ax + by + c = 0
   ========================= */
class Line {
public:
    double a, b, c;

    /* ---------- Constructors ---------- */

    Line() : a(0), b(1), c(0) {}

    Line(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {
        normalize();
    }

    /* ---------- Factory methods ---------- */

    // From two points
    static Line fromPoints(const Point& p1, const Point& p2) {
        if (std::abs(p1.x - p2.x) < EPS &&
            std::abs(p1.y - p2.y) < EPS)
            throw std::invalid_argument("Points must be distinct");

        double a = p2.y - p1.y;
        double b = p1.x - p2.x;
        double c = -(a * p1.x + b * p1.y);
        return Line(a, b, c);
    }

    // From slope and point
    static Line fromSlopePoint(double slope, const Point& p) {
        double a = slope;
        double b = -1.0;
        double c = p.y - slope * p.x;
        return Line(a, b, c);
    }

    // Vertical line: x = k
    static Line vertical(double x) {
        return Line(1.0, 0.0, -x);
    }

    /* ---------- Properties ---------- */

    bool isVertical() const {
        return std::abs(b) < EPS;
    }

    bool isHorizontal() const {
        return std::abs(a) < EPS;
    }

    // slope = -a / b
    bool slope(double& outSlope) const {
        if (isVertical()) return false;
        outSlope = -a / b;
        return true;
    }

    // Angle with +X axis (radians)
    double angleWithXAxis() const {
        // Direction vector = (b, -a)
        return std::atan2(-a, b);
    }

    // Angle with +Y axis
    double angleWithYAxis() const {
        return angleWithXAxis() - M_PI_2;
    }

    /* ---------- Distance & Projection ---------- */

    double distanceToPoint(const Point& p) const {
        return std::abs(a * p.x + b * p.y + c);
    }

    Point projectPoint(const Point& p) const {
        double d = a * p.x + b * p.y + c;
        return Point(
            p.x - a * d,
            p.y - b * d
        );
    }

    /* ---------- Reflection ---------- */

    Point reflectPoint(const Point& p) const {
        Point proj = projectPoint(p);
        return Point(
            2 * proj.x - p.x,
            2 * proj.y - p.y
        );
    }

    Line reflectLine(const Line& other) const {
        Point p1, p2;

        if (!other.isVertical()) {
            p1 = Point(0, (-other.c) / other.b);
            p2 = Point(1, (-other.a - other.c) / other.b);
        } else {
            double x = -other.c / other.a;
            p1 = Point(x, 0);
            p2 = Point(x, 1);
        }

        Point r1 = reflectPoint(p1);
        Point r2 = reflectPoint(p2);

        return Line::fromPoints(r1, r2);
    }

    /* ---------- Intersection ---------- */

    static bool intersection(const Line& l1,
                             const Line& l2,
                             Point& outPoint) {
        double det = l1.a * l2.b - l2.a * l1.b;
        if (std::abs(det) < EPS)
            return false; // parallel

        outPoint.x = (l1.b * l2.c - l2.b * l1.c) / det;
        outPoint.y = (l2.a * l1.c - l1.a * l2.c) / det;
        return true;
    }

private:
    void normalize() {
        double norm = std::sqrt(a * a + b * b);
        if (norm > EPS) {
            a /= norm;
            b /= norm;
            c /= norm;
        }
    }
};

} // namespace geom2d
