#include <stdlib.h> // exit()
#include <stdio.h>
#include <syslog.h> // syslog(), openlog()
#include <sys/stat.h> 
#include <fcntl.h> // open(), flags

int main(int argv, char ** argc){
	
	// make sure user inputted only 1 argument
	if(argv != 2){
		printf("Error: Expected 1 argument of a filename\n");
		exit(EXIT_FAILURE);
	}
	
	const char LOG_FILE[] = "logger_file"; // name of customer logger file
	char* fileName; // pointer to argument file name
	fileName = argc[1]; // fileName inputted from the user
	
	// open the user-inputted file
	int n_open = open(fileName, O_RDONLY); // open file with read-only
	
	// -1 is returned when an error occurs in opening the file
	if(n_open == -1){
		 
		// opens connection to the system logger to input the custom log file 
		openlog(LOG_FILE, LOG_INFO | LOG_USER, LOG_USER);
		
		// log err message to custom log file
		syslog(LOG_ERR, "(Tarek/Tavid) ERROR: An error occured in trying to open the file %s\n", fileName);
	}
	// no err was returned by open
	else {
		
		// opens connection to the system logger to input the custom log file 
		openlog(LOG_FILE, LOG_ERR | LOG_INFO | LOG_USER, LOG_ERR);
		
		// log success message to custom log file
		syslog(LOG_ERR, "(Tarek/Tavid) Success: Opened file, %s\n", fileName);
	}
	
	// terminate program
	exit(EXIT_SUCCESS);
}
