#include <stdio.h>
#include <string.h>

#define MAX_FILES 10

struct File {
    char name[100];
    int size;
};

int main() {
    struct File files[MAX_FILES];
    int fileCount = 0;
    char command[20];
    char name[100];
    int i, j, found;

    while (1) {
        printf("Enter command (create, list, delete, exit): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            if (fileCount < MAX_FILES) {
                printf("Enter file name: ");
                scanf("%s", files[fileCount].name);
                printf("Enter file size: ");
                scanf("%d", &files[fileCount].size);
                fileCount++;
                printf("File created successfully.\n");
            } else {
                printf("File system is full.\n");
            }
        } else if (strcmp(command, "list") == 0) {
            printf("List of files:\n");
            for (i = 0; i < fileCount; i++) {
                printf("%s - %d bytes\n", files[i].name, files[i].size);
            }
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter file name to delete: ");
            scanf("%s", name);
            found = 0;
            for (i = 0; i < fileCount; i++) {
                if (strcmp(files[i].name, name) == 0) {
                    for (j = i; j < fileCount - 1; j++) {
                        files[j] = files[j + 1];
                    }
                    fileCount--;
                    printf("File deleted successfully.\n");
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("File not found.\n");
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
