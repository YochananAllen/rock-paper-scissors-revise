// rock,paper,scissors-revise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Name: Yochanan Allen
//Revise your original Rock Paper Scissors Game so that it is repeatable
//using  sentinel value to end..On each iteration of the game you should
//accept the name of the player and keep count of how many times they
//have won.Modify your program using a new branch of your project so that


#include <iostream>
#include <string>

using namespace std;


int getComputerChoice() {
    return (rand() % 3 + 1);  
}


string choiceToString(int choice) {
    if (choice == 1) return "rock";
    else if (choice == 2) return "paper";
    else return "scissors";
}


string getUserChoice() {
    string userChoice;
    while (true) {
        cout << "Enter your choice (rock, paper, or scissors), or type 'exit' to quit: ";
        cin >> userChoice;
        if (userChoice == "rock" || userChoice == "paper" || userChoice == "scissors" || userChoice == "exit") {
            break;
        }
        else {
            cout << "Invalid choice. Please enter 'rock', 'paper', 'scissors', or 'exit'." << endl;
        }
    }
    return userChoice;
}


string determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "tie";
    }
    else if ((userChoice == "rock" && computerChoice == "scissors") ||
        (userChoice == "scissors" && computerChoice == "paper") ||
        (userChoice == "paper" && computerChoice == "rock")) {
        return "user";
    }
    else {
        return "computer";
    }
}


void playGame(string playerName) {
    int userWins = 0;
    int computerWins = 0;
    int ties = 0;

    while (true) {
        
        int computerChoiceNum = getComputerChoice();
        string computerChoice = choiceToString(computerChoiceNum);

        
        string userChoice = getUserChoice();

        
        if (userChoice == "exit") {
            break;
        }

        
        cout << " Computer chose " << computerChoice << "." << endl;
        cout << playerName << " chose " << userChoice << "." << endl << endl;

        
        string winner = determineWinner(userChoice, computerChoice);

        if (winner == "tie") {
            cout << "It's a tie!" << endl;
            ties++;
        }
        else if (winner == "user") {
            cout << playerName << " wins!" << endl;
            userWins++;
        }
        else {
            cout << "Computer wins!" << endl;
            computerWins++;
        }

        
        cout << " Current Score:" << endl;
        cout << playerName << " Wins: " << userWins << endl;
        cout << "Computer Wins: " << computerWins << endl;
        cout << "Ties: " << ties << endl << endl;
    }

    
    cout << " Game Over!" << endl;
    cout << "Final Score:" << endl;
    cout << playerName << " Wins: " << userWins << endl;
    cout << "Computer Wins: " << computerWins << endl;
    cout << "Ties: " << ties << endl;
}

int main() {
    cout << "Welcome to Rock, Paper, Scissors!" << endl;

    
    string playerName;
    cout << "Please enter your name: ";
    cin >> playerName;

    
    playGame(playerName);

    cout << "Thanks for playing! Goodbye!" << endl;

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
