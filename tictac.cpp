// tictac.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <limits>
#include <string>
#include <math.h>
#include "Header1.h"

int main()
{

	int i = 0;
	std::string selection = ""; // input is taken as string
	tictac tic;
	char board[27] = { ' ' };
	tic.makeboard(board); // board is filled with blanks
	std::cout << "Welcome Let's Play\n\n";

	while (i < 27) // Game Loop
	{

		tic.Displaynumbering();
		std::cout << "\n";
		tic.Display(board);
		std::cout << "\nIt's Player X's turn. Make a selection Player X.\n\n";
		bool invalidinput = true; // input is assumed invalid until proven otherwise.
		bool numeralcheckpass = false; // assume input fails numeral check.

		while (invalidinput)  // This loop checks if a non-numeral was entered
		{
			std::cin >> selection;
			std::string decimalcheck = selection;

			// This block checks for non integer inputs. It also rejects negative inputs
			{
				if (decimalcheck.std::string::find_first_not_of(std::string("0123456789")) != std::string::npos) // if it contains a non-number there is a problem
				{
					std::cout << "Invaid Input! Please try again.\n\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					numeralcheckpass = false; // numeralcheckpass may have been se false in previous run
				}
				else
				{
					tic.choice = std::stoi(decimalcheck); // It's easier to use an integer for next few checks.
					numeralcheckpass = true; // needed to enter next block
					//invalidinput = false;i
				}
			}

			if (numeralcheckpass == true)
			{ // This block checks if the spot is already taken or if the input > 27.
				if (tic.choice > 27)
				{
					std::cout << "We don't have that many spaces! Please try again.\n\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					//invalidinput = true;
				}
				else if (board[tic.choice] != ' ')
				{
					std::cout << "That spot is already taken! Please try again.\n\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					//invalidinput = true;
				}
				else
				{
					board[tic.choice] = 'X'; // Marks player selection
					i = i++; // counts number of turns until game ends
					invalidinput = false; // escape loop
				}
			}
		}

		// Check for X victory
		bool Xvictory = tic.convertboardbitwise(board, 'X');
		if (Xvictory == true)
		{
			std::cout << "\nPlayer X wins\n\n";
			system("pause");
			return 0;
		}

		tic.Displaynumbering();
		std::cout << "\n";
		tic.Display(board);
		std::cout << "\nIt's Player O's turn. Make a selection Player O.\n\n";
		invalidinput = true; // input already initilized above.
		numeralcheckpass = false; // input is already initilized above

		if (i != 27)  // This prevents an O turn after X's last turn
		{

			while (invalidinput)  // This loop checks if a non-numeral was entered
			{
				std::cin >> selection;
				std::string decimalcheck = selection;

				// This block checks for non integer inputs. It also rejects negative inputs
				{
					if (decimalcheck.std::string::find_first_not_of(std::string("0123456789")) != std::string::npos) // if it contains a non-number there is a problem
					{
						std::cout << "Invaid Input! Please try again.\n\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						numeralcheckpass = false; // numeralcheckpass may have been set false in previous run
					}
					else
					{
						tic.choice = std::stoi(decimalcheck); // It's easier to use an integer for next few checks.
						numeralcheckpass = true; // needed to enter next block
						//invalidinput = false;
					}
				}

				if (numeralcheckpass == true)
				{ // This block checks if the spot is already taken or if the input > 27.
					if (tic.choice > 27)
					{
						std::cout << "We don't have that many spaces! Please try again.\n\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						//invalidinput = true;
					}
					else if (board[tic.choice] != ' ')
					{
						std::cout << "That spot is already taken! Please try again.\n\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						//invalidinput = true;
					}
					else
					{
						board[tic.choice] = 'O'; // Marks player selection
						i = i++; // counts number of turns until game ends
						invalidinput = false; // escape loop
					}
				}
			}

		}
		// Check for O victory
		bool Ovictory = tic.convertboardbitwise(board, 'O');
		if (Ovictory == true)
		{
			std::cout << "\nPlayer O wins\n\n";
			system("pause");
			return 0;
		}
	}
	std::cout << "\nCat's Game\n\n";
	system("pause");
	std::cout << "the game ends";
	return 0; // end
}

