#include <iostream>
#include <iomanip> // For formatting output if needed
using namespace std;

// ==========================================
// FOREGROUND COLORS (Text)
// ==========================================

// --- Grayscale ---
const string FG_WHITE        = "\033[38;5;255m";
const string FG_LIGHT_GRAY   = "\033[38;5;250m";
const string FG_GRAY_70      = "\033[38;5;245m";
const string FG_GRAY_50      = "\033[38;5;242m";
const string FG_GRAY_40      = "\033[38;5;240m";
const string FG_DARK_GRAY    = "\033[38;5;235m";

// --- Reds & Pinks ---
const string FG_DARK_RED     = "\033[38;5;88m";
const string FG_RED          = "\033[38;5;196m";
const string FG_LIGHT_RED    = "\033[38;5;203m";
const string FG_HOT_PINK     = "\033[38;5;198m";
const string FG_PINK         = "\033[38;5;218m";

// --- Oranges & Yellows ---
const string FG_DARK_ORANGE  = "\033[38;5;130m";
const string FG_ORANGE       = "\033[38;5;208m";
const string FG_PEACH        = "\033[38;5;223m";
const string FG_GOLD         = "\033[38;5;220m";
const string FG_YELLOW       = "\033[38;5;226m";
const string FG_LIGHT_YELLOW = "\033[38;5;228m";

// --- Greens ---
const string FG_DEEP_GREEN   = "\033[38;5;22m";
const string FG_EMERALD      = "\033[38;5;70m";
const string FG_GREEN        = "\033[38;5;46m";
const string FG_LIME         = "\033[38;5;118m";
const string FG_MINT         = "\033[38;5;121m";

// --- Blues & Cyans ---
const string FG_MIDNIGHT     = "\033[38;5;17m";
const string FG_NAVY         = "\033[38;5;19m";
const string FG_BLUE         = "\033[38;5;21m";
const string FG_ELEC_BLUE    = "\033[38;5;33m";
const string FG_BRIGHT_BLUE  = "\033[38;5;39m";
const string FG_TEAL         = "\033[38;5;30m";
const string FG_CYAN         = "\033[38;5;51m";
const string FG_AQUA         = "\033[38;5;87m";

// --- Purples & Magentas ---
const string FG_DARK_PURPLE  = "\033[38;5;53m";
const string FG_PURPLE       = "\033[38;5;93m";
const string FG_MAGENTA      = "\033[38;5;201m";
const string FG_VIOLET       = "\033[38;5;177m";
const string FG_LAVENDER     = "\033[38;5;183m";

// --- Earth Tones ---
const string FG_BROWN        = "\033[38;5;94m";
const string FG_OLIVE        = "\033[38;5;58m";
const string FG_RUST         = "\033[38;5;130m";
const string FG_SAND         = "\033[38;5;144m";


// ==========================================
// BACKGROUND COLORS
// ==========================================

// --- Grayscale ---
const string BG_WHITE        = "\033[48;5;255m";
const string BG_LIGHT_GRAY   = "\033[48;5;250m";
const string BG_GRAY_70      = "\033[48;5;245m";
const string BG_GRAY_50      = "\033[48;5;242m";
const string BG_GRAY_40      = "\033[48;5;240m";
const string BG_GRAY_30      = "\033[48;5;235m";

// --- Reds & Pinks ---
const string BG_DARK_RED     = "\033[48;5;88m";
const string BG_RED          = "\033[48;5;196m";
const string BG_HOT_PINK     = "\033[48;5;198m";
const string BG_PINK         = "\033[48;5;218m";

// --- Oranges & Yellows ---
const string BG_ORANGE       = "\033[48;5;208m";
const string BG_PEACH        = "\033[48;5;223m";
const string BG_YELLOW       = "\033[48;5;226m";

// --- Greens ---
const string BG_DEEP_GREEN   = "\033[48;5;22m";
const string BG_EMERALD      = "\033[48;5;70m";
const string BG_GREEN        = "\033[48;5;46m";
const string BG_LIME         = "\033[48;5;118m";
const string BG_MINT         = "\033[48;5;121m";

// --- Blues & Cyans ---
const string BG_MIDNIGHT     = "\033[48;5;17m";
const string BG_ELEC_BLUE    = "\033[48;5;33m";
const string BG_BLUE         = "\033[48;5;21m";
const string BG_CYAN         = "\033[48;5;51m";
const string BG_AQUA         = "\033[48;5;87m";

// --- Purples & Magentas ---
const string BG_PURPLE       = "\033[48;5;93m";
const string BG_MAGENTA      = "\033[48;5;201m";
const string BG_LAVENDER     = "\033[48;5;183m";

// --- Earth Tones ---
const string BG_BROWN        = "\033[48;5;94m";
const string BG_OLIVE        = "\033[48;5;58m";
const string BG_RUST         = "\033[48;5;130m";

// --- Reset ---
const string RESET_COLOR     = "\033[0m";


int main()
{
    cout << "================ FOREGROUND COLORS ================\n\n";

    // Grayscale
    cout << FG_WHITE << "  White text        " << RESET_COLOR << "\n";
    cout << FG_LIGHT_GRAY << "  Light Gray text   " << RESET_COLOR << "\n";
    cout << FG_GRAY_70 << "  Gray 70 text      " << RESET_COLOR << "\n";
    cout << FG_GRAY_50 << "  Gray 50 text      " << RESET_COLOR << "\n";
    cout << FG_GRAY_40 << "  Gray 40 text      " << RESET_COLOR << "\n";
    cout << FG_DARK_GRAY << "  Dark Gray text    " << RESET_COLOR << "\n\n";

    // Reds & Pinks
    cout << FG_DARK_RED << "  Dark Red text     " << RESET_COLOR << "\n";
    cout << FG_RED << "  Red text          " << RESET_COLOR << "\n";
    cout << FG_LIGHT_RED << "  Light Red text    " << RESET_COLOR << "\n";
    cout << FG_HOT_PINK << "  Hot Pink text     " << RESET_COLOR << "\n";
    cout << FG_PINK << "  Pink text         " << RESET_COLOR << "\n\n";

    // Oranges & Yellows
    cout << FG_DARK_ORANGE << "  Dark Orange text  " << RESET_COLOR << "\n";
    cout << FG_ORANGE << "  Orange text       " << RESET_COLOR << "\n";
    cout << FG_PEACH << "  Peach text        " << RESET_COLOR << "\n";
    cout << FG_GOLD << "  Gold text         " << RESET_COLOR << "\n";
    cout << FG_YELLOW << "  Yellow text       " << RESET_COLOR << "\n";
    cout << FG_LIGHT_YELLOW << "  Light Yellow text " << RESET_COLOR << "\n\n";

    // Greens
    cout << FG_DEEP_GREEN << "  Deep Green text   " << RESET_COLOR << "\n";
    cout << FG_EMERALD << "  Emerald text      " << RESET_COLOR << "\n";
    cout << FG_GREEN << "  Green text        " << RESET_COLOR << "\n";
    cout << FG_LIME << "  Lime text         " << RESET_COLOR << "\n";
    cout << FG_MINT << "  Mint text         " << RESET_COLOR << "\n\n";

    // Blues & Cyans
    cout << FG_MIDNIGHT << "  Midnight text     " << RESET_COLOR << "\n";
    cout << FG_NAVY << "  Navy text         " << RESET_COLOR << "\n";
    cout << FG_BLUE << "  Blue text         " << RESET_COLOR << "\n";
    cout << FG_ELEC_BLUE << "  Elec Blue text    " << RESET_COLOR << "\n";
    cout << FG_BRIGHT_BLUE << "  Bright Blue text  " << RESET_COLOR << "\n";
    cout << FG_TEAL << "  Teal text         " << RESET_COLOR << "\n";
    cout << FG_CYAN << "  Cyan text         " << RESET_COLOR << "\n";
    cout << FG_AQUA << "  Aqua text         " << RESET_COLOR << "\n\n";

    // Purples & Magentas
    cout << FG_DARK_PURPLE << "  Dark Purple text  " << RESET_COLOR << "\n";
    cout << FG_PURPLE << "  Purple text       " << RESET_COLOR << "\n";
    cout << FG_MAGENTA << "  Magenta text      " << RESET_COLOR << "\n";
    cout << FG_VIOLET << "  Violet text       " << RESET_COLOR << "\n";
    cout << FG_LAVENDER << "  Lavender text     " << RESET_COLOR << "\n\n";

    // Earth Tones
    cout << FG_BROWN << "  Brown text        " << RESET_COLOR << "\n";
    cout << FG_OLIVE << "  Olive text        " << RESET_COLOR << "\n";
    cout << FG_RUST << "  Rust text         " << RESET_COLOR << "\n";
    cout << FG_SAND << "  Sand text         " << RESET_COLOR << "\n\n";


    cout << "================ BACKGROUND COLORS ================\n\n";

    // Grayscale
    cout << BG_WHITE << FG_DARK_GRAY << "  White       " << RESET_COLOR << "\n"; // Contrast text for visibility
    cout << BG_LIGHT_GRAY << FG_DARK_GRAY << "  Light Gray  " << RESET_COLOR << "\n";
    cout << BG_GRAY_70 << "  Gray 70     " << RESET_COLOR << "\n";
    cout << BG_GRAY_50 << "  Gray 50     " << RESET_COLOR << "\n";
    cout << BG_GRAY_40 << "  Gray 40     " << RESET_COLOR << "\n";
    cout << BG_GRAY_30 << "  Gray 30     " << RESET_COLOR << "\n\n";

    // Reds & Pinks
    cout << BG_DARK_RED << "  Dark Red    " << RESET_COLOR << "\n";
    cout << BG_RED << "  Red         " << RESET_COLOR << "\n";
    cout << BG_HOT_PINK << "  Hot Pink    " << RESET_COLOR << "\n";
    cout << BG_PINK << FG_DARK_GRAY << "  Pink        " << RESET_COLOR << "\n\n";

    // Oranges & Yellows
    cout << BG_ORANGE << "  Orange      " << RESET_COLOR << "\n";
    cout << BG_PEACH << FG_DARK_GRAY << "  Peach       " << RESET_COLOR << "\n";
    cout << BG_YELLOW << FG_DARK_GRAY << "  Yellow      " << RESET_COLOR << "\n\n";

    // Greens
    cout << BG_DEEP_GREEN << "  Deep Green  " << RESET_COLOR << "\n";
    cout << BG_EMERALD << "  Emerald     " << RESET_COLOR << "\n";
    cout << BG_GREEN << FG_DARK_GRAY << "  Green       " << RESET_COLOR << "\n";
    cout << BG_LIME << FG_DARK_GRAY << "  Lime        " << RESET_COLOR << "\n";
    cout << BG_MINT << FG_DARK_GRAY << "  Mint        " << RESET_COLOR << "\n\n";

    // Blues & Cyans
    cout << BG_MIDNIGHT << "  Midnight    " << RESET_COLOR << "\n";
    cout << BG_ELEC_BLUE << "  Elec Blue   " << RESET_COLOR << "\n";
    cout << BG_BLUE << "  Blue        " << RESET_COLOR << "\n";
    cout << BG_CYAN << FG_DARK_GRAY << "  Cyan        " << RESET_COLOR << "\n";
    cout << BG_AQUA << FG_DARK_GRAY << "  Aqua        " << RESET_COLOR << "\n\n";

    // Purples & Magentas
    cout << BG_PURPLE << "  Purple      " << RESET_COLOR << "\n";
    cout << BG_MAGENTA << "  Magenta     " << RESET_COLOR << "\n";
    cout << BG_LAVENDER << FG_DARK_GRAY << "  Lavender    " << RESET_COLOR << "\n\n";

    // Earth Tones
    cout << BG_BROWN << "  Brown       " << RESET_COLOR << "\n";
    cout << BG_OLIVE << "  Olive       " << RESET_COLOR << "\n";
    cout << BG_RUST << "  Rust        " << RESET_COLOR << "\n\n";

    return 0;
}
