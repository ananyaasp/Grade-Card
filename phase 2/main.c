#include <stdio.h>
#include <stdlib.h>
#include "grade_calculator.h"

int main() {
    int num_students;
    num_students=10;
    
    Subject *subjects = create_subjects();

   
    Student *students = (Student *)malloc(num_students * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int s = 0; s < num_students; ++s) {
        students[s].name = (char *)malloc(50 * sizeof(char)); 
        printf("Enter details for student %d:\n", s + 1);
        printf("Enter student's name: ");
        scanf("%s", students[s].name);

       
        students[s].marks = (int **)malloc(6 * sizeof(int *));
        if (students[s].marks == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        for (int i = 0; i < 6; ++i) {
            students[s].marks[i] = (int *)malloc(3 * sizeof(int));
            if (students[s].marks[i] == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }

            printf("Enter marks for %s:\n", subjects[i]);
            for (int j = 0; j < 3; ++j) {
                printf("Test %d: ", j + 1);
                scanf("%d", &students[s].marks[i][j]);
            }
        }

        printf("\n");
        calculate_grade_card(&students[s], subjects, 6);
    }

    for (int i = 0; i < num_students; ++i) {
        free(students[i].name);
        for (int j = 0; j < 6; ++j) {
            free(students[i].marks[j]);
        }
        free(students[i].marks);
    }
    free(students);
    free_subjects(subjects, 6);

    return 0;
}
