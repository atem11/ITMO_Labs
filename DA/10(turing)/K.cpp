#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("infixlogic.out", "w", stdout);

    //
    cout << "2" << '\n';

    //start
    cout << "S 0 _ -> S _ > 0 >" << '\n';
    cout << "S 1 _ -> S _ > 1 >" << '\n';
    cout << "S o _ -> S _ > o >" << '\n';
    cout << "S ( _ -> S _ > ( >" << '\n';
    cout << "S ) _ -> goAnd _ ^ _ <" << '\n';
    cout << "S a _ -> and _ > _ <" << '\n';
    cout << "S _ _ -> allOr _ ^ _ <" << '\n';

    //AND
    cout << "and 1 1 -> S _ > 1 >" << '\n';
    cout << "and 1 0 -> S _ > 0 >" << '\n';
    cout << "and 0 1 -> S _ > 0 >" << '\n';
    cout << "and 0 0 -> S _ > 0 >" << '\n';
    cout << "and ( 1 -> andBr _ ^ 1 >" << '\n';
    cout << "and ( 0 -> andBr _ ^ 0 >" << '\n';

    //AND + '('
    cout << "andBr _ _ -> S _ > a >" << '\n';

    //find ')'
    cout << "goAnd _ 0 -> goAnd0 _ ^ _ <" << '\n';
    cout << "goAnd _ 1 -> goAnd1 _ ^ _ <" << '\n';

    //find a + 0
    cout << "goAnd0 _ o -> goAnd0o _ ^ _ <" << '\n';
    cout << "goAnd0 _ a -> goAnd0a _ ^ _ <" << '\n';
    cout << "goAnd0 _ _ -> S _ > 0 >" << '\n';
    cout << "goAnd0 _ ( -> S _ > 0 >" << '\n';

    //find a + 1
    cout << "goAnd1 _ o -> goAnd1o _ ^ _ <" << '\n';
    cout << "goAnd1 _ a -> goAnd1a _ ^ _ <" << '\n';
    cout << "goAnd1 _ _ -> S _ > 1 >" << '\n';
    cout << "goAnd1 _ ( -> S _ > 1 >" << '\n';


    //find a + 0o
    cout << "goAnd0o _ 1 -> goAnd _ ^ 1 ^" << '\n';
    cout << "goAnd0o _ 0 -> goAnd _ ^ 0 ^" << '\n';


    //find a + 0a
    cout << "goAnd0a _ 1 -> S _ > 0 >" << '\n';
    cout << "goAnd0a _ 0 -> S _ > 0 >" << '\n';

    //find a + 1o
    cout << "goAnd1o _ 1 -> goAnd _ ^ 1 ^" << '\n';
    cout << "goAnd1o _ 0 -> goAnd _ ^ 1 ^" << '\n';


    //find a + 1a
    cout << "goAnd1a _ 1 -> S _ > 1 >" << '\n';
    cout << "goAnd1a _ 0 -> S _ > 0 >" << '\n';

    //All or
    cout << "allOr _ 0 -> allOr0 _ ^ _ <" << '\n';
    cout << "allOr _ 1 -> allOr1 _ ^ _ <" << '\n';

    //All or 0
    cout << "allOr0 _ o -> allOr0o _ ^ _ <" << '\n';
    cout << "allOr0 _ _ -> AC 0 ^ _ <" << '\n';

    //All or 0 + o
    cout << "allOr0o _ 0 -> allOr _ ^ 0 ^" << '\n';
    cout << "allOr0o _ 1 -> allOr _ ^ 1 ^" << '\n';

    //All or 1
    cout << "allOr1 _ o -> allOr1o _ ^ _ <" << '\n';
    cout << "allOr1 _ _ -> AC 1 ^ _ <" << '\n';

    //All or 1 + o
    cout << "allOr1o _ 0 -> allOr _ ^ 1 ^" << '\n';
    cout << "allOr1o _ 1 -> allOr _ ^ 1 ^" << '\n';

    cout << "" << '\n';
    return 0;
}


