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