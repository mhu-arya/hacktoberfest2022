#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input

/*
    Pre-Defining all the functions to be used in the program.
    All global variables declared here.
*/

using namespace std;
char menuInput;
char mainInput;

// Vectors support dynamic assignment so used over arrays in this project

vector<string> id;
vector<string> password;
vector<int> bal(9999, 0);

// Definition of all functions

void printIntroMenu();
void printMainMenu(int index, string uname);
void start();
void login();
void createAccount();
void addData(string name, string pass);
void deposit(int index, string uname);
void withdraw(int index, string uname);
void request(int index, string uname);

/*
    The main function just invokes the start function which kicks off the rest of the program;

    Start Function:
        1. Calls the printIntroMenu() Function to print the entry menu;
        2. User selects the options shown and the program moves forward accordingly.
*/

int main(){
    cout << "Hello, User!! Welcome to this ATM Project!" << endl;
    cout << endl;
    start();
    return 0;
}

void start(){
    cout << "Please Select an option from the menu below: " << endl;
    printIntroMenu();
}

/*
    printIntroMenu() function:
        1. Asks the user for the choice of the function he/she wants to perform
        2. Proceeds the program accordingly.
        3. If the user enters wrong choice he/she will be prompted to enter the values again.
*/

void printIntroMenu(){
    cout << "l -> Login\nc -> Create New Account\nq -> Quit\n\n> " ;
    cin >> menuInput;
    switch (menuInput){
        case 'l':
            login();
            break;
        case 'c':
            createAccount();
            break;
        case 'q':
            exit(0);
            break;
        default:
            cout << "Please enter correct input!!! \n" << endl;
            printIntroMenu();
            break;
    }
}