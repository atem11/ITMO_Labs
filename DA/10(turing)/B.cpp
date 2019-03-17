#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("aplusb.out", "w", stdout);

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
    cout << "s + -> s + >" << '\n';
    cout << "s _ -> re _ <" << '\n';

    //clean ans
    cout << "cln 2 -> cln 0 <" << '\n';
    cout << "cln 3 -> cln 1 <" << '\n';
    cout << "cln 1 -> cln 1 <" << '\n';
    cout << "cln 0 -> cln 0 <" << '\n';
    cout << "cln _ -> ac _ >" << '\n';

    //return
    cout << "re + -> cln _ <" << '\n';
    cout << "re 0 -> p0 _ <" << '\n';
    cout << "re 1 -> p1 _ <" << '\n';

    //plus 0 before '+' "p0"
    cout << "p0 0 -> p0 0 <" << '\n';
    cout << "p0 1 -> p0 1 <" << '\n';
    cout << "p0 + -> p0a + <" << '\n';

    //plus 0 after '+' "p0a"
    cout << "p0a 2 -> p0a 2 <" << '\n';
    cout << "p0a 3 -> p0a 3 <" << '\n';
    cout << "p0a 0 -> s 2 >" << '\n';
    cout << "p0a 1 -> s 3 >" << '\n';
    cout << "p0a _ -> s 2 >" << '\n';

    //plus 1 before '+' "p1"
    cout << "p1 0 -> p1 0 <" << '\n';
    cout << "p1 1 -> p1 1 <" << '\n';
    cout << "p1 + -> p1a + <" << '\n';

    //plus 1 after '+' "p1a"
    cout << "p1a 2 -> p1a 2 <" << '\n';
    cout << "p1a 3 -> p1a 3 <" << '\n';
    cout << "p1a 0 -> s 3 >" << '\n';
    cout << "p1a 1 -> per 2 <" << '\n';
    cout << "p1a _ -> s 3 >" << '\n';

    //1 + 1 "per"
    cout << "per 0 -> s 1 >" << '\n';
    cout << "per 1 -> per 0 <" << '\n';
    cout << "per _ -> s 1 >" << '\n';

    return 0;
}

