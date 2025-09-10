# Testing and Compliance Report

## 100% Line Coverage Achieved ✅

All source files have been tested with 100% line coverage:

- `ft_printf.c`: **100.00%** of 33 lines
- `ft_printf_utils.c`: **100.00%** of 12 lines  
- `ft_printf_numbers.c`: **100.00%** of 16 lines
- `ft_printf_hex.c`: **100.00%** of 24 lines

**Total: 100.00% of 85 lines covered**

## Norminette Compliance ✅

All source files pass norminette v3.3.59 checks:

```
ft_printf.c: OK!
ft_printf_utils.c: OK!
ft_printf_numbers.c: OK!
ft_printf_hex.c: OK!
ft_printf.h: OK!
```

## Test Suite

The comprehensive test suite (`test_main.c`) covers:

- **Character format** (`%c`) - various ASCII characters
- **String format** (`%s`) - normal strings, empty strings, NULL
- **Pointer format** (`%p`) - valid pointers, NULL, edge cases
- **Integer formats** (`%d`, `%i`) - positive, negative, zero, INT_MIN, INT_MAX
- **Unsigned format** (`%u`) - various values including UINT_MAX
- **Hexadecimal lowercase** (`%x`) - various values including 0 and UINT_MAX
- **Hexadecimal uppercase** (`%X`) - various values including 0 and UINT_MAX
- **Percent literal** (`%%`) - single and multiple percent signs
- **Edge cases**:
  - NULL format string (returns -1)
  - Empty format string
  - Format string ending with `%`
  - Invalid format specifiers
  - Mixed format combinations

## Running Tests

To run the test suite with coverage:

```bash
./run_tests.sh
```

This script will:
1. Compile the test suite with coverage flags
2. Run all tests
3. Generate and display the coverage report
4. Clean up temporary files

## Compliance with 42 Norm

The code strictly follows the 42 School Norm v4.1:

- ✅ Functions are max 25 lines
- ✅ Lines are max 80 columns
- ✅ Proper indentation with tabs
- ✅ Correct brace placement
- ✅ Proper variable declarations
- ✅ No forbidden constructs (for, do-while, switch, ternary, VLA)
- ✅ Max 5 functions per file
- ✅ Max 5 variables per function
- ✅ Max 4 parameters per function
- ✅ Proper 42 header on all files
- ✅ Header guards in .h file
- ✅ Snake_case naming conventions