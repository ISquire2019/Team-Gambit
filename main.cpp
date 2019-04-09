#include <iostream>
#include <fstream> //ifstream, ofstream
#include <cstdlib> //exit function
#include <time.h> //time NULL
#include <stdlib.h> //rand(); srand()
#include <algorithm> //sorting
#include <string> //toupper
#include <vector> //vectors, push_back(), etc.

using namespace std;


//prototypes
void displayMenu(int &);
void populateVector(vector<string> & , int);
void chooseSecretAnswer(vector<string>);

int main()
{
    vector<string>words;

    //rand function
    unsigned seed = time(NULL);
    srand(seed);

    //initialize variables
    string answer;

    int choice;

    displayMenu(choice);

    if(choice == 6)
    {
        cout << "Thank you for playing our game" << endl;
        cout << "Have a good day." << endl;
        return 0;
    }


    populateVector(words,choice);

    //char choices[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    chooseSecretAnswer(words);

    return 0;
}
void displayMenu(int & choice)
{
    /*
    Function: displayMenu
    Programmer: Isaiah Sule
    Date: 4-9-2019
    Description: Has the user choose the topic they wish to use to play Hangman.
    */
    do
    {
        cout << "Please choose from the following options:" << endl;
        cout << "1. Animals" << endl;
        cout << "2. Sports" << endl;
        cout << "3. Cars" << endl;
        cout << "4. Fruits and Vegetables" << endl;
        cout << "5. Countries" << endl;
        cout << "6. Exit" << endl;
        cout << "Your choice: " << endl;

        cin.clear();
        cin.sync();
        cin >> choice;

    }while(cin.fail() || choice > 6 || choice < 1);
}
void populateVector(vector<string> &arr, const int choice) //choice should not be interfered with while in this function
{
    /*
    Function: populateVector
    Programmer: Isaiah Sule
    Date: 4-9-2019
    Description: Opens a file based on the choice the user made from the last function
    Parameters: vector<string> & arr, const int choice
    */
    ifstream iFile;

    switch(choice)
    {
    case 1:
        iFile.open("Animals.txt");
        break;
    case 2:
        iFile.open("Sports.txt");
        break;
    case 3:
        iFile.open("Cars.txt");
        break;
    case 4:
        iFile.open("Fruits and Vegetables.txt");
        break;
    case 5:
        iFile.open("Countries.txt");
        break;
    default: //safe code
        cout << "Something went wrong. File not found." << endl;
        cout << "Try again." << endl;
        cout << "EXITING..." << endl;
        break;
    }

    //place data into the vector
    string line; //stores data from each line of the file
    while(!iFile.eof())
    {
        getline(iFile,line);
        arr.push_back(line);
    }
}
void chooseSecretAnswer(vector<string>arr)
{
    /*
    Function: chooseSecretAnswer
    Programmer: Isaiah Sule
    Date: 4-9-2019
    Description: Creates an index out of a random number between 1 and the size of the vector.
                 Stores the result in an integer, arrIndex.
                 Declares secret answer using the stored index.
    Parameters: vector<string>arr
    */
    string secretAnswer;
    int arrIndex;

    arrIndex = rand() % arr.size() + 1; // between 1 and the max size of the vector
    secretAnswer = arr.at(arrIndex);

    cout << "The secret answer is " << secretAnswer << endl;
}
