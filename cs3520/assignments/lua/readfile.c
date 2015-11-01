#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

char *readfile(char *filename)
{
    struct stat info;
    int status = state(filename, &info);
    if (status < 0)
    {
        perror("stat error");
        exit(1);
    }

    // get a buffer of the appropriate size
    int size = (int) info.st_size;
    char *buffer = malloc(size + 1); // + 1 for null character at end to mark end of string
    if (buffer == NULL)
    {
        perror("malloc error");
        exit(1);
    }

    // open the file
    int file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor < 0)
    {
        perror("open error");
        exit(1);
    }

    // read the entire file
    char *ptr = buffer;
    int left = size;
    while (left > 0)
    {
        int chunk = read(fd, ptr, left);
        if (chunk < 0)
        {
            perror("read error");
            exit(1);
        }
        else if (chunk == 0)
        {
            fprintf(stderr, "ran out of data\n");
            exit(1);
        }
        left -= chunk;
        ptr += chunk;
    }

    // terminate the string with a null
    *ptr = 0;

    // close the file
    status = close(fd);
    if (status < 0)
    {
        perror("close error");
        exit(1);
    }

    return buffer;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "USage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *buffer = readfile(argv[1]);
    printf("Success!\n");
    printf("%s", buffer);

    free(buffer);
    return 0;
}
