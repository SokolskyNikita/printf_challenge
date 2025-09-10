# ft_printf GPT-5-Pro version 

Minimal `printf` reimplementation producing a static library `libftprintf.a`.

## What is implemented

- Core `ft_printf(const char *fmt, ...)` with sequential scan, no buffering.
- Conversions supported: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.
- Helper utilities: `ft_strlen`, generic unsigned base printer.
- Makefile targets: `all` (default), `clean`, `fclean`, `re`, `bonus`.

## How to build

```bash
make
```

This creates `libftprintf.a` at the repository root.

## How to test and get coverage

```bash
make test      # builds and runs tests
make coverage  # enforces 100% line coverage with gcov
```

Notes:
- Coverage uses gcc/gcov; the Makefile cleans stale gcov artifacts and enforces 100% by scanning for unexecuted lines.

## Sample programs

Build and run examples:

```bash
make samples
./samples/basic
./samples/edge
```

## Files layout

- `ft_printf.h`: public API and prototypes.
- `src/ft_printf.c`: dispatcher and main formatting loop.
- `src/print_char_str.c`: `%c`, `%s`, `%%`.
- `src/print_signed.c`: `%d`, `%i`.
- `src/print_unsigned.c`: `%u`.
- `src/print_hex.c`: `%x`, `%X`.
- `src/print_pointer.c`: `%p` with `0x` prefix.
- `src/print_base.c`: generic unsigned base printer.
- `src/utils.c`: `ft_strlen`.

## Norm compliance notes

- No forbidden constructs (no for/while without braces violations, no ternaries, no VLAs, no switch/goto).
- Max 5 functions per `.c` file respected.
- Each function under 25 lines (excluding braces).
- Headers guarded and includes limited.
- Up to 4 parameters per function.

## What remains

- Optional: add more tests in `tests/` (not required by the subject).

Everything required by the subject is implemented.
