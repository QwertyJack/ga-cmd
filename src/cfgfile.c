#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*-----------------------------------------------------------------*/
int
load_key(char *filename, char **key)
{
int result = 0;
FILE *fp;
struct stat s;

if (filename == NULL)
	{
	return 0;
	}

char *pathname = calloc(sizeof(char), 256);
snprintf(pathname, 256, "%s/.ga-cmd.d/%s", getenv("HOME"), filename);
fp = fopen(pathname, "r");
if (!fp) {
    fprintf(stderr, "ga-cmd: couldn't open keyfile: %s\n", pathname);
    return 0;
}

if (fstat(fileno(fp), &s) != 0) {
    fprintf(stderr, "ga-cmd: couldn't stat keyfile: %s\n", pathname);
    return 0;
}

if (s.st_mode & (S_IRWXO | S_IRWXG)) {
    fprintf(stderr, "ga-cmd: bad permissions on keyfile: %s\n", pathname);
    return 0;
}

int bytes_read;
*key = calloc(sizeof(char), s.st_size + 1);
bytes_read = fread(*key, sizeof(char), s.st_size, fp);
fclose(fp);
for (int c = 0; c < bytes_read; ++c) {
    if ((*key)[c] == '\n') {
        (*key)[c]=0;
        bytes_read = c-1;
        break;
    }
}

return bytes_read;
}
