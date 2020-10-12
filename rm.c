#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //use exec function to recursively delete the files inside a non-empty directory
    if (argc == 3 && !(strcmp(argv[1], "-r")))
    {
        execlp("rm", "rm", "-r", argv[2], NULL);
        return 0;
    }
    if (argc != 2 || argv[1] == "--help")
    {
        printf("\nusage: rm [File Name] or rm -r [File Name]\n");
        return 0;
    }
    //use remove function if the directory is empty, ot when we are removing a file
    int status;
    status = remove(argv[1]);
    if (status != 0)
        printf("rm: cannot remove '%s': No such file or directory\n", argv[1]);
    return 0;
}
