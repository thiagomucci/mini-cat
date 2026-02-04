#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	if(argc != 3)
	{
		write(STDERR_FILENO, "usage: program <dir> <file>\n",
			sizeof("usage: program <dir> <file>\n") - 1);
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
		perror("openat file");
			exit(1);
			}

	close(fd);
	close(dirfd);
	return 0;
}
