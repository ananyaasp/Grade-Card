#include <stdio.h>
#include "grade_calculator.h"

int main() {
    int num_students = 10;
    char name[50];
    int marks[6][3]; 

    
    for (int s = 0; s < num_students; ++s) {
        printf("Enter details for student %d:\n", s + 1);
        printf("Enter student's name: ");
        scanf("%s", name);

       
        printf("Enter marks for 6 subjects (Test 1, Test 2, Test 3):\n");
        for (int i = 0; i < 6; ++i) {
            printf("%s:\n", get_subject_name(i));
            for (int j = 0; j < 3; ++j) {
                printf("Test %d: ", j + 1);
                scanf("%d", &marks[i][j]);
            }
        }

       
        printf("\n");
        calculate_grade_card(name, marks);
    }

    return 0;
}

