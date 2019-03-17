#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("convertto2.out", "w", stdout);

    //
    cout << "start: s" << '\n';
    cout << "accept: ac" << '\n';
    cout << "reject: rj" << '\n';
    cout << "blank: _" << '\n';

    //start
    cout << "s 0 -> ac 0 ^" << '\n';
    cout << "s 1 -> init 1 <" << '\n';
    cout << "s 2 -> init 2 <" << '\n';

    //init
    cout << "init _ -> goEnd # >" << '\n';

    //go to end
    cout << "goEnd 0 -> goEnd 0 >" << '\n';
    cout << "goEnd 1 -> goEnd 1 >" << '\n';
    cout << "goEnd 2 -> goEnd 2 >" << '\n';
    cout << "goEnd # -> goEnd # >" << '\n';
    cout << "goEnd _ -> minus _ <" << '\n';

    //go to start
    cout << "goSt 0 -> goSt 0 <" << '\n';
    cout << "goSt 1 -> goSt 1 <" << '\n';
    cout << "goSt 2 -> goSt 2 <" << '\n';
    cout << "goSt # -> plus # <" << '\n';

    //plus 1
    cout << "plus _ -> goEnd 1 >" << '\n';
    cout << "plus 1 -> plus 0 <" << '\n';
    cout << "plus 0 -> goEnd 1 >" << '\n';

    //minus 1
    cout << "minus 1 -> goSt 0 <" << '\n';
    cout << "minus 2 -> goSt 1 <" << '\n';
    cout << "minus 0 -> goMinus 2 <" << '\n';

    //goMinus
    cout << "goMinus 1 -> goSt 0 <" << '\n';
    cout << "goMinus 2 -> goSt 1 <" << '\n';
    cout << "goMinus 0 -> goMinus 2 <" << '\n';
    cout << "goMinus # -> clean # >" << '\n';

    //clean
    cout << "clean 2 -> clean _ >" << '\n';
    cout << "clean _ -> cleanAc _ <" << '\n';

    //clean acepted
    cout << "cleanAc _ -> cleanAc _ <" << '\n';
    cout << "cleanAc # -> Ac _ <" << '\n';

    //Accepted
    cout << "Ac 0 -> Ac 0 <" << '\n';
    cout << "Ac 1 -> Ac 1 <" << '\n';
    cout << "Ac _ -> ac _ >" << '\n';

    cout << "" << '\n';
    return 0;
}
