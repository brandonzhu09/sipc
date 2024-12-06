## Selecting Optimizations
Finding which optimizations to choose was influenced by how effectively it can be extended over to a TIP program and figuring out how to write a program that makes the most of the optimization being performed.

I had to experiment with the input size a lot when executing optimized and non-optimized programs to find a considerable difference in runtime between the two programs. In order to do that, I needed to make sure that the TIP program also needs to scale in time complexity with the input size so the runtimes are not negligible for optimized and non-optimized programs.

## Dead Code Elimination (DCE)
### Description
Dead Code Elimination (DCE) is a crucial optimization for simplifying programs by removing computations and instructions that have no impact on the program's observable behavior, such as its outputs or side effects. My reasons for selecting DCE involves its ability to:

- Identify variables and computations whose results are not used in determining the program’s final output and eliminate them.
- Detect instructions that have no side effects and contribute nothing to the final return value or state and eliminate them.

### **Evidence Supporting the Benefits of DCE**

- When running a DCE pass, benchmark results for the optimized program was about 5.38x faster between optimized and unoptimized passes of the same program.
- Original assembly includes operations for calculating `a = a + b`, `c = a - b`, and `d = a * b`, which were no longer present in the optimized assembly. None of these affect the program's output, which is only dependent on `b`.
- Removing dead computations resulted in a smaller code size, which translated to faster compilation and reduced memory usage during execution.

## Sparse Conditional Constant Propagation (SCCP)
### Description
Sparse Conditional Constant Propagation (SCCP) is an optimization that combines constant propagation and dead code elimination by analyzing code to identify constant values and unreachable code paths. It works efficiently by tracking the flow of constants through variables and determining whether certain code blocks will execute based on conditions. SCCP is a powerful optimization because it simplifies code, reduces runtime overhead, and removes unnecessary computations, making programs faster and smaller. It is particularly effective in handling branch-heavy code and simplifying control flow by replacing conditional expressions with their resolved outcomes.
### **Evidence Supporting the Benefits of SCCP**

- When running a SCCP pass paired with DCE, benchmark results for the optimized program showed about a 1.386 second improvement or about 2.67x faster than the unoptimized program.

## Inline Pass
The Inline Pass in LLVM is an optimization technique that aims to replace function calls with the body of the called function. This pass works by inlining small functions into the caller's code, eliminating the overhead of a function call (such as the stack manipulation, jumping to the function, and returning) and potentially improving the performance of the program.
### **Evidence Supporting the Benefits of Inline Pass**

- When running an Inline pass paired with SCCP and DCE, benchmark results for the optimized program showed about a 1.437 second improvement in performance between optimized and unoptimized passes of the same program.

## Loop Unrolling
### Description
Loop unrolling is an optimization that reduces the overhead of loop control by decreasing the number of iterations executed and increasing the amount of work done per iteration. My reasons for selecting Loop Unrolling involves its ability to reduce the significant overhead of loop control in a high-iteration loop, such as branch instructions.

### Evidence Supporting the Benefits of Loop Unrolling
- When running a Loop Unrolling pass paired with SCCP, benchmark results for the optimized program showed about a 2.813 second improvement and about 2.76x faster than the unoptimized program.

## Tail Call Elimination
### Description
Tail call elimination (TCE) is a compiler optimization that replaces the stack frame of a function with that of its tail call when the last operation of the function is a call to another function, often itself in recursive cases. This optimization prevents the creation of new stack frames for each call, thereby avoiding excessive stack growth and the risk of stack overflow during deep recursion. By reusing the current stack frame, TCE allows recursive functions to run in constant stack space, making them as efficient as iterative solutions while maintaining the clarity and expressiveness of recursion.

### Evidence Supporting the Benefits of Tail Call Elimination
- The primary optimization that I saw with Tail Call Elimination (TCE) was its improvement in reducing stack space and lowering the risk of stack overflow for long recursive calls. In my benchmarks, when I called the recursive function in my TIP program with input size of 1000000, the unoptimized program led to a segmentation fault, likely due to stack overflow. However, when executing the optimized TIP program with the same input size, it was able to terminate successfully.   


