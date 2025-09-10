# ft_printf

## Because ft_putnbr() and ft_putstr() aren't enough

*Summary: The goal of this project is quite straightforward: you will reimplement `printf()`. This will primarily teach you how to handle a variable number of arguments. How cool is that? Actually, it's pretty cool! :)*

*Version: 11.0*

# Chapter I

## Introduction

You will explore one of the most popular and versatile functions in C: `printf()`. This exercise provides an excellent opportunity to improve your programming skills. It is considered moderately difficult.

You will discover **variadic functions** in C.

The key to a successful `ft_printf` is well-structured and extensible code.

Once you have successfully completed this assignment, you will be allowed to add your `ft_printf()` to your `libft`, making it available for use in your school C projects.

# Chapter II

## Common Instructions

- Your project must be written in C.
- Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check, and you will receive a 0 if there is a norm error.
- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc.) except for undefined behavior. If this occurs, your project will be considered non-functional and will receive a 0 during the evaluation.
- All heap-allocated memory must be properly freed when necessary. Memory leaks will not be tolerated.
- If the subject requires it, you must submit a Makefile that compiles your source files to the required output with the flags `-Wall`, `-Wextra`, and `-Werror`, using `cc`. Additionally, your Makefile must not perform unnecessary relinking.
- Your Makefile must contain at least the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`.
- To submit bonuses for your project, you must include a `bonus` rule in your Makefile, which will add all the various headers, libraries, or functions that are not allowed in the main part of the project. Bonuses must be placed in `_bonus.{c/h}` files, unless the subject specifies otherwise. The evaluation of mandatory and bonus parts is conducted separately.
- If your project allows you to use your `libft`, you must copy its sources and its associated Makefile into a `libft` folder. Your project's Makefile must compile the library by using its Makefile, then compile the project.
- We encourage you to create test programs for your project, even though this work **does not need to be submitted and will not be graded**. It will give you an opportunity to easily test your work and your peers' work. You will find these tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to the assigned Git repository. Only the work in the Git repository will be graded. If Deepthought is assigned to grade your work, it will occur after your peer-evaluations. If an error happens in any section of your work during Deepthought's grading, the evaluation will stop.

# Chapter III

## Mandatory part

| Program name     | `libftprintf.a`                                                                             |
|------------------|---------------------------------------------------------------------------------------------|
| Turn in files    | `Makefile`, `*.h`, `*/*.h`, `*.c`, `*/*.c`                                                    |
| Makefile         | `NAME`, `all`, `clean`, `fclean`, `re`                                                        |
| External functs. | `malloc`, `free`, `write`,<br>`va_start`, `va_arg`, `va_copy`, `va_end`                       |
| Libft authorized | Yes                                                                                         |
| Description      | Write a library that contains `ft_printf()`, a function that will mimic the original `printf()` |

You have to recode the `printf()` function from libc.

The prototype of `ft_printf()` is:

```c
int ft_printf(const char *, ...);
```

Here are the requirements:

- Do not implement the original `printf()`'s buffer management.
- Your function has to handle the following conversions: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`.
- Your implementation will be evaluated against the behavior of the original `printf()`.
- You must use the command `ar` to create your library. The use of the `libtool` command is strictly forbidden.
- `libftprintf.a` must be created at the root of your repository.

You have to implement the following conversions:

- `%c` Prints a single character.
- `%s` Prints a string (as defined by the common C convention).
- `%p` The `void *` pointer argument has to be printed in hexadecimal format.
- `%d` Prints a decimal (base 10) number.
- `%i` Prints an integer in base 10.
- `%u` Prints an unsigned decimal (base 10) number.
- `%x` Prints a number in hexadecimal (base 16) lowercase format.
- `%X` Prints a number in hexadecimal (base 16) uppercase format.
- `%%` Prints a percent sign.

# Chapter IV

## Submission and peer-evaluation

Submit your assignment in your Git repository as usual. Only the work inside your repository will be evaluated during the defense. Don't hesitate to double-check the names of your files to ensure they are correct.

Once you have completed this assignment, you will be allowed to add your `ft_printf()` to your `libft`, enabling its use in your school C projects.

During the evaluation, a brief **modification of the project** may occasionally be requested. This could involve a minor behavior change, a few lines of code to write or rewrite, or an easy-to-add feature.

While this step may **not be applicable to every project**, you must be prepared for it if it is mentioned in the evaluation guidelines.

This step is meant to verify your actual understanding of a specific part of the project. The modification can be performed in any development environment you choose (e.g., your usual setup), and it should be feasible within a few minutes — unless a specific timeframe is defined as part of the evaluation.

You can, for example, be asked to make a small update to a function or script, modify a display, or adjust a data structure to store new information, etc.

The details (scope, target, etc.) will be specified in the **evaluation guidelines** and may vary from one evaluation to another for the same project.
