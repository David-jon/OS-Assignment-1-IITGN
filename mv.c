#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char *file = argv[1];
    char *location = argv[2];
    char move_location[100];

    if (argc != 3)
    {
        printf("\nUsage: mv [source] [destination]\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        DIR *dir;
        dir = opendir(location);
        if (dir == NULL)
        {
            if (rename(file, location) != 0)
                printf("mv: cannot stat '%s': No such file or directory\n", argv[1]);
        }
        else
        {
            char *ptr;
            ptr = getcwd(move_location, 100);
            strcat(move_location, "/");
            strcat(move_location, location);
            strcat(move_location, "/");
            strcat(move_location, file);
            if (rename(file, ptr) == -1)
                printf("mv: cannot stat '%s': No such file or directory\n", argv[1]);
            closedir(dir);
        }
    }
    return 0;
}
