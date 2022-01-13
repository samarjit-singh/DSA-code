#include <iostream>
using namespace std;

int toh(int n, int a, int b, int c) {

    if (n > 0) {
        toh(n - 1, a, c, b);
        cout << a << "to" << c <<endl;
        toh(n - 1, b, a, c);
    }
    return 0;
}


int main()
{
    toh(15, 1, 2, 3);
    return 0;
}