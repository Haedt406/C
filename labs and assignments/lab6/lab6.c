//Made by Benjamin Haedt, Falll 2020 semester, CSCI112, MSU Bozeman
//This program reads in all the current processes that are running (using ps aux). 
//then finds the last user to do a bash process (is -bash).
//then does a finder command on that net id and prints out the user's name and the last time they logged in

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>


int main(void) {
	char* answer = malloc(sizeof(char) * 2000);	//creates our character strings we will use and mallocs the memory
	char* match = "-bash";
	char* user = malloc(sizeof(char) * 8);
	char* endUser = malloc(sizeof(char) * 30);
	
    if (fork() == 0) {  // our first fork, child process, to take the date and put it into a txt file
        int fd;
        if  ((fd = open("out.txt", O_RDWR|O_CREAT,S_IRUSR|S_IWUSR)) == -1) {
            perror("Error: could not open\n");
            exit(1);
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
		execl("/bin/ps", "/bin/ps", "aux", "--sort", "-etime", NULL);
    }
	
    else { //parent process, find the data we need for the next part
		wait(NULL);
		FILE* infptr = fopen("out.txt", "r");
		if (infptr == NULL){
			printf("ERROR: could not open input file\n");
			return(0);
		}
		char* line = malloc(sizeof(char) * 2000);
		fgets(line, 2000, infptr);
		//printf("%s\n", line);
		while(fgets(line, 2000, infptr) != NULL){
				if(strstr(line, match) != NULL){
					if(strstr("root", line) != 0 || strstr("s68j891", line) !=0){
						strcpy(answer, line);
						strcpy(user, strtok(answer, " "));
					}
				}	
		}
		free(line);
		fclose(infptr);
	}
	if (fork() == 0){ //second child process, puts the data of one user into another txt file
		int fingerOut;
        // This function makes a system call to open a file
        if  ((fingerOut = open("fingerOut.txt", O_RDWR|O_CREAT,S_IRUSR|S_IWUSR)) == -1) {
            perror("Error: could not open\n");
            exit(1);
        }
        dup2(fingerOut, STDOUT_FILENO);
        close(fingerOut);
		execl("/bin/finger", "/bin/finger", user, NULL);
	}
    else {														 				//out last parent process, prints the information we need from the last text file
		wait(NULL);
		FILE* infptr = fopen("fingerOut.txt", "r");
		if (infptr == NULL){													//tells the program to exit if the file cannot be opened
			printf("ERROR: could not open input file\n");
			return(0);
		}
		char* line = malloc(sizeof(char) * 1000);
		fgets(line, 1000, infptr);
		strtok(line, ":");
		strtok(NULL, ":");
		strcpy(endUser, strtok(NULL, ":"));
		fgets(line, 1000, infptr);
		
		while ((strcmp(line, "On Since")) != 0 && ((strcmp(line, "last login")) !=0)){ //searches the fingerOut file for the information we need
				if(strstr("On Since", line) == 0){
					printf("Name is %s \n %s", endUser, fgets(line,1000,infptr));
					break;
				}
				fgets(line, 1000, infptr);
		}
		free(line); 															//frees the lines being read in after each switch between threads
		fclose(infptr);															//closes the file we opened and modified
	}

	return(1);																	//returns a successful completion
}


