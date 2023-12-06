
#include <stdio.h>
#include "ft_printf.h"

int main() {
    // Test cases
    printf("\n===============================\n");
    ft_printf("Character: ||%c||\n", 'A');
    printf("Character: ||%c||\n", 'A');

    printf("\n===============================\n");
    ft_printf("String: ||%s||\n", "Hello, World!");
    ft_printf("String: ||%s||\n", "Hello, World!");
    int *ptr = NULL;
    printf("\n===============================\n");
    ft_printf("Pointer: ||%p||\n", (void*)ptr);
    printf("Pointer: ||%p||\n", (void*)ptr);

    printf("\n===============================\n");
    ft_printf("Integer: ||%d|| ||%i||\n", 123, -456);
    printf("PPInteger: ||%d|| ||%i||\n", 123, -456);


    printf("\n===============================\n");
    ft_printf("Unsigned Integer: ||%u||\n", 789);
    printf("Unsigned Integer: ||%u||\n", 789);

    printf("\n===============================\n");
    ft_printf("Hexadecimal (lowercase): ||%x||\n", 0xABCD);
    printf("Hexadecimal (lowercase): ||%x||\n", 0xABCD);

    printf("\n===============================\n");
    ft_printf("-%Hexadecimal  (uppercase): ||%X||\n%%");
    // printf("   Hexadecimal  (uppercase): ||%X||\n%%", 0xABCD);

    // Additional tests
    printf("\n===============================\n");
    ft_printf("Percentage: ||%%||\n");
    printf("Percentage: ||%%||\n");


    printf("\n===============================\n");
    ft_printf("Multiple: ||%d||%s||%c||\n", 42, "Testing", 'Z');
    printf("Multiple: ||%d||%s||%c||\n", 42, "Testing", 'Z');

    return 0;
}
// int main() {
//     // char *str = "4444";
//     char const *f1 = "\ntesting ||%d||----%a======%=====||%d||---||%d||%X|%-======\n%%%";

//     ft_printf(f1, 12, 123, 210,  123);
//     printf(f1, 12, 123, 210, 15);

//     return 0;
// }