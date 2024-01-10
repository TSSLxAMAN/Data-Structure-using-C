#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *new_node, *front = NULL, *rear = NULL;

void enqueue()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = new_node;
        rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("The Queue is Empty.");
    }
    else if (front == rear)
    {
        rear = NULL;
        front = NULL;
        printf("The Queue is Empty now.");
    }
    else
    {
        struct node *temp;
        temp = front;
        front = front->next;
        printf("The Dequeued data is : %d", temp->data);
        free(temp);
    }
}

void peek()
{
    if (front == NULL)
    {
        printf("The Queue is Empty");
    }
    else
    {
        printf("The front item is : %d", front->data);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("The Queue is Empty.");
    }
    
    struct node *temp;
    temp = front;
    while (temp != NULL)
    {
        printf("%d || ", temp->data);
        temp = temp->next;
    }
}

void is_empty()
{
    if (front == NULL)
    {
        printf("The Queue is Empty.");
    }
    else
    {
        printf("The Queue is not Empty.");
    }
}

void get_length(){
    int count = 1;
    struct node *temp;
    temp = front;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    printf("The Length of the Queue is : %d",count);
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
        printf("6. Length of Queue.\n");
        printf("7. Exit.\n");
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
            get_length();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid input.");
            break;
        }
    }
}