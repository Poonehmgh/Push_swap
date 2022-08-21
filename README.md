# Push_swap

V.1 The rules
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.

+++++++

V.1 The rules
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.


+++++++


Program name:
  push_swap
Turn in files:
  Makefile, *.h, *.c
Makefile:
  NAME, all, clean, fclean, re
Arguments:
  stack a: A list of integers
External functs.
  • read, write, malloc, free, exit
  • ft_printf and any equivalent YOU coded
Libft authorized:
  Yes
Description:
  Sort stacks
  
 ++++++++
 
 My approach: 
 
  1. Before everything, I calculate the actual indexes of each element in the order. So I sort the elements and according to          their order of magnitude I give them indexes. (the smallest number is 0 and the biggest is input amount)
  2. I push all the elements (except the last three) from stack A to stack B.
  3. Then I sort stack A (the 3 elements).
  4. Then I calculate the desired position of stack B items in stack A according to their index (step 1)
  5. Then I calculate the cost of moving each element to the desired location. 
  6. Then I find the element with minimum cost. 
  7. Then I execute some rotations / reverse rotations to put the minimum costelement in the right place in stack B. 
  8. Then I update from step 4 and do this until nothing is left in B. 
  9. Then I do the final rotation in A so they become in the right order. 
  
  +++++++
  
  My grade: 
    grade 5 for 100 numbers 
    grade 4 for 500 numbers
    
  ++++++++
  
  a good guide: 
  
  https://www.codequoi.com/en/push_swap-efficient-positional-sorting-algorithm/
  
  
  
  
