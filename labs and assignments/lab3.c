// Made by Benjamin Haedt for CSCI 112, taught by MaryAnn Cummings, Fall 2020 Semester at MSU Bozeman
//This program grades a n-question test and provides the grade for each test-taker and provides how many students missed each question
//

#include <stdio.h> //this lets us use stdio.h in program, used for basic input/output

void printNumMissed(const int missedBy[], int numOfQuestions){ //function to print the number of answers missed
	printf("Question\t");			//a print statement
	for (int i = 0; i < numOfQuestions; i++){		//a for loop that prints out the number of questions, how much detail do you want when i comment? last time i didnt put a overall discription and got docked points
		printf("%d ", i+1);	//part of the for loop that prints out the actual numbers
	}
	printf("\nMissed by\t");		//prints missed by on the screen
	for (int i = 0; i < numOfQuestions; i++){		// the next for loop in this function
		printf("%d ", missedBy[i]);		
	}
	printf("\n");
	return;		//ends the function
}

void printRightAnswers(const char answers[], int number){ // the other function as requried by the assignment, it prints the right answers
	printf("Questions\t");
	for (int i = 0; i < number; i++){
		printf("%d ", i+1);
	}
	printf("\nAnswers\t      ");
	for (int i = 0; i <= number; i++){
		printf("%c ", answers[i]);
	}
	printf("\n");
	return;
}

int main(void){			//out main function
	int numOfQuestions, id;		//delcairs our integer variables
	char answer;			//declares our char variables
	scanf("%d", &numOfQuestions);		// scans stdin  and puts it into the variable numOfQuestions
//	printf("%d", numOfQuestions);
	char rightAnswers[numOfQuestions];	//sets up our array of right answers
	int missedBy[numOfQuestions];		//sets up the array that holds the number of questions missed
	for (int i = 0; i <= numOfQuestions; i++){	//initializes each value in the missedby array to 0
		missedBy[i] = 0;
	}

	for (int i = 0; i <= numOfQuestions; i++){ //puts the right answers into the rightanswer array
		scanf("%c", &rightAnswers[i]);
	}

	printRightAnswers(rightAnswers, numOfQuestions); //calls the printRightAnswers function
	printf("ID\tGrade(%%)\n");

	while (scanf("%d ", &id) == 1){		//while loop that will go through each student, compute their grade, then print it to the screen, also adds  to the missedBy array to show how many students missed each question
		printf("%d\t", id);
		int missed = numOfQuestions;
		for (int i = 0; i < numOfQuestions; i++){
			scanf("%c", &answer);
			if (answer != rightAnswers[i+1]){
				missedBy[i] += 1;
				missed -= 1;
			}
		}
		double percentMissed = (double) missed / (double) numOfQuestions;
		percentMissed = percentMissed * 100;
		printf("%.2f\n", percentMissed);
	}
	printNumMissed(missedBy, numOfQuestions);
	return(0);
}

