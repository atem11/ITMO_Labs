#include <bits/stdc++.h>

using namespace std;

int IND = 0;
int CNT = 0;

struct Node {
    int ind;
    map<char, Node*> children;

    Node () {
        ind = ++IND;
    }
};

struct Trie {
    Node* root;

    Trie() {
        root = new Node();
    }

private:
    void print(Node* ptr) {
        for (auto v : ptr->children) {
            cout << ptr->ind << ' ' << v.second->ind << ' ' << v.first << '\n';
        }
        for (auto v : ptr->children) {
            print(v.second);
        }
    }

public:
    void add(string s) {
        Node* tmp = root;
        for (auto c : s) {
            if (tmp->children.count(c) == 0) {
                CNT++;
                tmp->children[c] = new Node();
            }
            tmp = tmp->children[c];
        }
    }

    void build (string s) {
        string tmp = "";
        for (int i = (int)s.length() - 1; i >=0; --i) {
            tmp = s[i] + tmp;
            add(tmp);
        }
    }

    void printAll() {
        print(root);
    }
};

int main() {
    //*
    freopen("trie.in", "r", stdin);
    freopen("trie.out", "w", stdout);//*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    Trie tree = Trie();
    tree.build(s);
    cout << IND << ' ' << CNT << '\n';
    tree.printAll();
    return 0;
}
