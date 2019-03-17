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

bool check_in_segment(point s, point f, point target) {
    if (wise(s, f, target) != 0) {
        return false;
    }
    return target.x >= min(s.x, f.x) && target.x <= max(s.x, f.x) &&
            target.y >= min(s.y, f.y) && target.y <= max(s.y, f.y);
}

int check_cross_segment(point s, point f, point target) {
    if (s.y == f.y) {
        return 0;
    }
    if (s.y > f.y) {
        swap(s, f);
    }
    if (target.y > f.y || target.y <= s.y) {
        return 0;
    }
    return wise(s, f, target) > 0 ? 1 : 0;
}

string check(vector<point>& polygon, point target) {
    int cnt = 0;
    for (int i = 0; i < polygon.size() - 1; ++i) {
        point s = polygon[i];
        point f = polygon[i + 1];

        if (check_in_segment(s, f, target)) {
            return "YES";
        }
        cnt += check_cross_segment(s, f, target);
    }
    if (cnt % 2 == 1) {
        return "YES";
    }
    return "NO";
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //*
    freopen("point.in", "r", stdin);
    freopen("point.out", "w", stdout);//*/

    int n;
    cin >> n;
    vector<point> polygon(n + 1);
    long long x, y;
    cin >> x >> y;
    for (int i = 0; i < n; ++i) {
        long long _x, _y;
        cin >> _x >> _y;
        polygon[i] = {_x, _y};
    }
    polygon[n] = polygon[0];
    cout << check(polygon, {x, y}) << "\n";
    return 0;
}
