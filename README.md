# ft_printf

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
