#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char lineBuffer[512];
    FILE *fp = NULL;
    size_t n = 0;
    int flag = 0;
    char *buffer = NULL;
    int count = 0;
    //flag variable if 1 uses a temporary file temp.txt to already use the existing code for when argument count is greater than 2
    if (argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    if (argc == 2)
    {
        flag = 1;
        printf("Enter text\n");
        char str[2000];
        fgets(str, 2000, stdin);
        fp = fopen("temp.txt", "w");
        fputs(str, fp);
        fclose(fp);
        //strcpy(argv[2],"temp.txt");
    }
    //for loop the grep for every argument vector value
    for (int i = 2; i < argc || flag; i++)
    {

        if (flag == 0)
        {
            fp = fopen(argv[i], "r");
            if (!fp)
            {
                printf("wgrep: cannot open file%s\n", argv[i]);
                exit(2);
            }
        }
        else
        {
            fp = fopen("temp.txt", "r");
        }
        // getline function for making the buffer size as dynamic as opposed to fgets()
        while (getline(&buffer, &n, fp) != -1)
        {
            //printf("What da 2\n");
            if (strstr(buffer, argv[1]))
            {
                if (flag == 0)
                {
                    printf("\n%s  %s", argv[i], buffer);
                }
                else
                    printf("\n%s ", buffer);
                ++count;
            }
        }
        if (flag == 1)
            flag = 0;
        fclose(fp);
    }
    printf("\nfound %d occurrences\n", count);
    return 0;
}
