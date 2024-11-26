#include "../ft_printf.h"
#include "../ft_printf_bonus.h"
#include <stdio.h>
// Test 1: Null Pointer
void test1p(void)
{
    printf("TEST 1: print(\"%%p\", NULL)\n");
    int j = ft_printf("%p", NULL);  // Using ft_printf to print a null pointer
    int i = printf("%p", NULL);     // Using standard printf to print a null pointer
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 2: Valid Pointer (Address of an Integer)
void test2p(void)
{
    int num = 42;
    printf("TEST 2: print(\"%%p\", &num)\n");
    int j = ft_printf("%p", &num);  // Using ft_printf to print the address of num
    int i = printf("%p", &num);     // Using standard printf to print the address of num
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 3: Pointer to Pointer (Address of a Pointer)
void test3p(void)
{
    int num = 42;
    int *ptr = &num;
    printf("TEST 3: print(\"%%p\", &ptr)\n");
    int j = ft_printf("%p", &ptr);  // Using ft_printf to print the address of the pointer ptr
    int i = printf("%p", &ptr);     // Using standard printf to print the address of the pointer ptr
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 4: Random Pointer Value (Non-Null Address)
void test4p(void)
{
    int num = 42;
    printf("TEST 4: print(\"%%p\", &num)\n");
    int j = ft_printf("%p", &num);  // Using ft_printf to print the address of num
    int i = printf("%p", &num);     // Using standard printf to print the address of num
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 5: Multiple Pointers
void test5p(void)
{
    int num1 = 42;
    int num2 = 100;
    printf("TEST 5: print(\"%%p %%p\", &num1, &num2)\n");
    int j = ft_printf("%p %p", &num1, &num2);  // Using ft_printf to print the addresses of num1 and num2
    int i = printf("%p %p", &num1, &num2);     // Using standard printf to print the addresses of num1 and num2
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 6: Pointer with Large Address
void test6p(void)
{
    unsigned long large_num = 1234567890;
    unsigned long *ptr = &large_num;
    printf("TEST 6: print(\"%%p\", ptr with large address)\n");
    int j = ft_printf("%p", ptr);  // Using ft_printf to print a pointer with a large address value
    int i = printf("%p", ptr);     // Using standard printf to print a pointer with a large address value
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 7: Address as Part of Larger String
void test7p(void)
{
    int num = 42;
    printf("TEST 7: print(\"%%s %%p\", \"Pointer address\", &num)\n");
    int j = ft_printf("%s %p", "Pointer address", &num);  // Using ft_printf to print a string and a pointer
    int i = printf("%s %p", "Pointer address", &num);     // Using standard printf to print a string and a pointer
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 8: Pointer with Hexadecimal Formatting
void test8p(void)
{
    int num = 42;
    printf("TEST 8: print(\"%%p\", &num) with hexadecimal formatting\n");
    int j = ft_printf("%#p", &num);  // Using ft_printf to print a pointer with hex formatting
    int i = printf("%#p", &num);     // Using standard printf to print a pointer with hex formatting
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Main Function to Call All Pointer Tests
// int main(void)
// {
//     // Call all the test functions for pointers
//     test1p();
//     test2p();
//     test3p();
//     test4p();
//     test5p();
//     test6p();
//     test7p();
//     test8p();

//     return 0;
// }
