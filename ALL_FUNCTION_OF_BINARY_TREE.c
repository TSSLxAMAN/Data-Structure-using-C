#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int x;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data(-1 for NULL) : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    new_node->data = x;
    printf("\nEnter the left child of node %d : ", x);
    new_node->left = create();
    printf("\nEnter the Right child of node %d : ", x);
    new_node->right = create();
    return new_node;
}

void preorder_traversal(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    printf("%d ---- ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ---- ", root->data);
    inorder_traversal(root->right);
}

void postorder_traversal(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ---- ", root->data);
}

int main()
{
    int choice;
    struct node *root;
    while (1)
    {
        printf("\n                    Menu                    \n");
        printf("____________________________________________\n");
        printf("1. Create tree.\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice :\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = create();
            break;
        case 2:
            if (root == NULL)
            {
                printf("The Tree is Empty.\n");
            }
            else
            {
                printf("The Preorder Traversal is : ");
                preorder_traversal(root);
            }
            break;
        case 3:
            printf("The Inorder Traversal is : ");
            inorder_traversal(root);
            break;
        case 4:
            printf("The Postorder Traversal is : ");
            postorder_traversal(root);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid input.\n");
            break;
        }
    }
}
