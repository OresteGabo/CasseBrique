
#include <iostream>
#include"Application.h"
using namespace std;

int main()
{
    Application app;
    cout << "Hello world!" << endl;
    return 0;
}


/*** La partie du test
*

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "tests/doctest.h"

TEST_CASE("lots of nested subcases") {
    cout << endl << "root" << endl;
    SUBCASE("") {
        cout << "1" << endl;
        SUBCASE("") { cout << "1.1" << endl; }
    }
    SUBCASE("") {
        cout << "2" << endl;
        SUBCASE("") { cout << "2.1" << endl; }
        SUBCASE("") {
            cout << "2.2" << endl;
            SUBCASE("") {
                cout << "2.2.1" << endl;
                SUBCASE("") { cout << "2.2.1.1" << endl; }
                SUBCASE("") { cout << "2.2.1.2" << endl; }
            }
        }
        SUBCASE("") { cout << "2.3" << endl; }
        SUBCASE("") { cout << "2.4" << endl; }
    }
}
*/
