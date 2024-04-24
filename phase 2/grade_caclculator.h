#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

typedef struct 
{
    char *name;
    int **marks; 
} Student;

typedef struct 
{
    char *name;
} Subject;

void calculate_grade_card(Student *student, Subject *subjects, int num_subjects);
char calculate_grade(float marks);
float calculate_points(int **marks, int num_subjects, int *credits);
Subject *create_subjects();
void free_subjects(Subject *subjects, int num_subjects);

#endif
