#include <chrono>
#include <iomanip>
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "HrSystem.h"

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

bool IsEnterKeyPressed();
void printCenteredRectangle(int, int, int, int);
void centerText(const string&, int);
void printCenteredRectangle1(int, int, int, int);

int main()
{
	int size, id, limit = 0;
	int choice = 0;
	char choice2 = 'k';
	bool try_again = false, again = false;

	// Change console color to desired color
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);

	// Get console window size
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	int screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int screenHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	// Calculate rectangle dimensions
	int rectangleWidth = screenWidth / 2;
	int rectangleHeight = screenHeight / 2;

	// Clear the console screen
	system("cls");

	// Print the centered rectangle
	printCenteredRectangle(rectangleWidth, rectangleHeight, 0, -11);

	WORD color = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

	SetConsoleTextAttribute(hConsole, color);

	// Wait for the user to press Enter
	while (_getch() != '\r') {}

	// Clear the console screen
	system("cls");

	// Reset the console color to the default
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	system("cls");

	SetConsoleTextAttribute(hConsole, 15);

	std::cout << setw(45) << " " << "Welcome to the HR system" << endl;

	SetConsoleTextAttribute(hConsole, 11);

	cout << setw(20) << " " << "|" << setw(75) << setfill('-') << "|" << endl;
	cout << setfill(' ');

	SetConsoleTextAttribute(hConsole, 15);

	cout << setw(40) << " Please enter the size of employees the company will have: ";
	cin >> size;

	// Clear the screen
	system("cls");

	HrSystem employees(size);

	SetConsoleTextAttribute(hConsole, 15);

	std::cout << setw(45) << " " << "Welcome to the HR system" << endl;

	SetConsoleTextAttribute(hConsole, 11);

	cout << setw(20) << " " << "|" << setw(75) << setfill('-') << "|" << endl;
	cout << setfill(' ');

	SetConsoleTextAttribute(hConsole, 15);
	do
	{
		try_again = false;
		again = false;

		cout << " What do you want to do?:\n 1 - Add Employees\n 2 - Edit Employees\n 3 - Delete Employees\n 4 - Search For An Employee\n 5 - Show All Employees\n 6 - Show Total Payroll Of The company \n";
		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
			{
				do {

					if (limit < size)
					{
						employees.addEmployee();
						limit++;

						cout << " Do you want to add more? (y/n):";
						cin >> choice2;

						if (choice2 == 'y' || choice2 == 'Y')
						{
							again = true;
							system("cls");
						}
						else
						{
							again = false;
						}
					}
					else
					{
						SetConsoleTextAttribute(hConsole, 6);
						cout << " The number of employees limit is reached:(\n";
						SetConsoleTextAttribute(hConsole, 15);

						break;
					}

				} while (again);

				break;
			}

		case 2:
			{
				employees.editEmployee();
				break;
			}

		case 3:
			{
				cout << " Please enter the ID of the employee you want to fire: ";
				cin >> id;

				employees.delEmployee(id);
				break;
			}

		case 4:
			{
				employees.FindEmployee();
				break;
			}

		case 5:
			{
				employees.ShowAll();
				break;
			}

		case 6:
			{

			employees.calcTotalPayroll();
			break;

			}

			default:
			{
				SetConsoleTextAttribute(hConsole, 6);
				cout << " The lovely system doesn't have this option at the moment :)\n";
				SetConsoleTextAttribute(hConsole, 15);
				
			}
			
		}

		cout << " Do you wish to do another systematic operation? (y/n)";
		cin >> choice2;

		if (choice2 == 'y' || choice2 == 'Y')
		{
			try_again = true;
		}

		system("cls");

	} while (try_again);

	system("cls");

	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);

	printCenteredRectangle1(rectangleWidth, rectangleHeight, 0, -11);

	SetConsoleTextAttribute(hConsole, 15);


	return 0;
}

void centerText(const string& text, int width)
{
	int textLength = static_cast<int>(text.length());
	int leftMargin = (width - textLength) / 2;
	int rightMargin = width - leftMargin - textLength;

	std::cout << std::string(leftMargin, ' ') << text << std::string(rightMargin, ' ');
}

void printCenteredRectangle(int width, int height, int bottomMargin, int topMargin)
{
	// Get console window size
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	// Calculate left and right margins for centering the rectangle
	int leftMargin = (consoleWidth - width) / 2;
	int rightMargin = consoleWidth - width - leftMargin;

	// Calculate the actual top margin to shift the rectangle down
	int actualTopMargin = (consoleHeight - (height + topMargin + bottomMargin)) / 2;

	// Print the top margin
	for (int i = 0; i < actualTopMargin; i++) {
		std::cout << std::endl;
	}

	// Print the top border
	std::cout << std::string(leftMargin, ' ') << std::string(width, '*') << std::string(rightMargin, ' ') << std::endl;

	// Print the rectangle body
	for (int i = 0; i < topMargin; i++) {
		std::cout << std::string(leftMargin, ' ') << '*' << std::string(width - 2, ' ') << '*' << std::string(rightMargin, ' ') << std::endl;
	}

	// Center the text
	std::string message = "Welcome, please press Enter to operate the system";
	std::string centeredMessage = std::string(leftMargin, ' ') + '*' + std::string((width - message.length()) / 2 - 1, ' ') + message + std::string((width - message.length()) / 2, ' ') + '*' + std::string(rightMargin, ' ');
	std::cout << centeredMessage << std::endl;

	// Print the bottom part of the rectangle
	for (int i = 0; i < bottomMargin; i++) {
		std::cout << std::string(leftMargin, ' ') << '*' << std::string(width - 2, ' ') << '*' << std::string(rightMargin, ' ') << std::endl;
	}

	// Print the bottom border
	std::cout << std::string(leftMargin, ' ') << std::string(width, '*') << std::string(rightMargin, ' ') << std::endl;
}

void printCenteredRectangle1(int width, int height, int bottomMargin, int topMargin)
{
	// Get console window size
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	// Calculate left and right margins for centering the rectangle
	int leftMargin = (consoleWidth - width) / 2;
	int rightMargin = consoleWidth - width - leftMargin;

	// Calculate the actual top margin to shift the rectangle down
	int actualTopMargin = (consoleHeight - (height + topMargin + bottomMargin)) / 2;

	// Print the top margin
	for (int i = 0; i < actualTopMargin; i++) {
		std::cout << std::endl;
	}

	// Print the top border
	std::cout << std::string(leftMargin, ' ') << std::string(width, '*') << std::string(rightMargin, ' ') << std::endl;

	// Print the rectangle body
	for (int i = 0; i < topMargin; i++) {
		std::cout << std::string(leftMargin, ' ') << '*' << std::string(width - 2, ' ') << '*' << std::string(rightMargin, ' ') << std::endl;
	}

	// Center the text
	std::string message = "Thank you for using the system :)";
	std::string centeredMessage = std::string(leftMargin, ' ') + '*' + std::string((width - message.length()) / 2 - 1, ' ') + message + std::string((width - message.length()) / 2, ' ') + '*' + std::string(rightMargin, ' ');
	std::cout << centeredMessage << std::endl;

	// Print the bottom part of the rectangle
	for (int i = 0; i < bottomMargin; i++) {
		std::cout << std::string(leftMargin, ' ') << '*' << std::string(width - 2, ' ') << '*' << std::string(rightMargin, ' ') << std::endl;
	}

	// Print the bottom border
	std::cout << std::string(leftMargin, ' ') << std::string(width, '*') << std::string(rightMargin, ' ') << std::endl;
}



