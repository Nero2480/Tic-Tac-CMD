#pragma once
class tictac
{

private:

	bool Doeswin(unsigned int bitvalue)
	{
		// horizontal victories
		for (int i = 0; i < 9; i++)
		{
			unsigned int horizontalLayercheck = 0b111 << (i * 3); // a staight horizontal row of 3 on a layer
			unsigned int placeholder = (bitvalue & horizontalLayercheck);
			if (placeholder == horizontalLayercheck)
			{
				return true; // victory
			}
		}

		// vertical victories
		for (int i = 0; i < 2; i++) // checking for vertical wins on first layer
		{
			unsigned int verticalLayercheck = 0b001001001 << (i); // // a staight vertical row of 3 on 1st layer
			unsigned int placeholder = (bitvalue & verticalLayercheck);
			if (placeholder == verticalLayercheck)
			{
				return true; // victory
			}
		}
		for (int i = 9; i < 12; i++) // checking for vertical wins on 2nd layer
		{
			unsigned int verticalLayercheck = 0b001001001 << (i);
			unsigned int placeholder = (bitvalue & verticalLayercheck);
			if (placeholder == verticalLayercheck)
			{
				return true; // victory
			}
		}

		for (int i = 18; i < 21; i++) // checking for vertical wins on 3rd layer
		{
			unsigned int verticalLayercheck = 0b001001001 << (i);
			unsigned int placeholder = (bitvalue & verticalLayercheck);
			if (placeholder == verticalLayercheck)
			{
				return true; // victory
			}
		}

		// checking for diagonals on a layer
		unsigned int diagonalLayercheck[6] = { 0b100010001,0b1010100, 0b100010001000000000, 0b1010100000000000, 0b100010001000000000000000000, 0b1010100000000000000000000 };
		for (int i = 0; i < 6; i++)
		{
			unsigned int placeholder = (bitvalue & diagonalLayercheck[i]);
			if (placeholder == diagonalLayercheck[i])
			{
				return true; // victory
			}
		}
		
		// checking for 3d verticals
		for (int i = 0; i < 9; i++)
		{
			unsigned int vertical3 = 0b1000000001000000001 << (i); // a staight vertical through three layers
			unsigned int placeholder = (bitvalue & vertical3);
			if (placeholder == vertical3)
			{
				return true; // victory
			}
		}

		// There is no straight horizontal through three layers it's covered by the 2D categories.

		// Diagonals going left to right downward diagonally
		for (int i = 0; i < 2; i++) 
		{
			unsigned int diagonalCubetype1 = 0b100000000010000000001 << (i * 3);
			unsigned int placeholder = (bitvalue & diagonalCubetype1);
			if (placeholder == diagonalCubetype1)
			{
				return true; // victory
			}
		}
		// Diagonals going right to left downward diagonally
		for (int i = 0; i < 2; i++)
		{
			unsigned int diagonalCubetype2 = 0b1000000010000000100 << (i * 3);
			unsigned int placeholder = (bitvalue & diagonalCubetype2);
			if (placeholder == diagonalCubetype2)
			{
				return true; // victory
			}
		}

		// Diagonals going top to bottom from birds eye view downward diagonally
		for (int i = 0; i < 2; i++)
		{
			unsigned int diagonalCubetype3 = 0b1000000000001000000000001 << (i);
			unsigned int placeholder = (bitvalue & diagonalCubetype3);
			if (placeholder == diagonalCubetype3)
			{
				return true; // victory
			}
		}

		// Diagonals going bottom to top from birds eye view downward diagonally
		for (int i = 0; i < 2; i++)
		{
			unsigned int diagonalCubetype4 = 0b1000001000001000000 << (i);
			unsigned int placeholder = (bitvalue & diagonalCubetype4);
			if (placeholder == diagonalCubetype4)
			{
				return true; // victory
			}
		}

		// The two diaganols going through the center of the cube
		for (int i = 0; i < 2; i++)
		{
			unsigned int diagonalCubetype5[2] = { 0b100000000000010000000000001, 0b100000010000001000000 };
			unsigned int placeholder = (bitvalue & diagonalCubetype5[i]);
			if (placeholder == diagonalCubetype5[i])
			{
				return true; // victory
			}
		}
		return false; // no victory
	}

public:

	bool convertboardbitwise(char *board, char x) // convert board into 27 bit number where the LSB is whether space 0 is occupied by char or not
	{
		unsigned int bitvalue = 0;
		for (int i = 0; i < 27; i++)
		{
			if (*(board + i) == x)
			{
				bitvalue += exp2(i);
			}
		}
		return Doeswin(bitvalue);
	}
	void Displaynumbering()
	{
		std::cout << " Layer 1        Layer 2         Layer 3\n";
		std::cout << "  " << 0 << "|" << 1 << "|" << 2 << "         " << 9 << "|" << 10 << "|" << 11 << "        " << 18 << "|" << 19 << "|" << 20 << "\n";
		std::cout << "  " << 3 << "|" << 4 << "|" << 5 << "        " << 12 << "|" << 13 << "|" << 14 << "        " << 21 << "|" << 22 << "|" << 23 << "\n";
		std::cout << "  " << 6 << "|" << 7 << "|" << 8 << "        " << 15 << "|" << 16 << "|" << 17 << "        " << 24 << "|" << 25 << "|" << 26 << "\n";
	}

	void Display(char *board1) // Displays the board
	{
		std::cout << " Layer 1        Layer 2         Layer 3\n";
		std::cout << "  " << board1[0] << "|" << board1[1] << "|" << board1[2] << "          " << board1[9] << "|" << board1[10] << "|" << board1[11] << "          " << board1[18] << "|" << board1[19] << "|" << board1[20] << "\n";
		std::cout << "  " << board1[3] << "|" << board1[4] << "|" << board1[5] << "          " << board1[12] << "|" << board1[13] << "|" << board1[14] << "          " << board1[21] << "|" << board1[22] << "|" << board1[23] << "\n";
		std::cout << "  " << board1[6] << "|" << board1[7] << "|" << board1[8] << "          " << board1[15] << "|" << board1[16] << "|" << board1[17] << "          " << board1[24] << "|" << board1[25] << "|" << board1[26] << "\n";
	}

	char makeboard(char *board) // creates board
	{
		for (int i = 0; i < 27; i++)
		{
			*(board + i) = ' ';
		}
		return *board;
	}

	int choice = 0;
};