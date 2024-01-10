#include <stdio.h>
#include <stdlib.h>
#define N 8

int deque[N];
int front = -1;
int rear = -1;
int data;

void enqueue_front()
{
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
        printf("The DEQUE is full.\n");
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        printf("Enter the data : ");
        scanf("%d", &data);
        deque[front] = data;
    }
    else if (front == 0)
    {
        printf("Enter the data : ");
        scanf("%d", &data);
        front = N - 1;
        deque[front] = data;
    }
    else
    {
        printf("Enter the data : ");
        scanf("%d", &data);
        front--;
        deque[front] = data;
    }
}
void enqueue_rear()
{
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
        printf("The DEQUE is full.\n");
    }
    else if (front == -1 && rear == -1)
    {
        printf("Enter the data : ");
        scanf("%d", &data);
        front++;
        rear++;
        deque[rear] = data;
    }
    else if (rear == N - 1)
    {
        printf("Enter the data : ");
        scanf("%d", &data);
        rear = (N - 1) % rear;
        deque[rear] = data;
    }
    else
    {
        printf("Enter the data : ");
        scanf("%d", &data);
        rear++;
        deque[rear] = data;
    }
}

void dequeue_front()
{
    if (front == -1 && rear == -1)
    {
        printf("The Queue is Empty.");
    }
    else if (front == rear)
    {
        printf("The dequeue element is : %d", deque[front]);
        front = -1;
        rear = -1;
    }
    else if (front == N - 1)
    {
        printf("The dequeue item is : %d", deque[front]);
        front = 0;
    }
    else
    {
        printf("The dequeue item is %d", deque[front]);
        front++;
    }
}

void dequeue_rear()
{
    if (front == -1 && rear == -1)
    {
        printf("The Qeueu is full.\n");
    }
    else if (front == rear)
    {
        printf("The dequeue item is : %d", deque[rear]);
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        printf("The dequeue item is : %d", deque[rear]);
        rear = N - 1;
    }
    else
    {
        printf("The dequeue item is : %d", deque[rear]);
        rear--;
    }
}

void peek_front()
{
    printf("The Front item is : %d", deque[front]);
}

void peek_rear()
{
    printf("The Rear item is : %d", deque[rear]);
}

void display()
{
    int i = front;
    while (i != rear)
    {
        printf("%d || ", deque[i]);
        i = (i + 1) % N;
    }
    printf("%d || ", deque[rear]);
}

void is_empty()
{
    if (front == -1 && rear == -1)
    {
        printf("The Queue is empty.");
    }
    else
    {
        printf("The Queue is not empty.");
    }
}

void is_full()
{
    if (rear == N - 1)
    {
        printf("The Queue is full.");
    }
    else
    {
        printf("The Queue is not full.");
    }
}

void get_length()
{
    if (front == -1 && rear == -1)
    {
        printf("The DEQUE is empty.");
    }
    else
    {
        int count = (rear - front + N) % N + 1;
        printf("The Length of the DEQUE is %d", count);
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n                    Menu                    \n");
        printf("____________________________________________\n");
        printf("1. Enqueue from Front.\n");
        printf("2. Enqueue from Rear.\n");
        printf("3. Dequeue from Front.\n");
        printf("4. Dequeue from Rear.\n");
        printf("5. Peek Front.\n");
        printf("6. Peek Rear.\n");
        printf("7. Display.\n");
        printf("8. Check empty.\n");
        printf("9. Length of Queue.\n");
        printf("10. Exit.\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue_front();
            break;
        case 2:
            enqueue_rear();
            break;
        case 3:
            dequeue_front();
            break;
        case 4:
            dequeue_rear();
            break;
        case 5:
            peek_front();
            break;
        case 6:
            peek_rear();
            break;
        case 7:
            display();
            break;
        case 8:
            is_empty();
            break;
        case 9:
            get_length();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Invalid input.");
            break;
        }
    }
}