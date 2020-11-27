#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{   
    char buf[1024];

    char *cwd =getcwd(buf, sizeof(buf));

    if (NULL == cwd) {
        perror("Get cerrent working directory fail.\n");
        exit(-1);
    } else {
        printf("%s\n", cwd);
    }

    return 0;
}
