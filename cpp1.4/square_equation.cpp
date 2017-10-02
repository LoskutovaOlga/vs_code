#include <cstdio>
#include <math.h>

int main()
{
    std::puts("Please enter a, b and c for 'ax^2 + bx + c = 0':");
    float a = 0;
    float b = 0;
    float c = 0;
    std::scanf("%f %f %f", &a, &b, &c);
    float d = b * b - 4 * a * c;
    float kd = sqrt(d);
    float x1 = (-b + kd) / (2 * a);
    float x2 = (-b - kd) / (2 * a);
    std::printf("solutions: %f\n %f\n", x1, x2);
}