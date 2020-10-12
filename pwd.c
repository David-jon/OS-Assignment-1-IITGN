#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc)
{
  char *p = ".", dir[10000];
  if (argc != 1)
  {
    printf("Usage pwd\n");
    exit(EXIT_FAILURE);
  } //just print the current working directory
  else if (getcwd(dir, sizeof(dir)) != NULL)
    printf("Working directory: %s\n", dir);
  return 0;
}
