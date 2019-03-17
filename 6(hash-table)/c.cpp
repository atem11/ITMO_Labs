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
    //return 10;
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
    node* prevans;
    node* nextans;
    node (string x1, string y1) {
        x = x1;
        y = y1;
        next = NULL;
        prevans = NULL;
        nextans = NULL;
    }
};

vector<node*> my_map(MOD);
node* previous = NULL;

void put(string x, string y) {
    int ind = my_hash(x);
    node* a = my_map[ind];
    while (a != NULL) {
        if (a->x == x) {
            (*a).y = y;
            return;
        }
        a = a->next;
    }
    node* b = new node(x, y);
    (*b).next = my_map[ind];
    (*b).prevans = previous;
    if (previous != NULL) (*previous).nextans = b;
    previous = b;
    my_map[ind] = b;
}

void prevf(string x) {
    int ind = my_hash(x);
    node* a = my_map[ind];
    while (a != NULL) {
        if (a->x == x) {
            if (a->prevans != NULL) {
                    cout << a->prevans->y << '\n';
            } else break;
            return;
        }
        a = a->next;
    }
    cout << "none\n";
}

void nextf(string x) {
    int ind = my_hash(x);
    node* a = my_map[ind];
    while (a != NULL) {
        if (a->x == x) {
            if (a->nextans != NULL) {
                    cout << a->nextans->y << '\n';
            } else break;
            return;
        }
        a = a->next;
    }
    cout << "none\n";
}

string get(string x) {
    string ans = "none";
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

void del(string x) {
    int ind = my_hash(x);
    node* a = my_map[ind];
    if (my_map[ind] == NULL) return;
    if (my_map[ind]->x == x) {
        node* p = my_map[ind]->prevans;
        node* n = my_map[ind]->nextans;
        if (previous == my_map[ind]) {
            previous = previous->prevans;
        }
        my_map[ind] = my_map[ind]->next;
        if (p != NULL) (*p).nextans = n;
        if (n != NULL) (*n).prevans = p;
        return;
    }
    while (a != NULL) {
        if (a->next != NULL) {
            if (a->next->x == x) {
                node* p = a->next->prevans;
                node* n = a->next->nextans;
                if (previous == a->next) {
                    previous = previous->prevans;
                }
                (*a).next = a->next->next;
                if (p != NULL) (*p).nextans = n;
                if (n != NULL) (*n).prevans = p;
                return;
            }
        }
        a = a->next;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    srand(time(0));
    makeHash();
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    string cmd;
    while (cin >> cmd) {
        string x;
        cin >> x;
        if (cmd == "put") {
            string y;
            cin >> y;
            put(x, y);
        } else if (cmd == "get") {
            cout << get(x) << '\n';
        } else if (cmd == "prev") {
            prevf(x);
        } else if (cmd == "next") {
            nextf(x);
        } else if (cmd == "delete"){
            del(x);
        }
        /*for (int i = 0; i < my_map.size(); ++i) {
            node* a = my_map[i];
            while (a != NULL) {
                cout << a->x << " + " << a->y << " - " << i << '\n';
                a = a->next;
            }
        }*/
    }
    return 0;
}

