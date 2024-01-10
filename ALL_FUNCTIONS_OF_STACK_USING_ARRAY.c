#include <stdio.h>
#define N 16
int top = -1;
int stack[N];

void push()
{
    int ele;
    printf("Enter the data : ");
    scanf("%d", &ele);
    if (top == N - 1)
    {
        printf("Overflow. Stack is full.");
    }
    else
    {
        top++;
        stack[top] = ele;
    }
}

void pop()
{
    int temp;
    if (top == -1)
    {
        printf("Underflow. Stack is empty.");
    }
    else
    {
        temp = stack[top];
        top--;
        printf("The item poped is %d", temp);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("The stack is empty.");
    }
    else
    {
        printf("The top item is : %d", stack[top]);
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("The stack is empty");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d || ", stack[i]);
        }
    }
}

void is_empty()
{
    if (top == -1)
    {
        printf("The Stack is empty.");
    }
    else
    {
        printf("The Stack is not empty.");
    }
}

void is_full()
{
    if (top == N)
    {
        printf("The Stack is full.");
    }
    else
    {
        printf("The Stack is not full.");
    }
}

void get_length()
{
    if (top == -1)
    {
        printf("The stack is empty");
    }
    else if (top == N)
    {
        printf("The Stack is full.");
    }
    
    else
    {
        printf("The length of stack is : %d", top + 1);
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n                    Menu                    \n");
        printf("____________________________________________\n");
        printf("1. Push.\n");
        printf("2. Pop.\n");
        printf("3. Peek.\n");
        printf("4. Display.\n");
        printf("5. Check empty.\n");
        printf("6. Check full.\n");
        printf("7. Length of Stack.\n");
        printf("8. Exit.\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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