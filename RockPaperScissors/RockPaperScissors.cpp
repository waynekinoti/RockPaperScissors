
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player
{
private:
    string name;
    string choice;

public:
    Player(string playerName)
    {
        name = playerName;
        choice = "";
    }

    void makeChoice()
    {
        int option;

        cout << "\nChoose your move:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1)
            choice = "Rock";
        else if (option == 2)
            choice = "Paper";
        else if (option == 3)
            choice = "Scissors";
        else
        {
            cout << "Invalid choice. Try again.\n";
            makeChoice();
        }
    }

    string getChoice()
    {
        return choice;
    }

    string getName()
    {
        return name;
    }
};


class Computer
{
private:
    string choice;

public:
    Computer()
    {
        choice = "";
    }

    void makeChoice()
    {
        int option = rand() % 3 + 1;

        if (option == 1)
            choice = "Rock";
        else if (option == 2)
            choice = "Paper";
        else
            choice = "Scissors";
    }

    string getChoice()
    {
        return choice;
    }
};



class Game
{
private:
    int userScore;
    int computerScore;
    int draws;

public:
    Game()
    {
        userScore = 0;
        computerScore = 0;
        draws = 0;
    }

    void playRound(string userChoice, string computerChoice)
    {
        cout << "\nYou selected: " << userChoice << endl;
        cout << "Computer selected: " << computerChoice << endl;

        if (userChoice == computerChoice)
        {
            cout << "It's a draw!" << endl;
            draws++;
        }
        else if ((userChoice == "Rock" && computerChoice == "Scissors") ||
            (userChoice == "Scissors" && computerChoice == "Paper") ||
            (userChoice == "Paper" && computerChoice == "Rock"))
        {
            cout << "You win!" << endl;
            userScore++;
        }
        else
        {
            cout << "Computer wins!" << endl;
            computerScore++;
        }
    }

    void displayScore()
    {
        cout << "\n========== SCOREBOARD ==========" << endl;
        cout << "Your wins: " << userScore << endl;
        cout << "Computer wins: " << computerScore << endl;
        cout << "Draws: " << draws << endl;
        cout << "================================" << endl;
    }
};



int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Player user("User");
    Computer computer;
    Game game;

    char playAgain;

    do
    {
        user.makeChoice();
        computer.makeChoice();

        game.playRound(user.getChoice(), computer.getChoice());

        game.displayScore();

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing!" << endl;

    return 0;
}

