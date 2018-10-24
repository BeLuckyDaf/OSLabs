#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void print_links(char* file, char* dir, ino_t inode) {
	printf("Printing links for file: %s\n", file);

	DIR *dirp = opendir(dir);
	if (dirp == NULL) return;

	char filepath[262];		
	struct stat sdata;	

	struct dirent* dp;
	while ((dp = readdir(dirp)) != NULL) {
		sprintf(filepath, "%s/%s", dir, dp->d_name);
		stat(filepath, &sdata);
		if (sdata.st_ino == inode) printf("%s\n", dp->d_name);
	}
}

int main() {
	DIR *dirp = opendir("./tmp");
	if (dirp == NULL) return 1;

	char filepath[262];		
	struct stat sdata;	

	struct dirent* dp;
	while ((dp = readdir(dirp)) != NULL) {
		sprintf(filepath, "%s/%s", "./tmp", dp->d_name);
		stat(filepath, &sdata);
		if (sdata.st_nlink >= 2 && 
			strcmp(dp->d_name, ".") != 0 && // skip the current and top dir links
			strcmp(dp->d_name, "..") != 0) print_links(dp->d_name, "./tmp", sdata.st_ino);
	}

	return 0;
}
