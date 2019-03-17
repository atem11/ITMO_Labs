#include <bits/stdc++.h>

using namespace std;

struct Node {
    int way0;
    int way1;

    char symbol;
};

int main() {
    freopen("start.in", "r", stdin);
    freopen("start.out", "w", stdout);

    int len, cnt;
    cin >> len >> cnt;
    vector<Node> automat;
    automat.resize(cnt);
    for (int i = 0; i < cnt; i++) {
        int way0, way1;
        char ch;
        cin >> way0 >> way1 >> ch;
        automat[i].way0 = way0 - 1;
        automat[i].way1 = way1 - 1;
        automat[i].symbol = ch;
    }
    vector<bool> markFin, mark;
    markFin.resize(cnt);
    mark.resize(cnt);
    for (int i = 0; i < cnt; i++) {
        markFin[i] = true;
    }
    string out;
    cin >> out;
    for (int i = 0; i < len; i++) {
        char ch = out[len - 1 - i];
        mark.clear();
        mark.resize(cnt);
        for (int n = 0; n < cnt; n++) {
            Node node = automat[n];
            if (automat[node.way0].symbol == ch && markFin[node.way0]) {
                mark[n] = true;
            }
            if (automat[node.way1].symbol == ch && markFin[node.way1]) {
                mark[n] = true;
            }
        }
        swap(mark, markFin);
    }

    int ans = 0;
    for (int i = 0; i < cnt; i++) {
        if (markFin[i]) {
            ans++;
        }
    }
    cout << ans;
    for (int i = 0; i < cnt; i++) {
    if (markFin[i]) {
        cout << " " <<  i + 1;
    }
}
    return 0;
}
