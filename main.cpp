#include <iostream>
#include <fstream> //ifstream, ofstream
#include <cstdlib> //exit function
#include <time.h> //time NULL
#include <stdlib.h> //rand(); srand()
#include <algorithm> //sorting
#include <string> //toupper
#include <vector> //vectors, push_back(), etc.

using namespace std;

const int MIN_WORD = 1; //const since there will always be at least 1 per file
int MAX_WORD = 1;       //not const as file will change value

//prototypes
void displayMenu(int &);
void populateVector(vector<string>&, int);
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

    cout << "next..." << endl;

    if(choice == 6)
    {
        cout << "Thank you for playing our game" << endl;
        cout << "Have a good day." << endl;
        return 0;
    }
    cout << "Safe code works..." << endl;

    populateVector(words,choice);

    for(int i = 0; i < words.size(); i++)
        cout << words.at(i) << endl;

    //char choices[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    cout << "The vector size of vector word is: " << words.size() << endl;
    chooseSecretAnswer(words);


    return 0;
}
void displayMenu(int & choice)
{
    /*
    Function    : displayMenu
    Programmer  : Isaiah Sule
    Date        : 4-9-2019
    Description : Has the user choose the topic they wish to use to play Hangman.
    Parameters  :
    Returns     :
    */

    cout << "inside displayMenu" << endl; //TESTING
    cout << "Please choose from the following options:" << endl;
    cout << "1. Animals" << endl;
    cout << "2. Sports" << endl;
    cout << "3. Cars" << endl;
    cout << "4. Fruits and Vegetables" << endl;
    cout << "5. Countries" << endl;
    cout << "6. Exit" << endl;
     do
    {
        cout << "Your choice: ";
        cin.clear();
        cin.sync();
        cin >> choice;

    }while(cin.fail() || choice > 6 || choice < 1);

    cout << "DONE..." << endl;

}
void populateVector(vector<string>&myV, const int choice) //choice should not be interfered with while in this function
{
    /*
    Function    : populateVector
    Programmer  : Isaiah Sule, Eros
    Date        : 4-9-2019
    Description : Opens a file based on the choice the user made from the last function
    Parameters  : vector<string> & myV, const int choice
    Returns     :
    */
    cout << "Inside populateVector" << endl;
    cout << "-----------BEFORE---------------" << endl;
    cout << "myV size is " << myV.size() << endl;
    ifstream iFile;

    switch(choice)
    {
    case 1:
        iFile.open("Animals.txt");
        cout << "opened Animals.txt" << endl;
        break;
    case 2:
        iFile.open("Sports.txt");
        cout << "opened Sports.txt" << endl;
        break;
    case 3:
        iFile.open("Cars.txt");
        cout << "opened Cars.txt" << endl;
        break;
    case 4:
        iFile.open("Fruits and Vegetables.txt");
        cout << "opened Fruits and Vegetables.txt" << endl;
        break;
    case 5:
        iFile.open("Countries.txt");
        cout << "opened Countries.txt" << endl;
        break;
    default: //safe code
        cout << "Something went wrong. File not found." << endl;
        cout << "Try again." << endl;
        cout << "EXITING..." << endl;
        break;
    }

    cout << "Done with loop" << endl;

    //place data into the vector
    cout << "placing data into vector..." << endl;
    string line = " "; //stores data from each line of the file
    while(getline(iFile, line))
    {
        cout << "inside loop" << endl;
        myV.push_back(line);
        cout << line << endl;
    }
    cout << "DONE..." << endl;
    cout << "-----------AFTER---------------" << endl;
    cout << "myV size is " << myV.size() << endl;
}
void chooseSecretAnswer(vector<string> myV)
{
    /*
    Function    : chooseSecretAnswer
    Programmer  : Isaiah Sule
    Date        : 4-9-2019
    Description : Creates an index out of a random number between 1 and the size of the vector.
                 Stores the result in an integer, arrIndex.
                 Declares secret answer using the stored index.
    Parameters  : vector<string>myV
    Returns     :
    */
    cout << "<<<<<inside chooseSecretAnswer >>>>>>>>" << endl;
    string secretAnswer;
    int arrIndex;
    arrIndex = rand() % (MAX_WORD - MIN_WORD + 1) + MIN_WORD; //this?

    cout << "the vector index is now " << arrIndex << endl;
    cout << "the vector size is now" << myV.size() << endl;
    secretAnswer = myV.at(arrIndex);


    cout << "The secret answer is " << secretAnswer << endl;
}

/****************************************************************************
                        Professor-provided functions
****************************************************************************/
void stateStart()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"  ===============\n"
         << endl;
}

void stateHead()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |    O  "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"  ===============\n"
         << endl;
}

void stateBody()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |    O  "<< endl
         <<"   |    |  "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"  ===============\n"
         << endl;
}

void stateOneArm()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |    O  "<< endl
         <<"   |   /|  "<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"  ===============\n"
         << endl;
}

void stateBothArms()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |    O  "<< endl
         <<"   |   /|\\"<< endl
         <<"   |       "<< endl
         <<"   |       "<< endl
         <<"  ===============\n"
         << endl;
}

void stateOneLeg()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |    O  "<< endl
         <<"   |   /|\\"<< endl
         <<"   |   /   "<< endl
         <<"   |       "<< endl
         <<"  ===============\n"
         << endl;
}

void stateDead()
{
    cout <<"\n\n"
         <<"   +----+  "<< endl
         <<"   |    |  "<< endl
         <<"   |    O  "<< endl
         <<"   |   /|\\"<< endl
         <<"   |   / \\"<< endl
         <<"   | You are Dead"<< endl
         <<"  ===============\n"
         << endl;
}
