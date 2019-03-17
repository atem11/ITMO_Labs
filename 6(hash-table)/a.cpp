#include <bits/stdc++.h>

using namespace std;

const int MOD = 4e6 + 37;
int a = 0, b = 0, p = 53;

void makeHash() {
    while (a <= 0) {
        a = rand() % p;
    }
    b = a;
    while (b == a || b <= 0) {
        b = rand() % p;
    }
}

int my_hash(string s) {
    int res = 0;
    int sz = s.length();
    for (int i = 0; i < sz; i++) {
        res = (res * p + s[i] * a + b) % MOD;
    }
    return res;
}

struct node {
    string x, y;
    node* next;
    node (string x1, string y1) {
        x = x1;
        y = y1;
        next = NULL;
    }
};

vector<node*> my_set(MOD);

void put(string x) {
    int ind = my_hash(x);
    node* a = my_set[ind];
    node* b = new node(x, "");
    if (a == NULL) {
        my_set[ind] = b;
        return;
    }
    while (a != NULL) {
        if (a->x == x) {
            return;
        }
        a = a->next;
    }
    a = my_set[ind];
    b->next = a;
    my_set[ind] = b;
}

string get(string x) {
    int ind = my_hash(x);
    string ans = "false\n";
    node* a = my_set[ind];
    while (a != NULL) {
        if (a->x == x) {
            ans = "true\n";
            break;
        }
        a = a->next;
    }
    return ans;
}

void del(string x) {
    int ind = my_hash(x);
    if (my_set[ind] == NULL) return;
    if (my_set[ind] != NULL && my_set[ind]->x == x) {
        my_set[ind] = my_set[ind]->next;
        return;
    }
    node* a = my_set[ind];
    while (a->next != NULL) {
        if (a->next->x == x) {
            (*a).next = a->next->next;
            return;
        }
        a = a->next;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    srand(time(0));
    makeHash();
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    string cmd;
    while (cin >> cmd) {
        string x;
        cin >> x;
        if (cmd == "insert") {
            put(x);
        } else if (cmd == "exists") {
            cout << get(x);
        } else {
            del(x);
        }
        /*for (int i = 0; i < my_set.size(); ++i) {
            node* a = my_set[i];
            while (a != NULL) {
                cout << a->x << " - " << i << '\n';
                a = a->next;
            }
        }*/
    }
    return 0;
}
