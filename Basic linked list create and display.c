#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *first = NULL;

void create();
void display();

int main() {
    int a;

    while (1) {
        printf("\n\n---- MENU ----\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &a);

        switch (a) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void create() {
    struct node *ptr, *temp;
    int data, ch;

    do {
        ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == NULL) {
            printf("Memory not allocated!\n");
            return;
        }

        printf("Enter node information: ");
        scanf("%d", &data);
        ptr->info = data;
        ptr->next = NULL;

        if (first == NULL) {
            first = ptr;
        } else {
            temp = first;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
        }

        printf("Do you want to continue? (1 for Yes / 0 for No): ");
        scanf("%d", &ch);
    } while (ch == 1);
}

void display() {
    struct node *p = first;

    if (p == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}
