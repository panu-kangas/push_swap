# PUSH_SWAP

A sorting algorithm project made by Panu Kangas.
Assignment provided by HIVE Helsinki coding school.

# Assignment

The main idea of push_swap assignment is quite simple: you have to write a program that arranges random numbers (integers) to an ascending order using a certain set of rules and instructions.

Initially you have two stacks: Stack A and Stack B.
Stack A is filled with random numbers, Stack B is empty.
In the end, if all went as it should, Stack A should have all the numbers in an ascending order and Stack B should be empty.

The push_swap program is supposed to analyze the numbers in Stack A and produce the smallest possible list of instructions/operations (listed below) to sort the numbers of Stack A.


## General rules of Hive (that affect the code):

- Hive students must follow a "Norm" when it comes to writing code. Norm determines certain rules for code layout. Two examples from the Norm:
  --> One function can only have a maximum of 25 lines of code.
  --> One .c file can only have up to 5 functions.
    Because of these rules I have made some "not so convenient" tricks with my syntax and program flow.
- Almost all of the regular C library functions are forbidden (printf, strlen etc).
  --> This is why my code utilizes Libft-library which is written by me. It consists of my own versions of these must-have functions (ft_printf, ft_strlen etc)

## Rules for the assignment:

- Numbers are given to the program as command line arguments.
- First number given is the first number of Stack A, second number given is the second number of Stack A etc.
- Numbers can be given in two formats: one number per argument (```./push_swap 1 2 3```) or all numbers in one argument-string (```./push_swap "1 2 3"```)
- Numbers have to fit in an int variable.
- No duplicate numbers allowed.

## Instructions for sorting:

You are allowed to use only these instructions/operations to sort the Stack A numbers:

- sa (swap a): Swap the first 2 elements of Stack A. Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of Stack B. Do nothing if there is only one or no elements.
- ss: Do sa and sb at the same time.

- pa (push to a): Take the first element of Stack B and put it to the first position of Stack A (moving the former first number of A to second position of Aetc).
  Do nothing if B is empty.
- pb (push to b): Take the first element of Stack A and put it to the first position of Stack B (moving the former first number of B to second position of B etc).
  Do nothing if A is empty.

- ra (rotate a): Move "forward" all elements of Stack A by 1 (former second becomes first, former third becomes second etc). The first element becomes the last one.
- rb (rotate b): Move "forward" all elements of Stack B by 1 (former second becomes first, former third becomes second etc). The first element becomes the last one.
- rr: Do ra and rb at the same time.

- rra (reverse rotate a): Move "backwards" all elements of Stack A by 1 (former first becomes second, former second becomes third etc).
  The last element becomes the first one.
- rrb (reverse rotate b): Move "backwards" all elements of Stack B by 1 (former first becomes second, former second becomes third etc).
  The last element becomes the first one.
- rrr: Do rra and rrb at the same time.
