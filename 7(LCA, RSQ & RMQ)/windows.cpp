#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e6 + 3;
const int PLUS = 1e6 + 1;
const int INF = -1e7;

struct Node {
    int l, r;
    int ls, rs;
    int mx = INF, add, indm;
};

Node M;

vector <Node> tree;

void build(int node, int l, int r) {
    tree[node].l = l;
    tree[node].r = r;
    tree[node].add = 0;
    if (l + 1 == r) {
        tree[node].ls = tree[node].ls = -1;
        tree[node].mx = 0;
        tree[node].indm = l + 1;
        return;
    }
    int mid = (r + l) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid, r);
    tree[node].ls = node * 2;
    tree[node].rs = node * 2 + 1;
    int rv = tree[node].rs, lv = tree[node].ls;
    tree[node].mx = max(tree[lv].mx, tree[rv].mx);
    tree[node].indm = tree[lv].indm;
    if (tree[lv].mx < tree[rv].mx) {
        tree[node].indm = tree[rv].indm;
    }
}

void setp(int node, int val) {
    if (node == -1) {
        return;
    }
    tree[node].add += val;
    tree[node].mx += val;
}

void push(int node) {
    if (node == -1) {
        return;
    }
    setp(tree[node].ls, tree[node].add);
    setp(tree[node].rs, tree[node].add);
    tree[node].add = 0;
}

void update(int node, int l, int r, int new_val) {
    if (r <= tree[node].l || tree[node].r <= l) {
        return;
    }
    if (l <= tree[node].l && tree[node].r <= r) {
        setp(node, new_val);
        return;
    }
    push(node);
    int rv = tree[node].rs, lv = tree[node].ls;
    update(lv, l, r, new_val);
    update(rv, l, r, new_val);
    tree[node].mx = max(tree[lv].mx, tree[rv].mx);
    tree[node].indm = tree[lv].indm;
    if (tree[lv].mx < tree[rv].mx) {
        tree[node].indm = tree[rv].indm;
    }
}

Node get(int node, int l, int r) {
    if (r <= tree[node].l || tree[node].r <= l) {
        return M;
    }
    if (l <= tree[node].l && tree[node].r <= r) {
        return tree[node];
    }
    push(node);
    int rv = tree[node].rs, lv = tree[node].ls;
    Node L = get(lv, l, r), R = get(rv, l, r);
    if (L.mx > R.mx) {
        return L;
    }
    return R;
}

struct Node1 {
    int x;
    int y1, y2, op;
};

struct Ans {
    int mx, x, y;
};

bool comp(Node1 a, Node1 b) {
    if (a.x == b.x) {
        return a.op > b.op;
    }
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("windows.in", "r", stdin);
    freopen("windows.out", "w", stdout);
    tree.resize(4 * MAX);
    build(1, 0, MAX);
    int n;
    cin >> n;
    vector<Node1> e;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1 += PLUS;
        y2 += PLUS;
        x1 += PLUS;
        x2 += PLUS;
        Node1 x;
        x.op = 1;
        x.x = x1;
        x.y1 = y1;
        x.y2 = y2;
        e.push_back(x);
        x.x = x2;
        x.op = -1;
        e.push_back(x);
    }
    sort(e.begin(), e.end(), comp);
    Ans ans;
    ans.mx = -1;
    ans.x = 0;
    ans.y = 0;
    for (size_t i = 0; i < e.size(); ++i)
    {
        update(1, e[i].y1 - 1, e[i].y2, e[i].op);
        Node res = get(1, e[i].y1 - 1, e[i].y2);
        if (res.mx > ans.mx)
        {
            ans.mx = res.mx;
            ans.x = e[i].x - PLUS;
            ans.y = res.indm - PLUS;
        }
    }
    cout << ans.mx << '\n' << ans.x << ' ' << ans.y << '\n';
    return 0;
}
