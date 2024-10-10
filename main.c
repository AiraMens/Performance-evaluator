/********* main.c ********
	
	Student Name 	= AYRA MENSAH
	Student Number	= 101221911
*/

// Includes go here


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a1_functions.h"

int main() {
    // Beginning of code, welcome message and asking for user input

    printf("\n\nWelcome to ABC Project Tracker\n");
    printf("Enter total project's budget: ");
    float budget = get_input_f();
    printf("Enter total project's duration in weeks: ");
    float duration = get_input_f();

    //Calculate the planned number of employees and display it
    unsigned short int needed_employees = calculate_employees(duration, budget);
    printf("The planned number of employees needed is: %hu\n", needed_employees);


//Initializing the project details and milestones
    milestone_t project_details = init_milestone("Planned Details", budget);

    milestone_t milestones[6];
    milestones[0] = project_details;
    milestones[1] = init_milestone("Technical requirements", budget / 5);
    milestones[2] = init_milestone("System Design", budget / 5);
    milestones[3] = init_milestone("Software Development", budget / 5);
    milestones[4] = init_milestone("Testing", budget / 5);
    milestones[5] = init_milestone("Product release", budget / 5);

    
    


    while (1) {
        printf("\n--------------------------------------------------\n\n");
        print_menu();
        int x;
        int valid = 0; // Flag to check if input is valid or not

// Handle user input and make sure choice is valid
         do {
            x = get_input_usi();

            if (x >= 0 && x <= 5){
                valid = 1; // Set the flag to indicate input is valid)
            }else{
                printf("\n\n-----------------------------------------------\nThe value you entered is wrong\n");
                printf("Enter a value between 0 and 5: ");
                
            }
        } while (!valid);


        if (x == 0) {
            //Check completion of project and calculate total cost of project
            check_project_completion(milestones, 6);
            float total_cost = 0;
            for (int i = 0; i < 6; i++) {
                total_cost += milestones[i].cost;
            }

            printf("\n--------------------------------------------\n---------- Project's Performance ----------\n--------------------------------------\n\n");
      
            //Display project's performance
            print_stats(milestones[0]);
            
            //Check whether user wants to finish remaining milestones or not
            printf("Do you want to finish the remaining milestones? (Y/N) ");
            char finish_choice;
            scanf(" %c", &finish_choice);
            if (finish_choice == 'N' || finish_choice == 'n') {
                printf("\n\n--------------------------------------------\n");
                printf("------- Final Project's Performance --------\n");
                printf("--------------------------------------------\n\n");
                if (total_cost > milestones[0].cost) {
                    printf("The project's cost is above budget!\n");
                } else {
                    printf("The project's cost is below budget!\n");
                }
                printf("Planned budget: %.2f\n", milestones[0].cost);
                printf("Actual Cost: %.2f\n", total_cost);
                printf("\n\n\n--------------------------------------------\n");
                printf("--- The program will quit now! Goodbye! ---\n");
                printf("--------------------------------------------\n");
                break;
            }
        } else if (x >= 1 && x <= 5) {
            //Calculate the number of employees, print milestone stats and check for milestone completion
            number_of_employees(&milestones[x ]); // Calculate the number of employees
            print_stats(milestones[x ]);

            if (milestones[x ].completed) {
                printf("\n------------------------------------------\n%s milestone is completed\ncannot be updated\n", milestones[x ].name);
            } else {
                update_stats(milestones, x );
                print_stats(milestones[x ]);
            }
        } 
      
    }

    return 0;
}
