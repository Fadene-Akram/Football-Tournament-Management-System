#ifndef TABLEMENU_H
#define TABLEMENU_H

#include <vector>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include "Tournament.h"
#include "File.h"

class TableMenu {
public:
    explicit TableMenu(const std::vector<std::string> &options);

    int showMenu();

    void setDynamicContent(const std::string &content);

    void setColor(int color);

    void resetColor();
    void setBackgroundColor(int color);
    void resetBackgroundColor();
    void printHorizontalLine(int length, int backgroundColor = 0);

private:
    const int tableWidth;
    const std::vector<std::string> options;
    int current_highlight;
    WORD originalAttributes; // Store original console attributes
    std::string dynamicContent;
};

TableMenu::TableMenu(const std::vector<std::string> &options)
    : tableWidth(18), options(options), current_highlight(0) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    originalAttributes = csbi.wAttributes;
}

void TableMenu::setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void TableMenu::resetColor() {
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset color to white
}

void TableMenu::setBackgroundColor(int color) {
    setColor(color << 4); // Set background color
}

void TableMenu::resetBackgroundColor() {
    setBackgroundColor(0); // Reset background color
}

void TableMenu::printHorizontalLine(int length, int backgroundColor) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    for (int i = 0; i < screenWidth; ++i) {
        setBackgroundColor(backgroundColor);
        std::cout << " ";
        resetBackgroundColor();
    }
    std::cout << std::endl;
}

void TableMenu::setDynamicContent(const std::string &content) {
    dynamicContent = content;
}

int TableMenu::showMenu() {
    int totalOptions = static_cast<int>(options.size());
    while (true) {

        system("cls");
        
        std::cout<<"\n\n\n\n"<<std::endl;
    printHorizontalLine(tableWidth, 14); // Print the top border with yellow background
    setColor(15);
    std::cout << "\t\t\t\t\t\t\t"<<"\033[3m"<<options[0];
    std::cout << "   " << std::endl;
        printHorizontalLine(tableWidth, 14); // Print the top border with yellow background
        for (int i = 1; i < totalOptions; ++i) {
            std::cout << "|";
            if (i == current_highlight) {
                setBackgroundColor(14); // Yellow background for selected row
                setColor(12); // Highlight the selected row with red color
                std::cout << "  ->  ";
            } else {
                setBackgroundColor(0); // Reset background color
                setColor(15); // Reset text color to white
                std::cout << "   ";
            }
            // Print the option text
            std::cout << "\t\t\t\t\t\t\t"<<"\033[3m"<<options[i];
            std::cout << "\033[0m";
            resetColor(); // Reset color
            resetBackgroundColor(); // Reset background color
            std::cout << "   |" << std::endl;
            printHorizontalLine(tableWidth, 14); // Horizontal line between choices
        }

        // Print dynamic content
        if (!dynamicContent.empty()) {
            std::cout << dynamicContent << std::endl;
        }

        char key = _getch();
        switch (key) {
            case 72: // Up Arrow key ASCII value
                current_highlight = (current_highlight - 1 + totalOptions) % totalOptions;
                break;
            case 80: // Down Arrow key ASCII value
                current_highlight = (current_highlight + 1) % totalOptions;
                break;
            case 13: // Enter key ASCII value
                system("cls");
                resetColor(); // Reset color before returning
                return current_highlight;
        }

        // Introduce a delay to avoid rapid key presses
        Sleep(100);
    }
}
#endif // TABLEMENU_H
