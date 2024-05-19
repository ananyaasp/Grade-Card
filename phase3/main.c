#include <stdio.h>
#include "grade_calculator.h"

#define MAX_STUDENTS 10

int main()
 {
    Student students[MAX_STUDENTS];
    int num_students;

    
    read_student_data("students.csv", students, &num_students);

    for (int s = 0; s < num_students; ++s) {

        printf("Marks for 6 subjects:\n");
        for (int i = 0; i < 6; ++i) {
            printf("%s:\n", get_subject_name(i));
            for (int j = 0; j < 3; ++j) {
                printf("Test %d: %d\n", j + 1, students[s].marks[i][j]);
            }
        }

        printf("\n");
        
        calculate_grade_card(students[s].name, students[s].marks);
    }

   
    return 0;
}
