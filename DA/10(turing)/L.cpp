#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("factorial.out", "w", stdout);

    //
    cout << "1" << '\n';

    //start
    cout << "S 0 -> init 0 <" << '\n';
    cout << "S 1 -> init 1 <" << '\n';

    //init
    cout << "init _ -> init2 + <" << '\n';

    //init2
    cout << "init2 _ -> goEnd 0 >" << '\n';

    //go to end
    cout << "goEnd 0 -> goEnd 0 >" << '\n';
    cout << "goEnd 1 -> goEnd 1 >" << '\n';
    cout << "goEnd + -> goEnd + >" << '\n';
    cout << "goEnd * -> goEnd * >" << '\n';
    cout << "goEnd _ -> minus _ <" << '\n';

    //go to start
    cout << "goSt 0 -> goSt 0 <" << '\n';
    cout << "goSt 1 -> goSt 1 <" << '\n';
    cout << "goSt * -> gl * <" << '\n';

    //minus 1
    cout << "minus 1 -> goSt 0 <" << '\n';
    cout << "minus 0 -> minus 1 <" << '\n';
    cout << "minus * -> clean * >" << '\n';

    //clean
    cout << "clean 1 -> clean _ >"<< '\n';
    cout << "clean _ -> clean2 _ <" << '\n';

    //clean2
    cout << "clean2 _ -> clean2 _ <" << '\n';
    cout << "clean2 0 -> clean2 _ <" << '\n';
    cout << "clean2 1 -> clean2 _ <" << '\n';
    cout << "clean2 * -> clean2 _ <" << '\n';
    cout << "clean2 + -> Ac _ <" << '\n';

    //Accepted
    cout << "Ac 0 -> Ac 0 <" << '\n';
    cout << "Ac 1 -> Ac 1 <" << '\n';
    cout << "Ac _ -> AC _ >" << '\n';


    ////plus 1////
    // 2 == 0; 3 == 1
    //go to last(good luck)
    cout << "gl 0 -> gl 0 >" << '\n';
    cout << "gl 1 -> gl 1 >" << '\n';
    cout << "gl 2 -> gl 2 >" << '\n';
    cout << "gl 3 -> gl 3 >" << '\n';
    cout << "gl + -> gl + >" << '\n';
    cout << "gl * -> re * <" << '\n';

    //return
    cout << "re 2 -> re 2 <" << '\n';
    cout << "re 3 -> re 3 <" << '\n';
    cout << "re 0 -> p0 2 <" << '\n';
    cout << "re 1 -> p1 3 <" << '\n';
    cout << "re + -> cln + <" << '\n';

    //plus 0 before +
    cout << "p0 0 -> p0 0 <" << '\n';
    cout << "p0 1 -> p0 1 <" << '\n';
    cout << "p0 + -> p0a + <" << '\n';

    //plus 0 after +
    cout << "p0a 2 -> p0a 2 <" << '\n';
    cout << "p0a 3 -> p0a 3 <" << '\n';
    cout << "p0a 0 -> gl 2 >" << '\n';
    cout << "p0a _ -> gl 2 >" << '\n';
    cout << "p0a 1 -> gl 3 >" << '\n';

    //plus 1 before +
    cout << "p1 0 -> p1 0 <" << '\n';
    cout << "p1 1 -> p1 1 <" << '\n';
    cout << "p1 + -> p1a + <" << '\n';

    //plus 1 after +
    cout << "p1a 2 -> p1a 2 <" << '\n';
    cout << "p1a 3 -> p1a 3 <" << '\n';
    cout << "p1a 0 -> gl 3 >" << '\n';
    cout << "p1a _ -> gl 3 >" << '\n';
    cout << "p1a 1 -> p1a2 2 <" << '\n';

    //plus 1 after + after raz
    cout << "p1a2 0 -> gl 1 >" << '\n';
    cout << "p1a2 1 -> p1a2 0 <" << '\n';
    cout << "p1a2 _ -> gl 1 >" << '\n';

    //clean plus
    cout << "cln 0 -> cln 0 <" << '\n';
    cout << "cln 1 -> cln 1 <" << '\n';
    cout << "cln 2 -> cln 0 <" << '\n';
    cout << "cln 3 -> cln 1 <" << '\n';
    cout << "cln _ -> cln2 _ >" << '\n';

    //cln2 plus
    cout << "cln2 0 -> cln2 0 >" << '\n';
    cout << "cln2 1 -> cln2 1 >" << '\n';
    cout << "cln2 2 -> cln2 0 >" << '\n';
    cout << "cln2 3 -> cln2 1 >" << '\n';
    cout << "cln2 + -> cln2 + >" << '\n';
    cout << "cln2 * -> goEnd * >" << '\n';

    cout << "" << '\n';
    return 0;
}


