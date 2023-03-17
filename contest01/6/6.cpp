#include <iostream>
#include <cmath>

// Solution based on:
// https://e-maxx.ru/algo/segment_to_line
// https://e-maxx.ru/algo/lines_intersection


using std::cin, std::cout, std::endl;
constexpr double EPS = 0.000001;
constexpr int DONT_INTER = 0;
constexpr int INTER = 1;
constexpr int COINCIDE = 2;
constexpr int NUM_POINTS = 4;


class Point
{
public:
    double x, y;
    Point() : x(0), y(0) {}
    Point(double x_, double y_) : x(x_), y(y_) {}
};

class Line
{
    // Ax + By + C = 0
public:
    double A, B, C;
    Line() : A(0), B(0), C(0) {}
    Line(Point point1, Point point2)
    {
        A = point1.y - point2.y;
        B = point2.x - point1.x;
        C = (-A) * point1.x - B * point1.y;
    }
};

struct Inter_res
{
    int mod;
    Point point;
    Inter_res() : mod(0), point(0, 0) {}
};

Inter_res
get_point_inter(Line line1, Line line2)
{
    Inter_res ans;
    double den = line1.A * line2.B - line2.A * line1.B;
    if (abs(den) < EPS) {
        double coeff1 = line1.A * line2.C - line1.C * line2.A;
        double coeff2 = line1.B * line2.C - line1.C * line2.B;
        if (abs(coeff1) < EPS && abs(coeff2) < EPS) {
            ans.mod = COINCIDE;
        } else {
            ans.mod = DONT_INTER;
        }
    } else {
        ans.mod = INTER;
        ans.point.x = line2.C * line1.B / den - line1.C * line2.B / den;
        ans.point.y = line2.A * line1.C / den - line1.A * line2.C / den;
    }
    return ans;
}


int
main(void)
{
    
    Point points[NUM_POINTS];
    for (int i = 0; i < NUM_POINTS; i++) {
        cin >> points[i].x >> points[i].y;
    }
    Line line1(points[0], points[1]);
    Line line2(points[2], points[3]);
    Inter_res ans = get_point_inter(line1, line2);
    cout << ans.mod << endl;
    if (ans.mod == INTER) {
        cout << ans.point.x << " " << ans.point.y << endl;
    }
    
    return 0;
}


