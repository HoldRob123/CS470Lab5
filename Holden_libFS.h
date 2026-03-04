#ifndef HOLDEN_LIBFS_H
#define HOLDEN_LIBFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100
#define MAX_FILESIZE 1024

/*
 * Structure representing a simulated file.
 */
typedef struct {
    char filename[MAX_FILENAME];   // Name of the file
    char data[MAX_FILESIZE];       // Simulated file data
    int isOpen;                    // Flag indicating if file is open
    int size;                      // Size of file content
} FS_File;

/* Function Prototypes */

/* Creates a new file */
int fileCreate(const char *filename);

/* Opens an existing file */
int fileOpen(const char *filename);

/* Writes data to an open file */
int fileWrite(const char *filename, const char *buffer);

/* Reads data from an open file */
int fileRead(const char *filename);

/* Closes an open file */
int fileClose(const char *filename);

/* Deletes a file */
int fileDelete(const char *filename);

#endif
