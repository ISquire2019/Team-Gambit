#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //exit function
#include <time.h> //time NULL
#include <stdlib.h> //rand(); srand()
#include <vector>

using namespace std;


//prototypes
void displayMenu(int &);
void populateVector(vector<string>, int);

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

    populateVector(words,choice);


    return 0;
}
void displayMenu(int & choice)
{
    /*
    Function: displayMenu
    Programmer: Isaiah Sule
    Date: 4-8-2019
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
void populateVector(vector<string>arr, const int choice)
{
    /*
    Function: populateVector
    Programmer: Isaiah Sule
    Date: 4-8-2019
    Description: Opens a file based on t
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
        cout << "Something went wrong. File not found" << endl;
        cout << "Try again." << endl;
        cout << "Exiting..." << endl;
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
    string answer;

    int arrIndex;

    arrIndex = rand() % arr.size() + 1; // between 1 to the max size of the array

    answer = toupper(arr.at(arrIndex));

}
