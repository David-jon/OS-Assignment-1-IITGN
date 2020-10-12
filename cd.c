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
  //We are using chdir to change the directory
  else if (chdir(p) == -1)
  {
    perror("chdir");
    exit(EXIT_FAILURE);
  }
  else if (getcwd(dir, sizeof(dir)) != NULL)
    printf("Working dir: %s\n", dir);
  else
    perror("Error");

  /*
  The program changes the directory but the shell reverts back to theoriginal working directory.
  It is because when the program is executed in the shell, the shell follows fork on exec mechanism. So, it doesn’t affect the current shell.
  */
  return 0;
}
