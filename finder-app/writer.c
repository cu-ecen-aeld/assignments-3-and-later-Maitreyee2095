#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

int main (int argc, char *argv[])
{
	openlog(NULL,0,LOG_USER);
	if(argc != 3)
	{
		printf("Invalid Number of arguments.\n1) File Path.\n2) String to be entered in the file.\n");
		syslog(LOG_ERR,"Invalid Number of arguments: %d",argc);
		exit(EXIT_FAILURE);
	} else {

		FILE *fhandle;
		const char *filename=argv[1];
		const char *writestr=argv[2];

		fhandle = fopen(filename, "w");
		if(fhandle == NULL)
		{
			perror("ERROR: Could not open file; fopen().\n");
			syslog(LOG_ERR,"Could not open file %s for write; fopen(), error was %d (%s)",filename,errno,strerror(errno));
			exit(EXIT_FAILURE);
		}
		syslog(LOG_DEBUG,"Writing %s to %s",writestr,filename);

		fprintf(fhandle, "%s\n",argv[2]);

		fclose(fhandle);
	}
	return 0;
}
