#include <iostream>
#include "String.hpp"
using namespace std;

int main()
{
    String str("123");
    String str1 = "123";
    str1.append('a');
    cout << str1 << endl;
    cout << str1[0] << endl;
    cout << String::compare(str1, str) << endl;
    //str1.clear();
    cout << str1 << endl;

    return 0;
}