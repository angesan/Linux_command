#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int main(int argc,char *argv[]){
	int rfd;//File descripter
	char buf[128];
	int i=0;
	for( i = 1;i<argc;i++){
	
		int charCount=0;
		int wordCount=0;
		int lineCount=0;

		rfd=open(argv[i],O_RDONLY);
		if(rfd == -1){
			fprintf(stderr,"No such file or directory\n");
			exit(1);
		}
		

		
		while(read(rfd,buf,1)!=0){
			charCount++;
			if(buf[0] ==' ' || buf[0]== '\n'){
				wordCount++;
			}
			if(buf[0] =='\n'){
				lineCount++;
			}
		}
		printf(" %4d %4d %4d %s\n",lineCount,wordCount,charCount,argv[i]);

		close(rfd);
	}
	return 0;
}
