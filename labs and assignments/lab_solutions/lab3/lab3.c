#include <stdio.h>

#define MAX_QUESTIONS 10

void PrintRightAnswers(char ra[], int n) {
   printf("Question\t");
    for (int i= 0; i < n; ++i) {
        printf("%d ", i+1);
    }
    printf("\nAnswer\t\t");
    for (int i = 0; i < n; ++i) {
        printf("%c ", ra[i]);
    }
    printf("\n");
    return;
}

void PrintNumMissed(int mn[], int n) {
   printf("Question\t");
    for (int i= 0; i < n; ++i) {
        printf("%d ", i+1);
    }
    printf("\nMissed By\t");
    for (int i = 0; i < n; ++i) {
        printf("%d ", mn[i]);
    }
    printf("\n");
    return;
}

int ReadRightAnswers(char ra[]) {
    int num;
    scanf("%d ", &num); // read in number of questions on test
    for (int i = 0; i < num; ++i) {
        scanf("%c", &ra[i]); // read in each right answer
    }
    return num;
}

void ProcessAnswers(int n, char ra[], int mn[]) {

    int id;
    char answer;
    int num_wrong;

    printf("ID\tGrade(%%)\n");
    while (scanf("%d ", &id) == 1) {  //read in student id
        num_wrong = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%c", &answer); // read in one answer
            if (ra[i] != answer) {
                ++num_wrong;
                ++mn[i]; // how many students missed a 
                         // question
            }
        }

        // determine percentage right
        double grade =  ((double)(n-num_wrong)/(double)n);

        // print student id and grade
        printf("%d\t%.2lf\n", id, grade*100.0);
    }
    return;
}

int main(void) {

    int num_questions;

    char right_answers[MAX_QUESTIONS];
    int missed_number[MAX_QUESTIONS] =
                    {[0 ... MAX_QUESTIONS-1] = 0};

    // read in number of questions and right answers
    num_questions = ReadRightAnswers(right_answers);

    PrintRightAnswers(right_answers, num_questions);

    // process each student's answers
    ProcessAnswers(num_questions, right_answers,
                    missed_number);

    // Print how many students missed each question
    PrintNumMissed(missed_number, num_questions);

    return(0);
}

