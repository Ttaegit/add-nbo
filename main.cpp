#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>


int main(int argc, char *argv[]) {

    uint32_t file1, file2;
    	FILE *file = fopen(argv[1], "r");
    	fread(&file1, sizeof(uint32_t), 1, file); //fread 파일안의 문자열 읽기, & 구조체 변수, sizeof 괄호안 구조체 크기 입력
    	fclose(file);

    	file = fopen(argv[2], "r");
    	fread(&file2, sizeof(uint32_t), 1, file);
    	fclose(file);
    
    	file1 = ntohl(file1); 
    	file2 = ntohl(file2);

    	printf ("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", file1, file1, file2, file2, file1 + file2, file1 + file2);
} //%d 10진수 정수 출력, %x int 값을 부호없는 16진수로 출력 
