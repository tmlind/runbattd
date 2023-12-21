#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

int main(int argc, char **argv)
{
	struct sockaddr_un sa = { AF_UNIX, };
	int err, fd;
	char buf[16];

	fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (!fd)
		return -1;

	bind(fd, (struct sockaddr *)&sa, sizeof(sa));

	sprintf(buf, "%i", fd);

	err = setenv("ANDROID_SOCKET_battdsock", buf, 1);
	if (err < 0)
		goto out;

	execl("/system/bin/battd", "/system/bin/battd", NULL);

out:
	close(fd);

	return 0;
}
