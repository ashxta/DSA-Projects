#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[100];
    char phone[15];
};

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int contactCount = 0;
    char command[20];
    char name[100];
    char phone[15];
    int i, j, found;

    while (1) {
        printf("Enter command (add, list, delete, search, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            if (contactCount < MAX_CONTACTS) {
                printf("Enter contact name: ");
                scanf("%s", contacts[contactCount].name);
                printf("Enter phone number: ");
                scanf("%s", contacts[contactCount].phone);
                contactCount++;
                printf("Contact added successfully.\n");
            } else {
                printf("Contact list is full.\n");
            }
        } else if (strcmp(command, "list") == 0) {
            printf("List of contacts:\n");
            for (i = 0; i < contactCount; i++) {
                printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            }
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter contact name to delete: ");
            scanf("%s", name);
            found = 0;
            for (i = 0; i < contactCount; i++) {
                if (strcmp(contacts[i].name, name) == 0) {
                    for (j = i; j < contactCount - 1; j++) {
                        contacts[j] = contacts[j + 1];
                    }
                    contactCount--;
                    printf("Contact deleted successfully.\n");
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Contact not found.\n");
            }
        } else if (strcmp(command, "search") == 0) {
            printf("Enter contact name to search: ");
            scanf("%s", name);
            found = 0;
            for (i = 0; i < contactCount; i++) {
                if (strcmp(contacts[i].name, name) == 0) {
                    printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Contact not found.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

