#include <iostream>

using namespace std;

void clearScreen()
{
    cout << "\033[2J\033[H";
}

void printRed(string text)
{
    cout << "\033[31m" << text << "\033[0m\n";
}
void printGreen(string text)
{
    cout << "\033[32m" << text << "\033[0m\n";
}
void printBlue(string text)
{
    cout << "\033[34m" << text << "\033[0m\n";
}
void printYello(string text)
{
    cout << "\033[33m" << text << "\033[0m\n";
}

class Chess
{
private:
    vector<int> rows = {8, 7, 6, 5, 4, 3, 2, 1};
    vector<char> cols = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char turn = 'w', player1, player2;

    vector<string> board = {
        "rnbqkbnr", // Black back rank
        "pppppppp", // Black pawns
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP", // White pawns
        "RNBQKBNR"  // White back rank
    };
    int getColIndex(char c)
    {
        return c - 'a';
    }
    int getRowIndex(char c)
    {
        return 8 - (c - '0');
    }

public:
    Chess(char p1 = 'w', char p2 = 'b')
    {
        player1 = p1;
        player2 = p2;
    }
    void printBoard()
    {
        for (int r = 0; r < 8; r++)
        {
            cout << rows[r] << " | ";
            for (int c = 0; c < 8; c++)
            {
                cout << board[r][c] << " ";
            }
            cout << endl;
        }
        cout << "    ";
        for (int c = 0; c < 8; c++)
        {
            cout << "--";
        }
        cout << "\n    ";
        for (int c = 0; c < 8; c++)
        {
            cout << cols[c] << " ";
        }
        cout << endl;
    }
    int getTurn()
    {
        return player1 == turn ? 0 : 1;
    }
    void move(string from, string to)
    {
        int fromCol = getColIndex(from[0]);
        int fromRow = getRowIndex(from[1]);

        int toRow = getRowIndex(to[1]);
        int toCol = getColIndex(to[0]);

        char piece = board[fromRow][fromCol];
        board[fromRow][fromCol] = '.';
        board[toRow][toCol] = piece;
    }
};

int main()
{
    Chess game;

    string from, to;
    for (int i = 0; i < 5; i++)
    {
        clearScreen();
        printBlue("** Best Chess Game Ever **");
        game.printBoard();
        cout << "Move from: \n>> ";
        cin >> from;
        cout << "Move to: \n>> ";
        cin >> to;

        game.move(from, to);
    }

    return 0;
}