#include "Holden_libFS.h"

int main() {
    char filename[] = "Holden_Introduction.txt";
    int choice;

    /* Intro paragraph */
    char introduction[] =
        "Hello, my name is Holden.\n"
        "I am currently studying Computer Science and learning about how operating systems function internally.\n\n"
        "I enjoy working with low-level programming and understanding how file systems work within different operating systems.\n"
        "This project has helped me understand how files are managed internally and how libraries are important.\n";

    do {
        printf("\n====== libFS Menu ======\n");
        printf("1. Create File\n");
        printf("2. Open File\n");
        printf("3. Write Introduction\n");
        printf("4. Read File\n");
        printf("5. Close File\n");
        printf("6. Delete File\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fileCreate(filename);
                break;
            case 2:
                fileOpen(filename);
                break;
            case 3:
                fileWrite(filename, introduction);
                break;
            case 4:
                fileRead(filename);
                break;
            case 5:
                fileClose(filename);
                break;
            case 6:
                fileDelete(filename);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 0);

    return 0;
}
