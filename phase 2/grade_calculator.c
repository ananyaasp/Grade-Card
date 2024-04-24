#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
    char *name;
    int **marks; 
} Student;


typedef struct {
    char *name;
} Subject;

void calculate_grade_card(Student *student, Subject *subjects, int num_subjects);
char calculate_grade(float marks);
Subject *create_subjects();
void free_subjects(Subject *subjects, int num_subjects);

void calculate_grade_card(Student *student, Subject *subjects, int num_subjects) 
{
    int credits[] = {5, 5, 4, 4, 3, 1};
    int total_credits = 22;
    float total_points = 0;

    printf("\n--------Grade Card for %s--------\n", student->name);
    for (int i = 0; i < num_subjects; ++i) {
        float sum = 0;

        for (int j = 0; j < 3; ++j) {
            sum += student->marks[i][j];
        }

        sum /= 3;

        total_points += sum / 10 * credits[i];

        char grade = calculate_grade(sum);
        printf("%s: Grade %c\n", subjects[i].name, grade);
    }
    float sgpa = total_points / total_credits;
    printf("SGPA: %.2f\n\n", sgpa);
}

char calculate_grade(float marks) {
    if (marks >= 90)
        return 'S';
    else if (marks >= 80)
        return 'A';
    else if (marks >= 70)
        return 'B';
    else if (marks >= 60)
        return 'C';
    else if(marks >= 50)
        return 'D';
    else if(marks >= 40)
        return 'E';
    else
        return 'F';
}

Subject *create_subjects() {
    Subject *subjects = (Subject *)malloc(6 * sizeof(Subject));
    if (subjects == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    subjects[0].name = "Physics";
    subjects[1].name = "C";
    subjects[2].name = "EEE";
    subjects[3].name = "Math";
    subjects[4].name = "Mechanics";
    subjects[5].name = "EVS";

    return subjects;
}

void free_subjects(Subject *subjects, int num_subjects) {
    for (int i = 0; i < num_subjects; ++i) {
        free(subjects[i].name);
    }
    free(subjects);
}
