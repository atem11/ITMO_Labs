#include <bits/stdc++.h>

using namespace std;

struct point {
	long long x;
	long long y;

	bool operator == (point& other) {
		return x == other.x && y == other.y;
	}

	bool operator < (point& other) {
        return  x < other.x;
    }
};

inline bool cmp_y (const point& a, const point& b) {
	return a.y < b.y;
}


long long dist(point& a, point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}


point A = {1000000001, 1000000001}, B = {-1000000001, -1000000001};

void update_ans(point& a, point& b) {
    if (dist(A, B) > dist(a, b)) {
        A = a;
        B = b;
    }
}

void find_points(vector<point>& points) {
    int sz = points.size();
    if (sz == 1) {
        return;
    }

    vector<point> L, R;
    for (int i = 0; i < sz / 2; i++) {
        L.push_back(points[i]);
    }
    for (int i = sz / 2; i < sz; i++) {
        R.push_back(points[i]);
    }
    int lx = R.front().x;
    find_points(L);
    find_points(R);
    merge(L.begin(), L.end(), R.begin(), R.end(), points.begin(), &cmp_y);
    int cur = 0;
    vector<point> tmp(sz);
    for (int i = 0; i < points.size(); ++i) {
        if (((points[i].x - lx) * (points[i].x - lx)) < dist(A, B)) {
            for (int j = cur - 1; j >= 0 && ((points[i].y - tmp[j].y) * (points[i].y - tmp[j].y)) < dist(A, B); --j) {
                update_ans(points[i], tmp[j]);
            }
            tmp[cur++] = points[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //*
    freopen("rendezvous.in", "r", stdin);
    freopen("rendezvous.out", "w", stdout);//*/

    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; ++i) {
        long long _x, _y;
        cin >> _x >> _y;
        points[i] = {_x, _y};
    }
    sort(points.begin(), points.end());
    find_points(points);
    cout << A.x << ' ' << A.y << ' ' << B.x << ' ' << B.y << '\n';
    return 0;
}
