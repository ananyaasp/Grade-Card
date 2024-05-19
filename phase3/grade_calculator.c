#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grade_calculator.h"

void read_student_data(const char *filename, Student students[], int *num_students) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", num_students);
    for (int i = 0; i < *num_students; ++i) {
        fscanf(file, "%s", students[i].name);
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 3; ++k) {
                fscanf(file, "%d", &students[i].marks[j][k]);
            }
        }
    }

    fclose(file);
}


void calculate_grade_card(char *name, int marks[][3]) {
    int credits[] = {5, 5, 4, 4, 3, 1};
    int total_credits = 22; 
    float total_points = 0;

    for (int i = 0; i < 6; ++i) {
        float sum = 0;

        for (int j = 0; j < 3; ++j) {
            sum += marks[i][j];
        }
        
        
        sum /= 3;

        total_points += sum / 10 * credits[i]; 
    }

   
    float sgpa = total_points / total_credits;

   
    printf("\n--------Grade Card for %s--------\n", name);
    for (int i = 0; i < 6; ++i) {
        float sum = 0;

    
        for (int j = 0; j < 3; j++) {
            sum += marks[i][j];
        }
        
        sum /= 3;

        char grade = calculate_grade(sum); 
        printf("%s: Grade %c\n", get_subject_name(i), grade);
    }
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

const char *get_subject_name(int subject_num) {
    switch (subject_num) {
        case 0:
            return "Physics";
        case 1:
            return "C";
        case 2:
            return "EEE";
        case 3:
            return "Math";
        case 4:
            return "Mechanics";
        case 5:
            return "EVS";
        default:
            return "Unknown";
    }
}
