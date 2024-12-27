#!/bin/sh

# Basic Tests

# Create outputs directory if it doesn't exist
mkdir -p outputs

# Define input file and outputs
input_file="test1.sh"
output_standard="outputs/test1"
output_pipex="outputs/test1_pipex"

# Test 1: Compare grep and word count
cat $input_file | grep a1 | wc -w > $output_standard
../sources/a.out $input_file "grep a1" "wc -w" $output_pipex

if diff -q $output_standard $output_pipex > /dev/null; then
    echo "Test 1: Passed"
else
    echo "Test 1: Failed"
fi

# Test 2: Count lines in ../sources/pipex.c
cat ../sources/pipex.c | wc -l > outputs/test2
../sources/a.out ../sources/pipex.c "cat" "wc -l" outputs/test2_pipex

if diff -q outputs/test2 outputs/test2_pipex > /dev/null; then
    echo "Test 2: Passed"
else
    echo "Test 2: Failed"
fi

# Test 3: List files and count lines
ls -l | wc -l > outputs/test3
../sources/a.out /dev/null "ls -l" "wc -l" outputs/test3_pipex

if diff -q outputs/test3 outputs/test3_pipex > /dev/null; then
    echo "Test 3: Passed"
else
    echo "Test 3: Failed"
fi

# Test 4: Concatenate and append listing
(cat ../sources/pipex.c && ls -l) > outputs/test4
../sources/a.out ../sources/pipex.c "cat ../sources/pipex.c && ls -l" "cat" outputs/test4_pipex

if diff -q outputs/test4 outputs/test4_pipex > /dev/null; then
    echo "Test 4: Passed"
else
    echo "Test 4: Failed"
fi

# Test 5: Show the first 5 lines
head -n 5 ../sources/pipex.c > outputs/test5
../sources/a.out ../sources/pipex.c "head -n 5" "cat" outputs/test5_pipex

if diff -q outputs/test5 outputs/test5_pipex > /dev/null; then
    echo "Test 5: Passed"
else
    echo "Test 5: Failed"
fi

# Test 6: Count words in ../sources/pipex.c
cat ../sources/pipex.c | wc -w > outputs/test6
../sources/a.out ../sources/pipex.c "cat" "wc -w" outputs/test6_pipex

if diff -q outputs/test6 outputs/test6_pipex > /dev/null; then
    echo "Test 6: Passed"
else
    echo "Test 6: Failed"
fi

# Test 7: Sort contents of ../sources/pipex.c
sort ../sources/pipex.c > outputs/test7
../sources/a.out ../sources/pipex.c "sort" "cat" outputs/test7_pipex

if diff -q outputs/test7 outputs/test7_pipex > /dev/null; then
    echo "Test 7: Passed"
else
    echo "Test 7: Failed"
fi

# Test 8: Search for "main" in ../sources/pipex.c
grep "main" ../sources/pipex.c > outputs/test8
../sources/a.out ../sources/pipex.c "grep main" "cat" outputs/test8_pipex

if diff -q outputs/test8 outputs/test8_pipex > /dev/null; then
    echo "Test 8: Passed"
else
    echo "Test 8: Failed"
fi

# Test 9: Count characters in ../sources/pipex.c
cat ../sources/pipex.c | wc -c > outputs/test9
../sources/a.out ../sources/pipex.c "cat" "wc -c" outputs/test9_pipex

if diff -q outputs/test9 outputs/test9_pipex > /dev/null; then
    echo "Test 9: Passed"
else
    echo "Test 9: Failed"
fi

# Test 10: Reverse contents of ../sources/pipex.c
tac ../sources/pipex.c > outputs/test10
../sources/a.out ../sources/pipex.c "tac" "cat" outputs/test10_pipex

if diff -q outputs/test10 outputs/test10_pipex > /dev/null; then
    echo "Test 10: Passed"
else
    echo "Test 10: Failed"
fi

# Test 11: Show file permissions of ../sources/pipex.c
ls -l ../sources/pipex.c | awk '{print $1}' > outputs/test11
../sources/a.out /dev/null "ls -l ../sources/pipex.c" "awk '{print \$1}'" outputs/test11_pipex

if diff -q outputs/test11 outputs/test11_pipex > /dev/null; then
    echo "Test 11: Passed"
else
    echo "Test 11: Failed"
fi

# Test 12: Combine commands (e.g., sleep and echo)
ls -l ../sources/pipex.c | sleep 4 && echo "hello" > outputs/test12
../sources/a.out /dev/null "ls -l ../sources/pipex.c" "sleep 4 && echo hello" outputs/test12_pipex

if diff -q outputs/test12 outputs/test12_pipex > /dev/null; then
    echo "Test 12: Passed"
else
    echo "Test 12: Failed"
fi
