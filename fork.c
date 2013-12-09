#include <stdio.h>
#include <stdlib.h>

int
main()
{
    int p1, p2;

    //sleep(5);
    p1 = fork();
    sleep(5);
    p2 = fork();
    sleep(5);

    //if (p1 == 0) {
        printf ("pid = %d, ppid = %d: p1 = %d, p2 = %d\n", getpid(), getppid(), p1, p2);
    //}

    return 0;
}
