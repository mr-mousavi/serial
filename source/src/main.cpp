#include <stdio.h>
#include "serial.hpp"
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char** argv) {
    Serial serial;
    if(serial.open("/dev/ttyS0", O_RDWR | O_NOCTTY)<=0){
    	printf("could not open serial port.\n");
	return -1;
    }
    printf("serial port is open successfuly .\n");
    if(serial.init(B9600)!=0){
	printf("could not init serial attributes.\n");
	return -2;	
    }
	
    //clearBuffer();
    char buf[] = "hello world";
    char buf2[100];
    while(1){
	 serial.write(buf,strlen(buf));
	 usleep(1000); 
	 serial.read(buf2, 100);
	 printf("%s\n", buf2);
	 usleep(1000); 
    }

    serial.close();

    return 0;
}
