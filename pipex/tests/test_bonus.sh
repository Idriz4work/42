#!/bin/sh

# BONUS TESTS

# Test 1: Count characters, then count words, then extract the first field
ls -l pipex.c | wc -c | wc -w | awk '{print $1}' > test_bonus1

# Test 2: Concatenate pipex.c and pipex.h, count lines, count words, and reverse
cat pipex.c pipex.h | wc -l | wc -w | tac > test_bonus2

# Test 3: List all files, sort, count lines, and extract the last field
ls -a | sort | wc -l | awk 'END {print}' > test_bonus3

# Test 4: Display first 10 lines of pipex.c, convert to uppercase, and count lines
head -n 10 pipex.c | tr '[:lower:]' '[:upper:]' | wc -l > test_bonus4

# Test 5: Find all .c files, count lines in each, sort by line count, and write to file
find . -name "*.c" | xargs wc -l | sort -n | tail -n 5 > test_bonus5

# Test 6: Search for "error" in pipex.c, count matches, reverse output, and display last line
grep "error" pipex.c | wc -l | tac | tail -n 1 > test_bonus6

# Test 7: Concatenate pipex.c, sort lines, count unique lines, and write to file
cat pipex.c | sort | uniq | wc -l > test_bonus7

# Test 8: List files, sort by size, take top 5, count words in filenames, and output
ls -l | sort -k5 -n | head -n 5 | awk '{print $NF}' | wc -w > test_bonus8

# Test 9: Search for a pattern in multiple files, count occurrences, and double-check count
grep "main" pipex.c pipex.h | wc -l | wc -c | awk '{print $1}' > test_bonus9

# Test 10: Count all files, list only unique extensions, count them, and write to file
ls -1 | awk -F. '{if (NF>1) print $NF}' | sort | uniq | wc -l > test_bonus10

# Test 11: List files, filter those with "pipex" in the name, and count them
ls -l | grep "pipex" | wc -l > test11

# Test 12: Concatenate pipex.c, convert to uppercase, and count words
cat pipex.c | tr '[:lower:]' '[:upper:]' | wc -w > test12

# Test 13: Find all .c files, count lines in each, and output the total count
find . -name "*.c" | xargs wc -l | awk '{total+=$1} END {print total}' > test13

# Test 14: Display the first 5 lines of pipex.c, reverse them, and count lines
head -n 5 pipex.c | tac | wc -l > test14

# Test 15: List all files, sort by size, and print the largest file
ls -l | sort -k5 -n | tail -n 1 > test15

# Test 16: Search for "main" in pipex.c, sort the matching lines, and print the first one
grep "main" pipex.c | sort | head -n 1 > test16

# Test 17: List files, display only filenames, and count unique filenames
ls -1 | sort | uniq | wc -l > test17

# Test 18: Combine pipex.c and pipex.h, count lines, and output the result
cat pipex.c pipex.h | wc -l | awk '{print $1}' > test18

# Test 19: Search for "return" in pipex.c, count matches, and output the count
grep "return" pipex.c | wc -l > test19

# TEST 20
cat file1 | ls | wc | awk '{printf("aviye")}' | echo ok | ls | cat | wc -l  > test20
