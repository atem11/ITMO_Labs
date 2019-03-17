#include <bits/stdc++.h>

using namespace std;

struct point {
	long long x;
	long long y;

	bool operator == (point& other) {
		return x == other.x && y == other.y;
	}

	bool operator < (point& other) {
        return x != other.x ? x < other.x : y < other.y;
    }
};

//LEFT > 0
//RIGHT < 0
long long wise(point& a, point& b, point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

long long dist(point& a, point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int bin_search(point& target, point& zero, vector<point>& polygon) {
    int l = 1;
    int r = polygon.size() - 1;
    while (l + 1 < r) {
        int m = (r + l) / 2;
        long long wise_s = wise(zero, polygon[m], target);
        if (wise_s < 0) {
            r = m;
        } else {
            l = m;
        }
    }
    if (l + 1 == r) {
        long long wise_s = wise(zero, polygon[r], target);
        if (wise_s >= 0) {
            return r;
        }
    }
    return l;
}

string check(vector<point>& polygon, point target) {
    int n = polygon.size();
    point zero = polygon[0];
    //крайние случаи
    if (wise(zero, polygon[1], target) < 0) {
        return "OUTSIDE";
    }
    if (wise(zero, polygon[n - 1], target) > 0) {
        return "OUTSIDE";
    }
    if (target == zero) {
        return "BORDER";
    }
    //Binary search
    int ind = bin_search(target, zero, polygon);
    point L = polygon[ind];
    //on line
    if (wise(zero, L, target) == 0) {
        long long distToL = dist(zero, L);
        long long distToTerget = dist(zero, target);
        if (distToL < distToTerget) {
            return "OUTSIDE";
        }
        if (distToL == distToTerget || ind == 1 || ind == n - 1) {
            return "BORDER";
        }
        return "INSIDE";
    }
    //else ))
    point R = polygon[ind + 1];
    long long wise_s = wise(L, R, target);
    if (wise_s == 0) {
        return "BORDER";
    }
    if (wise_s > 0) {
        return "INSIDE";
    }
    return "OUTSIDE";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //*
    freopen("inside.in", "r", stdin);
    freopen("inside.out", "w", stdout);//*/

    int n;
    cin >> n;
    vector<point> polygon(n);
    long long x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        polygon[i] = {x, y};
    }
    if (wise(polygon[0], polygon[1], polygon[2]) < 0) {
        reverse(polygon.begin(), polygon.end());
    }
    rotate(polygon.begin(), min_element(polygon.begin(), polygon.end()), polygon.end());

    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        long long x, y;
        cin >> x >> y;
        cout << check(polygon, {x, y}) << "\n";
    }
    return 0;
}
