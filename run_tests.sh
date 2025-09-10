#!/bin/bash

# Compile with coverage
echo "Compiling test suite with coverage..."
gcc -Wall -Wextra -Werror --coverage -o test_runner test_main.c \
    ft_printf.c ft_printf_utils.c ft_printf_numbers.c ft_printf_hex.c

# Run tests
echo "Running tests..."
./test_runner > test_output.txt 2>&1

# Generate coverage report
echo -e "\n=== COVERAGE REPORT ==="
gcov test_runner-ft_printf.gcda test_runner-ft_printf_utils.gcda \
     test_runner-ft_printf_numbers.gcda test_runner-ft_printf_hex.gcda

# Clean up coverage files
rm -f *.gcda *.gcno *.gcov

echo -e "\nTest output saved to test_output.txt"