#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define MAX_BUFF 4096

int
main(int argc, char *argv[])
{
	ssize_t n;
	char buf[MAX_BUFF];

	if(argc != 3)
	{
		write(STDERR_FILENO,
			"try: ./program <dir> <file>\n",
				sizeof("try: ./program <dir> <file>\n") -1);
		exit(1);
	}
	
	int dirfd = open(argv[1], O_RDONLY);
	if(dirfd < 0)
	{
		perror("open dir");
		exit(1);
	}

	int fd = openat(dirfd, argv[2], O_RDONLY);
	if(fd < 0)
	{
		perror("open file");
		exit(1);
	}

	while((n = read(fd, buf, MAX_BUFF)) > 0)
	{
	if(write(STDOUT_FILENO, buf, n) != n)
	{
		perror("write");
		exit(1);
	}
	}

	if(n < 0)
	{
		perror("read");
		exit(1);
	}

	if(close(fd) < 0)
	{
		perror("close file");
		exit(1);
	}
	if(close(dirfd) < 0)
	{
		perror("close dir");
		exit(1);
	}

	return 0;
}
