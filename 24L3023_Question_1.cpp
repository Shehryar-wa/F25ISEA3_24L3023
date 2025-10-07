//#include<iostream>
//#include<conio.h>
//#include<string>
//using namespace std;
//
//bool ispalindrome(string userWord)
//{
//	string checkString = userWord;     // copy of the original string
//	int size = userWord.length();
//
//	for (int i = 0; i < size / 2; i++)
//	{
//		char swap = userWord[size - 1 - i];   // swaping characters, starting from back to front
//		userWord[size - 1 - i] = userWord[i];
//		userWord[i] = swap;
//	}
//
//	if (checkString == userWord)    // if string remains same after swapping then return true
//		return true;
//
//	return false;    // otherwise return false
//}
//
//int main()
//{
//	string userWord;
//	while (true)
//	{
//		system("cls");    // clears the screen for understandable output
//		cout << "\n\t\t\t\tPalindrome Checker\n\n";
//		cout << "\033[33m" << "**********************************************************************************************\n" << "\033[00m ";
//		cout << "\nEnter string you want to check for palindrome: "; // input a string 
//		getline(cin, userWord);
//
//		if (ispalindrome(userWord))				// check for palindrome string using a function
//			cout << "\nThe string \"" << userWord << "\" is a Palindrome!!" << "\033[92m " << " YES " << "\033[00m ";
//		else 
//			cout << "\nThe string \"" << userWord << "\" is not a Palindrome!!" << "\033[91m " << " NO " << "\033[00m ";
//
//		cout << "\033[33m" << "\n\n**********************************************************************************************\n" << "\033[00m ";
//		
//		// exit if esc is pressed
//		cout << "\n\n\t\tPress Esc key to exit the program\n\t\t\t\t OR \n\t\tPress any key to continue!!!\n";    
//		int key = _getch();
//		if (key == 27)
//			break;
//	}
//}