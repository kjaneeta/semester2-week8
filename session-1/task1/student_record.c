/**
 * Implementation of a student record management system using structures
 * 
 * This program demonstrates the use of structures in C to manage student data
 * including personal information and module marks.
 */

#include <stdio.h>
#include <string.h>

#include "student_record.h"

/**
 * Calculate the average mark for a student
 * 
 * param student The student whose average mark is to be calculated
 * return float The average mark
 */
float calculate_average(struct student_record student) {
    // TODO: Implement this function to calculate and return the average
    // of the three module marks

    
    float sum = 0;
    for(int i = 0; i < 3; i++)
    {
        sum = sum + student.marks[i];
    }

    float avg = sum/3;

    return avg; // Placeholder return value
}

/**
 * Display student information including name, ID, marks, and average
 * 
 * student The student whose information is to be displayed
 */
void display_student(struct student_record student) {
    // TODO: Implement this function to display student information
    // Format: Name, ID, individual marks, and average mark

    printf("Name: %s, ID: %d, Marks: ", student.name, student.id);

    for (int i = 0; i < 3; i++) 
    {
        printf("%f ", student.marks[i]);
    }

    printf(", Average: %f\n", calculate_average(student));


}

/*
 * main
 */
int main( void ) {
    // TODO: Create and initialise a student variable with sample data
    // Example: name = "John Smith", id = 12345, marks = {75.0, 68.5, 81.0}
    
    struct student_record student = {"John Smith", 12345, {75.0f, 68.5f, 81.0f}};
    
    // TODO: display the student data and average mark
    display_student(student);
    printf("Average = %f\n", calculate_average(student));

    // Modify the student's name and third module mark
    strcpy(student.name, "Jane Doe"); // strcpy -> copy one string into another
    student.marks[2] = 85.0f;

    // Display updated student
    display_student(student);
    printf("Average = %f\n", calculate_average(student));

    return 0;
}