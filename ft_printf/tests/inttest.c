#include <stdio.h>

// Test 1: Normal Integer
void test1i(void)
{
    printf("TEST 1: print(\"%%d\", 42)\n");
    int j = ft_printf("%d", 42);  // Using ft_printf to print the integer 42
    int i = printf("%d", 42);     // Using standard printf to print the integer 42
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 2: Negative Integer
void test2i(void)
{
    printf("TEST 2: print(\"%%d\", -42)\n");
    int j = ft_printf("%d", -42);  // Using ft_printf to print the negative integer
    int i = printf("%d", -42);     // Using standard printf to print the negative integer
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 3: Zero Integer
void test3i(void)
{
    printf("TEST 3: print(\"%%d\", 0)\n");
    int j = ft_printf("%d", 0);  // Using ft_printf to print the integer 0
    int i = printf("%d", 0);     // Using standard printf to print the integer 0
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 4: Large Integer
void test4i(void)
{
    printf("TEST 4: print(\"%%d\", 2147483647)\n");
    int j = ft_printf("%d", 2147483647);  // Using ft_printf to print the max integer
    int i = printf("%d", 2147483647);     // Using standard printf to print the max integer
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 5: Very Small Negative Integer (Min Int)
void test5i(void)
{
    printf("TEST 5: print(\"%%d\", -2147483648)\n");
    int j = ft_printf("%d", -2147483648);  // Using ft_printf to print the min integer
    int i = printf("%d", -2147483648);     // Using standard printf to print the min integer
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 6: Multiple Integers
void test6i(void)
{
    printf("TEST 6: print(\"%%d %%d %%d\", 1, -5, 42)\n");
    int j = ft_printf("%d %d %d", 1, -5, 42);  // Using ft_printf to print multiple integers
    int i = printf("%d %d %d", 1, -5, 42);     // Using standard printf to print multiple integers
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 7: Integer with Leading Zeros
void test7i(void)
{
    printf("TEST 7: print(\"%%d\", 0042)\n");
    int j = ft_printf("%d", 0042);  // Using ft_printf to print an integer with leading zeros
    int i = printf("%d", 0042);     // Using standard printf to print an integer with leading zeros
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 8: Integer as Part of Larger String
void test8i(void)
{
    printf("TEST 8: print(\"%%s %%d\", \"Age\", 30)\n");
    int j = ft_printf("%s %d", "Age", 30);  // Using ft_printf to print a string and an integer
    int i = printf("%s %d", "Age", 30);     // Using standard printf to print a string and an integer
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Main Function to Call All Tests
// int main(void)
// {
//     // Call all the test functions
//     test1i();
//     test2i();
//     test3i();
//     test4i();
//     test5i();
//     test6i();
//     test7i();
//     test8i();

//     return 0;
// }
