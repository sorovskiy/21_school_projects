#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	//line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//line = get_next_line(fd);
	//i = read_file(fd, line);

	//printf("i - %d, s - %s\n", i, line);


	while((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}


//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//
//
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//
//	line = get_next_line(fd);
//	free(line);

//


//	line = get_next_line(fd);
//	printf("%s", line);
//	line = get_next_line(fd);
//	printf("%s", line);
//	line = get_next_line(fd);
//	printf("%s", line);


	//line = get_next_line(fd);
	//printf("%s", line);
	return 0;
}



/*
	//line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ret = read(fd, line, BUFFER_SIZE);
	while (ret > 0)
	{
		line[ret] = '\0';
		printf("i - %d, s - %s\n", ret, line);
		ret = read(fd, line, BUFFER_SIZE);
	}
	close(fd);
 */