#include "tests.h"
#include <iostream>
#include <cstddef>
#include <gmpxx.h>

struct point {
    double x, y;
};

int wise(point& a, point& b, point& c) {
    int res = 0;
    double Eps = abs(8 * std::numeric_limits<double>::epsilon() * ((b.x - a.x) * (c.y - a.y) + (b.y - a.y) * (c.x - a.x)));
    double area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

    if (area > Eps) {
        return 1;
    } else if (area < -Eps) {
        return -1;
    } else {
        mpq_class a_x(a.x);
        mpq_class a_y(a.y);
        mpq_class b_x(b.x);
        mpq_class b_y(b.y);
        mpq_class c_x(c.x);
        mpq_class c_y(c.y);
        res = sgn((b_x - a_x) * (c_y - a_y) - (c_x - a_x) * (b_y - a_y));
    }
    return res;
}

bool check(double a, double b, double c, double d) {
    if (a > b) {
        swap(a, b);
    }
    if (c > d) {
        swap(c, d);
    }
    return max(a,c) <= min(b,d);
}

bool check(point a, point b, point c, point d) {
    return check(a.x, b.x, c.x, d.x) && check(a.y, b.y, c.y, d.y);
}

int main() {
    int test_id;
    std::cin >> test_id;
    std::vector<double> test = genTest(test_id);

    for (size_t i = 0; i < test.size();) {
        point a = {test[i++], test[i++]};
        point b = {test[i++], test[i++]};
        point c = {test[i++], test[i++]};
        point d = {test[i++], test[i++]};

        int w_abc = wise(a, b, c);
        int w_abd = wise(a, b, d);
        int w_cda = wise(c, d, a);
        int w_cdb = wise(c, d, b);

        int w_ab = w_abc * w_abd;
        int w_cd = w_cda * w_cdb;
        if (check(a, b, c, d) && (w_ab <= 0 && w_cd <= 0)) {
            std::cout << "Y";
        } else {
            std::cout << "N";
        }
    }
}
