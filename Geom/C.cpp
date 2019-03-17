#include <bits/stdc++.h>

using namespace std;

int N;

struct point {
    long long x, y;

    bool operator < (point& other) {
        return x != other.x ? x < other.x : y < other.y;
    }
};

long long tring_area(point& a, point& b, point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool right_wise(point& a, point& b, point& c) {
    return tring_area(a, b, c) < 0;
}

bool left_wise(point& a, point& b, point& c) {
    return tring_area(a, b, c) > 0;
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
        if (i == points.size() - 1 || right_wise(first, tmp, last)) {
            while (up.size() > 1 && !right_wise(up[up.size() - 2], up[up.size() - 1], tmp)) {
                up.pop_back();
            }
            up.push_back(tmp);
        }
        //down event
        if (i == points.size() - 1 || left_wise(first, tmp, last)) {
            while (down.size() > 1 && !left_wise(down[down.size() - 2], down[down.size() - 1], tmp)) {
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //*
    freopen("hull.in", "r", stdin);
    freopen("hull.out", "w", stdout);//*/
    cin >> N;
    vector<point> dots(N);
    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        dots[i] = {x, y};
    }

    vector<point> ans = graham(dots);
    cout << ans.size() << '\n';
    for (point p : ans) {
        cout << p.x << ' ' << p.y << '\n';
    }

    return 0;
}
