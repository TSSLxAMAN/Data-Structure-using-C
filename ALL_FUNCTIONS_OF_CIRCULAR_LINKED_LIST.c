#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *new_node, *tail;

void create()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;
    printf("Enter the data : ");
    scanf("%d", &new_node->data);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        tail->next = new_node;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = new_node;
        tail = new_node;
        tail->next = head;
    }
}
void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("The List is not created yet.");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            printf("->%d ", temp->data);
            temp = temp->next;
        }
        printf("->%d ->NULL", temp->data);
    }
}

void insert_in_beg()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = NULL;
    printf("Enter the data you want : ");
    scanf("%d", &new_node->data);
    tail->next = new_node;
    new_node->next = head;
    head = new_node;
}

void insert_in_end()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = NULL;
    printf("Enter your data : ");
    scanf("%d", &new_node->data);
    new_node->next = tail->next;
    tail->next = new_node;
    tail = new_node;
}

void insert_at_a_pos()
{
    if (head == NULL)
    {
        printf("The list is not created yet");
    }
    else
    {
        struct node *temp;
        int position, i = 0;
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter your position : ");
        scanf("%d", &position);
        temp = head;
        while (i < position - 1 && temp != tail)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            printf("The list is not created yet.");
        }
        else
        {
            printf("Enter the data : ");
            scanf("%d", &new_node->data);
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

void delete_in_beg()
{
    if (head == NULL)
    {
        printf("The list not created yet. Nothing to delete.");
    }
    else
    {
        struct node *temp;
        temp = head;
        tail->next = head->next;
        head = head->next;
        free(temp);
    }
}

void delete_in_end()
{
    if (head == NULL)
    {
        printf("The list is not created yet. Nothing to delete.");
    }
    else
    {
        struct node *current_node, *prev_node;
        current_node = head;
        if (current_node->next == current_node)
        {
            printf("All the nodes are deleted.");
        }

        while (current_node != tail)
        {
            prev_node = current_node;
            current_node = current_node->next;
        }

        prev_node->next = head;
        free(tail);
        tail = prev_node;
    }
}

int get_length(){
    int count = 1;
    struct node* temp;
    temp = head;
    while (temp != tail)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void delete_at_a_pos(){
    if (head == NULL)
    {
        printf("The list is not created yet. Nothing ti delete.");
    }
    int count,position,i;    
    count = get_length();
    printf("Enter the positon you want to delete : ");
    scanf("%d",&position);
    if (position > count || position < 0)
    {
        printf("Invalid position.");
    }
    else
    {
        struct node *current_node,*next_node;
        current_node = head;
        while (i < position - 1)
        {
            current_node = current_node->next;
            i++;
        }
        next_node = current_node->next;
        current_node->next = next_node->next;
        free(next_node);      
    }
    
    
}

void main()
{
    int choice,len;
    while (1)
    {
        printf("\n                    Menu                    \n");
        printf("____________________________________________\n");
        printf("1. Create node.\n");
        printf("2. Display list.\n");
        printf("3. Insert in beginning.\n");
        printf("4. Insert in end.\n");
        printf("5. Insert at a pos.\n");
        printf("6. Delete in beginning.\n");
        printf("7. Delete in end.\n");
        printf("8. Delete at a position.\n");
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
            len = get_length();
            if (len == 0 )
            {
                printf("The list is empty");
            }
            
            printf("The length of the list is : %d",len);
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