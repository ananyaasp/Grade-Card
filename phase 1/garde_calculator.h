#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

void calculate_grade_card(char *name, int marks[][3]);
char calculate_grade(float marks);
float calculate_points(int marks);
const char *get_subject_name(int subject_num);

#endif
