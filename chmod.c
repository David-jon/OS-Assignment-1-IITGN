#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("chmod [0-7][0-7][0-7] [Filename]\n");
		exit(1);
	}
	struct stat st;
	mode_t mode;
	const char *path = argv[2];
	int num = atoi(argv[1]);
	stat(path, &st);

	mode = st.st_mode & 07777;
	//first removing all the permissions of the current file
	mode &= ~(S_IRUSR);
	mode &= ~(S_IWUSR);
	mode &= ~(S_IXUSR);
	mode &= ~(S_IRGRP);
	mode &= ~(S_IWGRP);
	mode &= ~(S_IXGRP);
	mode &= ~(S_IROTH);
	mode &= ~(S_IWOTH);
	mode &= ~(S_IXOTH);
	chmod(path, mode);
	//dividing the input number into three categories
	int others = num % 10;
	num /= 10;
	int group = num % 10;
	num /= 10;
	int user = num % 10;
	//printf("user %d,group %d,others %d argc %d num %d\n", user, group, others, argc, num);
	//setting the permissions using bitwise operators
	if (user & 4)
		mode |= S_IRUSR;

	if (user & 2)
		mode |= S_IWUSR;

	if (user & 1)
		mode |= S_IXUSR;

	if (user & 4)
		mode |= S_IRGRP;

	if (user & 2)
		mode |= S_IWGRP;

	if (user & 1)
		mode |= S_IXGRP;

	if (user & 4)
		mode |= S_IROTH;

	if (user & 2)
		mode |= S_IWOTH;

	if (user & 1)
		mode |= S_IXOTH;

	chmod(path, mode);
	return 0;
}
