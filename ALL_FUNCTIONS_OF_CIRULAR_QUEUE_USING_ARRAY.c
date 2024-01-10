#include <stdio.h>
#include <stdlib.h>
#define N 8

int circular_queue[N];
int front = -1;
int rear = -1;

void enqueue()
{
    if (front == -1 & rear == -1)
    {
        front++;
        rear++;
        printf("Enter the value : ");
        scanf("%d", &circular_queue[front]);
    }
    else if (((rear + 1) % N) == front)
    {
        printf("The Queue is full");
    }
    else
    {
        rear = (rear + 1) % N;
        printf("Enter the value : ");
        scanf("%d", &circular_queue[rear]);
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("The Queue is Empty.");
    }
    else if (front == rear)
    {
        printf("The Queue is Empty now.");
        printf("\nThe Dequeued item is : %d", circular_queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("The Dequeue item is : %d", circular_queue[front]);
        front = (front + 1) % N;
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("\nThe Circular Queue is Empty.");
    }
    else
    {
        printf("The top item is : %d", circular_queue[front]);
    }
}

void display()
{

    if (front == -1)
    {
        printf("The Queue is empty. Nothing to delete.");
    }
    else
    {
        int i = front;
        while (i != rear)
        {
            printf("%d || ", circular_queue[i]);
            i = (i + 1) % N;
        }
        printf("%d || ", circular_queue[rear]);
    }
}

void is_empty()
{
    if (front == -1)
    {
        printf("The Queue is Empty.");
    }
    else
    {
        printf("The Queue is not Empty.");
    }
}

void is_full()
{
    if (((rear + 1) % N) == front)
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
    if (front == -1)
    {
        printf("The Queue is empty");
    }
    else if (((rear + 1) % N) == front)
    {
        printf("The Queue is full.");
    }

    else
    {
        int count = (rear - front + N) % N + 1;
        printf("The length of Queue is : %d", count);
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n                    Menu                    \n");
        printf("____________________________________________\n");
        printf("1. Enqueue.\n");
        printf("2. Dequeue.\n");
        printf("3. Peek.\n");
        printf("4. Display.\n");
        printf("5. Check empty.\n");
        printf("6. Check full.\n");
        printf("7. Length of Circilar Queue.\n");
        printf("8. Exit.\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            is_empty();
            break;
        case 6:
            is_full();
            break;
        case 7:
            get_length();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid input.");
            break;
        }
    }
}