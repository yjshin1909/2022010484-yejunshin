#include <stdio.h>

struct MyStruct
{
    int a;
    int b;
};

union MyUnion
{
    int a;
    int b;
};

int main()
{

    struct MyStruct s;
    union MyUnion u;

    s.a = 10;
    s.b = 20;

    u.a = 10;
    u.b = 20;

    printf("=== 구조체 ===\n");
    printf("s.a = %d\n", s.a);
    printf("s.b = %d\n", s.b);

    printf("\n=== 공용체 ===\n");
    printf("u.a = %d\n", u.a);
    printf("u.b = %d\n", u.b);

    return 0;
}
