#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 32

struct array
{
    int size;
    int arr[MAX_SIZE];
} *ptr = NULL;
struct array2
{
    int size2;
    int arr2[MAX_SIZE];
} *ptr2 = NULL;
struct array3
{
    int size3;
    int arr3[MAX_SIZE];
} *ptr3 = NULL;

void create()
{
    int i, size;
    ptr = (struct array *)malloc(sizeof(struct array));
    ptr->size = 0;
    printf("Enter the number of elements (0 - 32):");
    scanf("%d", &size);
    if (size < 0 || size > MAX_SIZE)
    {
        printf("Cannot create a array of That size.");
        free(ptr);
    }
    else
    {
        printf("Enter the elements : \n");
        for (i = 0; i < size; i++)
        {
            scanf("%d", &ptr->arr[i]);
        }
        ptr->size = size;
    }
}

void Display()
{
    int i;
    printf("The array is : [ ");
    if (ptr == NULL)
    {
        printf("The array is not created");
    }
    else
    {
        for (i = 0; i < ptr->size; i++)
        {
            printf("%d ", ptr->arr[i]);
        }
        printf("]\n");
    }
}

void insert_at_beg()
{
    int data;
    printf("Enter the element : ");
    scanf("%d", &data);
    for (size_t i = ptr->size; i > 0; i--)
    {
        ptr->arr[i] = ptr->arr[i - 1];
    }
    ptr->arr[0] = data;
    ptr->size++;
}

void insert_at_end()
{
    int data;
    printf("Enter the element : ");
    scanf("%d", &data);
    ptr->arr[ptr->size] = data;
    ptr->size++;
}

void insert_at_pos()
{
    int position, data;
    if (ptr == NULL)
    {
        printf("The array has not been created yet.");
    }
    else
    {
        printf("Enter the position you want to enter : ");
        scanf("%d", &position);
        if (position < 0 || position > ptr->size)
        {
            printf("Invalid position");
        }
        else
        {
            printf("Enter the data : ");
            scanf("%d", &data);
            for (size_t i = ptr->size; i > position; i--)
            {
                ptr->arr[i] = ptr->arr[i - 1];
            }
            ptr->arr[position] = data;
            ptr->size++;
        }
    }
}

void delete_at_beg()
{
    if (ptr == NULL)
    {

        printf("The array is not created yet. Nothing to delete");
    }
    else
    {
        for (size_t i = 0; i < ptr->size - 1; i++)
        {
            ptr->arr[i] = ptr->arr[i + 1];
        }
        ptr->size--;
    }
}

void delete_at_end()
{
    if (ptr == NULL)
    {
        printf("The array is not created yet. Nothing to delete");
    }
    else
    {
        ptr->size--;
    }
}

void delete_at_pos()
{
    int position;
    if (ptr == NULL)
    {
        printf("The array is not created yet. Nothing to delete");
    }
    else
    {
        printf("Enter the position you want to delete : ");
        scanf("%d", &position);
        if (position < 0 || position > ptr->size)
        {
            printf("Invalid position");
        }
        else
        {
            for (size_t i = ptr->size; i > position - 1; i--)
            {
                ptr->arr[position] = ptr->arr[position + 1];
            }
        }
        ptr->size--;
    }
}

void get_length()
{
    int count;
    if (ptr == NULL)
    {
        printf("The array is not created yet.");
    }
    else
    {
        for (size_t i = 0; i < ptr->size; i++)
        {
            count++;
        }
    }
}

void max_element()
{
    int max = ptr->arr[0];
    if (ptr == NULL)
    {
        printf("The array is not created yet.\n");
    }
    else
    {
        for (size_t i = 0; i < ptr->size; i++)
        {
            if (ptr->arr[i] > max)
            {
                max = ptr->arr[i];
            }
        }
        printf("The maximum element of the array is : %d", max);
    }
}

void min_element()
{
    if (ptr == NULL)
    {
        printf("The array is not created yet.\n");
    }
    else
    {
        int min = ptr->arr[0];
        for (size_t i = 0; i < ptr->size; i++)
        {
            if (ptr->arr[i] < min)
            {
                min = ptr->arr[i];
            }
        }
        printf("The minimum element of the array is : %d", min);
    }
}

void sort_ascending()
{
    int temp;
    if (ptr == NULL)
    {
        printf("The array is not created yet.\n");
    }
    else
    {
        for (size_t i = 0; i < ptr->size - 1; i++)
        {
            for (size_t j = 0; j < ptr->size - i - 1; j++)
            {
                if (ptr->arr[j] > ptr->arr[j + 1])
                {
                    temp = ptr->arr[j];
                    ptr->arr[j] = ptr->arr[j + 1];
                    ptr->arr[j + 1] = temp;
                }
            }
        }
    }
}

void sort_descending()
{
    int temp;
    if (ptr == NULL)
    {
        printf("The array is not created yet.\n");
    }
    else
    {
        for (size_t i = 0; i < ptr->size - 1; i++)
        {
            for (size_t j = 0; j < ptr->size - i - 1; j++)
            {
                if (ptr->arr[j] < ptr->arr[j + 1])
                {
                    temp = ptr->arr[j];
                    ptr->arr[j] = ptr->arr[j + 1];
                    ptr->arr[j + 1] = temp;
                }
            }
        }
    }
}

void Reverse()
{
    int temp, start = 0, end = ptr->size - 1;
    if (ptr == NULL)
    {
        printf("The array is not created yet.\n");
    }
    else
    {
        while (start < end)
        {
            temp = ptr->arr[start];
            ptr->arr[start] = ptr->arr[end];
            ptr->arr[end] = temp;
            start++;
            end--;
        }
    }
}

void merge_array()
{
    int size;
    ptr2 = (struct array2 *)malloc(sizeof(struct array2));
    ptr3 = (struct array3 *)malloc(sizeof(struct array3));

    ptr2->size2 = 0;
    if (ptr == NULL)
    {
        printf("The array is not created yet. First create the array and try again.\n");
    }
    else
    {
        printf("Enter the number of elements in the newly created array : ");
        scanf("%d", &size);
        if (size < 0 || size > MAX_SIZE)
        {
            printf("Cannot create a array of that size\n");
        }
        else
        {
            printf("Enter teh elements of the array : \n");
            for (size_t i = 0; i < size; i++)
            {
                scanf("%d", &ptr2->arr2[i]);
            }
            ptr2->size2 = size;
        }
        printf("The newly created array is : [ ");
        for (size_t i = 0; i < ptr2->size2; i++)
        {
            printf("%d ", ptr2->arr2[i]);
        }
        printf("]\n");
        ptr3->size3 = ptr2->size2 + ptr->size;
        for (size_t i = 0; i < ptr->size; i++)
        {
            ptr3->arr3[i] = ptr->arr[i];
        }
        for (size_t i = 0; i < ptr2->size2; i++)
        {
            ptr3->arr3[ptr->size + i] = ptr2->arr2[i];
        }
        printf("The merged array is : [ ");
        for (size_t i = 0; i < ptr3->size3; i++)
        {
            printf("%d ", ptr3->arr3[i]);
        }
        printf("]\n");
    }
}

void sort_merge_ascending()
{
    int temp;
    if (ptr3 == NULL)
    {
        printf("The array is not created yet.\n");
    }
    else
    {
        for (size_t i = 0; i < ptr3->size3 - 1; i++)
        {
            for (size_t j = 0; j < ptr3->size3 - i - 1; j++)
            {
                if (ptr3->arr3[j] > ptr3->arr3[j + 1])
                {
                    temp = ptr3->arr3[j];
                    ptr3->arr3[j] = ptr3->arr3[j + 1];
                    ptr3->arr3[j + 1] = temp;
                }
            }
        }
    }
}

void sort_merge_descending()
{
    int temp;
    if (ptr3 == NULL)
    {
        printf("The array is not created yet.\n");
    }
    else
    {
        for (size_t i = 0; i < ptr3->size3 - 1; i++)
        {
            for (size_t j = 0; j < ptr3->size3 - i - 1; j++)
            {
                if (ptr3->arr3[j] < ptr3->arr3[j + 1])
                {
                    temp = ptr3->arr3[j];
                    ptr3->arr3[j] = ptr3->arr3[j + 1];
                    ptr3->arr3[j + 1] = temp;
                }
            }
        }
    }
}

void Merge_print()
{
    if (ptr3 == NULL)
    {
        printf("Merged array is not created yet.\n");
    }
    else
    {
        printf("The marged array is : [ ");
        for (size_t i = 0; i < ptr3->size3; i++)
        {
            printf("%d ", ptr3->arr3[i]);
        }
        printf("]\n");
    }
}

int search_in_array()
{
    if (ptr == NULL)
    {
        printf("The array has created yet.");
    }
    else
    {
        int number, i;
        int check = 0;
        printf("Enter the element you want to search in the array : ");
        scanf("%d", &number);
        for (i = 0; i < ptr->size; i++)
        {
            if (ptr->arr[i] == number)
            {
                check = 1;
                break;
            }
        }
        if (check == 1)
        {
            printf("%d is found at %d index in the array", number, i);
        }
        else
        {
            printf("%d not found in the array.\n", number);
        }
    }
}

void search_in_merged_array()
{
    if (ptr3 == NULL)
    {
        printf("The array has created yet.");
    }
    else
    {
        int number2, i;
        int check2 = 0;
        printf("Enter the element you want to search in the array : ");
        scanf("%d", &number2);
        for (i = 0; i < ptr3->size3; i++)
        {
            if (ptr3->arr3[i] == number2)
            {
                check2 = 1;
                break;
            }
        }
        if (check2 == 1)
        {
            printf("%d is found at %d index in the array", number2, i);
        }
        else
        {
            printf("%d not found in the array.\n", number2);
        }
    }
}

void check_if_empty()
{
    if (ptr == NULL)
    {
        printf("The array is empty");
    }
    else
    {
        printf("NO the array has some element in it.");
    }
}
void check_if_full()
{
    if (ptr == NULL)
    {
        printf("The array has not created yet");
    }
    else
    {
        if (ptr->size == MAX_SIZE)
        {
            printf("The array is full");
        }
    }
}

void replace_element()
{
    int element, replace, check = 0, positon = 0, i;
    if (ptr == NULL)
    {
        printf("The array has not been created yet.");
    }
    else
    {
        printf("Enter the element you want to replace : ");
        scanf("%d", &element);
        printf("Enter the replaced element : ");
        scanf("%d", &replace);
        for (i = 0; i < ptr->size; i++)
        {
            if (ptr->arr[i] == element)
            {
                ptr->arr[i] = replace;
            }
        }
    }
}

int sum_of_array()
{
        int sum = 0;
    if (ptr == NULL)
    {
        printf("The array is not created yet.");
    }
    else
    {
        for (size_t i = 0; i < ptr->size; i++)
        {
            sum = sum + ptr->arr[i];
        }
        printf("The sum of the array is : %d ", sum);
    }
    return sum;
}
int average(){
    int average = 0;
    if (ptr == NULL)
    {
        printf("The array is not created yet.");
    }
    else{
        average = sum_of_array();
        average = average / ptr->size;
        printf("The average of the : %d",average);
    }
    
}

int main(int argc, char const *argv[])
{
    int choice;
    while (1)
    {
    Menu:
        printf("\n                    Menu                    \n");
        printf("____________________________________________\n");
        printf("1. Create array.\n");
        printf("2. Display array.\n");
        printf("3.Insert in beginning.\n");
        printf("4.Insert in end.\n");
        printf("5.Insert at a position.\n");
        printf("6.Delete in beginning.\n");
        printf("7.Delete in end.\n");
        printf("8.Delete at a position.\n");
        printf("9.Length of array.\n");
        printf("10.Maximum element of the array.\n");
        printf("11.Minimum element of the array.\n");
        printf("12.Sort the array.\n");
        printf("13.Reverse the array.\n");
        printf("14.Merged two arrays.\n");
        printf("15.Display Merged array.\n");
        printf("16.Sort Merged array.\n");
        printf("17.Search element.\n");
        printf("18.Check if array is empty.\n");
        printf("19.Check if array is full.\n");
        printf("20.Replace Element.\n");
        printf("21.Sum of array.\n");
        printf("22.Average of array.\n");
        printf("23. Exit.\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            Display();
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
            max_element();
            break;
        case 11:
            min_element();
            break;
        case 12:
            int choice;
        Sort:
            printf("\n                    Sort Menu                    \n");
            printf("____________________________________________\n");
            printf("1.Ascending\n");
            printf("2.Descending\n");
            printf("3.Go back to menu\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                sort_ascending();
                goto Menu;
                break;
            case 2:
                sort_descending();
                goto Menu;
                break;
            case 3:
                goto Menu;
                break;
            default:
                printf("Invalid input");
                goto Sort;
                break;
            }
            break;
        case 13:
            Reverse();
            break;
        case 14:
            merge_array();
            break;
        case 15:
            Merge_print();
            break;
        case 16:
            int choice2;
        Sort2:
            printf("\n                    Sort Menu                    \n");
            printf("____________________________________________\n");
            printf("1.Ascending\n");
            printf("2.Descending\n");
            printf("3.Go back to menu\n");
            printf("Enter your choice : ");
            scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                sort_merge_ascending();
                goto Menu;
                break;
            case 2:
                sort_merge_descending();
                goto Menu;
                break;
            case 3:
                goto Menu;
                break;
            default:
                printf("Invalid input");
                goto Sort2;
                break;
            }
            break;

        case 17:
            int choice3;
        Search:
            printf("\n                    Search Menu                    \n");
            printf("____________________________________________\n");
            printf("1.In original array\n");
            printf("2.In merged array\n");
            printf("3.Go back to menu\n");
            printf("Enter your choice : ");
            scanf("%d", &choice3);
            switch (choice3)
            {
            case 1:
                search_in_array();
                goto Menu;
                break;
            case 2:
                search_in_merged_array();
                goto Menu;
                break;
            case 3:
                goto Menu;
                break;
            default:
                printf("Invalid input");
                goto Sort2;
                break;
            }
            break;

        case 18:
            check_if_empty();
            break;
        case 19:
            check_if_full();
            break;
        case 20:
            replace_element();
            break;
        case 21:
            sum_of_array();
            break;
        case 22:
            average();
            break;
        case 23:
            exit(0);
            break;
        default:
            printf("Invalid choice. Try again.");
            break;
        }
    }
}