#include<stdio.h>
#define MAX 20
struct STACK
{
    int TOS ;
    chat data[MAX];
};
void push(struct STACK*, char);
char pop(struct STACK*)
int priority(char);

int main()
{
    struct STACK temp = {-1};
    struct STACK output = {-1};
    char infix[MAX]; 
    char gbg, operator;
    int i=0;
    print("Enter infix expression:");
    fgets(infix, MAX, stdin);

    while (infix[i] != '\n')
    {
        switch (infix[i])
        {
        case '(':
            push(&temp, '(');
            break;
        case ')' :
        while(temp.data[top.TOS] != '(')
        {
            gbg = pop(&temp);
            push(&output,gbg);
        }
        gbg = pop(&temp);
        break;

      case'+':
      case'-':
      case'*':
      case'/':
      case'^':
          operator = infix[i];
          while (priority(temp.data[temp.TOS]) >= priority(operator))
          {
            gbg = pop(&temp);
            push(&output, gbg);
          }
          push(&temp, operator);
          break;
          
        default:
          push(&output, infix[i]);
          break;

        }
        i += 1;
    }
    while (temp.TOS != -1)
    {
        gbg = pop(&temp);
        push(&output, gbg);
    }
    printf("the Postfix expression is %s ", output.data);
    print("\n");
    
    return 0;
}
    
    



