#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head, *tail, *new_node;

void create()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        head->next = head;
        tail->prev = tail;
    }
    else
    {
        tail->next = new_node;
        new_node->next = head;
        new_node->prev = tail;
        head->prev = new_node;
        tail = new_node;
    }
}

void display()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("The list i empty.\n");
    }
    else
    {
        while (temp != tail)
        {
            printf("%d-> ", temp->data);
            temp = temp->next;
        }
        printf("%d-> NULL", temp->data);
    }
}

void insert_in_beg()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &new_node->data);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        new_node->next = head;
        new_node->prev = tail;
    }
    else
    {
        new_node->prev = head->prev;
        new_node->next = head;
        head = new_node;
    }
}

void insert_in_end()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &new_node->data);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        new_node->next = head;
        new_node->prev = tail;
    }
    else
    {
        new_node->prev = tail;
        new_node->next = head;
        head->prev = new_node;
        tail->next = new_node;
        tail = new_node;
    }
}

int get_length()
{
    int count = 1;
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("The List is empty.");
    }
    else
    {
        while (temp != tail)
        {
            temp = temp->next;
            count++;
        }
    }
    return count;
}

void insert_at_a_pos()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    int length, position, i;
    struct node *temp;
    temp = head;
    length = get_length();
    printf("Enter the position : ");
    scanf("%d", &position);
    if (length <= position || position < 0)
    {
        printf("Invalid position");
    }
    else
    {
        printf("Enter the data : ");
        scanf("%d", &new_node->data);
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        new_node->prev = temp;
        new_node->next = temp->next;
        temp->next = new_node;
        temp->next->prev = new_node;
    }
}

void delete_in_beg()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("The list is empty nothing to delete.");
    }
    else
    {
        tail->next = head->next;
        head = head->next;
        free(temp);
    }
}

void delete_in_end()
{
    struct node *temp;
    temp = tail;
    if (head == NULL)
    {
        printf("The list is empty nothing to delete.");
    }
    else
    {
        tail->prev->next = tail->next;
        tail = tail->prev;
        free(temp);
    }
}

void delete_at_a_pos()
{
    int i, position, length;
    struct node *temp;
    temp = head;
    length = get_length();
    if (head == NULL)
    {
        printf("The list is empty nothing to delete.");
    }
    else
    {
        printf("Enter the position : ");
        scanf("%d", &position);
        if (position >= length || position < 0)
        {
            printf("Invalid position.");
        }
        else if (position == 1)
        {
            delete_in_beg();
        }

        else
        {
            while (i < position - 1)
            {
                temp = temp->next;
                i++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n                    Menu                    \n");
        printf("____________________________________________\n");
        printf("1. Create node.\n");
        printf("2. Display.\n");
        printf("3. Insert in beginning.\n");
        printf("4. Insert in end.\n");
        printf("5. Insert at a given position.\n");
        printf("6. Delete in beginning.\n");
        printf("7. Delete in end.\n");
        printf("8. Delete at a given position.\n");
        printf("9. Length of list.\n");
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
            insert_at_a_pos();
            break;
        case 6:
            delete_in_beg();
            break;
        case 7:
            delete_in_end();
            break;
        case 8:
            delete_at_a_pos();
            break;
        case 9:
            int length;
            length = get_length();
            if (length == 0)
            {
                printf("The list is empty");
            }
            else
            {
                printf("The length of the list is : %d", length);
            }
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