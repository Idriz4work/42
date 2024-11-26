
#include "header.h"

int	main(void)
{
    // Integer Tests
    test1i();  // Test 1: Printing integer 0
    test2i();  // Test 2: Printing negative integer
    test3i();  // Test 3: Printing a positive integer
    test4i();  // Test 4: Printing a large integer
    test5i();  // Test 5: Printing minimal integer value
    test6i();  // Test 6: Printing a negative large integer
    test7i();  // Test 7: Printing multiple integers at once
    test8i();  // Test 8: Printing integer with zero padding

    // String Tests
    test1s();  // Test 1: Printing a regular string
    test2s();  // Test 2: Printing an empty string
    test3s();  // Test 3: Printing a string with special characters
    test4s();  // Test 4: Printing a string with spaces
    test5s();  // Test 5: Printing a string with long length
    test6s();  // Test 6: Printing a NULL string (edge case)

    // Empty and Invalid Tests for Strings
    test_empty();              // Test 1: Printing an empty string
    test_invalid_value();      // Test 2: Handling invalid values (e.g., NULL pointers)
    test_basic();              // Test 3: Basic string handling
    test_maximal_value();      // Test 4: Printing a very long string
    test_minimal_value();      // Test 5: Printing minimal value of string
    test_verylong();           // Test 6: Printing a very long string input
    test_withothers();         // Test 7: Testing string with other format specifiers

    // Unsigned Integer, Hexadecimal and Pointer Tests
    test_sui();                // Test 1: Printing unsigned integers
    test_xXp();                // Test 2: Testing hexadecimal (lowercase and uppercase)
    test_signcd();             // Test 3: Printing signed values and characters
    test_cspdiuxXdoublesign();

    // Pointer Tests
    test_emptyp();             // Test 2: Printing empty pointer
    test_invalid_valuep();     // Test 3: Handling invalid pointer values
    test_maximal_valuep();     // Test 4: Printing a large pointer value

    // Pointer Specific Tests
    test1p();  // Test 1: Printing pointer address (e.g., %p)
    test2p();  // Test 2: Printing a null pointer
    test3p();  // Test 3: Printing a pointer with a valid address
    test4p();  // Test 4: Printing a pointer with zero padding
    test5p();  // Test 5: Printing a large pointer value
    test6p();  // Test 6: Printing a pointer in hexadecimal format
    test7p();  // Test 7: Multiple pointer prints in one call
    test8p();  // Test 8: Pointer test with null and valid values

    // Hexadecimal Tests
    test1h();  // Test 1: Printing hexadecimal (lowercase)
    test2h();  // Test 2: Printing hexadecimal (uppercase)
    test3h();  // Test 3: Printing hexadecimal of zero
    test4h();  // Test 4: Printing large hexadecimal number (lowercase)
    test5h();  // Test 5: Printing large hexadecimal number (uppercase)
    test6h();  // Test 6: Printing hexadecimal with 0x prefix
    test7h();  // Test 7: Printing multiple hexadecimal numbers
    test8h();  // Test 8: Printing hexadecimal with zero padding (lowercase)
    test9h();  // Test 9: Printing hexadecimal with zero padding (uppercase)

    return 0;
}
