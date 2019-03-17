#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

long long INF = 1e18 + 7;

struct Node {
   long long min = INF;
   bool isSet = false;
   long long Set, add;

};

vector<Node> tree;
int pow = 1;

void create() {
    for(int i = pow - 1; i >= 1; i--)
        tree[i].min = min(tree[2 * i].min,tree[2 * i + 1].min);

}

void propagate(int node) {
    if (node < pow) {
        if(tree[node].isSet) {
            tree[2 * node].Set = tree[node].Set;
            tree[2 * node + 1].Set = tree[node].Set;
            tree[2 * node].min = tree[node].Set;
            tree[2 * node + 1].min = tree[node].Set;
            tree[2 * node].add = 0;
            tree[2 * node + 1].add = 0;
            tree[node].isSet = false;
            tree[2 * node].isSet = true;
            tree[2 * node + 1].isSet = true;
        } else {
            if (tree[2 * node].isSet) {
                tree[2 * node].Set += tree[node].add;
            } else {
                tree[2 * node].add += tree[node].add;
            }
            if (tree[2 * node + 1].isSet) {
                tree[2 * node + 1].Set += tree[node].add;
            } else {
                tree[2 * node + 1].add += tree[node].add;
            }
            tree[2 * node].min += tree[node].add;
            tree[2 * node + 1].min += tree[node].add;
            tree[node].add = 0;
        }
    }
}

void set(int node, int l, int r, int L, int R, long long value) {
    if ((l <= L) && (R <= r)) {
        tree[node].isSet = true;
        tree[node].Set = value;
        tree[node].min = value;
        tree[node].add = 0;
    } else if(l <= R && r >= L) {
        propagate(node);
        int m = (L + R) / 2;
        set(2 * node, l, r, L, m, value);
        set(2 * node + 1, l, r, m + 1, R, value);
        if(tree[node].isSet) {
            tree[node].min = tree[node].Set;
        } else {
            tree[node].min = min(tree[2 * node].min, tree[2 * node + 1].min);
        }
    }
}

void add(int node, int l, int r, int L, int R, long long value) {
    if(l <= L && R <= r) {
        if(tree[node].isSet) {
            tree[node].Set += value;
            tree[node].min = tree[node].Set;
        } else {
                tree[node].add += value;
                tree[node].min += value;
            }
        } else if(l <= R && r >= L) {
            propagate(node);
            int m = (L + R) / 2;
            add(2 * node, l, r, L, m, value);
            add(2 * node + 1, l, r, m + 1, R, value);
            if(tree[node].isSet) {
                tree[node].min = tree[node].Set;
            } else {
                tree[node].min = min(tree[2 * node].min, tree[2 * node + 1].min);
            }
        }
}

long long get_min(int node, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        if(tree[node].isSet) {
            return tree[node].Set;
        } else {
            return tree[node].min;
        }
    } else if(L <= r && R >= l) {
        int m = (l + r) / 2;
        propagate(node);
        return min(get_min(node * 2, l, m, L, R), get_min(node * 2 + 1, m + 1, r, L , R));
    }
    return INF;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("rmq2.in", "r", stdin);
    freopen("rmq2.out", "w", stdout);
    int n;
    cin >> n;
    while(pow < n) {
        pow *= 2;
    }
    tree.resize(2 * pow);
    for (int i = pow; i < pow + n; i++) {
        cin >> tree[i].min;
    }
    create();
    string cmnd;
    while (cin >> cmnd)
    {
        int l, r;
        if (cmnd == "set") {
            long long value;
            cin >> l >> r >> value;
            set(1, l - 1, r - 1, 0, pow - 1, value);
        } else if (cmnd == "min") {
            cin >> l >> r;
            cout << get_min(1, 0, pow - 1, l - 1, r - 1) << "\n";
        } else {
            long long value;
            cin >> l >> r >> value;
            add(1, l - 1, r - 1, 0, pow - 1, value);
        }
    }
    return 0;
}
