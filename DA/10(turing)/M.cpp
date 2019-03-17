#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sorting.out", "w", stdout);

    //
    cout << "3" << '\n';

    //start
    cout << "S 0 _ _ -> goChT 0 ^ 0 ^ _ ^" << '\n';
    cout << "S 1 _ _ -> goChT 1 ^ 0 ^ _ ^" << '\n';

    //check T
    cout << "goChT 0 0 _ -> goChT 0 > 0 > _ ^" << '\n';
    cout << "goChT 1 1 _ -> goChT 1 > 1 > _ ^" << '\n';
    cout << "goChT | _ _ -> write | ^ _ < _ ^" << '\n';
    cout << "goChT _ _ _ -> write _ ^ _ < _ ^" << '\n';

    cout << "goChT 0 1 _ -> goChF 0 > 1 > _ ^" << '\n';
    cout << "goChT 1 0 _ -> goChF 1 > 0 > _ ^" << '\n';
    cout << "goChT 0 _ _ -> goChF 0 > _ ^ _ ^" << '\n';
    cout << "goChT 1 _ _ -> goChF 1 > _ ^ _ ^" << '\n';

    cout << "goChT | 0 _ -> goToFr | > 0 ^ _ ^" << '\n';
    cout << "goChT | 1 _ -> goToFr | > 1 ^ _ ^" << '\n';

    cout << "goChT _ 0 _ -> goToSt _ > 0 ^ _ ^" << '\n';
    cout << "goChT _ 1 _ -> goToSt _ > 1 ^ _ ^" << '\n';

    //check F
    cout << "goChF 0 1 _ -> goChF 0 > 1 ^ _ ^" << '\n';
    cout << "goChF 0 0 _ -> goChF 0 > 0 ^ _ ^" << '\n';
    cout << "goChF 0 _ _ -> goChF 0 > _ ^ _ ^" << '\n';
    cout << "goChF 1 0 _ -> goChF 1 > 0 ^ _ ^" << '\n';
    cout << "goChF 1 1 _ -> goChF 1 > 1 ^ _ ^" << '\n';
    cout << "goChF 1 _ _ -> goChF 1 > _ ^ _ ^" << '\n';

    cout << "goChF | 0 _ -> goChF | > 0 ^ _ ^" << '\n';
    cout << "goChF _ 0 _ -> goChF _ > 0 ^ _ ^" << '\n';
    cout << "goChF | 1 _ -> goChF | > 1 ^ _ ^" << '\n';
    cout << "goChF _ 1 _ -> goChF _ > 1 ^ _ ^" << '\n';
    cout << "goChF | _ _ -> goChF | > _ ^ _ ^" << '\n';
    cout << "goChF _ _ _ -> goChF _ > _ ^ _ ^" << '\n';

    //go ot front

    //write
    cout << "write | 1 _ -> write | ^ 1 < _ ^" << '\n';
    cout << "write | 0 _ -> write | ^ 0 < _ ^" << '\n';
    cout << "write | _ _ -> ins | ^ _ > _ ^" << '\n';
    cout << "write _ 1 _ -> write _ ^ 1 < _ ^" << '\n';
    cout << "write _ 0 _ -> write _ ^ 0 < _ ^" << '\n';
    cout << "write _ _ _ -> ins _ ^ _ > _ ^" << '\n';

    //insert
    cout << "ins | 1 _ -> ins | ^ 1 > 1 >" << '\n';
    cout << "ins | 0 _ -> ins | ^ 0 > 0 >" << '\n';
    cout << "ins | _ _ -> ins | ^ 1 > 1 >" << '\n';

    return 0;
}
