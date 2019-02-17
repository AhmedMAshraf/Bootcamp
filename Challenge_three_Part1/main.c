/*
 * AUTHOR: Ahmed Nofal, Avelabs Embedded R&D software team
 */
#include <stdio.h>
/* Complete the function below to detect the endianness of the machine*/
void Detect_Endianness(void){
	int x = 0xABCDE123 ;
	char *p = &x ;

	if(*p == 0xAB)
	{
		printf("Big endian\n");
	}
	else{
		printf("Little endian\n");
	}
}

int main(void){
	Detect_Endianness();
}
