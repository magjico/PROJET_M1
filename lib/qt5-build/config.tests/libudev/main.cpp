/* Generated by configure */
#include <libudev.h>
int main(int argc, char **argv)
{
    (void)argc; (void)argv;
    /* BEGIN TEST: */
    udev_unref(udev_new());
    /* END TEST */
    return 0;
}