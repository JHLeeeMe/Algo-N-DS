/** Simple File Extension Checker
 */

#include <stdio.h>

int
main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    // Open img file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
        return 1;
    
    // Allocate 3 bytes buffer && Read 8 bytes
    unsigned char bytes[8];
    fread(bytes, 8, 1, file);
    
    // Check extensions
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
        printf("Maybe JPEG\n");

    else if (bytes[0] == 0x42 && bytes[1] == 0x4d)
        printf("Maybe BMP\n");

    else if (bytes[0] == 0x47 && bytes[1] == 0x49 && bytes[2] == 0x46 && bytes[3] == 0x38)
        printf("Maybe GIF\n");

    else if (bytes[0] == 0x89 && bytes[1] == 0x50 && bytes[2] == 0x4e && bytes[3] == 0x47
             && bytes[4] == 0x0d && bytes[5] == 0x0a && bytes[6] == 0x1a && bytes[7] == 0x0a)
        printf("Maybe PNG\n");
    
    else if ((bytes[0] == 0x49 && bytes[1] == 0x20 && bytes[2] == 0x49)
             || (bytes[0] == 0x49 && bytes[1] == 0x49 && bytes[2] == 0x2a && bytes[3] == 0x00)
             || (bytes[0] == 0x4d && bytes[1] == 0x4d && bytes[2] == 0x00))
        printf("Maybe TIFF\n");

    else
        printf("Not an image file\nOR Not supported\n");

    fclose(file);
}
