#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("balanced.out", "w", stdout);

    // ) == 0; ( == 1
    cout << "start: s" << '\n';
    cout << "accept: ac" << '\n';
    cout << "reject: rj" << '\n';
    cout << "blank: _" << '\n';

    //go to ')'
    cout << "s 0 -> s 0 >" << '\n';
    cout << "s 1 -> s 1 >" << '\n';
    cout << "s ( -> s ( >" << '\n';
    cout << "s ) -> findOp 0 <" << '\n';
    cout << "s _ -> check _ <" << '\n';

    //find '('
    cout << "findOp 0 -> findOp 0 <" << '\n';
    cout << "findOp 1 -> findOp 1 <" << '\n';
    cout << "findOp ( -> s 1 >" << '\n';
    cout << "findOp _ -> rj _ ^" << '\n';

    //check ans
    cout << "check 0 -> check 0 <" << '\n';
    cout << "check 1 -> check 1 <" << '\n';
    cout << "check ( -> rj _ ^" << '\n';
    cout << "check _ -> ac _ >" << '\n';

    cout << "" << '\n';
    return 0;
}



