#include <fcntl.h>
#include <dirent.h>
//#include <string.h>
#include <stdio.h>
//#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
void my_stat(char *);

int main(int argc, char **argv)
{
    DIR *dir = opendir(".");
    if (argc == 2)
    {
        dir = opendir(argv[1]);
    }
    struct dirent *strdir = readdir(dir);
    while (strdir != NULL)
    {

        if (strdir->d_name[0] != '.' && strdir->d_name[0] != '\0')
        {
            printf("%s\n", strdir->d_name);
        }
        strdir = readdir(dir);
    }
    printf("\n");
    closedir(dir);
}
