// get the screen buffer
static char* const VGA_MEMORY = (char*)0xb8000;

// width and height of the terminal
static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;

// void inside paremeters indicateds an empty argument list
void kernel_early(void) {
    // do something
}

// 0x10000000 is the kernels physical address
int main(void) {
    const char *str = "Hello World!";   // the actuall hello world.

    unsigned int i = 0;                 // place holder for text string position
    unsigned int j = 0;                 // place holder for video buffer position

    unsigned int scolor = 0;            // selected color

    // \0 means end of string or 'null'
    while (str[i] != '\0') {
        VGA_MEMORY[j] = str[i];
        
        if (scolor == 1) {
            VGA_MEMORY[j + 1] = 0x01;       // set the color 0x0(VGA COLOR NUMBER CODE)
        }
        if (scolor == 2) {
            VGA_MEMORY[j + 1] = 0x03;       // set the color 0x0(VGA COLOR NUMBER CODE)
        }
        if (scolor == 3) {
            VGA_MEMORY[j + 1] = 0x05;       // set the color 0x0(VGA COLOR NUMBER CODE)
        }
        if (scolor == 4) {
            VGA_MEMORY[j + 1] = 0x07;       // set the color 0x0(VGA COLOR NUMBER CODE)
        }
        if (scolor == 5) {
            VGA_MEMORY[j + 1] = 0x09;       // set the color 0x0(VGA COLOR NUMBER CODE)
        }
        if (scolor == 6) {
            VGA_MEMORY[j + 1] = 0x011;       // set the color 0x0(VGA COLOR NUMBER CODE)
        }
        if (scolor == 7) {
            VGA_MEMORY[j + 1] = 0x013;       // set the color 0x0(VGA COLOR NUMBER CODE)
        }
        if (scolor == 8) {
            VGA_MEMORY[j + 1] = 0x015;       // set the color 0x0(VGA COLOR NUMBER CODE)
        }

        i++;
        scolor++;
        j += 2;
    }

    return 0;
}