#include <cstdio>

int calc(int a, int b)
{
    return a * 2 + b;
}

double calc(char* str, double b)
{
    int a = 0;
    sscanf_s(str, "%d", &a);
    return a / b;
}

int main()
{
    printf("%d\n", calc(1, 4));
    printf("%f\n", calc("3", 5));
    return 0;
}