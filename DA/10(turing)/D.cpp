#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("tandem.out", "w", stdout);

    // 2 == 0; 3 == 1; 4 == 0; 5 == 1;
    cout << "start: s" << '\n';
    cout << "accept: ac" << '\n';
    cout << "reject: rj" << '\n';
    cout << "blank: _" << '\n';

    //start
    cout << "s 0 -> s2 2 >" << '\n';
    cout << "s 1 -> s2 3 >" << '\n';
    cout << "s 4 -> stch 4 <" << '\n';
    cout << "s 5 -> stch 5 <" << '\n';

    //go to last
    cout << "s2 1 -> s2 1 >" << '\n';
    cout << "s2 0 -> s2 0 >" << '\n';
    cout << "s2 _ -> s3 _ <" << '\n';
    cout << "s2 4 -> s3 4 <" << '\n';
    cout << "s2 5 -> s3 5 <" << '\n';

    //swap 2nd
    cout << "s3 0 -> s4 4 <" << '\n';
    cout << "s3 1 -> s4 5 <" << '\n';
    cout << "s3 2 -> rj 2 ^" << '\n';
    cout << "s3 3 -> rj 3 ^" << '\n';

    //go to forward
    cout << "s4 1 -> s4 1 <" << '\n';
    cout << "s4 0 -> s4 0 <" << '\n';
    cout << "s4 2 -> s 2 >" << '\n';
    cout << "s4 3 -> s 3 >" << '\n';

    //start checked
    cout << "stch 2 -> stch 2 <" << '\n';
    cout << "stch 3 -> stch 3 <" << '\n';
    cout << "stch 4 -> stch 4 <" << '\n';
    cout << "stch 5 -> stch 5 <" << '\n';
    cout << "stch _ -> check _ >" << '\n';

    //return to check
    cout << "back 0 -> back 0 <" << '\n';
    cout << "back 1 -> back 1 <" << '\n';
    cout << "back 2 -> back 2 <" << '\n';
    cout << "back 3 -> back 3 <" << '\n';
    cout << "back _ -> check _ >" << '\n';

    //check
    cout << "check 2 -> find4 0 >" << '\n';
    cout << "check 3 -> find5 1 >" << '\n';
    cout << "check 0 -> check 0 >" << '\n';
    cout << "check 1 -> check 1 >" << '\n';
    cout << "check _ -> ac _ ^" << '\n';

    //find 4
    cout << "find4 4 -> back 0 <" << '\n';
    cout << "find4 5 -> rj _ ^" << '\n';
    cout << "find4 _ -> rj _ ^" << '\n';
    cout << "find4 0 -> find4 0 >" << '\n';
    cout << "find4 1 -> find4 1 >" << '\n';
    cout << "find4 2 -> find4 2 >" << '\n';
    cout << "find4 3 -> find4 3 >" << '\n';

    //find 5
    cout << "find5 5 -> back 1 <" << '\n';
    cout << "find5 4 -> rj _ ^" << '\n';
    cout << "find5 _ -> rj _ ^" << '\n';
    cout << "find5 0 -> find5 0 >" << '\n';
    cout << "find5 1 -> find5 1 >" << '\n';
    cout << "find5 2 -> find5 2 >" << '\n';
    cout << "find5 3 -> find5 3 >" << '\n';

    cout << "" << '\n';
    return 0;
}
