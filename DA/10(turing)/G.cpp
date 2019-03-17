#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("less.out", "w", stdout);

    // 2 == 0; 3 == 1; 4 == 0; 5 == 1;
    cout << "start: s" << '\n';
    cout << "accept: ac" << '\n';
    cout << "reject: rj" << '\n';
    cout << "blank: _" << '\n';

    //go to last
    cout << "s 0 -> findZ 2 >" << '\n';
    cout << "s 1 -> findZ 3 >" << '\n';
    cout << "s < -> checkLen < >" << '\n';

    //find '<' ->
    cout << "findZ 0 -> findZ 0 >" << '\n';
    cout << "findZ 1 -> findZ 1 >" << '\n';
    cout << "findZ < -> markL < >" << '\n';

    //mark second part
    cout << "markL 4 -> markL 4 >" << '\n';
    cout << "markL 5 -> markL 5 >" << '\n';
    cout << "markL 0 -> goToS 4 <" << '\n';
    cout << "markL 1 -> goToS 5 <" << '\n';
    cout << "markL _ -> rj _ ^" << '\n';

    //go to start
    cout << "goToS 4 -> goToS 4 <" << '\n';
    cout << "goToS 5 -> goToS 5 <" << '\n';
    cout << "goToS < -> goToS < <" << '\n';
    cout << "goToS 0 -> goToS 0 <" << '\n';
    cout << "goToS 1 -> goToS 1 <" << '\n';
    cout << "goToS 2 -> s 2 >" << '\n';
    cout << "goToS 3 -> s 3 >" << '\n';

    //check length
    cout << "checkLen 4 -> checkLen 4 >" << '\n';
    cout << "checkLen 5 -> checkLen 5 >" << '\n';
    cout << "checkLen _ -> clear _ <" << '\n';
    cout << "checkLen 0 -> ac _ ^" << '\n';
    cout << "checkLen 1 -> ac _ ^" << '\n';

    //clear stack
    cout << "clear 2 -> clear 0 <" << '\n';
    cout << "clear 4 -> clear 0 <" << '\n';
    cout << "clear 3 -> clear 1 <" << '\n';
    cout << "clear 5 -> clear 1 <" << '\n';
    cout << "clear < -> clear < <" << '\n';
    cout << "clear _ -> chF _ >" << '\n';

    //check first num
    cout << "chF 0 -> goS0 2 >" << '\n';
    cout << "chF 1 -> goS1 3 >" << '\n';
    cout << "chF < -> rj _ ^" << '\n';

    //find '<' with 0 ->
    cout << "goS0 0 -> goS0 0 >" << '\n';
    cout << "goS0 1 -> goS0 1 >" << '\n';
    cout << "goS0 < -> ch0 < >" << '\n';

    //find '<' with 1 ->
    cout << "goS1 0 -> goS1 0 >" << '\n';
    cout << "goS1 1 -> goS1 1 >" << '\n';
    cout << "goS1 < -> ch1 < >" << '\n';

    //check with 0
    cout << "ch0 4 -> ch0 4 >" << '\n';
    cout << "ch0 5 -> ch0 5 >" << '\n';
    cout << "ch0 1 -> ac _ ^" << '\n';
    cout << "ch0 0 -> ret 4 <" << '\n';

    //check with 1
    cout << "ch1 4 -> ch1 4 >" << '\n';
    cout << "ch1 5 -> ch1 5 >" << '\n';
    cout << "ch1 0 -> rj _ ^" << '\n';
    cout << "ch1 1 -> ret 5 <" << '\n';

    //return to chF
    cout << "ret 4 -> ret 4 <" << '\n';
    cout << "ret 5 -> ret 5 <" << '\n';
    cout << "ret < -> ret < <" << '\n';
    cout << "ret 0 -> ret 0 <" << '\n';
    cout << "ret 1 -> ret 1 <" << '\n';
    cout << "ret 2 -> chF 2 >" << '\n';
    cout << "ret 3 -> chF 3 >" << '\n';

    cout << "" << '\n';
    return 0;
}
