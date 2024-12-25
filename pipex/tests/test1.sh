#!/bin/sh

# Basic Tests

# TEST STANDARD
cat file1 | grep a1 | wc -w > testSTANDARD

# Test 1: Count lines in pipex.c and write to test1
cat pipex.c | wc -l > test1

# Test 2: List files in the current directory and write the count to test2
ls -l | wc -l > test2

# Test 3: Concatenate contents of pipex.c and append a file listing to test3
(cat pipex.c && ls -l) > test3

# Test 4: Show the first 5 lines of pipex.c and write to test4
head -n 5 pipex.c > test4

# Test 5: Count words in pipex.c and write to test5
cat pipex.c | wc -w > test5

# Test 6: Sort the contents of pipex.c and write to test6
sort pipex.c > test6

# Test 7: Search for "main" in pipex.c and write matching lines to test7
grep "main" pipex.c > test7

# Test 8: Count characters in pipex.c and write to test8
cat pipex.c | wc -c > test8

# Test 9: Reverse the contents of pipex.c and write to test9
tac pipex.c > test9

# Test 10: Display file permissions of pipex.c and write to test10
ls -l pipex.c | awk '{print $1}' > test10


ls -l pipex.c | sleep 4 | echo hello > test11
