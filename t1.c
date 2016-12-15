#include <stdio.h>
#include <stdlib.h>

unsigned char* ram;FILE* fp1;

char* get_command_address(){
	
}

char* get_cpu_command(){
	
}

void do_cpu_command(){
	fread(ram,1,1,fp1);
	printf("0x%x\n",*ram);
}

main(){
	ram = malloc(1024*1024);
	*(ram+1)=0b00000000;*(ram+2)=0b00000000;*(ram+3)=0b00000000;
	*(ram+4)=0b00000000;*(ram+5)=0b00000000;*(ram+6)=0b00000000;
	fp1 = fopen("/root/redant/test","rw");
	fread(ram,1,1,fp1);
	if( (*ram&0b10000000) == 0b10000000 ){
		*(ram+6)=*(ram+6)|0b00000001;
	}else{
		*(ram+6)=*(ram+6)&0b11111110;
	}
	if( (*ram&0b01000000) == 0b01000000 ){
		*(ram+7)=*(ram+7)|0b10000000;
	}else{
		*(ram+7)=*(ram+7)&0b01111111;
	}
	printf("end!\n");
}
