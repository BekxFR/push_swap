# Push_swap Algorithm Exercise


|    Project Name    |                                                                       push_swap                                                                      |
| :----------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------: |
|    Description     |                                             A sorting algorithm using stacks with a limited set of instrutions and using the lowest possible number of actions                                              |
|    Technologies    | <a href="#"><img alt="C" src="https://custom-icon-badges.demolab.com/badge/C-03599C.svg?logo=c-in-hexagon&logoColor=white&style=for-the-badge"></a> |
| External libraries |     read(), write(), malloc(), free(), exit()      |

#### Usage

```bash
  gcl https://github.com/trobert42/push_swap.git
  cd push_swap
  make
  ./push_swap [list of numbers]
```


### This project entails sorting data in a stack using a restricted set of instructions while minimizing the number of operations. The main tasks involve:

   1. Implementing efficient sorting algorithms tailored to the restricted instruction set.
   2. Practicing C programming by writing clean, efficient, and well-structured code.
   3. Understanding and managing algorithmic complexity to optimize sorting performance.


### More specifically, you are required to:

- Develop a program named push_swap that takes a stack of integers as input and outputs the shortest sequence of instructions needed to sort the stack.
- The instructions allowed for sorting include sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, and rrr. Each instruction corresponds to a specific manipulation of the stack elements.
- Ensure that the program outputs the sequence of instructions separated by newline characters.
- Aim to minimize the number of operations required to sort the stack, as the efficiency of your sorting algorithm will be evaluated.
- Implement error handling to detect and report any issues with the input data or the program's execution.

### Additionally, there's a bonus task:

- Develop a program named checker that verifies whether the sequence of instructions output by push_swap correctly sorts the stack.
- The checker program should take the initial stack and the sequence of instructions as inputs and output either "OK" if the stack is sorted correctly or "KO" if not.
- Handle potential errors gracefully, providing appropriate error messages if the input data or instructions are invalid.

By completing these tasks, you will gain valuable experience in algorithm design, C programming, and algorithmic complexity analysis.
