/* Write a C program that will open an existing file with CAT command  through popen() system call and will then display the content in your terminal. */

#include <stdio.h>

int main() {
  FILE *fp = popen("cat assign4.txt", "r");
  if(fp == NULL) {
	printf("Could not open file");
	return 1;
  }
  while(1) {
	char ch = fgetc(fp);
	if(feof(fp)) break;
	printf("%c", ch);
  }
  pclose(fp);
  return 0;
}
