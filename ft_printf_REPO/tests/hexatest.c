#include "../ft_printf.h"
#include "../ft_printf_bonus.h"
#include <stdio.h>

// Test 1: Print Hexadecimal (Lowercase)
void test1h(void)
{
    printf("TEST 1: print(\"%%x\", 42)\n");
    int j = ft_printf("%x", 42);  // Using ft_printf to print 42 in lowercase hex
    int i = printf("%x", 42);     // Using standard printf to print 42 in lowercase hex
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 2: Print Hexadecimal (Uppercase)
void test2h(void)
{
    printf("TEST 2: print(\"%%X\", 42)\n");
    int j = ft_printf("%X", 42);  // Using ft_printf to print 42 in uppercase hex
    int i = printf("%X", 42);     // Using standard printf to print 42 in uppercase hex
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 3: Print Hexadecimal (0)
void test3h(void)
{
    printf("TEST 3: print(\"%%x\", 0)\n");
    int j = ft_printf("%x", 0);  // Using ft_printf to print 0 in hexadecimal
    int i = printf("%x", 0);     // Using standard printf to print 0 in hexadecimal
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 4: Print Large Hexadecimal Number (Lowercase)
void test4h(void)
{
    unsigned int num = 1234567890;
    printf("TEST 4: print(\"%%x\", 1234567890)\n");
    int j = ft_printf("%x", num);  // Using ft_printf to print large number in lowercase hex
    int i = printf("%x", num);     // Using standard printf to print large number in lowercase hex
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 5: Print Large Hexadecimal Number (Uppercase)
void test5h(void)
{
    unsigned int num = 1234567890;
    printf("TEST 5: print(\"%%X\", 1234567890)\n");
    int j = ft_printf("%X", num);  // Using ft_printf to print large number in uppercase hex
    int i = printf("%X", num);     // Using standard printf to print large number in uppercase hex
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 6: Print Hexadecimal with Prefix
void test6h(void)
{
    unsigned int num = 42;
    printf("TEST 6: print(\"%%#x\", 42)\n");
    int j = ft_printf("%#x", num);  // Using ft_printf to print 42 with hex prefix (0x)
    int i = printf("%#x", num);     // Using standard printf to print 42 with hex prefix (0x)
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 7: Print Multiple Hexadecimal Values
void test7h(void)
{
    unsigned int num1 = 255;
    unsigned int num2 = 4096;
    printf("TEST 7: print(\"%%x %%x\", 255, 4096)\n");
    int j = ft_printf("%x %x", num1, num2);  // Using ft_printf to print two hexadecimal numbers
    int i = printf("%x %x", num1, num2);     // Using standard printf to print two hexadecimal numbers
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 8: Print Hexadecimal with Zero Padding (Lowercase)
void test8h(void)
{
    unsigned int num = 42;
    printf("TEST 8: print(\"%%08x\", 42)\n");
    int j = ft_printf("%08x", num);  // Using ft_printf to print with zero padding
    int i = printf("%08x", num);     // Using standard printf to print with zero padding
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 9: Print Hexadecimal with Zero Padding (Uppercase)
void test9h(void)
{
    unsigned int num = 42;
    printf("TEST 9: print(\"%%08X\", 42)\n");
    int j = ft_printf("%08X", num);  // Using ft_printf to print with zero padding (uppercase)
    int i = printf("%08X", num);     // Using standard printf to print with zero padding (uppercase)
    printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Main Function to Call All Hexadecimal Tests
// int main(void)
// {
//     // Call all the test functions for hexadecimal formatting
//     test1h();
//     test2h();
//     test3h();
//     test4h();
//     test5h();
//     test6h();
//     test7h();
//     test8h();
//     test9h();

//     return 0;
// }
