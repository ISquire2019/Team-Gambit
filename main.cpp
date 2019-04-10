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
string allLetters = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";

//prototypes
void displayMenu(int &);
void populateVector(vector<string> & , int);
string chooseSecretAnswer(vector<string>);
void displayGame(int );
void userAnswer(char &);
bool letterCheck(string &,char );
void wordUpdate(bool &, string &, string &,char );
bool gameWon(bool ,string &,int );
char playAgain(string &);
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
    int incorrectCounter = 0,
        correctCounter = 0,
        maxWordSize;
    char replay,
         userInp;
    bool update;

    //rand function
    unsigned seed = time(NULL);
    srand(seed);

    //initialize variables
    string answer;
    string blanks;  //to store the "Your Choice" letters

    int choice;
    do
    {
        displayMenu(choice);

        if(choice == 6)
        {
            cout << "Thank you for playing our game" << endl;
            cout << "Have a good day." << endl;
            return 0;
        }


        populateVector(words,choice);
/*
        for(int i = 0; i < words.size(); i++)
            cout << words.at(i) << endl;
*/
    //char choices[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

        do
        {

            answer = chooseSecretAnswer(words);
            maxWordSize = answer.size();
            //cout << "Answer size before the displayGame function is: " << answer.size() << endl;
            for(int i = 0; i < answer.size(); i++)
            {
                blanks.push_back('_');
            }

            do
            {
                displayGame(incorrectCounter);
                cout << "Available letters: "
                     << allLetters << endl;
                cout << "Your Choice: ";
                for(int i = 0; i < answer.size(); i++)
                {
                    cout << blanks.at(i) << " ";
                }
                if(incorrectCounter == 6)
                {
                    break;
                }
                //cout << answer << endl;
                userAnswer(userInp);
                cout << "update in main before letterCheck function: " << update << endl;
                update = letterCheck(answer, userInp);
                cout << "update in main after letterCheck function: " << update << endl;
                wordUpdate(update, answer, blanks, userInp);
                cout << "update in main after functions: " << update << endl;
                if(update == true)
                {
                    for(int i = 0; i < answer.size(); i++)
                    {
                        if(answer.at(i) == userInp)
                        {
                            correctCounter++;
                        }
                    }
                }
                else if(update == false)
                {
                    incorrectCounter++;
                }
                cout << "Answer size: " << answer.size() << endl;
                cout << "correctCounter after addition: " << correctCounter << endl;
                cout << "incorrectCounter after addition: " << incorrectCounter << endl;
                if(correctCounter == answer.size())
                {
                    displayGame(incorrectCounter);
                cout << "Available letters: "
                     << allLetters << endl;
                cout << "Your Choice: ";
                for(int i = 0; i < answer.size(); i++)
                {
                    cout << blanks.at(i) << " ";
                }
                    cout << "\n\nCongratulations, You won!!" << endl;
                    break;
                }
            }while(incorrectCounter != 7);
            replay = playAgain(answer);
        }while(replay == 'Y');
    }while(replay == 'N');

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
    cout << "Your choice: ";
    cin.clear();
    cin.sync();
    cin >> choice;
    while(cin.fail() || choice > 6 || choice < 1)
    {
        cout << "Please enter a valid number: ";
        cin.clear();
        cin.sync();
        cin >> choice;
    }
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
        iFile.open("FruitsAndVegetables.txt");
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
    arr.clear();
    while(!iFile.eof())
    {
        getline(iFile,line);    //grabs characters in line
        for(int i = 0; i < line.size(); i++) //loops through each character stored in line
        {
            line.at(i) = toupper(line.at(i)); //makes letter uppercase
        }
        arr.push_back(line); //stores line string in arr vector
    }
    iFile.close();
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
    Parameters      : answer    (string) byReference
    Returns         : correctCounter    (int)
***/
void displayGame(int incorrectCounter)
{
    cout << "incorrectCounter in displayGame: " << incorrectCounter << endl;
    switch(incorrectCounter)    //reads incorrectCounter to determine state to display
    {
        case 0:
            stateStart();
            break;
        case 1:
            stateHead();
            break;
        case 2:
            stateBody();
            break;
        case 3:
            stateOneArm();
            break;
        case 4:
            stateBothArms();
            break;
        case 5:
            stateOneLeg();
            break;
        case 6:
            stateDead();
            break;
    }
}

void userAnswer(char &userInp)
{
    cout << "\n\nEnter a letter: ";
    cin >> userInp;
    userInp = toupper(userInp);
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
    Programmer(s)   : Eros Rodriguez
    Date            : 04/10/2019
    Parameters      : update    (boolean) byValue
                      answer    (string) byReference
                      userInp   (char) byValue
                      incorrectCounter  (int) byValue
    Returns         : incorrectCounter  (int)
***/
void wordUpdate(bool &update, string &answer, string &blanks, char userInp)
{
    if(update == true)  //verifies that user input matches at least one letter of the secret word
    {
        for(int i = 0; i < allLetters.size(); i++)      //loops through the available letters
        {
            if(allLetters.at(i) == userInp)     //checks to see if user input matches a letter
            {
                allLetters.at(i) = ' ';     //updates available letters
            }
        }
        //cout << "Available letters: "
          //   << allLetters << "\n" << endl;

        for(int i = 0; i < answer.size(); i++)  //loops through the characters of the answer
        {
            if(answer.at(i) == userInp)     //Checks to see if user's input matches a letter of the secret answer
            {
                blanks.at(i) = userInp;
            //    cout << blanks.at(i) << " " << endl;
            }
        }
    }/*
    else if(update == false)
    {
        incorrectCounter++;
    }
    return incorrectCounter;
    */
}
/*
bool gameWon(bool update, string &answer, int correctCounter)
{
    if(correctCounter == answer.size())
    {
        update = true;
    }
    return update;
}
/***
    Function        : playAgain
    Programmer(s)   : Eros Rodriguez
    Date            : 04/09/2019
    Parameters      : answer    (string) byReference
    Returns         : userInp   (char)
***/
char playAgain(string &answer)
{
    char userInp;
    cout << "\n\nThe answer was: "
         << answer
         << endl;
    cout << "Play again? (Y/N)" << endl;
    cout << "Your Choice: ";
    cin >> userInp;
    userInp = toupper(userInp);
    return userInp;
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
