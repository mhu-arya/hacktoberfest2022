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



/*
    Login Function:
        1. This function first check if there are any accounts stored if there is no account the user is prompted to go to the intromenu function to create an account.
        2. If there is/are account(s) in the storage then the user enters the username.
        3. the program checks if the username exists before asking for password.
        4. if the user exists then user is prompted to enter password
        5. after that password validation occurs and based on that the program proceeds accordingly.
*/

void login(){
    bool found = false;
    string uname, paswd, dummy;
    int index;
    if (id.size() == 0 && password.size()  == 0){
        cout << endl;
        cout << "Currently we have no accounts!! Please create an account!" << endl;
        printIntroMenu();
    }
    else{
        getline(cin, dummy);
        cout << endl;
        cout << "Enter your User Name: ";
        getline(cin, uname);
        cout << endl;

        for(int i = 0; i < id.size(); i ++){
            if(uname == id[i]){
                found = true;
                index = i;
                break;
            }
        }
        if(found){
            cout << "Enter your Password: ";
            getline(cin, paswd);
            if(password[index] == paswd){
                cout << endl;
                cout << "****** LOGIN SUCCESSFULL ******" << endl << endl;
                printMainMenu(index, uname);
            }
            else{
                cout << endl;
                cout << "ERROR!!! PLEASE START AGAIN" << endl << endl;
                printIntroMenu();
            }
        }
        else{
            cout << "No such user exists!! Please Register!" << endl << endl;
            printIntroMenu();
        }
    }
}

/*
    addData function:
        1. It justs pushes the passed values into it to the vectors.
*/

void addData(string name, string pass){
    replace(name.begin(), name.end(), ' ', '_');
    id.push_back(name);
    replace(pass.begin(), pass.end(), ' ', '_');
    password.push_back(pass);
}

/* 

    Create a Account:
        1. user is prompted to create an account. By default the spaces get converted to underscores

*/

void createAccount(){
    string uname, paswd, dummy;
    getline(cin, dummy);
    cout << endl;
    cout << "Enter user name [spaces get converted to underscore]: ";
    getline(cin, uname);

    cout << endl;

    cout << "Enter a password[spaces get converted to underscore]: ";
    getline(cin, paswd);

    addData(uname, paswd);
    cout << endl;
    cout << "Thank You! Your account has been created!" << endl << endl;

    printIntroMenu();
}

/* 
    printMainMenu funtion:
        1. It is called if the login is successful
        2. It asks for the user choice for the functions like deposit, view balance, withdraw.
        3. the program proceeds further according to the input provided.
*/

void printMainMenu(int index, string uname){
    cout << endl;
    cout << "--------Hello, " << uname << "! Please select from options below --------" << endl << endl;
    cout << "d -> Deposit Money\nw -> Withdraw Money\nr -> Request Balance\nq -> Quit\n\n> " ;
    cin >> mainInput;

    switch (mainInput){
        case 'd':
            deposit(index, uname);
            break;
        case 'w':
            withdraw(index, uname);
            break;
        case 'r':
            request(index, uname);
            break;
        case 'q':
            cout << "Thank you, " << uname << "!" << endl << endl;
            printIntroMenu();
            break;
        default:
            cout << endl;
            cout << "Wrong Choice!! Please Enter Again!" << endl;
            printMainMenu(index, uname);
    }
}

/*
    deposit function:
        1. Facilitates the user to deposti amount into their account.
*/

void deposit(int index, string uname){
    cout << endl;
    int dpMoney;

    cout << "Enter the amount to be depostied: $";
    cin >> dpMoney;

    bal.at(index) += dpMoney;
    cout << endl;
    cout << "Deposited Successfully!!" << endl << endl;
    cout << "------------------------" << endl;


    printMainMenu(index, uname);
}
/*
    withdraw function:
        1. Checks for the balance in the acount first.
        2. If balance is 0 then moeny can't be withdrwan.
        3. Else the control moves further where user is asked for amount to be withdrawn
        4. the user has to enter amount and if enters more than the balance he/she has to enter again.
*/

void withdraw(int index, string uname){
    int wdMoney;
    /*try
    {
        cout << bal.at(index);
    }
    catch(const std::out_of_range& e)
    {
        cout << endl;
        cout << "No balance!! Please deposit some money first!" << endl;

    }*/
    // The vector.at() function throws an  std::out_of_range exception if there is null value at that particular index. This try catch block handles it.

    if(bal.at(index) == 0){
        cout << endl;
        cout << "Your balance is $0! You can't withdraw money right now!" << endl;
        printMainMenu(index, uname);
    }
    else{
        int i = 0;
        cout << endl;
        cout << "Enter amount to be withdrawn: $";
        cin >> wdMoney;
        while (!(wdMoney <= bal.at(index)))
        {
            if(i == 2){
                cout << endl;
                cout << "Sorry, invalid inputs recieved too many times! Start Again"<< endl;
                printMainMenu(index, uname);
                break;
            }
            cout << endl;
            cout << "You don't have sufficient balance!" << endl << endl;
            cout << "Enter amount to be withdrawn: $";
            cin >> wdMoney;
            i+=1;
        }
        
        cin.clear();
        bal.at(index) -= wdMoney;
        cout << endl;
        cout << "Transaction Successfull!!" << endl << endl;
        cout << "--------------------------" << endl;
        printMainMenu(index, uname);
    }
}

/*
    request funtion:
        1. Displays the user balance.
*/
void request(int index, string uname){
    if(bal.at(index) == 0){
        cout << endl;
        cout << "Your balance is $0!" << endl;
        printMainMenu(index, uname);
    }
    else{
        cout << endl;
        cout << "Dear, "<< uname << " your balance is: $"<< bal.at(index) << endl; 
        printMainMenu(index, uname);
    }
}