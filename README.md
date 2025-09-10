# ft_printf Opus 4.1 version

## Project overview

This project implements a custom version of the C standard library's `printf()` function, following the strict coding standards of École 42's Norm.

## Implementation status

### Completed features

All mandatory requirements have been successfully implemented:

1. **Core functionality**
   - Created `libftprintf.a` static library
   - Implemented `ft_printf()` function with variadic argument handling
   - Return value matches the number of characters printed

2. **Supported conversions**
   - `%c` - Single character printing
   - `%s` - String printing (with NULL handling)
   - `%p` - Pointer address in hexadecimal format (with "0x" prefix, "(nil)" for NULL)
   - `%d` - Signed decimal integer
   - `%i` - Signed integer (same as %d)
   - `%u` - Unsigned decimal integer
   - `%x` - Hexadecimal lowercase
   - `%X` - Hexadecimal uppercase
   - `%%` - Literal percent sign

3. **File structure**
   - `ft_printf.h` - Header file with function prototypes
   - `ft_printf.c` - Main function with format string parsing
   - `ft_printf_utils.c` - Basic output functions (putchar, putstr)
   - `ft_printf_numbers.c` - Numeric conversion functions (integers)
   - `ft_printf_hex.c` - Hexadecimal and pointer conversion functions
   - `Makefile` - Build system with all required rules

4. **Norm compliance**
   - All functions are under 25 lines
   - All lines are under 80 columns
   - Proper indentation with tabs
   - Snake_case naming convention
   - Proper 42 header in all files
   - No more than 5 functions per file
   - No more than 5 variables per function
   - No more than 4 parameters per function

5. **Edge cases handled**
   - NULL string prints "(null)"
   - NULL pointer prints "(nil)" 
   - INT_MIN and INT_MAX handled correctly
   - Zero values handled for all numeric types

## Build instructions

```bash
# Compile the library
make

# Clean object files
make clean

# Clean everything including the library
make fclean

# Rebuild from scratch
make re
```

## Testing

The implementation has been tested against the original `printf()` for:
- All supported conversion specifiers
- Edge cases (NULL, INT_MIN, INT_MAX, zero values)
- Return value accuracy
- Mixed format strings with multiple conversions

## What remains

Nothing - the project is complete and ready for submission. All mandatory requirements have been fulfilled according to the assignment specifications and Norm requirements.

## Notes

- The implementation does not include printf's buffer management (as specified)
- No bonus features were implemented (flags, width, precision, etc.)
- The library can be integrated into libft after successful evaluation
