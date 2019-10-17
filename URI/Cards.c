#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct
{
  int size, start;
  int card[MAX];
}
Queue;

int pop(Queue * queue)
{
  int value;

  if (queue -> size > 0)
  {
    value = queue -> card[queue -> start];
    queue -> start = (queue -> start + 1) % MAX;
    queue -> size--;
  }

  return value;
}

int push(Queue * queue, int value)
{
  int end = 0;

  if (queue -> size < MAX)
  {
    end = (queue -> start + queue -> size) % MAX;

    queue -> card[end] = value;
    queue -> size++;
    
    return 0;
  }

  return -1;
}

Queue * createQueue(int amount)
{
  Queue * queue = (Queue *) malloc(sizeof(Queue));

  queue -> size = 0;
  queue -> start = 0;

  for (int i = 0; i < amount; i++) push(queue, i + 1);

  return queue;
}

int main(void)
{
  int cardAmount;
  int discarded[MAX];

  while (1)
  {
    int discardedAmount = 0, remainingCard;

    scanf("%d", &cardAmount);

    if (!cardAmount) break;

    Queue * queue = createQueue(cardAmount);

    for (int x = 0; discardedAmount != cardAmount - 1; x++)
    {
      discarded[x] = pop(queue);

      remainingCard = pop(queue);

      push(queue, remainingCard);

      discardedAmount++;
    }

    printf("Discarded cards: %d", discarded[0]);

    for (int i = 1; i < discardedAmount; i++)
    {
      printf(", %d", discarded[i]);
    }

    printf("\n");

    printf("Remaining card: %d\n", remainingCard);

    free(queue);
  }

  return 0;
}
