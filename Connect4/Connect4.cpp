#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
using namespace std;

struct Connect4 {
    char Data[6][7];
    string PlayerNames[2];
    char PlayerChar[2];
    bool GameOver;

    Connect4(string Names[] = nullptr) {
        if (Names == nullptr) {
            string DefaultNames[2] = { "Player 1", "Player 2" };
            initialize(DefaultNames);
        }
        else {
            initialize(Names);
        }
    }

    void initialize(string Names[]) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                Data[i][j] = '-';
            }
        }
        PlayerNames[0] = Names[0];
        PlayerNames[1] = Names[1];
        PlayerChar[0] = 'X';
        PlayerChar[1] = 'O';
        GameOver = false;
    }

    void displayBoard() {
        system("clear||cls");
        cout << "\n     ======================================" << endl;
        cout << "                   CONNECT 4" << endl;
        cout << "     ======================================\n\n";

        cout << "       1   2   3   4   5   6   7\n";
        cout << "     +---+---+---+---+---+---+---+\n";
        for (int i = 0; i < 6; i++) {
            cout << "     |";
            for (int j = 0; j < 7; j++) {
                cout << " " << Data[i][j] << " |";
            }
            cout << "\n";
            cout << "     +---+---+---+---+---+---+---+\n";
        }
        cout << "\n\n";
    }

    bool makeMove(int column, int player) {
        column--;

        for (int i = 5; i >= 0; i--) {
            if (Data[i][column] == '-') {
                Data[i][column] = PlayerChar[player];
                simulateDrop(column, player, i);
                return true;
            }
        }
        cout << "Column is full. Try a different one.\n";
        return false;
    }

    void simulateDrop(int column, int player, int row) {
        for (int i = 0; i <= row; i++) {
            Data[i][column] = PlayerChar[player];
            if (i > 0) Data[i - 1][column] = '-';
            displayBoard();
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }

    bool checkWinner(char token) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                if (Data[i][j] == token && Data[i][j + 1] == token &&
                    Data[i][j + 2] == token && Data[i][j + 3] == token) {
                    return true;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 7; j++) {
                if (Data[i][j] == token && Data[i + 1][j] == token &&
                    Data[i + 2][j] == token && Data[i + 3][j] == token) {
                    return true;
                }
            }
        }
        for (int i = 3; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                if (Data[i][j] == token && Data[i - 1][j + 1] == token &&
                    Data[i - 2][j + 2] == token && Data[i - 3][j + 3] == token) {
                    return true;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                if (Data[i][j] == token && Data[i + 1][j + 1] == token &&
                    Data[i + 2][j + 2] == token && Data[i + 3][j + 3] == token) {
                    return true;
                }
            }
        }
        return false;
    }

    void start() {
        int currentPlayer = 0;

        while (!GameOver) {
            displayBoard();
            cout << PlayerNames[currentPlayer] << "'s turn (" << PlayerChar[currentPlayer] << "). Choose a column: ";

            int column;
            cin >> column;

            while (column <= 0 || column > 7) {
                cout << "Invalid column! Choose between 1 and 7.\n";
                cout << PlayerNames[currentPlayer] << "'s turn (" << PlayerChar[currentPlayer] << "). Choose a column again: ";
                cin >> column;
            }

            if (makeMove(column, currentPlayer)) {
                if (checkWinner(PlayerChar[currentPlayer])) {
                    displayBoard();
                    cout << "\n\nHurrah!! " << PlayerNames[currentPlayer] << " Wins the Game!\n\n";
                    GameOver = true;
                }
                else {
                    currentPlayer = 1 - currentPlayer;
                }
            }
        }
    }
};

int main() {
    cout << "\n     ======================================" << endl;
    cout << "       WELCOME TO THE CONNECT 4 GAME!" << endl;
    cout << "     ======================================\n\n";

    string Names[2];

    cout << "Enter name for Player 1: ";
    cin >> Names[0];
    cout << "Enter name for Player 2: ";
    cin >> Names[1];

    Connect4 game(Names);
    game.start();

    system("pause");
    return 0;
}