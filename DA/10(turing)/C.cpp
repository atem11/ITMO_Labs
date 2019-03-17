#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("mirror.out", "w", stdout);

    // 2 == 0; 3 == 1
    cout << "start: s" << '\n';
    cout << "accept: ac" << '\n';
    cout << "reject: rj" << '\n';
    cout << "blank: _" << '\n';

    //go to last
    cout << "s 0 -> s 0 >" << '\n';
    cout << "s 1 -> s 1 >" << '\n';
    cout << "s 2 -> s 2 >" << '\n';
    cout << "s 3 -> s 3 >" << '\n';
    cout << "s _ -> ret _ <" << '\n';

    //clean ans
    cout << "cln 2 -> cln 0 <" << '\n';
    cout << "cln 3 -> cln 1 <" << '\n';
    cout << "cln 1 -> cln 1 <" << '\n';
    cout << "cln 0 -> cln 0 <" << '\n';
    cout << "cln _ -> ac _ >" << '\n';

    //go back
    cout << "back 3 -> back 3 >" << '\n';
    cout << "back 2 -> back 2 >" << '\n';
    cout << "back _ -> cln _ <" << '\n';

    //return
    cout << "ret 2 -> ret 2 <" << '\n';
    cout << "ret 3 -> ret 3 <" << '\n';
    cout << "ret 1 -> add1 3 >" << '\n';
    cout << "ret 0 -> add0 2 >" << '\n';
    cout << "ret _ -> back _ >" << '\n';

    //add 0
    cout << "add0 2 -> add0 2 >" << '\n';
    cout << "add0 3 -> add0 3 >" << '\n';
    cout << "add0 _ -> ret 2 <" << '\n';

    //add 1
    cout << "add1 2 -> add1 2 >" << '\n';
    cout << "add1 3 -> add1 3 >" << '\n';
    cout << "add1 _ -> ret 3 <" << '\n';

    cout << "" << '\n';
    return 0;
}


