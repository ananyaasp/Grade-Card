#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

typedef struct {
    char name[50];
    int marks[6][3];
} Student;

void calculate_grade_card(char *name, int marks[][3]);
char calculate_grade(float marks);
const char *get_subject_name(int subject_num);
void read_student_data(const char *filename, Student students[], int *num_students);


#endif
