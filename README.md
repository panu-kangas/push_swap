# 🔢 PUSH_SWAP 🔢

A sorting algorithm project made by Panu Kangas.  
Assignment provided by Hive Helsinki coding school.  
Project is written in C-language on macOS.

<br/>  

# How to use? 🤔

NOTE:  
This project works definitely on macOS and most likely on Linux (haven't tested that yet).  
It will not work on Windows, sadly 🙁


Git clone the push_swap repository and ```cd``` into it.  
Do ```make all``` in the directory to compile my push_swap program.  
Do ```make bonus```in the directory to compile my checker program.  

Other Makefile rules:

- ```make clean```--> remove all object files
- ```make fclean```--> remove all object files + executables
- ```make re```--> do fclean + all

<br/>  

# The original assignment 📎

The main idea of push_swap project is quite simple: you have to write a program that arranges random numbers (integers) into ascending order using a strict set of rules and operations.
Rules and operation details are listed in later segments of this Readme.

Initially you have two stacks: Stack A and Stack B.
Stack A is filled with random numbers, Stack B is empty.
In the end, if all went as it should, Stack A should have all of the original numbers in ascending order and Stack B should be empty.

The push_swap program is supposed to analyze numbers of Stack A and then produce a list of operations (the smallest list possible) to do this sorting. Eventually the operation list generated by push_swap is compared to a certain "operation count limit". Push_swap project is then graded based on this comparison.  
Info about operation count limits can be found in later segments of this Readme.

<br/>

🏆 BONUS 🏆  

The bonus part of this assignment was to write a checker program, that takes the numbers of Stack A as arguments and then waits (reading from standard input) for a list of operations. Finally it should perform these instructions to the Stack A and print "OK" if numbers were sorted after the operation execution.
If not, it should print "KO".  If input was incorrect, it shold print "Error".

<br/>

### Operations to do the sorting 📑

Push_swap can only use these operations to sort the numbers in Stack A:

↕️ SA (swap a): Swap the first 2 elements of Stack A.  
↕️ SB (swap b): Swap the first 2 elements of Stack B.  
↕️↕️ SS (swap both): Do sa and sb at the same time. This is counted as one move.   

➡️ PA (push to a): Take the first element of Stack B and put it as the first element of Stack A (moving the former first element of A to the second position of A etc).  
➡️ PB (push to b): Take the first element of Stack A and put it as the first element of Stack B (moving the former first element of B to second position of B etc).  

⤴️ RA (rotate a): Move "forwards" all elements of Stack A by 1 (former second element becomes first, former third element becomes second etc). The first element of A becomes the last element of A.  
⤴️ RB (rotate b): Move "forwards" all elements of Stack B by 1 (former second element becomes first, former third element becomes second etc). The first element of B becomes the last element of B.  
⤴️⤴️ RR (rotate both): Do ra and rb at the same time. This is counted as one move.  

⤵️ RRA (reverse rotate a): Move "backwards" all elements of Stack A by 1 (former first element becomes second, former second element becomes third etc).
  The last element of A becomes the first element of A.  
⤵️ RRB (reverse rotate b): Move "backwards" all elements of Stack B by 1 (former first element becomes second, former second element becomes third etc).
  The last element of B becomes the first element of B.  
⤵️⤵️ RRR (reverse rotate both): Do rra and rrb at the same time. This is counted as one move.  

<br/>

### Operation count limits 🧮

Here are the operation count limits for push_swap project's maximum points.   
If push_swap program can do the sorting of Stack A within these limits, the program is awarded full 100/100 points 😎

| Stack size  | Operation count limit |
| ------------- | ------------- |
| 3 numbers | 3 operations max |
| 5 numbers | 12 operations max (if 8 or less, kudos) |
| 100 numbers | less that 700 operations |
| 500 numbers | less than 5500 operations |  

<br/>

### Rules for push_swap assignment 🛑

- Numbers are given to the program as command line arguments.
- First number given is the first number of Stack A, second number given is the second number of Stack A etc.
- Numbers can be given in two formats: one number per argument (```./push_swap 1 2 3```) or all numbers in one argument-string (```./push_swap "1 2 3"```)
- Numbers have to fit in an int variable.
- No duplicate numbers allowed.
- Program should write "Error" if these rules are broken (dupicate number found etc)

<br/>

# What ideas/sorting algorithms I used? 🧠

1️⃣ I used an idea that follows the principles of <ins>insertion sort</ins> to do the actual final sorting.
  An example:  
  
  If I had a number X as the first element of Stack B, and I wanted to sort that into Stack A, I'd used my *sort_b_to_a* -function.
  *Sort_b_to_a* first finds the correct position for the number X in stack A, then rotates stack A so that when I push the number X on top of stack A it is moved to it's correct position.
  "Correct position" in this case means a position where the number after X is greater than X and the number before X is smaller than X.
  This is because eventually we want the numbers of Stack A to be in ascending order.  
  
  If we just loop this idea and in the end rotate Stack A so that the smallest number is in the first position, we should get us a nicely sorted stack 😎

2️⃣ The insertion sort alone couldn't get me the full points, because it is very inefficient with bigger stack sizes. So I also used <ins>divide and conquer</ins> kind of logic with bigger stacks.  
Most of the times I would just break down the Stack A numbers into smaller segments, just to make the insertion sort more efficient.
For example:  

A stack of 100 numbers is quite easy to break down into segments of 12 numbers.  
So after this operation, 12 biggest numbers of the original stack are right next to each other (in a segment), then after that the next 12 biggest numbers in a separate segment etc.

<br/>

### The steps of sorting 👣

I made my algorith behave a bit differently depending on the size of the initial Stack A. Here is a short walkthrough of my algrithms inner logic:  

🔢 **1-3 numbers**

- Hard coded solutions
- With a stack of 1 nothing needs to be done

🔢🔢 **4-20 numbers (sort_small)**

- First loop through the whole Stack A and use insertion sort to arrange (all but the 3 biggest) numbers to Stack B.
- Then use the previously hard coded solutions to sort the 3 biggest numbers (which are still in Stack A)
- Then move all sorted numbers from Stack B to Stack A.
- Finally rotate Stack A to get the smallest number on top.

🔢🔢🔢 **21-320 (sort_mid)**

- First divide the Stack A numbers into 8 segments (divide and conquer) by moving them two segments at a time into Stack B.
- Division to 8 segments might leave me with a modulus value.
  --> If so, the "modulus amount of numbers" is left in Stack A. Now I sort them using sort_small logic.
- Then I use insertion sort to sort all the numbers from Stack B to Stack A. Because numbers are now close to their final position, this happenss quite efficiently.
- Finally rotate Stack A to get the smallest number on top.

🔢🔢🔢🔢 **321--> (sort_big)**

Yeah... this was a bit difficult to do with my approach 😆  
But this is what happened in a nutshell:

- First divide the Stack A numbers into x amoount of segments that have a size of 100 numbers (with 500 numbers we have 5 segments). We divide the segments by moving them one at a time into Stack B.
- Then we move all the numbers back to Stack A, and so we have Stack A filled with 100 number segments.
- Now we sort the numbers one 100 number segment at a time using the sort_mid logic.
- When one segment is sorted, we rotate past it to get to the next 100 number segment. Then we sort_mid that.
- We continue this until no segments are left. There might also be a sort the "reminder" (modulus) set of numbers at the bottom of Stack A. We sort that in the end.

This final sort_big algo was a bit too difficult to implement. I mean, it is not nice and neat, and has maybe too many steps along the way to be easily followed...  
But it did the job, so I'm happy 😁

### The bonus 🏆

The bonus part's source files can be found in the "bonus" repository.  

The easiest way to test it is using a pipe:  
./push_swap SOME_NUMBERS  |  ./checker SOME_NUMBERS  

For example:  
```./push_swap 5 4 3 2 1 | ./checker 5 4 3 2 1```  
The program then prints "OK" if the push_swap program works, and "KO" if it doesn't 😁
