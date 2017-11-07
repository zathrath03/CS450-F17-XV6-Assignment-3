#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main (void)
{
	int *virtAddress = (int*)12285; //limited to 12285 2^14-2^12
	uv2p(virtAddress);
	printf(1, "back in uv2pTest.c\n");
	exit();
}