/* Adjacency matrix of the tree is :

    A   B   C   D   E   F   G   H   I
A   0   1   1   1   0   0   0   0   0
B   0   0   0   0   1   0   0   0   0
C   0   1   0   0   0   0   1   0   0
D   0   0   1   0   0   0   1   0   0
E   0   0   1   0   0   1   0   0   0
F   0   0   1   0   0   0   0   1   0
G   0   0   0   0   0   1   0   1   1
H   0   0   0   0   1   0   0   0   1
I   0   0   0   0   0   1   0   0   0

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void bsf(int adj[][MAX], int visited[MAX], int start)
{
    int queue[MAX], rear = -1, front = -1, i, k;
    for (k = 0; k < MAX; k++)
    {
        visited[k] = 0;
    }
    queue[++rear] = start;
    ++front;
    visited[start] = 1;

    while (rear >= front)
    {
        start = queue[front++];
        printf("%c - ", start + 65);
        for (i = 0; i < MAX; i++)
        {
            if (adj[start][i] && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dsf(int adj[][MAX], int visited[MAX], int start)
{
    int stack[MAX];
    int top = -1, i, k;
    for (k = 0; k < MAX; k++)
    {
        visited[k] = 0;
    }
    stack[++top] = start;
    visited[start] = 1;

    while (top != -1)
    {
        start = stack[top--];
        printf("%c - ", start + 65);
        for (i = 0; i < MAX; i++)
        {
            if (adj[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
                break;
            }
        }
    }
}

/* TEST :  Adjacency matrix of the tree is :

    A   B   C   D   E
A   0   1   1   1   0
B   0   0   0   1   0
C   0   1   0   0   0
D   0   0   0   0   1
E   0   0   1   0   0

*/

int main()
{
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j;
    int choice, size;
    while (1)
    {
        printf("\n                    Menu                    \n");
        printf("____________________________________________\n");
        printf("1. Enter values in Graph.\n");
        printf("2. BFS Traversal.\n");
        printf("3. DSF Traversal.\n");
        printf("4. Exit.\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter your Adjency Matrix of (5x5): \n");
            for (i = 0; i < MAX; i++)
            {
                for (j = 0; j < MAX; j++)
                {
                    printf("Element at [%d] x [%d] = ", i, j);
                    scanf("%d", &adj[i][j]);
                }
            }
            break;
        case 2:
            printf("BSF Traversal : ");
            bsf(adj, visited, 0);
            break;
        case 3:
            printf("DSF Traversal : ");
            dsf(adj, visited, 0);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid input.");
            break;
        }
    }
}