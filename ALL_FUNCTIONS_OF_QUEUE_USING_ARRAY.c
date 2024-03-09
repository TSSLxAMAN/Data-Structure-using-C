#include <stdio.h>
#define N 16

int front = -1;
int rear = -1;
int queue[N];

void enqueue()
{
    if (rear == N)
    {
        printf("The queue is full.");
    }
    else
    {
        if (front == -1)
        {
            front++;
        }
        rear++;
        printf("Enter the data : ");
        scanf("%d", &queue[rear]);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("\nThe Queue is empty. Nothing to delete.");
    }
    else
    {
        if (front == rear)
        {
            printf("The Dequeue item is  : %d", queue[front]);
            printf("The Queue is empty now.");
            rear = -1;
            front = -1;
        }
        else
        {
            int temp = front;
            front++;
            printf("The Dequeued element is : %d", queue[temp]);
        }
    }
}

void peek()
{
    if (front == -1)
    {
        printf("The Queue is empty. Nothing to delete.");
    }
    else
    {
        printf("The front item is : %d", queue[front]);
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
        for (int i = front; i <= rear; i++)
        {
            printf("%d || ", queue[i]);
        }
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
    if (rear == N)
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
    if (rear == -1)
    {
        printf("The stack is empty");
    }
    else if (rear == N)
    {
        printf("The Stack is full.");
    }

    else
    {
        printf("The length of stack is : %d", rear + 1);
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
        printf("7. Length of Queue.\n");
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