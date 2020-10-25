 /* ---------------------------------------------------------
 mastermind.cpp

 Author: Mayur Patel

 Description of Program:
 The program selects 3 distinct random digits 0..9.
 On each turn you guess 3 digits. The program indicates
 how many are correct. You have 10 moves to guess the number.
 Input of 000 displays the hidden digits. Input of 999 exits the program.
 -----------------------------------------------------------
 */

#include <iostream>  //output and input library
#include <iomanip>   //used to setw for spacing
#include <cstdlib>   //c standard library
#include <time.h>    //time to seed random

using namespace std; //classes and functions from standard namespace

//function to print the header of the program
void printHeader() {
    cout << "MasterMind\n\n"
         << "The program selects 3 distinct random digits 0..9.\n"
         << "On each turn you guess 3 digits. The program indicates\n"
         << "how many are correct. You have 10 moves to guess the number.\n"
         << "Enter the three digits on each turn with spaces in between.\n"
         << "Good luck!\n\n"
         << "Input of 000 displays the hidden digits. Input of 999 exits the program.\n\n";
}

//function to run the game
void runGame() {
    int digitUser[3],      //array for the users input
        digitComputer[3],  //array for the computer generated numbers
        inPlace = 0,       //variable to show if right number is in place
        outPlace = 0,      //variable to show if right number is in any of the inputs
        i;                 //variable for the use of loops
    
    //generates the numbers the user needs to match to win the game
    digitComputer[0] = rand() % 10;
    digitComputer[1] = rand() % 10;
    digitComputer[2] = rand() % 10;
    
    //loop to make sure that the second number generated is not similar to the first number
    while (digitComputer[0] == digitComputer[1]) {
        digitComputer[1] = rand() % 10;
    }
    
    //loop to make sure the last number generated is not the same as the first two numbers
    while (digitComputer[2] == digitComputer[0] || digitComputer[2] == digitComputer[1]) {
        digitComputer[2] = rand() % 10;
    }
    
    //prints the header of the program
    printHeader();   
    
    //displays and sets the width of the checking system
    cout << setw(34) << "In place" << setw(19) << "Out of place\n" 
         << setw(34) << "--------" << setw(19) << "------------\n";
    
    //loop that runs 11 times to have the user keep inputting numbers until turns run out or until the user gets the numbers right
    for (i = 0; i <= 10; ++i) {
        inPlace = 0;    //keeps setting the inPlace value to 0 to make sure the checking system resets
        outPlace = 0;   //keeps setting the outPlace value to 0 to make sure the checking system resets
        
        //checks if the user's last turn has been used up and ends the loop
        if (i == 10) {
            cout << "\nBetter luck next time.\n\nExiting Program...\n";
            break;
        }
        
        //gets and displays the users guess
        cout << i + 1 << ". Your guess: ";
        cin >> digitUser[0] >> digitUser[1] >> digitUser[2];
        cout << "\tYou entered: " << digitUser[0] << digitUser[1] << digitUser[2];
        
        //checks user input for 000 to show hidden computer generated numbers and 999 to end the program
        if (digitUser[0] == 0 && digitUser[1] == 0 && digitUser[2] == 0) {
            cout << "\n\tHidden digits: " << digitComputer[0] << digitComputer[1] << digitComputer[2] << endl;
            continue;  //goes to the next iteration of the loop
        }
        else if (digitUser[0] == 9 && digitUser[1] == 9 && digitUser[2] == 9) {
            cout << "\n\nExiting Program...\n";
            exit(0);  //exits the program
        }
        
        //nested if statements to check which digits are in place and sets the inPlace value accordingly
        if ((digitUser[0] == digitComputer[0]) || (digitUser[1] == digitComputer[1]) || (digitUser[2] == digitComputer[2])) {
            inPlace = 1;
            if (((digitUser[0] == digitComputer[0]) && (digitUser[1] == digitComputer[1])) || ((digitUser[1] == digitComputer[1]) && (digitUser[2] == digitComputer[2])) || ((digitUser[0] == digitComputer[0]) && (digitUser[2] == digitComputer[2]))) {
                inPlace = 2;
                if (digitUser[0] == digitComputer[0] && digitUser[1] == digitComputer[1] && digitUser[2] == digitComputer[2]) {
                    inPlace = 3;
                    cout << setw(10) << inPlace << setw(18) << outPlace << endl << "\n\n***Congratulations!***\n\nExiting Program...\n"; 
                    break;  //exits loop after user wins
                }
            }
        }
        
        //nested if statement to check which number of out of place and sets outPlace accordindly
        if ((digitUser[0] == digitComputer[1] || digitUser[0] == digitComputer[2]) || (digitUser[1] == digitComputer[0] || digitUser[1] == digitComputer[2]) || (digitUser[2] == digitComputer[0] || digitUser[2] == digitComputer[1])) {
            outPlace = 1;
            if (((digitUser[0] == digitComputer[1] || digitUser[0] == digitComputer[2]) && (digitUser[1] == digitComputer[0] || digitUser[1] == digitComputer[2])) || ((digitUser[0] == digitComputer[1] || digitUser[0] == digitComputer[2]) && (digitUser[2] == digitComputer[0] || digitUser[2] == digitComputer[1])) || ((digitUser[1] == digitComputer[0] || digitUser[1] == digitComputer[2]) && (digitUser[2] == digitComputer[0] || digitUser[2] == digitComputer[1]))) {
                outPlace = 2;
                if ((digitUser[0] == digitComputer[1] || digitUser[0] == digitComputer[2]) && (digitUser[1] == digitComputer[0] || digitUser[1] == digitComputer[2]) && (digitUser[2] == digitComputer[0] || digitUser[2] == digitComputer[1])) {
                    outPlace = 3;
                }
            } 
        }
        
        //displays inPlace and outPlace to let user know their progress
        cout << setw(10) << inPlace << setw(18) << outPlace << endl;
    }   
}

//main function to run the whole program
int main() {
    srand(time(NULL));  //initializes seed of random to time
    
    runGame();          //calls the runGame function
    
    return 0;           //ends the program after everything is run through
}