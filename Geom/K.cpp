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


point A = {0, 0}, B = {-0, -0};

void update_ans(point& a, point& b) {
    if (dist(A, B) < dist(a, b)) {
        A = a;
        B = b;
    }
}

vector<point> graham(vector<point>& points) {
    //init
    sort(points.begin(), points.end());
    point first = points[0];
    point last = points[points.size() - 1];
    vector<point> up, down;
    up.push_back(first);
    down.push_back(first);
    //find
    for (size_t i = 1; i < points.size(); ++i) {
        point tmp = points[i];
        //up event
        if (i == points.size() - 1 || wise(first, tmp, last) < 0) {
            while (up.size() > 1 && wise(up[up.size() - 2], up[up.size() - 1], tmp) >= 0) {
                up.pop_back();
            }
            up.push_back(tmp);
        }
        //down event
        if (i == points.size() - 1 || wise(first, tmp, last) > 0) {
            while (down.size() > 1 && wise(down[down.size() - 2], down[down.size() - 1], tmp) <= 0) {
                down.pop_back();
            }
            down.push_back(tmp);
        }
    }
    //merge
    for (size_t i = down.size() - 2; i > 0; --i) {
        up.push_back(down[i]);
    }
    return up;
}

void ternarnik(int target, vector<point>& points) {
    int l = 1;
    int r = points.size() - 1;
    int sz = points.size();
    while (l + 2 < r) {
        int lmid = (r + 2 * l) / 3;
        int rmid = (2 * r + l) / 3;
        int L = (target + lmid) % sz;
        int R = (target + rmid) % sz;
        if (dist(points[target], points[R]) > dist(points[target], points[L])) {
            l = lmid;
        } else {
            r = rmid;
        }
    }
    for (int i = l; i < r; ++i) {
        int M = (target + i) % sz;
        update_ans(points[target], points[M]);
    }
}

void find_points(vector<point> points) {
    for (int i = 0; i < points.size(); ++i) {
        ternarnik(i, points);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //*
    freopen("diameter.in", "r", stdin);
    freopen("diameter.out", "w", stdout);//*/
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; ++i) {
        long long _x, _y;
        cin >> _x >> _y;
        points[i] = {_x, _y};
    }
    sort(points.begin(), points.end());
    if (points.front() == points.back()) {
        cout << 0;
    } else {
        update_ans(points.front(), points.back());
        find_points(graham(points));
        cout.precision(13);
        cout << fixed << sqrt(dist(A, B));
    }
    return 0;
}

