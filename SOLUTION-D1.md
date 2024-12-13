## Challenges
- Understanding that the array element reference operator is an expression, not a statement, therefore it cannot stand on its own as a statement in the program
- Using C++ references to determine the right operator precedence for the grammar rules
- Writing operator precedence tests using the helper methods in ParserHelper to compare correct parse trees according to precedence rules

Overall, I modeled my approach in creating grammar rules and unit tests after the existing TIP code structure. Especially for the unit testing, I took inspiration from the unit tests in the `TIPParserTest` for testing operator precedence and determining that lexically and syntactically incorrect programs will be caught during lexical analysis and parsing. 

While I had an operator precedence test for arithmetic operations for the modulo operator that was added into the SIP language, I also had a test for logical operators, where I tested expressions like `not true or false` to ensure that `not` has higher precedence than `or`. The expected parse tree here, `(expr (expr not (expr true)) or (expr false))`, confirms that the parser first applies the `not` operator to `true` before evaluating the `or` operation. 