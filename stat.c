#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  struct stat buf;
  stat("file.txt", &buf);
  printf("Size: %li\n", buf.st_size);
  printf("Mode: %o\n", buf.st_mode);
  printf("Time of Last Access: %s\n", ctime((time_t *) &buf.st_atime));
  return 0;
}