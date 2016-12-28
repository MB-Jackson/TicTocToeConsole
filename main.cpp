//  A simple console bases Tic Tac Toe game that allows two players to compete.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
//#include <conio.h>

using namespace std;

/*		FUNCTION PROTOTYPES			*/
void splashScreen();
void askForUserName(string &, string &);
void validateUserName(string &);
void displayGrid(string &, string &);
void firstPlayerMakeMove(char(gameMatrix)[3][3], string, int &);
void secondPlayerMakeMove(char(gameMatrix)[3][3], string, int &);
void validateUserGameChoice(string &, char &, char(gameMatrix)[3][3]);
bool winDeterminant(char(gameMatrix)[3][3], int);
void resetGame(bool &);
void clearScreen();

/*		MAIN INITIATION			*/
int main() {
    string userNameFirst, userNameSecond;;
    bool gameContinue = true;
    
    splashScreen();
    askForUserName(userNameFirst, userNameSecond);
    do {
        displayGrid(userNameFirst, userNameSecond);
        resetGame(gameContinue);
    } while (gameContinue);
    return 0;
}

/* Generic introduction splash screen */
void splashScreen() {
    
    cout << "  ***************************************\n";
    cout << "  ***************************************\n";
    cout << "  ***************************************\n";
    cout << "  ************               ************\n";
    cout << "  ************  TIC TOC TOE  ************\n";
    cout << "  ************  By. Michael  ************\n";
    cout << "  ************     Jackson  *************\n";
    cout << "  ************              *************\n";
    cout << "  ***************************************\n";
    cout << "  ***************************************\n";
    cout << "  ***************************************\n\t";
    
    system("pause");
    clearScreen();
}

/* askforusername(); asks both users for their respective names, accepts input as a string, and passes strings to validateusername(); to validate that input is not empty and only contains alpha chars */
void askForUserName(string& userNameFirst, string& userNameSecond) {
    
    cout << "    Hey, buddy! Enter the first user's name\n";
    cout << "***make sure its only alphas and a single word***\t";
    
    getline(cin, userNameFirst);
    validateUserName(userNameFirst);
    
    cout << endl;
    cout << "Enter the second user's name. Same rules apply: \t";
    getline(cin, userNameSecond);
    validateUserName(userNameSecond);
    
    clearScreen();
    return;
}

void validateUserName(string& userName) {
    bool validName = false;
    while (!validName) {
        int counter = 0;
        if (userName.length() > 0) {
            for (char & c : userName) {
                if (isalpha(char(c))) {
                    counter++;
                    if (userName.length() == counter) {
                        validName = true;
                        continue;
                    }
                }
                else {
                    counter = 0;
                    cout << "Your name must be a single word of alpha characters:\t";
                    getline(cin, userName);
                    break;
                }
            }
        }
        else {
            counter = 0;
            cout << "Your name must be a single word of alpha characters:\t";
            getline(cin, userName);
            continue;
        }
    }
}

/* main graph function that controls output of tic tac toe matrix*/
void displayGrid(string& userNameFirst, string& userNameSecond) {
    
    char gameMatrix[3][3] = { { '1', '2', '3' }, {'4', '5', '6'}, {'7', '8', '9'} };
    int moveCounter = 0;
    bool gameResetFlag = false;
    
    do {
        
        cout << setw(27) << "TIC TAC TOE\n\n";
        // First Stage of TicTacToe Matrix
        cout << "\t" << setw(8) << "|" << setw(8) << "|" << setw(8) << "\n";
        
        cout << "\t";
        cout << setw(4) << gameMatrix[0][0] << setw(4) << "|";
        cout << setw(4) << gameMatrix[0][1] << setw(4) << "|";
        cout << setw(4) << gameMatrix[0][2] << setw(4) << endl;
        
        cout << "\t" << setw(8) << "|" << setw(8) << "|" << setw(8) << "\n";
        cout << "\t" << " ----------------------" << endl;
        
        // Second Stage of TicTacToe Matrix
        cout << "\t" << setw(8) << "|" << setw(8) << "|" << setw(8) << "\n";
        
        cout << "\t";
        cout << setw(4) << gameMatrix[1][0] << setw(4) << "|";
        cout << setw(4) << gameMatrix[1][1] << setw(4) << "|";
        cout << setw(4) << gameMatrix[1][2] << setw(4) << endl;
        
        cout << "\t" << setw(8) << "|" << setw(8) << "|" << setw(8) << "\n";
        cout << "\t" << " ----------------------" << endl;
        
        // Third Stage of TicTacToe Matrix
        cout << "\t" << setw(8) << "|" << setw(8) << "|" << setw(8) << "\n";
        
        cout << "\t";
        cout << setw(4) << gameMatrix[2][0] << setw(4) << "|";
        cout << setw(4) << gameMatrix[2][1] << setw(4) << "|";
        cout << setw(4) << gameMatrix[2][2] << setw(4) << endl;
        
        cout << "\t" << setw(8) << "|" << setw(8) << "|" << setw(8) << "\n\n\t";
        
        if ((moveCounter % 2) == 0) {	// Increments moveCounter variable and uses modulus to switch players
            firstPlayerMakeMove(gameMatrix, userNameFirst, moveCounter);
        }
        else {
            secondPlayerMakeMove(gameMatrix, userNameSecond, moveCounter);
        }
        
        if (winDeterminant(gameMatrix, moveCounter)) {
            gameResetFlag = true;
            system("Pause");
        }
        clearScreen();
        continue;
        
    } while (!gameResetFlag);
    return;
}

/* firstPlayerMakeMove(); AND secondPlayerMakeMove(); TAKES GAME MATRIX AND PLACES USER INPUT ON TIC TAC TOE GRAPH*/
void firstPlayerMakeMove(char(gameMatrix)[3][3], string userNameFirst, int& moveCounter) {
    string userGameChoice;
    char userGameChoiceChar;
    char userGameIcon = 'X';
    
    cout << userNameFirst << "! Enter your choice! You're 'X':\t";
    
    getline(cin, userGameChoice);
    validateUserGameChoice(userGameChoice, userGameChoiceChar, gameMatrix);
    
    if (userGameChoiceChar == '1' && gameMatrix[0][0] == '1') {
        gameMatrix[0][0] = userGameIcon;
    }
    else if (userGameChoiceChar == '2' && gameMatrix[0][1] == '2') {
        gameMatrix[0][1] = userGameIcon;
    }
    else if (userGameChoiceChar == '3' && gameMatrix[0][2] == '3') {
        gameMatrix[0][2] = userGameIcon;
    }
    else if (userGameChoiceChar == '4' && gameMatrix[1][0] == '4') {
        gameMatrix[1][0] = userGameIcon;
    }
    else if (userGameChoiceChar == '5' && gameMatrix[1][1] == '5') {
        gameMatrix[1][1] = userGameIcon;
    }
    else if (userGameChoiceChar == '6' && gameMatrix[1][2] == '6') {
        gameMatrix[1][2] = userGameIcon;
    }
    else if (userGameChoiceChar == '7' && gameMatrix[2][0] == '7') {
        gameMatrix[2][0] = userGameIcon;
    }
    else if (userGameChoiceChar == '8' && gameMatrix[2][1] == '8') {
        gameMatrix[2][1] = userGameIcon;
    }
    else if (userGameChoiceChar == '9' && gameMatrix[2][2] == '9') {
        gameMatrix[2][2] = userGameIcon;
    }
    else {
        cout << "\n\tPosition already taken, try again.";
        moveCounter--;
        system("pause");
        
    }
    moveCounter++;
    return;
}

void secondPlayerMakeMove(char(gameMatrix)[3][3], string userNameSecond, int& moveCounter) {
    string userGameChoice;
    char userGameChoiceChar;
    char userGameIcon = 'O';
    
    cout << userNameSecond << "! Enter your choice! You're 'O':\t";
    
    getline(cin, userGameChoice);
    validateUserGameChoice(userGameChoice, userGameChoiceChar, gameMatrix);
    
    if (userGameChoiceChar == '1' && gameMatrix[0][0] == '1') {
        gameMatrix[0][0] = userGameIcon;
    }
    else if (userGameChoiceChar == '2' && gameMatrix[0][1] == '2') {
        gameMatrix[0][1] = userGameIcon;
    }
    else if (userGameChoiceChar == '3' && gameMatrix[0][2] == '3') {
        gameMatrix[0][2] = userGameIcon;
    }
    else if (userGameChoiceChar == '4' && gameMatrix[1][0] == '4') {
        gameMatrix[1][0] = userGameIcon;
    }
    else if (userGameChoiceChar == '5' && gameMatrix[1][1] == '5') {
        gameMatrix[1][1] = userGameIcon;
    }
    else if (userGameChoiceChar == '6' && gameMatrix[1][2] == '6') {
        gameMatrix[1][2] = userGameIcon;
    }
    else if (userGameChoiceChar == '7' && gameMatrix[2][0] == '7') {
        gameMatrix[2][0] = userGameIcon;
    }
    else if (userGameChoiceChar == '8' && gameMatrix[2][1] == '8') {
        gameMatrix[2][1] = userGameIcon;
    }
    else if (userGameChoiceChar == '9' && gameMatrix[2][2] == '9') {
        gameMatrix[2][2] = userGameIcon;
    }
    else {
        cout << "\n\tPosition already taken, try again. ";
        moveCounter--;
        system("pause");
    }
    moveCounter++;
    return;
}

/*COMPARES GAME MATRIX WITH PRE-DETERMINED WIN CONDITIONS TO VERIFY IF THERE IS A WINNER*/
bool winDeterminant(char(gameMatrix)[3][3], int moveCounter)
{
    // Analyzes if 'X' wins
    if ((gameMatrix[0][0] == 'X' && gameMatrix[0][1] == 'X' && gameMatrix[0][2] == 'X') ||
        (gameMatrix[1][0] == 'X' && gameMatrix[1][1] == 'X' && gameMatrix[1][2] == 'X') ||
        (gameMatrix[2][0] == 'X' && gameMatrix[2][1] == 'X' && gameMatrix[2][2] == 'X') ||
        (gameMatrix[0][0] == 'X' && gameMatrix[1][0] == 'X' && gameMatrix[2][0] == 'X') ||
        (gameMatrix[0][1] == 'X' && gameMatrix[1][1] == 'X' && gameMatrix[2][1] == 'X') ||
        (gameMatrix[0][2] == 'X' && gameMatrix[1][2] == 'X' && gameMatrix[2][2] == 'X') ||
        (gameMatrix[0][0] == 'X' && gameMatrix[1][1] == 'X' && gameMatrix[2][2] == 'X') ||
        (gameMatrix[2][0] == 'X' && gameMatrix[1][1] == 'X' && gameMatrix[0][2] == 'X')) {
        
        cout << "\n\n\t***************************************";
        cout << "\n\t Congratulations! X has won the game. \n";
        cout << "\t***************************************\n\n\t";
        return true;
    }
    
    // Analyzes if 'O' wins
    else if ((gameMatrix[0][0] == 'O' && gameMatrix[0][1] == 'O' && gameMatrix[0][2] == 'O') ||
             (gameMatrix[1][0] == 'O' && gameMatrix[1][1] == 'O' && gameMatrix[1][2] == 'O') ||
             (gameMatrix[2][0] == 'O' && gameMatrix[2][1] == 'O' && gameMatrix[2][2] == 'O') ||
             (gameMatrix[0][0] == 'O' && gameMatrix[1][0] == 'O' && gameMatrix[2][0] == 'O') ||
             (gameMatrix[0][1] == 'O' && gameMatrix[1][1] == 'O' && gameMatrix[2][1] == 'O') ||
             (gameMatrix[0][2] == 'O' && gameMatrix[1][2] == 'O' && gameMatrix[2][2] == 'O') ||
             (gameMatrix[0][0] == 'O' && gameMatrix[1][1] == 'O' && gameMatrix[2][2] == 'O') ||
             (gameMatrix[2][0] == 'O' && gameMatrix[1][1] == 'O' && gameMatrix[0][2] == 'O')) {
        
        cout << "\n\n\t***************************************";
        cout << "\n\t Congratulations! O has won the game. \n";
        cout << "\t***************************************\n\n\t";
        return true;
    }
    
    else if (moveCounter >= 9) {
        cout << "\n\n\t***************************************";
        cout << "\n\t     Looks like there is a tie! \n";
        cout << "\t***************************************\n\n\t";
        return true;
    }
    else {
        return false;
    }
    
}

/*VALIDATES THAT USER ENTERED GAME CHOICE IS BETWEEN 1 AND 9*/
void validateUserGameChoice(string& userGameChoice, char& userGameChoiceChar, char(gameMatrix)[3][3]) {
    
    while (userGameChoice != "1" && 
           userGameChoice != "2" && 
           userGameChoice != "3" &&
           userGameChoice != "4" &&
           userGameChoice != "5" && 
           userGameChoice != "6" &&
           userGameChoice != "7" &&
           userGameChoice != "8" &&
           userGameChoice != "9") {
        cout << "\n\tPlease enter a valid grid choice.\t";
        getline(cin, userGameChoice);
    }
    
    userGameChoiceChar = userGameChoice.c_str()[0];
    return;
}

void resetGame(bool& gameContinue) {
    string userContinueChoice;
    cout << "     Would you like to play again? ";
    cout << "Y/y will restart. Any other key will exit.\t";
    getline(cin, userContinueChoice);
    
    if (userContinueChoice == "y" || userContinueChoice == "Y") {
        clearScreen();
        return;
    }
    else {
        gameContinue = false;
    }
}

void clearScreen() {
    system("CLS");
}
