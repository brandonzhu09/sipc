# Challenges
- One of my biggest challenges in this deliverable is completing the codegen functions for the Array construction and for loops. The array construction codegen function was difficult because there needed to be a way to determine the size of the array so that it can be used with the Array length prefix expression. My implementation was to reserve the first element in the array to be the length of the array so that the value can be accessed directly from the R-value of the array pointer.
- I ran into failing system tests for the logical not expression which I realized required a logical not computation, not a bitwise not operation that I was using before.

My approach to testing and achieving high code coverage is by writing system tests that cover all the new SIP features added, starting with simple cases but also adding more complex cases to look for any issues with lValue or rValue generation, etc. 

