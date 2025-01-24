#!/bin/bash

# Function to run the tests using the given format
run_test() {
    ARG="$1"
    echo "Running Test: $ARG"
    .././push_swap $ARG | ./checker_linux $ARG
    echo "---------------------------------"
}

# Test cases with 2-3 numbers

# Sorted cases
run_test "1 2"
run_test "1 2 3"

# Reverse order cases
run_test "2 1"
run_test "3 2 1"

# Mixed order cases
run_test "2 3 1"
run_test "3 1 2"
run_test "1 3 2"

# Duplicate values (should return an error)
run_test "2 2"
run_test "1 3 3"

# Negative numbers
run_test "-1 0"
run_test "0 -1 2"
run_test "-3 -1 -2"

# Mixed positive and negative numbers
run_test "-1 1"
run_test "3 -2 1"
run_test "-10 5 0"

# Edge cases (min/max int)
run_test "-2147483648 0"
run_test "2147483647 -2147483648"
run_test "-2147483648 2147483647 0"

# Single number
run_test "1"
run_test "-1000000"

# Large numbers
run_test "999999 1000000"
run_test "1000000 999999 1000001"

# Small numbers
run_test "-999999 -1000000"
run_test "-1000000 -999999 -1000001"

# Empty input (should return nothing or error)
run_test ""

# Extra spaces (handling spaces properly)
run_test "  1   2  "
run_test "   3  2  1   "

# Non-numeric input (should output error)
run_test "1 a 2"
run_test "hello 3 5"
run_test "1.5 2 3"

# Leading zeros
run_test "01 02 03"
run_test "0001 0002 0003"

# Mixed duplicates
run_test "3 3 2"
run_test "1 2 2"
run_test "100 200 200"
