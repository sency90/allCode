#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>

#define FBDEVFILE "/dev/fb"

typedef unsigned char ubyte;

unsigned short makepixel(ubyte r, ubyte g, ubyte b) {
    return (unsigned short)(((r>>3)<<11)|((g>>2)<<5)|(b>>3));
}

int main() {
    //fbfd: frame buffer file descriptor
    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    int x = 0, y = 0;
    long int location = 0;

    /* Open the file for reading and writing */
    fbfd = open(FBDEVFILE, O_RDWR);
    if(!fbfd) {
        printf("Error: cannot open framebuffer device.\n");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    /* Get fixed screen information */
    if(ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo)) {
        printf("Error reading fixed information.\n");
        exit(2);
    }

    /* Get variable screen information to the 'vinfo' variable*/
    if(ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
        printf("Error reading variable information.\n");
        exit(3);
    }

    /* Figure out the size of the screen in bytes */
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    /* Map the device to memory */
    fbp = ((char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0));
    if((int)fbp == -1) {
        printf("Error: failed to map framebuffer device to memory.\n");
        exit(4);
    }

    printf("The framebuffer device was mapped to memory successfully.\n");
    x=100; y=100;   /* Where we are going to put the pixel */

    /* Figure out where in memory to put the pixel */
    location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;

    *(fbp + location) = 100;        /* Some blue */
    *(fbp + location + 1) = 15;     /* A little green */
    *(fbp + location + 2) = 200;    /* A lot of red */
    *(fbp + location + 3) = 0;      /* No transparency */

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}
