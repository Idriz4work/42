# Push Swap

A project that implements an efficient sorting algorithm using two stacks and a limited set of operations.

## Overview

Push Swap is a sorting algorithm project that challenges you to sort a stack of integers using two stacks (A and B) and a specific set of operations. The goal is to sort all numbers in stack A in ascending order while minimizing the number of operations used.

## How it Works

The program takes a list of integers as input in stack A, with stack B initially empty. Using a combination of push, swap, and rotate operations, the program must sort all numbers in ascending order in stack A, with stack B empty at the end.

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first 2 elements at the top of stack A |
| `sb` | Swap first 2 elements at the top of stack B |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Push top element from stack B to stack A |
| `pb` | Push top element from stack A to stack B |
| `ra` | Rotate stack A up (first element becomes last) |
| `rb` | Rotate stack B up (first element becomes last) |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | Execute `rra` and `rrb` simultaneously |

## Implementation Details

The program:
1. Takes a list of integers as input
2. Can optionally normalize/index the numbers for easier handling
3. Implements all required stack operations
4. Uses an efficient sorting algorithm to minimize operations
5. Outputs the sequence of operations needed to sort the stack

## Example

Initial state:
```
Stack A: 2 1 3 6 5 8
Stack B: (empty)
```

After some operations:
```
Stack A: 1 2 3 5 6 8
Stack B: (empty)
```

The program outputs the sequence of operations performed to achieve the sort.

## Algorithm Considerations

- The chosen algorithm should minimize the number of operations
- Different approaches may be needed for different input sizes
- Optimization is crucial for performance benchmarks
- Numbers can be normalized/indexed to simplify the sorting process

## Installation & Usage

```bash
# Compile
make

# Run with a list of integers
./push_swap 4 67 3 87 23

# Check if the solution is valid (bonus)
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

## Bonus: Checker Program

The checker program validates the sorting operations:
- Takes the same integer list as input
- Reads and executes sorting operations
- Displays "OK" if the stack is properly sorted
- Displays "KO" if the stack is not sorted
- Displays "Error" for invalid inputs

## Contributing

Feel free to submit issues and enhancement requests or follow these steps to contribute:
1. Fork the project
2. Create your feature branch
3. Commit your changes
4. Push to the branch
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details 
