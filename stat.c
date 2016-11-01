#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

char* getMode(mode_t perm){
  char *permStr = calloc(sizeof(char),32);
  if (perm & S_IRUSR) permStr[0] = 'r'; else permStr[0] = '-';
  if (perm & S_IWUSR) permStr[1] = 'w'; else permStr[1] = '-';
  if (perm & S_IXUSR) permStr[2] = 'x'; else permStr[2] = '-';
  if (perm & S_IRGRP) permStr[3] = 'r'; else permStr[3] = '-';
  if (perm & S_IWGRP) permStr[4] = 'w'; else permStr[4] = '-';
  if (perm & S_IXGRP) permStr[5] = 'x'; else permStr[5] = '-';
  if (perm & S_IROTH) permStr[6] = 'r'; else permStr[6] = '-';
  if (perm & S_IWOTH) permStr[7] = 'w'; else permStr[7] = '-';
  if (perm & S_IXOTH) permStr[8] = 'x'; else permStr[8] = '-';
  return permStr;
}

void printReadableSize(long n){
	if (n < 1000) printf("Size: %li B\n", n);
  else if (n < 1000000) printf("Size: %f KB\n", n/1000.0);
  else if (n < 1000000000) printf("Size: %f MB\n", n/1000000.0);
  else printf("2Size: %f GB\n", n/1000000000.0);
}

int main() {
  struct stat buf;
  stat("file.txt", &buf);
  printf("Size: %li\n", buf.st_size);
  printReadableSize((long)buf.st_size);
  printf("Mode: %o\n", buf.st_mode);
  printf("2Mode:%s\n",getMode(buf.st_mode));
  printf("Time of Last Access: %s\n", ctime((time_t *) &buf.st_atime));
  return 0;
}