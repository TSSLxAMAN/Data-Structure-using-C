#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int value)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return create(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void preorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ---- ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder_traversal(root->left);
        printf("%d ---- ", root->data);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ---- ", root->data);
    }
}

struct node *search(struct node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == value)
    {
        return root;
    }
    else if (value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

struct node *inorder_successor(struct node *root)
{
    struct node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node *delete_node(struct node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (value < root->data)
    {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete_node(root->right, value);
    }
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
                free(temp);
            }
        }
        else
        {
            struct node *temp = inorder_successor(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    int choice, x;
    struct node *root = NULL;
    while (1)
    {
        printf("\n                    Menu                    \n");
        printf("____________________________________________\n");
        printf("1. Create tree OR Insert node .\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search element.\n");
        printf("6. Delete node.\n");
        printf("7. Delete Tree.\n");
        printf("8. Exit\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data : ");
            scanf("%d", &x);
            root = insert(root, x);
            printf("The value %d added to the Tree.\n", x);
            break;
        case 2:
            if (root == NULL)
            {
                printf("The Tree is empty.");
            }
            else
            {
                printf("Preorder Traversal : ");
                preorder_traversal(root);
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("The Tree is empty.");
            }
            else
            {
                printf("Inorder Traversal : ");
                inorder_traversal(root);
            }
            break;
        case 4:
            if (root == NULL)
            {
                printf("The Tree is empty.");
            }
            else
            {
                printf("Preorder Traversal : ");
                postorder_traversal(root);
            }
            break;
        case 5:
            printf("Enter the data you want to search : ");
            scanf("%d", &x);
            struct node *n;
            n = search(root, x);
            if (n == NULL)
            {
                printf("The value %d not found.\n", x);
            }
            else
            {
                printf("The value %d found.\n", x);
            }
            break;
        case 6:
            printf("Enter the data you want to delete : ");
            scanf("%d", &x);
            struct node *n1;
            n1 = delete_node(root, x);
            if (n1 == NULL)
            {
                printf("The value %d not found.\n", x);
            }
            else
            {
                printf("The value %d deleted from tree.\n", x);
            }
            break;
        case 7:
            root = NULL;
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid input.\n");
            break;
        }
    }
}