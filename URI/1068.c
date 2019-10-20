#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

typedef struct
{
  int top;
  char characters[MAX];
}
Stack;

char pop(Stack * stack)
{
  return (stack -> top > 0) ? stack -> characters[--stack -> top] : -1;
}

int push(Stack * stack, char character)
{
  if (stack -> top < MAX - 1)
  {
    stack -> characters[stack -> top++] = character;
    return 0;
  }

  return -1;
}

int valid(char expression[], Stack * stack)
{
  for (int i = 0; expression[i] != '\0'; i++)
  {
    if (expression[i] == ')')
    {
      if (pop(stack) != '(') return 0;
    }

    if (expression[i] == '(') push(stack, '(');
  }

  return stack -> top == 0;
}

Stack * createStack()
{
  Stack * stack = (Stack *) malloc(sizeof(Stack));

  stack -> top = 0;

  return stack;
}

int main(void)
{
  char expression[MAX];

  while (scanf("%s", expression) != EOF)
  {
    Stack * stack = createStack();

    printf("%scorrect\n", (valid(expression, stack)) ? "" : "in");

    free(stack);
  }

  return 0;
}
