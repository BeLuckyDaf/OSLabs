#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("/dev/random", O_RDONLY);
    
    char buf[21];
    buf[20] = '\0';
    
    read(fd, buf, 20);
    printf("%s\n", buf);
    
    close(fd);
    
    return 0;
}