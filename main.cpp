#include <iostream>
#include "snowman.hpp"
#include <limits>

int main()
{
    bool exit = false;
    cout << "***************************\nWelcome to SNOWMAN program!\n***************************\n";
    cout << "There are two rules for using this application:" << endl;
    cout << "1 - The input must be a number with length of 8." << endl;
    cout << "2 - For every digit 'i': 1 <= i <= 4." << endl;
    cout << "If you wish to exit press: -1 and then click \"Enter\"" << endl;
    cout << "Now please choose your snowman: " << endl;
    int num = 0;
    while (!exit)
    {
        cin >> num;
        if(cin.fail()){
            cout << "Please enter an integer number! otherwise the program will not work correctly..\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (num == -1){

            exit = true;
        }
        else
        {
            try
            {
                cout << ariel::snowman(num) << endl;               
            }
            catch (string message)
            {
                cout << "Caught exception: " << message;
            }
            catch (std::out_of_range message)
            {
                cout << "Caught exception: " << message.what();
            }
            cout << "Please choose again or press -1 to quit.\n";
        }
    }
    cout << "Thanks for using the program, you can write (in the terminal)- \"make clean\" to delete the files.\n";
    return 0;
}