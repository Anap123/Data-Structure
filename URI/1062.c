#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct
{
  int top;
  int vector[MAX];
}
Stack;

int empty(Stack *);
int top(Stack *);
Stack * create();
void pop(Stack *);
void push(Stack *, int);

int main(void)
{
  int size;
  int wagons[MAX];

  while (1)
  {
    scanf("%d", &size);

    if (!size) break;

    while (1)
    {
      int index = 0;
      Stack * stack = create();

      scanf("%d", &wagons[0]);

      if (!wagons[0])
      {
        printf("\n");
        break;
      }

      for (int i = 1; i < size; i++) scanf("%d", &wagons[i]);

      for (int i = 1; i <= size; i++)
      {
        push(stack, i);

        while (stack -> top > 0 && wagons[index] == top(stack))
        {
          pop(stack);
          index++;
        }
      }

      printf("%s\n", (empty(stack)) ? "Yes": "No");
    }
  }
  
  return 0;
}

Stack * create()
{
  Stack * stack = (Stack *) malloc(sizeof(Stack));

  stack -> top = 0;

  return stack;
}

void pop(Stack * stack)
{
  if (stack -> top > 0) stack -> top--;
}

void push(Stack * stack, int value)
{
  if (stack -> top < MAX) stack -> vector[stack -> top++] = value;
}

int empty(Stack * stack)
{
  return !(stack -> top);
}

int top(Stack * stack)
{
  return stack -> vector[stack -> top - 1];
}
