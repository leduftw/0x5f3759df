#include <stdio.h>

float inverse_square_root(float x) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = x * 0.5F;
    y = x;
    i = *(long *)&y;  // evil floating point bit hack
    i = 0x5f3759df - (i >> 1);  // what the fuck?
    y = *(float *)&i;
    y = y * (threehalfs - (x2 * y * y));  // 1st iteration
    y = y * (threehalfs - (x2 * y * y));  // 2st iteration, this can be removed

    return y;
}

int main() {
    float x = 2;
    printf("1/sqrt(%.2f)=%.2f", x, inverse_square_root(x));

    return 0;
}
