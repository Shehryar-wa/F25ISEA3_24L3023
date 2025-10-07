//#include<iostream>
//#include<conio.h>
//#include<string>
//#include <windows.h>  // for Sleep()
//#include <cstdlib>    // for rand(), srand()
//#include <ctime>      // for time()
//using namespace std;
//
//// prints title screen
//void printtitle()
//{
//	system("cls");
//
//	cout << "\033[33m" << "********************************************************************************************************************\n" << "\033[00m";
//	cout << "\n\t\t\t\t\t\ttic tac toe!!!\n";
//	cout << "\033[33m" << "\n********************************************************************************************************************\n\n" << "\033[00m";
//}
//
//// prints Player information and their symbols
//void playerInfo(string name1,string name2, int wontoss)
//{
//	cout << "\n\t\t\tThe following players are playing this tictactoe game:\n\n\n";
//	if(wontoss == 1)
//		cout << "\t\t\t\t" << name1 << " (X)\t\t\t" << name2 << " (O)\n\n\n";
//	else
//		cout << "\t\t\t\t" << name1 << " (O)\t\t\t" << name2 << " (X)\n\n\n";
//}
//
//// class that includes all the functionality of tictactoe game
//class tictactoe
//{
//	char** board;
//	int size;
//
//public:
//	char n1_symbol;   // symbol of player 1
//	char n2_symbol;   // symbol of player 2
//	int currentTurn;  // which player is playing
//	int wontoss;      // which player won the toss
//
//	//construct a 3x3 board as default
//	tictactoe(int s = 3)
//	{
//		size = s;
//		board = new char* [size];
//		int num = 1;
//		for (int i = 0; i < size; i++)
//		{
//			board[i] = new char[size];
//			for (int j = 0; j < size; j++)
//			{
//				board[i][j] = ('0' + (num++));
//			}
//		}
//	}
//	
//	//print the tictactoe Board
//	void printboard()
//	{
//		cout << "\033[00m" << "\t\t\t\t\t\t -------------\n";
//		for (int i = 0; i < size; i++)
//		{
//			cout << "\t\t\t\t\t\t";
//			for (int j = 0; j < size; j++)
//			{
//				cout << "\033[00m" << " | ";
//				if (board[i][j] == 'X')
//					cout << "\033[36m" << board[i][j];
//				else if (board[i][j] == 'O')
//					cout << "\033[91m" << board[i][j];
//				else
//					cout << "\033[93m" << board[i][j];
//
//				if (j == size - 1)
//					cout << "\033[00m" << " |";
//			}
//			cout << endl;
//		}
//		cout << "\033[00m" "\t\t\t\t\t\t -------------\n" << "\033[00m";
//	}
//
//	// helper function used to select which player plays first
//	void selectfirstTurn(string name1,string name2)
//	{
//		srand(time(0));
//
//		string sides[2] = { name1, name2 };
//		int delay = 50;
//		int index = 0;	
//
//		printtitle();
//		cout << "\n\nLets see who play first...\n";
//
//
//		//console based UI animation part 
//		for (int i = 0; i < 20; i++)
//		{
//			if (0 == i % 2)
//				cout << "\r\t\t\t\t\t\t" << "\033[33m" << sides[0] << "                              ";
//			else
//				cout << "\r\t\t\t\t\t\t" << "\033[93m" << sides[1] << "                              ";
//			index = i % 2;
//			Sleep(delay);
//			delay += 20;
//		}
//		cout << "\033[00m";
//
//		string result = sides[rand() % 2];
//		cout << "\r                                                                   \n\n\n\t\t\t\033[92m" << result << "\033[00m" << " will play first, with " << "\033[36m" << "(X) " << "\033[00m" << "as representation!!!!\n\n\n\n\t\t\t\t\t\t" << "\033[33m" << "LOADING......" << "\033[00m";
//
//		//assigning symbols to the players
//		if (result == sides[0])
//		{
//			n1_symbol = 'X';
//			n2_symbol = 'O';
//			currentTurn = wontoss = 1;
//			;
//		}
//		else
//		{
//			n2_symbol = 'X';
//			n1_symbol = 'O';
//			currentTurn = wontoss = 2;
//		}
//	}
//
//	//add the respective player symbol to the avaliable number present in the board
//	int addSymbol(int number)
//	{
//		char symbol = (currentTurn == 1) ? n1_symbol : n2_symbol;
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//			{
//				if (board[i][j] == (number))
//				{
//					board[i][j] = symbol;
//					return 0;
//				}
//			}
//		}
//		return 1;
//	}
//
//	// helper fucntion which announce who is the winner of the game 
//	bool checkForWinner()
//	{
//		bool horizontalcheck = true;
//		bool verticalcheck = true;
//		bool diagonalcheck = true;
//		bool sec_diagonalcheck = true;
//
//		char symbol = (currentTurn == 1) ? n1_symbol : n2_symbol;
//
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//			{
//				if (board[i][j] == symbol)
//				{
//					horizontalcheck = true;
//					continue;
//				}
//				horizontalcheck = false;
//				break;
//			}
//			if (horizontalcheck)
//				return true;
//		}
//
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//			{
//				if (board[j][i] == symbol)
//				{
//					verticalcheck = true;
//					continue;
//				}
//				verticalcheck = false;
//				break;
//			}
//			if (verticalcheck)
//				return true;
//		}
//
//		for (int i = 0; i < size; i++)
//		{
//			if (board[i][i] != symbol)
//				diagonalcheck = false;
//			if (board[i][size - 1 - i] != symbol)
//				sec_diagonalcheck = false;
//		}
//
//		if (horizontalcheck || verticalcheck || diagonalcheck || sec_diagonalcheck)
//			return true;
//
//		return false;
//	}
//
//	//helper function which checks, is their any place avaliable for symbol 
//	bool draw()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++)
//			{
//				if (board[i][j] >= '1' && board[i][j] <= (48 + (size * size)))
//					return false;
//			}
//		}
//		return true;
//	}
//};
//
//int main()
//{
//	tictactoe game1;
//	string name1 = "1", name2 = "2"; // name of players 
//
//	printtitle();
//	// name input section
//	cout << "\t\t\tEnter the name of Player_1 : " << "\033[33m";
//	getline(cin, name1);
//	cout << "\033[00m" << "\n\t\t\tEnter the name of Player_2 : " << "\033[93m";
//	getline(cin, name2);
//	cout << "\033[00m";
//	printtitle();
//
//	//console based UI animation section
//	game1.selectfirstTurn(name1, name2);
//	Sleep(3500);
//
//	while (true) // loop that runs till it finds any winner or match is draw
//	{
//		printtitle();
//		playerInfo(name1, name2, game1.wontoss);
//
//		game1.printboard();
//
//		int number = 0;
//		if(game1.currentTurn == 1) // number input section
//			cout << "\n\nPress avaliable Numbers, " << name1 << ": ";
//		else
//			cout << "\n\nPress avaliable Numbers, " << name2 << ": ";
//		number = _getch();
//
//		if (game1.addSymbol(number)) // adds symbol in the board
//		{
//			cout << "\033[91m" << "\n\nOUT OF RANGE!!!\nPress any key to continue!!!\n" << "\033[00m";
//			_getch();
//			continue;
//		}
//
//		if (game1.checkForWinner())
//		{
//			// UI part
//			printtitle();
//			playerInfo(name1, name2, game1.wontoss);
//
//			game1.printboard();
//
//			if (game1.currentTurn == 1)
//			{
//				cout << "\033[92m" << "\n\n\n\t\t\t\t\t" << name1 << "\033[00m" << " is the winner of the game!!!\n\n\n\n\n\n\n\n\n";
//				break;
//			}
//			else
//			{
//				cout << "\033[92m" << "\n\n\n\t\t\t\t\t" << name2 << "\033[00m" << " is the winner of the game!!!\n\n\n\n\n\n\n\n\n";
//				break;
//			}
//		}
//
//		game1.currentTurn = (game1.currentTurn == 1) ? 2 : 1;  // changes the turn from one player to another 
//
//		if (game1.draw()) // Display this msg when draw occurs
//		{
//			cout << "\033[91m" << "\n\n\n\t\t\t\t\t\tThe match is draw so GOOD BYE!!!\n\n\n\n" << "\033[00m";
//			break;
//		}
//	}
//}