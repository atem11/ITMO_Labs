#include <bits/stdc++.h>

using namespace std;

struct point {
	long long x;
	long long y;
	int id;

	bool operator == (point& other) {
		return x == other.x && y == other.y;
	}

	bool operator != (point& other) {
		return x != other.x || y != other.y;
	}

	bool operator < (point& other) {
        return x != other.x ? x < other.x : y < other.y;
    }
};

struct triangle {
    point a;
    point b;
    point c;
};

//LEFT > 0
//RIGHT < 0
long long wise(point& a, point& b, point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}


bool check_in_triangle(point& target, triangle& tri) {
    point p1 = tri.a;
    point p2 = tri.b;
    point p3 = tri.c;
    long long wise_p1p2 = wise(p1, p2, target);
    long long wise_p2p3 = wise(p2, p3, target);
    long long wise_p3p1 = wise(p3, p1, target);
    return wise_p1p2 > 0 && wise_p2p3 > 0 && wise_p3p1 >= 0;
}

bool check_all_points(triangle& t, vector<point>& polygon) {
    for (int i = 0; i < polygon.size(); ++i) {
        point p = polygon[i];
        if (p != t.a && p != t.b && p != t.c) {
            if (check_in_triangle(p, t)) {
                return false;
            }
        }
    }
    return true;
}

int next(int ind, vector<point>& polygon) {
    if (ind + 1 == polygon.size()) {
        return 0;
    }
    return ind + 1;
}


int prev(int ind, vector<point>& polygon) {
    if (ind == 0) {
        return polygon.size() - 1;
    }
    return ind - 1;
}

vector<triangle> triangulation(vector<point> polygon) {
    int ind = 0;
    vector<triangle> ans;
    while (polygon.size() > 3) {
        point cur = polygon[ind];
        point prv = polygon[prev(ind, polygon)];
        point nxt = polygon[next(ind, polygon)];
        if (wise(prv, cur, nxt) > 0) {
            triangle t = {prv, cur, nxt};
            if (check_all_points(t, polygon)) {
                ans.push_back(t);
                polygon.erase(polygon.begin() + ind);
                ind = prev(ind, polygon);
            } else {
                ind = next(ind, polygon);
            }
        } else {
            ind = next(ind, polygon);
        }
    }
    ans.push_back({polygon[0], polygon[1], polygon[2]});
    return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*
    freopen("input.in", "r", stdin);
    freopen("input.out", "w", stdout);//*/

    int n;
    cin >> n;
    vector<point> polygon(n);
    for (int i = 0; i < n; ++i) {
        long long _x, _y;
        cin >> _x >> _y;
        polygon[i] = {_x, _y, i + 1};
    }
    vector<triangle> triangul = triangulation(polygon);
    for (int i = 0; i < triangul.size(); ++i) {
        triangle t = triangul[i];
        cout << t.a.id << ' ' << t.b.id << ' ' << t.c.id << '\n';
    }
    return 0;
}
