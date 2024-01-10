#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head, *new_node, *tail;

void create()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->prev = NULL;
    printf("Enter the data : ");
    scanf("%d", &new_node->data);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

void display()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("The array is not created yet.\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("->%d", temp->data);
            temp = temp->next;
        }
        printf("->NULL");
    }
}

void insert_in_beg()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
    {
        printf("The list is not created yet.");
    }
    else
    {
        printf("Enter the data you want to insert : ");
        scanf("%d", &new_node->data);
        head->prev = new_node;
        new_node->next = head;
        new_node->prev = NULL;
        head = new_node;
    }
}

void insert_in_end()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
    {
        printf("The list is not created yet.");
    }
    else
    {
        printf("Enter the data you want to insert : ");
        scanf("%d", &new_node->data);
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

void insert_at_pos()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
    {
        printf("The list is not created yet.");
    }
    else
    {
        struct node *temp;
        int position, i = 0;
        printf("Enter the position you want to insert : ");
        scanf("%d", &position);
        printf("Enter the data you want to insert : ");
        scanf("%d", &new_node->data);
        temp = head;
        while (i < position - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            printf("Invalid position;");
        }
        else
        {
            new_node->prev = temp;
            new_node->next = temp->next;
            if (temp->next != NULL)
            {
                new_node->next->prev = new_node;
            }
            temp->next = new_node;
        }
    }
}

void del_in_beg()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("The array is not created yet.\n");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void del_in_end()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("The array is not created yet.\n");
    }
    else
    {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

void del_at_pos()
{
    struct node *temp;
    int position, i = 0;
    if (head == NULL)
    {
        printf("The array is not created yet .");
    }
    else
    {
        struct node *temp;
        temp = head;
        printf("Enter the postion you want ot delete : ");
        scanf("%d", &position);
        while (i < position - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void get_length()
{ 
    struct node *temp;
    int count = 0;
    temp = head;
    if (head == NULL)
    {
        printf("The array is not created yet.\n");
    }
    else
    {
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        printf("The current length of the list is : %d\n", count);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n                    Menu                    \n");
        printf("____________________________________________\n");
        printf("1. Create node.\n");
        printf("2. Display List node.\n");
        printf("3. Insert in begining.\n");
        printf("4. Insert in end.\n");
        printf("5. Insert at a position.\n");
        printf("6. Delete in begining.\n");
        printf("7. Delete in end.\n");
        printf("8. Delete at a position.\n");
        printf("9. Length of the list.\n");
        printf("10. Exit.\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_in_beg();
            break;
        case 4:
            insert_in_end();
            break;
        case 5:
            insert_at_pos();
            break;
        case 6:
            del_in_beg();
            break;
        case 7:
            del_in_end();
            break;
        case 8:
            del_at_pos();
            break;
        case 9:
            get_length();
            break;
        case 10:
            exit(0);
            break;

        default:
            printf("Invalid input. Try again.");
            break;
        }
    }
}