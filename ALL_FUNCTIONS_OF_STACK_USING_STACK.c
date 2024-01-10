#include <stdio.h>
#include <stdlib.h>
#define N 8
int count;
int stack1[N], stack2[N];
int top1 = -1, top2 = -1;

void push1(int data)
{
    top1++;
    stack1[top1] = data;
}

int push2(int data)
{
    top2++;
    stack2[top2] = data;
}

int pop1()
{
    int temp;
    temp = stack1[top1];
    top1--;
    return temp;
}

int pop2()
{
    int temp;
    temp = stack2[top2];
    top2--;
    return temp;
}

void enqueue()
{
    if (top1 == N - 1)
    {
        printf("The Queue is full");
    }

    else
    {
        int data;
        printf("Enter the data : ");
        scanf("%d", &data);
        push1(data);
        count++;
    }
}

int dequeue()
{
    int a, b, c, i;
    if (top1 == -1 && top2 == -1)
    {
        printf("The Queue is empty.");
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            a = pop1();
            push2(a);
        }
        b = pop2();
        printf("The Dequeue item is : %d", b);
        count--;
        for (i = 0; i < count; i++)
        {
            c = pop2();
            push1(c);
        }
    }
}

void peek()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("The Queue is empty.");
    }
    else
    {
        printf("Enter the top item is : %d", stack1[top1]);
    }
}

void display()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("The Queue is empty.");
    }
    else
    {
        for (int i = 0; i <= top1; i++)
        {
            printf("%d || ", stack1[i]);
        }
    }
}

void is_empty()
{
    if (top1 == -1 && top2 == -1)
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
    if (top1 == N - 1)
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
    printf("The Size of Queue is : %d", count);
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