#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include "add-nbo.h"

#define BUFFER_SIZE 100

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Use: %s <filename> <filename>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "rb");
    if(!file1){
        printf("Error %s\n", argv[1]);
        return 1;
    }
    FILE *file2 = fopen(argv[2], "rb");
    if(!file2){
        printf("Error %s\n", argv[2]);
        fclose(file1);
        return 1;
    }
    uint8_t buffer[BUFFER_SIZE];
    uint32_t a;
    uint32_t b;
    
    fread(&a, sizeof(uint32_t), BUFFER_SIZE, file1);
    fread(&b, sizeof(uint32_t), BUFFER_SIZE, file2);
    
    uint32_t c = ntohl(a);
    uint32_t d = ntohl(b);

    uint32_t result = add_nbo(c,d);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n",c,c,d,d,result,result);
    
    fclose(file1);
    fclose(file2);
    return 0;
}