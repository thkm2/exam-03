#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_stars(char *s) {
	while (*s)
	{
		printf("*");
		s++;
	}
	
}

void filter(char *s1, char *s2) {
	int i = -1;
	while (s1[++i])
	{
		int j = 0;
		while (s1[i + j] == s2[j])
		{
			if (s2[j + 1] == '\0')
			{
				print_stars(s2);
				i += j + 1;
			}
			j++;
		}
		printf("%c", s1[i]);
	}
}

int main(int ac, char **av) {
	if (ac != 2)
		return (1);
	char buffer[1024] = {0};
	int bytes_read = read(0, buffer, 1023);
	buffer[bytes_read] = 0;
	filter(buffer, av[1]);
	return (0);
}