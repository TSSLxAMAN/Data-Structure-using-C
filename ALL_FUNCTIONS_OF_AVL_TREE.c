#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *create(int value)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->height = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
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

int get_height(struct node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int get_balance_factor(struct node *root)
{
    if (root == NULL)
        return 0;
    return get_height(root->left) - get_height(root->right);
}

int max(int x, int y)
{
    return (x > y) ? x : y;
}

struct node *left_rotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    return y;
}

struct node *right_rotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    return x;
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
    else
    {
        return root;
    }

    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    int balance = get_balance_factor(root);

    // LL
    if (balance < -1 && value > root->right->data)
    {
        root = left_rotate(root);
    }

    // RR
    if (balance > 1 && value < root->left->data)
    {
        root = right_rotate(root);
    }

    // LR
    if (balance > 1 && value > root->left->data)
    {
        root->left = left_rotate(root->left);
        root = right_rotate(root);
    }

    // RL
    if (balance < -1 && value < root->right->data)
    {
        root->right = right_rotate(root->right);
        root = left_rotate(root);
    }
    return root;
}

void inorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ---- ", root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ---- ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    inorder_traversal(root->right);
    printf("%d ---- ", root->data);
}

struct node *delete_node(struct node *root, int value)
{
    if (root == NULL)
    {
        return root;
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
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            struct node *temp = inorder_successor(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    if (root == NULL)
        return root;

    root->height = 1 + max(get_height(root->left), get_height(root->right));
    int balance = get_balance_factor(root);

    // R0,R1
    if (balance > 1 && get_balance_factor(root->left) >= 0)
    {
        return right_rotate(root);
    }

    // R-1
    if (balance > 1 && get_balance_factor(root->left) < 0)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // L0 ,L-1
    if (balance < -1 && get_balance_factor(root->right) <= 0)
    {
        return left_rotate(root);
    }

    // L1
    if (balance < -1 && get_balance_factor(root->right) > 0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
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
        search(root->left, value);
    }
    else
    {
        search(root->right, value);
    }
}

int main()
{
    struct node *root = NULL;
    struct node *temp = NULL;
    int choice, x;
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
        printf("8. Exit.\n");
        printf("Enter your chice : ");
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
                printf("Postorder Traversal : ");
                postorder_traversal(root);
            }
            break;
        case 5:
            printf("Enter the data you want to search : ");
            scanf("%d", &x);
            temp = search(root, x);
            if (temp == NULL)
            {
                printf("Not Found : %d.\n", x);
            }
            else
            {
                printf("Found : %d.\n", x);
            }
            temp = NULL;
            break;
        case 6:
            printf("Enter the data you want to delete : ");
            scanf("%d", &x);
            delete_node(root, x);
            printf("Deleted : %d", x);
            break;
        case 7:
            root = NULL;
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid Input");
            break;
        }
    }
}