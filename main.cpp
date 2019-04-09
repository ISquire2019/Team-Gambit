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
void populateVector(vector<string>);

int main()
{
    vector<string>words;

    //rand function
    unsigned seed = time(NULL);
    srand(seed);

    //initialize variables
    string answer;

    //choose a random answer
    int choice;

    displayMenu(choice);

    populateVector(words);


    return 0;
}
void displayMenu(int & choice)
{
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
void populateVector(vector<string>arr)
{
    ifstream iFile;


    //choose a file to open
    int chance = rand() % 5 + 1;

    switch(chance)
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
    default:
        cout << "Something went wrong." << endl;
        cout << "Try again." << endl;
        cout << "Exiting..." << endl;
        break;
    }
    cout << "Reading file " << iFile << "..." << endl;

    cout << "Populating vector..." << endl;


    //supposedly, I'd place the data within the file within each part of the vector
    //VVVV

}
