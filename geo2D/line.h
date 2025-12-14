#ifndef LINE_H
#define LINE_H

#include "point.h"
#include "geom_utils.h"

class Line {
public:
    // ax + by + c = 0
    double a, b, c;

    Line() : a(0), b(0), c(0) {}

    // from slope and point
    static Line fromSlopePoint(double slope, const Point& p) {
        Line l;
        l.a = -slope;
        l.b = 1;
        l.c = slope * p.x - p.y;
        return l;
    }

    // from two points
    static Line fromPoints(const Point& p1, const Point& p2) {
        Line l;
        l.a = p2.y - p1.y;
        l.b = p1.x - p2.x;
        l.c = -(l.a * p1.x + l.b * p1.y);
        return l;
    }

    double slope() const {
        if (nearlyEqual(b, 0)) return INFINITY;
        return -a / b;
    }

    // intersection with another line
    bool intersection(const Line& other, Point& out) const {
        double det = a * other.b - other.a * b;
        if (nearlyEqual(det, 0)) return false;

        out.x = (b * other.c - other.b * c) / det;
        out.y = (other.a * c - a * other.c) / det;
        return true;
    }
};

#endif
