#include "chess.hpp"
#include <cstdlib>

using namespace chess;
using namespace std;

const string FG_WHITE        = "\033[38;5;255m";
const string FG_BLACK        = "\033[38;5;0m";
const string BG_GRAY_40      = "\033[48;5;240m";
const string BG_GRAY_50      = "\033[48;5;242m";
const string FG_ELEC_BLUE    = "\033[38;5;33m";
const string RESET_COLOR     = "\033[0m";

void refreshScreen() {
    #ifdef _WIN32
        system("cls");   // For Windows
    #else
        system("clear"); // For Linux/macOS
    #endif
}

void printBoard(Board &board) {
    refreshScreen();

    cout << "\n     a  b  c  d  e  f  g  h\n";
    // Upgraded top border
    cout << "   ┌────────────────────────┐\n";

    for (int r = 7; r >= 0; r--) {
        // Upgraded left border
        cout << " " << r + 1 << " │";

        for (int c = 0; c < 8; c++) {
            Square square = Square(r * 8 + c);
            PieceType piece = board.at<PieceType>(square);
            Color color = board.at<Piece>(square).color();

            if (square.is_dark()) {
                cout << BG_GRAY_40;
            } else {
                cout << BG_GRAY_50;
            }

            string icon = "   ";
            if (piece != PieceType::NONE) {
                if (piece == PieceType::PAWN)   icon = " ♟ ";
                if (piece == PieceType::KNIGHT) icon = " ♞ ";
                if (piece == PieceType::BISHOP) icon = " ♝ ";
                if (piece == PieceType::ROOK)   icon = " ♜ ";
                if (piece == PieceType::QUEEN)  icon = " ♛ ";
                if (piece == PieceType::KING)   icon = " ♚ ";
            }

            cout << (color == Color::WHITE ? FG_WHITE : FG_BLACK) << icon;
            cout << RESET_COLOR;
        }
        // Upgraded right border
        cout << "│ " << r + 1 << "\n";
    }

    // Upgraded bottom border
    cout << "   └────────────────────────┘\n";
    cout << "     a  b  c  d  e  f  g  h\n\n";
}



int main() {
    Board board = Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    Movelist moves;
    movegen::legalmoves(moves, board);

    int turn = 0; // 0 = White, 1 = Black

    string input = "";
    while(1){
        printBoard(board);

        cout << "Turn" << (turn ? " Black" : " White") << ": ";
        cin >> input;

        if(input == "-1") break;

        Move next_move = uci::uciToMove(board, input);
        board.makeMove(next_move);

        auto status = board.isGameOver();

        if(status.first == GameResultReason::CHECKMATE){
            cout << FG_ELEC_BLUE << "\nCheck Mate" << RESET_COLOR << endl;
            break;
        }
        if(status.first == GameResultReason::STALEMATE){
            cout << FG_ELEC_BLUE << "\nStaleMate" << RESET_COLOR << endl;
            break;
        }
        if(status.first == GameResultReason::FIFTY_MOVE_RULE){
            cout << FG_ELEC_BLUE << "\nGame Over by Fifty Move Rule" << RESET_COLOR << endl;
            break;
        }
        if(status.first == GameResultReason::THREEFOLD_REPETITION){
            cout << FG_ELEC_BLUE << "\nThree Move Repetation" << RESET_COLOR << endl;
            break;
        }

        turn = (turn + 1) % 2;
    }


    return 0;
}
