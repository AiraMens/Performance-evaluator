/********* definitions.c ********
	
	Student Name 	= AYRA MENSAH
	Student Number	= 101221911
*/

// Your solution goes here
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a1_functions.h"


#define MAX_HOURS 40.0
#define HOURLY_RATE 25.0

// Function to calculate the number of employees needed for the entire project

void number_of_employees(milestone_t *project_details) {
    project_details->num_employees = calculate_employees(project_details->time, project_details->cost);
}
// Function to calculate the number of employees needed for the project based on cost and time
unsigned short int calculate_employees(float duration, float budget) {
    // Calculate the number of employees needed based on the given formula
    float fulltime_salary = duration * HOURLY_RATE * MAX_HOURS ;
    float weekly_cost = budget / duration;
    unsigned short int employees = (unsigned short int)round( weekly_cost / (MAX_HOURS * HOURLY_RATE));
    return employees;
    
}


// Function to initialize a milestone
milestone_t init_milestone(char stage_name[], float assigned_budget) {
    milestone_t milestone;
    strcpy(milestone.name, stage_name);
    milestone.cost = assigned_budget;
    milestone.time = 0.0;
    milestone.num_employees = 0;
    milestone.completed = 0;
    return milestone;
}

// Function to get user input for unsigned short int
unsigned short int get_input_usi(void) {
    unsigned short int input;
    do {
        scanf("%hu", &input);
        if (input < 0) {
            printf("\n-------------------------------------\nThe value you entered is wrong\nEnter a positive value: ");
        }
    } while (input < 0);
    return input;
}

// Function to get user input for float
float get_input_f(void) {
    float input;
    do {
        scanf("%f", &input);
        if (input < 0) {
            printf("\n-------------------------------------\nThe value you entered is wrong\nEnter a positive value: ");
        }
    } while (input < 0);
    return input;
}

// Function to print the menu
void print_menu(void) {
    printf("Which milestone you want to update? (0 to exit):\n");
    printf("1. Technical requirements\n");
    printf("2. System Design\n");
    printf("3. Software Development\n");
    printf("4. Testing\n");
    printf("5. Product release\n");
    printf("\n\nYour choice is: ");
}

// Function to print the stats of a milestone
void print_stats(milestone_t details) {
    printf("\n\n------------- Milestone Stats --------------\n");
    printf("Below is \"%s\" current stats:\n", details.name);
    printf("--------------------------------------------\n\n");
    printf("Actual time: %.2f weeks\n", details.time);
    printf("Actual number of employees: %hu\n", details.num_employees);
    printf("Actual cost: %.2f$\n", details.cost);
    printf("Completed: %s\n", details.completed ? "Yes" : "No");
}

// Function to update the stats of a milestone

void update_stats(milestone_t milestone_array[], int milestone_num) {
    float actual_time, actual_cost;
    int actual_num_employees;
    char complete_choice;


    printf("\n\n-------------- Update Stats -------------\n\n");

    printf("Enter the milestone's actual time: ");
    scanf("%f", &actual_time);
    printf("Enter the milestone's actual number of employees: ");
    scanf("%d", &actual_num_employees);
    printf("Is this milestone complete? (Y/N) ");
    scanf(" %c", &complete_choice);

    actual_cost = actual_time * actual_num_employees * HOURLY_RATE;
    milestone_array[milestone_num].time = actual_time;
    milestone_array[milestone_num].num_employees = actual_num_employees;
    milestone_array[milestone_num].cost = actual_cost;

    if (complete_choice == 'Y' || complete_choice == 'y') {
        milestone_array[milestone_num].completed = 1;
    }

    printf("Stats Updated!\n\n");
}



// Function to check if all milestones are completed or not
void check_project_completion(milestone_t milestone_array[], int num_milestones) {
    int mile_completed = 1; // Assume all milestones are completed
    for (int i = 1; i < num_milestones; i++) {
        if (!milestone_array[i].completed) {
            mile_completed = 0; // At least one milestone is not complete
            break;
        }
    }

    // Update the project's completion status if necessary
    if (mile_completed) {
        milestone_array[0].completed = 1;
    }
}
