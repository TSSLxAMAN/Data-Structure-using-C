#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create()
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

void display()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("The list is empty \n");
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("->%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("->NULL\n");
    }
}

void insert_at_beg()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void insert_at_end()
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

void insert_at_pos()
{
    int position, i = 1;
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the position : ");
    scanf("%d", &position);
    printf("Enter the data : ");
    scanf("%d", &new_node->data);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        temp = head;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_at_beg()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("The list is empty. Nothing to delete.\n");
    }
    else
    {
        temp = head;
        head = head->next;
        printf("The element %d has been deleted", temp->data);
        free(temp);
    }
}

void delete_at_end()
{
    struct node *temp, *ptr;
    if (head == NULL)
    {
        printf("The list is empty. Nothig to delete");
    }
    else
    {
        temp = head;
        ptr = head;
        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
        printf("The element %d has been deleted.", temp->data);
        free(ptr);
    }
}

void delete_at_pos()
{
    int position, i = 1;
    struct node *temp, *ptr;
    if (head == NULL)
    {
        printf("THe list is empty. Nothing to delete.");
    }
    else
    {
        printf("Enter the position you want to delete : ");
        scanf("%d", &position);
        temp = head;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        ptr = temp->next;
        temp->next = ptr->next;
        free(ptr);
    }
}

void get_length()
{
    struct node *temp;
    int count = 0;
    temp = head;
    if (head == NULL)
    {
        printf("There are 0 nodes in the list");
    }
    else
    {
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        printf("There are %d nodes in the list", count);
    }
}

int main(int argc, char const *argv[])
{
    int choice;
    while (1)
    {
        printf("\n                    Menu                    \n");
        printf("____________________________________________\n");
        printf("1. Create node.\n");
        printf("2. Display.\n");
        printf("3. Insert at beginning.\n");
        printf("4. Insert at end.\n");
        printf("5. Insert at position.\n");
        printf("6. Deletion at beginning.\n");
        printf("7. Deletion at end.\n");
        printf("8. Deletion at a position.\n");
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
            insert_at_beg();
            break;
        case 4:
            insert_at_end();
            break;
        case 5:
            insert_at_pos();
            break;
        case 6:
            delete_at_beg();
            break;
        case 7:
            delete_at_end();
            break;
        case 8:
            delete_at_pos();
            break;
        case 9:
            get_length();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Invalid choice. Try again.");
            break;
        }
    }
}
