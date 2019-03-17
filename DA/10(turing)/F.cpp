#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("reverse.out", "w", stdout);

    // 2 == 0; 3 == 1; 4 == 0; 5 == 1;
    cout << "start: s" << '\n';
    cout << "accept: ac" << '\n';
    cout << "reject: rj" << '\n';
    cout << "blank: _" << '\n';

    //go to last
    cout << "s 0 -> s 0 >" << '\n';
    cout << "s 1 -> s 1 >" << '\n';
    cout << "s 2 -> s 2 >" << '\n';
    cout << "s 3 -> s 3 >" << '\n';
    cout << "s 4 -> s 4 >" << '\n';
    cout << "s 5 -> s 5 >" << '\n';
    cout << "s _ -> ret _ <" << '\n';

    //clean ans
    cout << "cln 1 -> cln 1 <" << '\n';
    cout << "cln 0 -> cln 0 <" << '\n';
    cout << "cln _ -> ac _ >" << '\n';

    //go back
    cout << "back 3 -> back _ >" << '\n';
    cout << "back 2 -> back _ >" << '\n';
    cout << "back 4 -> back 0 >" << '\n';
    cout << "back 5 -> back 1 >" << '\n';
    cout << "back _ -> cln _ <" << '\n';

    //return
    cout << "ret 2 -> ret 2 <" << '\n';
    cout << "ret 3 -> ret 3 <" << '\n';
    cout << "ret 4 -> ret 4 <" << '\n';
    cout << "ret 5 -> ret 5 <" << '\n';
    cout << "ret 0 -> add0 2 >" << '\n';
    cout << "ret 1 -> add1 3 >" << '\n';
    cout << "ret _ -> back _ >" << '\n';

    //add 0
    cout << "add0 2 -> add0 2 >" << '\n';
    cout << "add0 3 -> add0 3 >" << '\n';
    cout << "add0 4 -> add0 4 >" << '\n';
    cout << "add0 5 -> add0 5 >" << '\n';
    cout << "add0 _ -> ret 4 <" << '\n';

    //add 1
    cout << "add1 2 -> add1 2 >" << '\n';
    cout << "add1 3 -> add1 3 >" << '\n';
    cout << "add1 4 -> add1 4 >" << '\n';
    cout << "add1 5 -> add1 5 >" << '\n';
    cout << "add1 _ -> ret 5 <" << '\n';

    cout << "" << '\n';
    return 0;
}



