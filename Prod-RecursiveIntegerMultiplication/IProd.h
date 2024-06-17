#include <iostream>
#include <cmath>

//calculate the product of two integers
int prod(int u, int v) {
#undef max
    int n = std::max((int)(log10(u) + 1), (int)(log10(v) + 1));
    int m, x, y, w, z;

    if (u == 0 || v == 0) {
        return 0;
    }
    else if (n <= 3) {
        return u * v;
    }
    else {
        m = n / 2;
        int q1 = pow(10, m);
        int q2 = pow(10, 2 * m);
        y = u % q1;
        x = u / q1;
        z = v % q1;
        w = v / q1;
        return prod(x, w) * q2 + (prod(x, z) + prod(w, y)) * q1 + prod(y, z);
    }
}
