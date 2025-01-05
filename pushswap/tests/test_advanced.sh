#!/bin/bash

# Create outputs directory if it doesn't exist
mkdir -p outputs

# Function to run tests
run_test() {
    ARG=$1
    ../push_swap $ARG | ./checker_linux $ARG > outputs/test_result

    if grep -q "OK" outputs/test_result; then
        echo "Test Passed"
    else
        echo "Test Failed"
    fi
}

# Test 1: Run push_swap with arguments "4 67 3 87 23"
ARG="4 67 3 87 23"
echo "Running Test 1: $ARG"
run_test "$ARG"

# Test 2: Run push_swap with argument "1"
ARG="1"
echo "Running Test 2: $ARG"
run_test "$ARG"

# Test 3: Run push_swap with arguments "2 1"
ARG="2 1"
echo "Running Test 3: $ARG"
run_test "$ARG"

# Test 4: Run push_swap with arguments "1 2 3 3" (duplicate)
ARG="1 2 3 3"
echo "Running Test 4: $ARG"
run_test "$ARG"

# Test 5: Run push_swap with invalid argument "1 twoi 3 4"
ARG="1 twoi 3 4"
echo "Running Test 5: $ARG"
run_test "$ARG"

# Test 6: Run push_swap with invalid argument "1 2 3 four"
ARG="1 2 3 four"
echo "Running Test 6: $ARG"
run_test "$ARG"

# Test 7: Run push_swap with reverse sorted arguments "4 3 2 1"
ARG="4 3 2 1"
echo "Running Test 7: $ARG"
run_test "$ARG"

# Test 8: Run push_swap with mixed sorted and unsorted arguments "1 2 4 3"
ARG="1 2 4 3"
echo "Running Test 8: $ARG"
run_test "$ARG"

# Test 9: Run push_swap with a large set of numbers "331 22 3323 44 49367"
ARG="331 22 3323 44 49367"
echo "Running Test 9: $ARG"
run_test "$ARG"
