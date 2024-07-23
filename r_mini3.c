#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[30];
    int score;
} student;
student *add_student(student *ptr, int *new_size)
{
    (*new_size)++;
    ptr = (student *)realloc(ptr, (*new_size) * sizeof(student));
    printf("Enter new student's name: ");
    scanf("%s", (ptr + (*new_size)-1)->name);
    printf("Enter new student's score: ");
    scanf("%d", &(ptr + (*new_size)-1)->score);
    return ptr;
    printf("\n");
}
// mai thanh gio
student *delete_student(student *ptr, int *size)
{
    char name[30];
    student *ptr_delete;
    printf("Enter name of student to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *size; i++)
    {
        if (strcmp(name, (ptr + i)->name) == 0)
        {
            for (int j = i; j < *size; j++)
            {
                *(ptr + j) = *(ptr + j + 1);
            }
            (*size)--;
            ptr_delete = (student *)realloc(ptr, *size * sizeof(student));
            printf("Delete sucessful!\n");
            printf("\n");
            return ptr_delete;
        }
    }
    printf("Not found out name of student\n");
    printf("/n");
}
void display_student(student *ptr, int size)
{   printf("==== All student ====\n");
    for (int i = 0; i < size; i++)
    {
        printf("Name is: %s\n", (ptr + i)->name);
        printf("Score: %d\n", (ptr + i)->score);
        printf("\n");
    }
}
void update_student(student *ptr, int size)
{
    char name[30];
    printf("Enter name of student to update: ");
    scanf("%s", name);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(name, (ptr + i)->name) == 0)
        {
            printf("Enter name to update: ");
            scanf("%s", (ptr + i)->name);
            printf("Enter score to update: ");
            scanf("%d", &(ptr + i)->score);
            printf("Update sucessful!\n");
            printf("\n");
            return;
        }
    }
    printf("Not found out name of student\n");
    printf("\n");
}
int main()
{
    int size = 0, choice;
    student *ptr = (student *)malloc(size * sizeof(student));
    while (1)
    {
        printf("====== Menu ======\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Display Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ptr = add_student(ptr, &size);
            break;
        case 2:
            ptr = delete_student(ptr, &size);
            break;
        case 3:
            update_student(ptr, size);
            break;
        case 4:
            display_student(ptr, size);
            break;
        case 5:
            printf("Exit menu!\n");
            return 0;
        default:
            printf("Enter again your choice!\n");
            break;
        }
    }
}