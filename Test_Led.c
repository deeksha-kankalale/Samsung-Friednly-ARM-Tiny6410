#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int on;
	int led_no;
	int fd;

	if (argc != 2 || sscanf(argv[1], "%d", &on) != 1 || on>1 || on<0) {
		fprintf(stderr, "Usage: leds led_no 0|1\n");
		exit(1);
	}

	fd = open("/dev/deeksha", 0);
	if (fd < 0) {
		fd = open("/dev/deeksha", 0);
	}
	if (fd < 0) {
		perror("open device leds");
		exit(1);
	}

	ioctl(fd, on);
	close(fd);

	return 0;
}

