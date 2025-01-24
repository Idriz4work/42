#!/bin/bash

# Function to run the tests using the given format
run_test() {
    ARG="$1"
    echo "Running Test: $ARG"
    .././push_swap $ARG | ./checker_linux $ARG
    echo "---------------------------------"
}

# Test cases with more than 3 numbers

# Sorted cases
run_test "1 2 3 4"
run_test "1 2 3 4 5"
run_test "1 2 3 4 5 6 7"

# Reverse order cases
run_test "4 3 2 1"
run_test "5 4 3 2 1"
run_test "7 6 5 4 3 2 1"

# Mixed order cases
run_test "3 1 4 2"
run_test "6 3 1 4 5 2"
run_test "9 7 3 8 4 1 5"

# Duplicate values (should return an error)
run_test "1 2 3 3 4"
run_test "5 5 5 5 5"
run_test "1 2 3 4 4 6 7"

# Negative numbers
run_test "-1 -2 -3 -4"
run_test "-10 -5 0 5 10"
run_test "1 -1 2 -2 3 -3"

# Mixed positive and negative numbers
run_test "-10 3 5 -7 2 8 -4"
run_test "4 -1 0 9 -5 8 3"
run_test "-100 50 -200 150 0"

# Edge cases (min/max int)
run_test "-2147483648 0 2147483647"
run_test "2147483647 1000000 -2147483648 0"
run_test "-1000000000 -500000000 0 500000000 1000000000"

# Large set of random numbers
run_test "100 99 98 97 96 95 94 93 92 91"
run_test "10 9 8 7 6 5 4 3 2 1"
run_test "23 15 8 42 91 74 36 53 61 12"

# Single number (should do nothing)
run_test "42"

# Edge case: already sorted
run_test "1 2 3 4 5 6 7 8 9 10"

# Edge case: all identical numbers (should output error)
run_test "7 7 7 7 7 7 7"

# Random order inputs
run_test "99 23 45 12 87 63 34 78"
run_test "1024 512 256 128 64 32 16 8 4 2 1"

# Empty input (should return nothing or error)
run_test ""

# Extra spaces (handling spaces properly)
run_test "  12   23  34  "
run_test "   4  3  2  1   "

# Non-numeric input (should output error)
run_test "1 two 3 four"
run_test "hello world 42"

# Leading zeros
run_test "01 02 03 04 05"
run_test "0001 0002 0003 0004"

# Mixed duplicates
run_test "10 20 30 10 40 50"
run_test "5 15 25 5 35 45 55"
run_test "99 88 77 99 66 55 99"

