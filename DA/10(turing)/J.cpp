#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("postfixlogic.out", "w", stdout);

    //
    cout << "1" << '\n';

    //start
    cout << "S 0 -> S 0 >" << '\n';
    cout << "S 1 -> S 1 >" << '\n';
    cout << "S o -> find o <" << '\n';
    cout << "S a -> find a <" << '\n';
    cout << "S _ -> AC _ <" << '\n';

    //find first state
    cout << "find _ -> find _ <" << '\n';
    cout << "find 0 -> find0 _ <" << '\n';
    cout << "find 1 -> find1 _ <" << '\n';

    //find0 second state
    cout << "find0 _ -> find0 _ <" << '\n';
    cout << "find0 0 -> go00 _ >" << '\n';
    cout << "find0 1 -> go01 _ >" << '\n';


    //find1 second state
    cout << "find1 _ -> find1 _ <" << '\n';
    cout << "find1 0 -> go10 _ >" << '\n';
    cout << "find1 1 -> go11 _ >" << '\n';

    //go 0 0
    cout << "go00 _ -> go00 _ >" << '\n';
    cout << "go00 a -> S 0 >" << '\n';
    cout << "go00 o -> S 0 >" << '\n';


    //go 0 1
    cout << "go01 _ -> go01 _ >" << '\n';
    cout << "go01 a -> S 0 >" << '\n';
    cout << "go01 o -> S 1 >" << '\n';


    //go 1 0
    cout << "go10 _ -> go10 _ >" << '\n';
    cout << "go10 a -> S 0 >" << '\n';
    cout << "go10 o -> S 1 >" << '\n';

    //go 1 1
    cout << "go11 _ -> go11 _ >" << '\n';
    cout << "go11 a -> S 1 >" << '\n';
    cout << "go11 o -> S 1 >" << '\n';

    cout << "" << '\n';
    return 0;
}

