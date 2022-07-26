#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

uint32_t my_ntohl (uint32_t n){
	uint32_t n1 = (n & 0xFF000000) >> 24;
	uint32_t n2 = (n & 0x00FF0000) >> 8;
	uint32_t n3 = (n & 0x0000FF00) << 8;
	uint32_t n4 = (n & 0x000000FF) << 24;

	return n1 | n2 | n3 | n4;
}

uint32_t sum(uint32_t n1, uint32_t n2){
	n1 = my_ntohl(n1);	
	n2 = my_ntohl(n2);

        return n1 + n2;
}


int main(int argc, char *argv[]){
    FILE *file_arg1, *file_arg2;
    uint32_t read_1, read_2, result;
    uint32_t bf_save1;
    uint32_t bf_save2;
    uint32_t temp_1, temp_2, temp_3;

    if(argc == 3){
        file_arg1 = fopen(argv[1], "r");
        file_arg2 = fopen(argv[2], "r");

        read_1 = fread(&bf_save1, 4, 1, file_arg1);
        read_2 = fread(&bf_save2, 4, 1, file_arg2);

        result = sum(bf_save1,bf_save2);
	temp_1 = my_ntohl(bf_save1);
	temp_2 = my_ntohl(bf_save2);
	temp_3 = int(temp_1) + int(temp_2);

        printf("Sum of your input files = %d(0x%x) + %d(0x%x) =  %d(0x%x)\n", temp_1, temp_1, temp_2, temp_2, temp_3, result);

	return 0;
    }

    else{
        printf("Arg Error");
    }

}
