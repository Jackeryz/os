#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	const char* file_path = "f.txt";
	struct stat file_stat;
		if(stat(file_path,&file_stat)==-1){
			perror("stat");
			exit(EXIT_FAILURE);}
	printf("Info for file : %s\n",file_path);
	printf("File size : %ld bytes\n",file_stat.st_size);

return 0;
}
