#include <bits/stdc++.h>

using namespace std;

const int MOD = 4e6 + 37;
int p = 53;

int my_hash(string s) {
    int res = 0;
    int sz = s.length();
    for (int i = 0; i < sz; i++) {
        res = (res * p + s[i]) % MOD;
    }
    return res;
}

struct node {
    string x;
    set<string> y;
    node* next;
    node (string x1, string y1) {
        x = x1;
        y.insert(y1);
        next = NULL;
    }
};

vector<node*> my_map(MOD);

void put(string x, string y) {
    int ind = my_hash(x);
    node* a = my_map[ind];
    while (a != NULL) {
        if (a->x == x) {
            (*a).y.insert(y);
            return;
        }
        a = a->next;
    }
    node* b = new node(x, y);
    (*b).next = my_map[ind];
    my_map[ind] = b;
}


set<string> get(string x) {
    set<string> ans;
    int ind = my_hash(x);
    node* a = my_map[ind];
    while (a != NULL) {
        if (a->x == x) {
            return a->y;
        }
        a = a->next;
    }
    return ans;
}

void delall(string x) {
    int ind = my_hash(x);
    node* a = my_map[ind];
    if (my_map[ind] == NULL) return;
    if (my_map[ind]->x == x) {
        my_map[ind] = my_map[ind]->next;
        return;
    }
    while (a != NULL) {
        if (a->next != NULL) {
            if (a->next->x == x) {
                (*a).next = a->next->next;
                return;
            }
        }
        a = a->next;
    }
}

void del(string x, string y) {
    int ind = my_hash(x);
    node* a = my_map[ind];
    if (my_map[ind] == NULL) return;
    if (my_map[ind]->x == x) {
        (*my_map[ind]).y.erase(y);
        if (my_map[ind]->y.size() == 0) {
            my_map[ind] = my_map[ind]->next;
        }
        return;
    }
    while (a != NULL) {
        if (a->x == x) {
            (*a).y.erase(y);
        }
        a = a->next;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);
    string cmd;
    while (cin >> cmd) {
        string x;
        cin >> x;
        if (cmd == "put") {
            string y;
            cin >> y;
            put(x, y);
        } else if (cmd == "get") {
            set<string> ans = get(x);
            cout << ans.size();
            for (set<string>::iterator it = ans.begin(); it != ans.end(); it++) {
                cout << ' ' << (*it);
            }
            cout << '\n';
        } else if (cmd == "delete") {
            string y;
            cin >> y;
            del(x, y);
        } else if (cmd == "deleteall") {
            delall(x);
        }
        /*for (int i = 0; i < my_set.size(); ++i) {
            node* a = my_set[i];
            while (a != NULL) {
                cout << a->x << " + " << a->y << " - " << i << '\n';
                a = a->next;
            }
        }*/
    }
    return 0;
}
