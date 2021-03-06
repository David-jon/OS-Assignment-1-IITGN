#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	int fp, op;
	char ch[1000];
	if (argc == 1)
		return 0;
	for (int i = 1; i < argc; i++)
	{
		fp = open(argv[i], O_RDONLY);
		//File can't be opened if returned value is -1
		if (fp == -1)
		{
			printf("wcat: cannot open file\n");
			exit(1);
		}
		//read every charecter and display on the screen
		while (op = read(fp, ch, 1000))
		{
			write(1, ch, op);
		}
		close(fp);
	}
	return 0;
}
