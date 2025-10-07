#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
using namespace std;

// Prints title board
void PrintMainBoard()
{
	system("cls");

	cout << "\033[33m" << "********************************************************************************************************************\n" << "\033[00m ";
	cout << "\n\t\t\t\t\t\tComplete Words!!!\n";
	cout << "\033[33m" << "\n********************************************************************************************************************\n\n" << "\033[00m ";
}

// ask user to press any key to continue
void skip()
{
	cout << "\n\n\n\t\t\t\tPress any key to continue!!! ";
	_getch();
}

//open file in read mode with name stored in filename string 
int fileopener(string filename, ifstream& file)
{
	 file.open(filename);

	if (!file)  // check if file opened successfully
	{
		cout << "File is not opening!!!!" << endl;
		return -1;
	}
	return 0;
}

// counts lines of the txt file
int FilelineCounter(ifstream& file)
{
	int line = 0;

	string fileline;
	while (getline(file, fileline))
	{
		line++;
	}

	return line;
}

//helper function: 
//				used to update chances remaining of guess
void mistakeOccur(int& mistakes, string guessWord)
{
	PrintMainBoard();
	cout << "\n\n\t\t\tThe word guessed wrong: " << guessWord;
	cout << "\n\n\n\t\t\t\t\tYou have done a mistake!!!\n\t\t\t\t\tThus mistake - 1\n";
	mistakes--;
	skip();
}

//helper function: 
//				used to update blank "_" with userinput and check if is it correct or not
void replaceLetterAndCheck(char userinput, string& guessWord, string& correctWord, int& mistake)
{
	for (int i = 0; guessWord[i] != '\0'; i++)
	{
		if (guessWord[i] == '_')
		{
			guessWord[i] = userinput;

			if (userinput != correctWord[i])
			{
				mistakeOccur(mistake, guessWord);
				guessWord[i] = '_';
				return;
			}
			return;
		}
	}
}

//helper function: 
//				used to is therr any blank left or not in  a word
bool underscoreCheck(string& word)
{
	for (int i = 0; word[i] != '\0'; i++)
	{
		if (word[i] == '_')
			return false;
	}
	return true;
}

int main()
{
	string filename = "hangman_file.txt";
	ifstream guessFile;
	fileopener(filename, guessFile);  // to open a guess word file

	ifstream correctFile;
	filename = "correct_word_file.txt";
	fileopener(filename, correctFile);  // to open a correct word file

	int nooflines = FilelineCounter(guessFile);  // calculate number of lines of file
	guessFile.clear();
	guessFile.seekg(0, ios::beg);

	// this part stores guess file data in array of string 
	string* guessWords = new string[nooflines];
	string temp;
	int arrayCounter = 0;
	while (getline(guessFile, temp))
	{
		guessWords[arrayCounter++] = temp;
	}
	//

	// this part stores correct file data in array of string 
	string* CorrectWords = new string[nooflines];
	arrayCounter = 0;
	while (getline(correctFile, temp))
	{
		CorrectWords[arrayCounter++] = temp;
	}
	//

	int mistakes = 7;   // there are the chances for the user to play 

	//   total display of console window
	int wordsCounter = 0;
	char userInput;
	while ((mistakes != 0) && (wordsCounter != nooflines))
	{
		PrintMainBoard();

		cout << "Fill the Blanks: " << "\033[91m" << "\033[3m( kindly press desired character only )\033[23m" << "\033[00m" << "\t\t\Chances remain: " << "\033[91m" << mistakes << "\033[00m" << "\n\n";
		cout << "\t\tYour " << wordsCounter + 1 << " word is: " << "\033[92m" << guessWords[wordsCounter] << "\n\n\033[00m";
		userInput = _getch();  // taking userinput

		replaceLetterAndCheck(userInput, guessWords[wordsCounter], CorrectWords[wordsCounter], mistakes);  //letter checking

		if (underscoreCheck(guessWords[wordsCounter]))   // if no uderscore remains then the word is completed 
		{
			PrintMainBoard();
			cout << "\t\tYour " << wordsCounter + 1 << " word is: " << "\033[92m" << guessWords[wordsCounter] << "\033[00m\n\n";
			cout << "\n\n\n\t\t\t\t\tYou have Completed Your  " << wordsCounter + 1 << " word!!!\n";
			skip();
			wordsCounter++;
		}

		if (mistakes == 0)  // if mistakes exceeds the limit then GAMEOVER
		{
			system("cls");
			cout << "\033[91m" << "\n\n\n\n\n\n\t\t\t\t\tYour have no chance remaining!!!\n\n\n\t\t\t\t\t\t\tGOOD BYE\n\n\n\n\n\n\n\n" << "\033[00m";
		}

		if (wordsCounter == nooflines)    // if all words are completed then Print YOU WON
		{
			system("cls");
			cout << "\033[92m" << "\n\n\n\n\n\n\t\t\t\t\tYou have completed all your words!!!\n\n\n\t\t\t\t\t\t\tYOU WON\n\n\n\n\n\n\n\n" << "\033[00m";
		}
	}

	guessFile.close();
	correctFile.close();
}