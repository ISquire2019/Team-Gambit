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
void populateVector(vector<string> & , int);
string chooseSecretAnswer(vector<string>);
void displayGame();
char playGame(string &, char );
bool letterCheck(string &,char &);
void stateUpdate(bool &);
void stateStart();
void stateHead();
void stateBody();
void stateOneArm();
void stateBothArms();
void stateOneLeg();
void stateDead();

int main()
{
    vector<string>words;
    char userInp;
    bool update;

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

    for(int i = 0; i < words.size(); i++)
        cout << words.at(i) << endl;

    //char choices[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


    answer = chooseSecretAnswer(words);

    displayGame();
    userInp = playGame(answer, userInp);
    //update = letterCheck(answer, userInp);
    //stateUpdate(update);

    //cout << answer;

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

}
void populateVector(vector<string> &arr, const int choice) //choice should not be interfered with while in this function
{
    /*
    Function    : populateVector
    Programmer  : Isaiah Sule
                  Eros Rodriguez
    Date        : 4-9-2019
    Description : Opens a file based on the choice the user made from the last function
    Parameters  : arr           (vector<string>) byReference
                  choice        (const int) byValue
    Returns     :
    */
    ifstream iFile;
    string line; //stores data from each line of the file

    switch(choice)
    {
    case 1:
        iFile.open("Animals.txt");
        cout << "File name: Animals.txt" << endl;
        break;
    case 2:
        iFile.open("Sports.txt");
        cout << "File name: Sports.txt" << endl;
        break;
    case 3:
        iFile.open("Cars.txt");
        cout << "File name: Cars.txt" << endl;
        break;
    case 4:
        iFile.open("Fruits and Vegetables.txt");
        cout << "File name: Fruits and Vegetables.txt" << endl;
        break;
    case 5:
        iFile.open("Countries.txt");
        cout << "File name: Countries.txt" << endl;
        break;
    default: //safe code
        cout << "Something went wrong. File not found." << endl;
        cout << "Try again." << endl;
        cout << "EXITING..." << endl;
        break;
    }

    //place data into the vector
    cout << "MyV Size is " << arr.size() << endl;
    while(!iFile.eof())
    {
        getline(iFile,line);    //grabs characters in line
        for(int i = 0; i < line.size(); i++) //loops through each character stored in line
        {
            line.at(i) = toupper(line.at(i)); //makes letter uppercase
        }
        arr.push_back(line); //stores line string in arr vector
    }
    cout << "myV size is " << arr.size() << endl;
}
string chooseSecretAnswer(vector<string> arr)
{
    /*
    Function    : chooseSecretAnswer
    Programmer  : Isaiah Sule
    Date        : 4-9-2019
    Description : Creates an index out of a random number between 1 and the size of the vector.
                  Stores the result in an integer, arrIndex.
                  Declares secret answer using the stored index.
    Parameters  : vector<string>arr     (string) byValue
    Returns     : secretAnswer          (string)
    */
    string secretAnswer;
    int arrIndex;

    MAX_WORD = arr.size(); // between 1 and the max size of the vector
    arrIndex = rand() % (MAX_WORD - MIN_WORD + 1) + MIN_WORD;
    secretAnswer = arr.at(arrIndex);


    //cout << "The secret answer is " << secretAnswer << endl;
    return secretAnswer;
}

/***
    Function        : displayGame
    Programmer(s)   : Eros Rodriguez
    Date            : 04/09/2019
    Parameters      :
    Returns         :
***/
void displayGame()
{
    stateStart();
    string allLetters = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    cout << allLetters << endl;
}

/***
    Function        : playGame
    Programmer(s)   : Eros Rodriguez
    Date            : 04/09/2019
    Parameters      : answer    (string) byReference
                      userInp   (char)   byValue
    Returns         : userInp   (char)
***/
char playGame(string &answer, char userInp)
{
    cout << "\nYour guess: ";
    for(int i = 0; i < answer.size(); i++)
    {
        cout << "_ ";
    }
    //cout << answer << endl;
    cout << "\n\nEnter a letter: ";
    cin >> userInp;
    return userInp;
}

/***
    Function        : letterCheck
    Programmer(s)   : Eros Rodriguez
    Date            : 04/09/2019
    Parameters      : answer    (string) byReference
                      userInp   (char)   byValue
    Returns         : correct   (bool)
***/
bool letterCheck(string &answer, char userInp)
{
    bool correct;
    int counter = 0;
    for(int i = 0; i < answer.size(); i++)
    {
        if(answer.at(i) == userInp)
        {
            counter++;
        }
    }
    if(counter > 0)
    {
        correct = true;
    }
    else
    {
        correct = false;
    }
    return correct;
}

/***
    Function        : stateUpdate
    Programmer(s)   : Eros Rodriguez
    Date            : 04/09/2019
    Parameters      : update    (bool) byValue
    Returns         :
***/
void stateUpdate(bool update)
{

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
