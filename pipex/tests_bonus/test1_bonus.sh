#!/bin/sh

# Create outputs_bonus directory if it doesn't exist
mkdir -p outputs_bonus 

# Existing Tests

# Test 1/3: File listing and line counting
cat file1 | ls -l | wc -l > outputs_bonus/test1_3
../sources/a.out file1 "ls -l" "wc -l" outputs_bonus/test1_3_pipex

if diff -q outputs_bonus/test1_3 outputs_bonus/test1_3_pipex > /dev/null; then
    echo "Test 1/3: Passed"
else
    echo "Test 1/3: Failed"
fi

# Test 2/3: Count lines in ../sources/pipex.c
cat file1 | wc -l > outputs_bonus/test2_3
../sources/a.out "file1" "cat" "wc -l" outputs_bonus/test2_3_pipex

if diff -q outputs_bonus/test2_3 outputs_bonus/test2_3_pipex > /dev/null; then
    echo "Test 2/3: Passed"
else
    echo "Test 2/3: Failed"
fi

# Test 3/3: Compare grep and word count
cat file1 | grep a1 | wc -w > outputs_bonus/test3_3
../sources/a.out file1 "grep a1" "wc -w" outputs_bonus/test3_3_pipex

if diff -q outputs_bonus/test3_3 outputs_bonus/test3_3_pipex > /dev/null; then
    echo "Test 3/3: Passed"
else
    echo "Test 3/3: Failed"
fi

# Test 4: List files and count lines
ls -l | wc -l > outputs_bonus/test4
../sources/a.out /dev/null "ls -l" "wc -l" outputs_bonus/test4_pipex

if diff -q outputs_bonus/test4 outputs_bonus/test4_pipex > /dev/null; then
    echo "Test 4: Passed"
else
    echo "Test 4: Failed"
fi

# Test 5: Show the first 5 lines
head -n 5 ../sources/pipex.c > outputs_bonus/test5
../sources/a.out ../sources/pipex.c "head -n 5" "cat" outputs_bonus/test5_pipex

if diff -q outputs_bonus/test5 outputs_bonus/test5_pipex > /dev/null; then
    echo "Test 5: Passed"
else
    echo "Test 5: Failed"
fi

# Test 6: Count words in ../sources/pipex.c
cat ../sources/pipex.c | wc -w > outputs_bonus/test6
../sources/a.out ../sources/pipex.c "cat" "wc -w" outputs_bonus/test6_pipex

if diff -q outputs_bonus/test6 outputs_bonus/test6_pipex > /dev/null; then
    echo "Test 6: Passed"
else
    echo "Test 6: Failed"
fi

# Test 7: Sort contents of ../sources/pipex.c
sort ../sources/pipex.c > outputs_bonus/test7
../sources/a.out ../sources/pipex.c "sort" "cat" outputs_bonus/test7_pipex

if diff -q outputs_bonus/test7 outputs_bonus/test7_pipex > /dev/null; then
    echo "Test 7: Passed"
else
    echo "Test 7: Failed"
fi

# Test 8: Search for "main" in ../sources/pipex.c
grep "main" ../sources/pipex.c > outputs_bonus/test8
../sources/a.out ../sources/pipex.c "grep main" "cat" outputs_bonus/test8_pipex

if diff -q outputs_bonus/test8 outputs_bonus/test8_pipex > /dev/null; then
    echo "Test 8: Passed"
else
    echo "Test 8: Failed"
fi

# Test 9: Count characters in ../sources/pipex.c
cat ../sources/pipex.c | wc -c > outputs_bonus/test9
../sources/a.out ../sources/pipex.c "cat" "wc -c" outputs_bonus/test9_pipex

if diff -q outputs_bonus/test9 outputs_bonus/test9_pipex > /dev/null; then
    echo "Test 9: Passed"
else
    echo "Test 9: Failed"
fi

# Test 10: Reverse contents of ../sources/pipex.c
tac ../sources/pipex.c > outputs_bonus/test10
../sources/a.out ../sources/pipex.c "tac" "cat" outputs_bonus/test10_pipex

if diff -q outputs_bonus/test10 outputs_bonus/test10_pipex > /dev/null; then
    echo "Test 10: Passed"
else
    echo "Test 10: Failed"
fi

# Test 12: Combine commands (e.g., sleep and echo)
ls -l ../sources/pipex.c | sleep 4 && echo "hello" > outputs_bonus/test12
../sources/a.out /dev/null "ls -l ../sources/pipex.c" "sleep 4 && echo hello" outputs_bonus/test12_pipex

if diff -q outputs_bonus/test12 outputs_bonus/test12_pipex > /dev/null; then
    echo "Test 12: Passed"
else
    echo "Test 12: Failed"
fi

# New Tests

# Test 13: Simple grep and word count
grep a1 < file1 | wc -w > outputs_bonus/test13
../sources/a.out file1 "grep a1" "wc -w" outputs_bonus/test13_pipex

if diff -q outputs_bonus/test13 outputs_bonus/test13_pipex > /dev/null; then
    echo "Test 13: Passed"
else
    echo "Test 13: Failed"
fi

# Test 14: Line count of a file
wc -l < file1 > outputs_bonus/test14
../sources/a.out file1 "cat" "wc -l" outputs_bonus/test14_pipex

if diff -q outputs_bonus/test14 outputs_bonus/test14_pipex > /dev/null; then
    echo "Test 14: Passed"
else
    echo "Test 14: Failed"
fi

# Test 15: Sorting a file
sort < file1 > outputs_bonus/test15
../sources/a.out file1 "sort" "cat" outputs_bonus/test15_pipex

if diff -q outputs_bonus/test15 outputs_bonus/test15_pipex > /dev/null; then
    echo "Test 15: Passed"
else
    echo "Test 15: Failed"
fi

# Test 16: Search and count characters
grep "pattern" < file1 | wc -c > outputs_bonus/test16
../sources/a.out file1 "grep pattern" "wc -c" outputs_bonus/test16_pipex

if diff -q outputs_bonus/test16 outputs_bonus/test16_pipex > /dev/null; then
    echo "Test 16: Passed"
else
    echo "Test 16: Failed"
fi

# Test 17: Reverse file contents
tac < file1 > outputs_bonus/test17
../sources/a.out file1 "tac" "cat" outputs_bonus/test17_pipex

if diff -q outputs_bonus/test17 outputs_bonus/test17_pipex > /dev/null; then
    echo "Test 17: Passed"
else
    echo "Test 17: Failed"
fi

# Test 18: Empty input file
touch empty_file
grep "anything" < empty_file | wc -w > outputs_bonus/test18
../sources/a.out empty_file "grep anything" "wc -w" outputs_bonus/test18_pipex

if diff -q outputs_bonus/test18 outputs_bonus/test18_pipex > /dev/null; then
    echo "Test 18: Passed"
else
    echo "Test 18: Failed"
fi

# Test 19: Non-existent command
../sources/a.out file1 "nonexistentcmd" "wc -l" outputs_bonus/test19_pipex 2> outputs_bonus/test19_err

if [ $? -ne 0 ] && [ -s outputs_bonus/test19_err ]; then
    echo "Test 19: Passed (handled error gracefully)"
else
    echo "Test 19: Failed"
fi
