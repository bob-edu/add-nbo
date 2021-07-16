#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t readFile(char * fileName) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        fprintf(stderr, "[!] Cannot open the file!\n");
        exit(EXIT_FAILURE);
    }

    uint32_t buffer;
    size_t count = fread(&buffer, 1, 4, fp);
    if (count != 4) {
        fprintf(stderr, "[!] File size is not 4 bytes!\n");
    }

    fclose(fp);

    return htonl(buffer);
}

int main(int argc, char *argv[])
{
    uint32_t num1, num2, sum;

    num1 = readFile(argv[1]);
    num2 = readFile(argv[2]);

    sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);
    
    return 0;
}
