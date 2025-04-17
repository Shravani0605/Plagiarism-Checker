#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h> // for delay()

void border(const char* title) {
    clrscr();
    textcolor(3); // Cyan

    for (int x = 1; x <= 80; x++) {
        gotoxy(x, 1); cout << "=";
        gotoxy(x, 25); cout << "=";
    }

    for (int y = 1; y <= 25; y++) {
        gotoxy(1, y); cout << "||";
        gotoxy(79, y); cout << "||";
    }

    gotoxy(1, 1); cout << "++";
    gotoxy(79, 1); cout << "++";
    gotoxy(1, 25); cout << "++";
    gotoxy(79, 25); cout << "++";

    textcolor(14); // Yellow
    gotoxy(30, 2); cputs(title);
    textcolor(7);  // Reset color
}

void start() {
    border(" PLAGIARISM CHECKER ");
    textcolor(11); // Light Cyan
    gotoxy(24, 6); cputs("* * * WELCOME TO * * *");
    gotoxy(20, 7); cputs("# # PLAGIARISM CHECKER # #");

    textcolor(14); // Yellow
    gotoxy(30, 9); cputs("Developed By:");
    textcolor(10); // Green
    gotoxy(32, 11); cputs("1. Shravani");
    gotoxy(32, 12); cputs("2. Vaibhav");
    gotoxy(32, 13); cputs("3. Sarthak");

    textcolor(15);
    gotoxy(22, 20); cputs("Press any key to continue...");
    getch();
}

void checkPlagiarism() {
    border(" CHECK PLAGIARISM ");

    char file1[50], file2[50];
    gotoxy(10, 5); cputs("Enter the name of the first file: ");
    cin >> file1;
    gotoxy(10, 6); cputs("Enter the name of the second file: ");
    cin >> file2;

    ifstream f1(file1);
    ifstream f2(file2);

    if (!f1 || !f2) {
        textcolor(12); // Red
        gotoxy(10, 8); cputs("Error opening file(s). Check filenames.");
        textcolor(15);
        gotoxy(10, 10); cputs("Press any key to return to the menu...");
        getch();
        return;
    }

    char line1[500], line2[500];
    int totalLines = 0, matchedLines = 0;

    while (!f1.eof() && !f2.eof()) {
        f1.getline(line1, 500);
        f2.getline(line2, 500);
        totalLines++;
        if (strcmp(line1, line2) == 0) {
            matchedLines++;
        }
    }

    while (!f1.eof()) {
        f1.getline(line1, 500);
        totalLines++;
    }

    while (!f2.eof()) {
        f2.getline(line2, 500);
        totalLines++;
    }

    float plagiarism = 0;
    if (totalLines > 0) {
        plagiarism = (matchedLines * 100.0) / totalLines;
    }

    textcolor(10); // Green
    gotoxy(10, 12); cputs("Plagiarism Detected: ");
    textcolor(14); cout << plagiarism << "%";

    f1.close();
    f2.close();

    textcolor(15);
    gotoxy(10, 15); cputs("Press any key to return to the menu...");
    getch();
}

void exitProgram() {
    border(" EXITING ");
    textcolor(14);
    gotoxy(24, 12); cputs("Thank you for using the Plagiarism Checker.");
    gotoxy(32, 14); cputs("Exiting...");
    delay(1000);
    getch();
    exit(0);
}

void main() {
    char ch;
    start();

    do {
        border(" MAIN MENU ");
        textcolor(11); // Light Cyan
        gotoxy(25, 6); cputs("[1] Check Plagiarism");
        gotoxy(25, 7); cputs("[2] Exit");
        textcolor(15);
        gotoxy(25, 9); cputs("Enter your choice: ");
        ch = getche();

        switch (ch) {
            case '1':
                checkPlagiarism();
                break;
            case '2':
                exitProgram();
                break;
            default:
                textcolor(12); // Red
                gotoxy(25, 11); cputs("Invalid choice. Try again.");
                textcolor(15);
                getch();
        }
    } while (ch != '2');
}
