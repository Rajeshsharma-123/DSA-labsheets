def precedence(opr):
    if opr == '^':
        return 3
    elif opr in ['*', '/']:
        return 2
    elif opr in ['+', '-']:
        return 1
    elif opr == '(':
        return 0
    return -1

def infix_to_postfix(expression):
    stack = []
    output = []
    elements = expression.split()

    for element in elements:
        if element not in ['^', '*', '/', '+', '-', '(', ')']: 
            output.append(element)
        elif element == '(':
            stack.append(element)  
        elif element == ')':
            # Pop until '(' is encountered
            while stack and stack[-1] != '(':
                output.append(stack.pop())
            stack.pop()  # Pop the '(' from the stack
        else:  # Operator
            # While the top of the stack has an operator with higher or equal precedence
            while (stack and precedence(stack[-1]) >= precedence(element)):
                output.append(stack.pop())
            stack.append(element)

    # Pop and append to output , until stack is empty 
    while stack:
        output.append(stack.pop())

    return ' '.join(output)    # the output is an list . so join() function concatenates all list items separated by a whitespace

infix_expr = input("Enter infix expression: ")
postfix_result = infix_to_postfix(infix_expr)
print(f"The postfix expression is: {postfix_result}")
