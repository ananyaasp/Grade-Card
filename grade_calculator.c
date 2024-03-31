#include <stdio.h>
#include "grade_calculator.h"

void calculate_grade_card(char *name, int marks[][3]) {
    int credits[] = {5, 5, 4, 4, 3, 1};
    int total_credits = 22; 
    float total_points = 0;

    for (int i = 0; i < 6; ++i) {
        float sum = 0;

        // Calculate average of marks for the subject
        for (int j = 0; j < 3; ++j) {
            sum += marks[i][j];
        }
        
        // Calculate average of marks
        sum /= 3;

        total_points += sum / 10 * credits[i]; 
    }

   
    float sgpa = total_points / total_credits;

    // Display grade card
    printf("\n--------Grade Card for %s--------\n", name);
    for (int i = 0; i < 6; ++i) {
        float sum = 0;

    
        for (int j = 0; j < 3; ++j) {
            sum += marks[i][j];
        }
        
        sum/= 3;

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
