#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rare;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rare = -1;
    q->Q = (int *)malloc(q->size * sizeof(struct Queue));
}

void enqueue(struct Queue *q, int x)
{
    if (q->rare == q->size - 1)
        printf("Queue is full");
    else
    {
        q->rare++;
        q->Q[q->rare] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rare)
        printf("Queue is empty");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rare; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}
int main()
{
    struct Queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    Display(q);
    printf("%d ", dequeue(&q));
    return 0;
}
