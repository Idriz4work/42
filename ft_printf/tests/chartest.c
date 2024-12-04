#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

void test1(void) {
    printf("TEST 1: print(\"%%d\", 0)\n");
    int j = ft_printf("%d", 0);  // Using ft_printf to print the number 0
    int i = printf("%d", 0);      // Using standard printf to print the number 0
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);     // Print the return values for both

    // printf("SEPARATE NEWLINE\n");

    printf("TEST 2: print(\" %%d \", 0)\n");
    j = ft_printf("%d", 0);  
    i = printf("%d", 0);     
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);  // Print the return values

    printf("TEST 3: print(\" %%d\", 0 - 256)\n");
    j = ft_printf("%d", 0 - 256);  // Print -256 using ft_printf
    i = printf("%d", 0 - 256);     // Print -256 using printf
    printf("%i\n%i\n", j, i);  // Print the return values

    printf("TEST 4: print(\"%d \", 0 + 256)\n");
    j = ft_printf("%d\n", 0 + 256);  // Print 256 using ft_printf
    i = printf("%d", 0 + 256);     // Print 256 using printf
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);  // Print the return values

    printf("TEST 5: print(\" %%d %%d %%d \", 0, 0, 1)\n");
    j = ft_printf("%d %d %d\n", 0, 0, 1);  // Print 0 0 1 using ft_printf
    i = printf("%d %d %d", 0, 0, 1);      // Print 0 0 1 using printf
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);  // Print the return values

    printf("TEST 6: print(\" %%d %%d %%d \", 32, 64, 128)\n");
    j = ft_printf("%d %d %d", 32, 64, 128);  // Print 32, 64, 128 using ft_printf
    i = printf("%d %d %d", 32, 64, 128);     // Print 32, 64, 128 using printf
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);  // Print the return values

    printf("TEST 7: print(\" %%d %%d %%d \", 1, 2, 3)\n");
    j = ft_printf("%d %d %d", 1, 2, 3);  // Print 1 2 3 using ft_printf
    i = printf("%d %d %d", 1, 2, 3);     // Print 1 2 3 using printf
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);  // Print the return values

    printf("TEST 8: print(\" %%d %%d %%d \", 2, 1, 0)\n");
    j = ft_printf("%d %d %d", 2, 1, 0);  // Print 2 1 0 using ft_printf
    i = printf("%d %d %d", 2, 1, 0);     // Print 2 1 0 using printf
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);  // Print the return values

    printf("TEST 9: print(\" %%d %%d %%d \", 0, 1, 2)\n");
    j = ft_printf("%d %d %d", 0, 1, 2);  // Print 0 1 2 using ft_printf
    i = printf("%d %d %d", 0, 1, 2);     // Print 0 1 2 using printf
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);  // Print the return values
}

void test2(void) {
    // Additional tests could be added here as needed
}

void test3(void) {
    // Additional tests could be added here as needed
}

void test4(void) {
    // Additional tests could be added here as needed
}

void test5(void) {
    // Additional tests could be added here as needed
}

void test6(void) {
    // Additional tests could be added here as needed
}

// int main(void) {
//     test1();  // Run all the tests from test1()
    // test2();  // Optional additional tests
    // test3();  // Optional additional tests
    // test4();  // Optional additional tests
    // test5();  // Optional additional tests
    // test6();  // Optional additional tests
// }
