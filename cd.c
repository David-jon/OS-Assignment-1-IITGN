#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *p = argv[1], dir[10000];
  if (argc != 2)
  {
    printf("Usage cd [Directory]\n");
    exit(EXIT_FAILURE);
  }
  else if (chdir(p) == -1)
  {
    perror("chdir");
    exit(EXIT_FAILURE);
  }
  else if (getcwd(dir, sizeof(dir)) != NULL)
    printf("Working dir: %s\n", dir);
  else
    perror("Error");
  return 0;
}
