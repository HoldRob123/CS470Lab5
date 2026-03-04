#include "Holden_libFS.h"

/* Tracks the currently opened file */
static FS_File currentFile;

/*
 * Creates a new file.
 * Returns 0 on success, -1 on failure.
 */
int fileCreate(const char *filename) {
    FILE *fp = fopen(filename, "w");

    if (!fp) {
        printf("Error: Unable to create file.\n");
        return -1;
    }

    fclose(fp);
    printf("File '%s' created successfully.\n", filename);
    return 0;
}

/*
 * Opens an existing file for reading and writing.
 */
int fileOpen(const char *filename) {
    FILE *fp = fopen(filename, "r+");

    if (!fp) {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    strcpy(currentFile.filename, filename);
    currentFile.isOpen = 1;

    fclose(fp);

    printf("File '%s' opened successfully.\n", filename);
    return 0;
}

/*
 * Writes data to the file.
 * The file must be opened before writing.
 */
int fileWrite(const char *filename, const char *buffer) {

    if (!currentFile.isOpen) {
        printf("Error: File is not open.\n");
        return -1;
    }

    FILE *fp = fopen(filename, "a");

    if (!fp) {
        printf("Error: Unable to write to file.\n");
        return -1;
    }

    fprintf(fp, "%s", buffer);
    fclose(fp);

    printf("Data written successfully.\n");
    return 0;
}

/*
 * Reads and prints file contents.
 * The file must be opened before reading.
 */
int fileRead(const char *filename) {

    if (!currentFile.isOpen) {
        printf("Error: File is not open.\n");
        return -1;
    }

    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Error: Unable to read file.\n");
        return -1;
    }

    char ch;

    printf("\n--- File Contents ---\n");

    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    printf("\n----------------------\n");

    fclose(fp);
    return 0;
}

/*
 * Closes the currently open file.
 */
int fileClose(const char *filename) {

    if (!currentFile.isOpen) {
        printf("Error: File already closed.\n");
        return -1;
    }

    currentFile.isOpen = 0;
    printf("File '%s' closed successfully.\n", filename);
    return 0;
}

/*
 * Deletes a file from the system.
 */
int fileDelete(const char *filename) {

    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
        return 0;
    } else {
        printf("Error: Unable to delete file.\n");
        return -1;
    }
}
