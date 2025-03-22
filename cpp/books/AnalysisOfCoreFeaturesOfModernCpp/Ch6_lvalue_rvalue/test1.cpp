#include <iostream>

using namespace std;

int x = 1;

int get_val(void)
{	
    return x;
}

void set_val(int val)
{
    x = val;
}

int main() {
    x++; /* rvalue */
    ++x; /* lvalue */

    //int *p = &x++; /* fail */
    int *q = &++x; /* success */
    //int *r = &get_val(); /* fail */

    int y = get_val();
    set_val(6);
    auto p = &"this is a lvalue";

    //int &x1 = 1; // compile err
    const int &x2 = 11; // compile succ
}
