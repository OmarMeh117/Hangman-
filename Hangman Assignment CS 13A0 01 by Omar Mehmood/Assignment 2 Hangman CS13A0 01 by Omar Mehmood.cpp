// Omar Mehmood
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void rules();
void startgame();
void hack();
void prank ();
void temp ();

string destroy;

int main ()
{
	int choicemenu;
	int fails {6};
	char guess;
	string word;
	string wordList[5];
	bool guessiscorrect = false;
	int playerone;
	string data [100];
	
	 
	cout << "WELCOME TO HANGMAN!";
	do {
	cout << "\n-------------------\n1) Create New Words - (NOTE: You may need to re-run the program after creating words.)\n2) Start New Game - (WARNING: Will not work without creating new words first!)\n3) Rules\n4) !!ER&&R\n5) Quit\n\nSELECTION: ";
	cin >> choicemenu;
	
	if(choicemenu == 1){
	ofstream CreateNewWords ("listofwordsbyOmar.txt");
	cout << "(all lowercase)Please enter amount of words: ";
	cin >> playerone;
	for (int i = 1 ; i <= playerone ; i++){
	cout << "words " << i << ": ";
	cin >> data[i];
	CreateNewWords << data[i] << endl;
	}
	
	}
	
		srand(time(0));
	ifstream RandomWord;
	RandomWord.open("listofwordsbyOmar.txt");
	for (int i = 0 ; i < 5 ; i++)
	{
		RandomWord >> wordList[i];
	 } 
	 int RandNum = rand()&5+1;
	 word = wordList[RandNum];
	 RandomWord.close();
	 string hiddenwordforUser(word.length(), '-');
			
	if (choicemenu == 2) {
	while (fails >= 0)	
	{
	guessiscorrect = false;
	cout << "\nGuess: ";
	cin >> guess;
	for (int i = 0 ; i < hiddenwordforUser.length() ; i++ )
	{
	 if (word[i] == guess ) 
	 {
      hiddenwordforUser[i] = guess; 
	  cout << guess << " is in the word";
	  guessiscorrect = true;
	 }
	}
	 if (word == hiddenwordforUser )
	 {
	 	cout << "\nGood job! you got the word!" << " The word was: " << hiddenwordforUser;
	 	break;
	 }
	  if (guessiscorrect == false)
	 {
	 	fails--;
	 	cout << "Sorry, " << guess << " is not part of the word";
	 }

	switch (fails)
	{ 
		case 6:
		{  
			cout << "\n________________" << endl;
			cout << "|        |      " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|_______________" << endl;
		
			break;
		}
		case 5:
		{
			cout << "\n________________" << endl;
			cout << "|        |      " << endl;
			cout << "|        O      " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|_______________" << endl;
			break;
		}
		case 4:
		{
			cout << "\n________________" << endl;
			cout << "|        |      " << endl;
			cout << "|        O      " << endl;
			cout << "|        |      " << endl;
			cout << "|        |      " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|_______________" << endl;
			
			break;
		}
		case 3:
		{
			cout << "\n________________" << endl;
			cout << "|        |      " << endl;
			cout << "|        O      " << endl;
			cout << "|        |      " << endl;
			cout << "|       /|      " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|_______________" << endl;
			
			break;
		}
		case 2:
		{
			
			cout << "\n________________" << endl;
			cout << "|        |      " << endl;
			cout << "|        O      " << endl;
			cout << "|        |      " << endl;
			cout << "|       /|\\    " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|               " << endl;
			cout << "|_______________" << endl;
			
			break;
		}
		case 1:
		{
			cout << "\n________________" << endl;
			cout << "|        |      " << endl;
			cout << "|        O      " << endl;
			cout << "|        |      " << endl;
			cout << "|       /|\\    " << endl;
			cout << "|       /       " << endl;
			cout << "|      /        " << endl;
			cout << "|               " << endl;
			cout << "|_______________" << endl;
			
			break;
		}
		case 0:
		{
			cout << "\n________________" << endl;
			cout << "|        |      " << endl;
			cout << "|        O      " << endl;
			cout << "|        |      " << endl;
			cout << "|       /|\\    " << endl;
			cout << "|       / \\    " << endl;
			cout << "|      /   \\   " << endl;
			cout << "|               " << endl;
			cout << "|_______________" << endl;
			cout << "You lost! better luck next time friend!";
			fails = -1;
			break;
		}
	}
}		

}

	if (choicemenu == 3) rules();
	
	if (choicemenu == 4) hack();
	
	if (choicemenu == 6) prank ();
	if (choicemenu == 7) temp ();
	
	}while (choicemenu != 5);
	cout << "Thank you for playing my game!";

	return 0;
}

void rules()
{
	cout << "\nHangman Requires 2 to 4 players!\n\nOne player thinks of a word or phrase, the others try to guess what it is one letter at a time.\n"
	<< "Everytime a guessing player gets a letter wrong, part of the body is drawn.\n"
	<< "If the players guessing get a letter correct, draw the letter in each word position that was guessed.\n"
	<< "If the hangman is fully drawn, the players guessing lose!\n"
	<< "Otherwise if the word is guessed, the guessing players win!\n";
	
}

void hack()
{
	cout << "ERROR ERROR SYSTEM COMPROMISED! FILES HAVE BEEN CORRUPUTED! 0xC00D080DL\n";
	ofstream hack ("listofwordsbyOmar.txt");
	hack << "ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR!";
}

void prank ()
{
	ofstream prank ("listofwordsbyOmar.txt");
	for (int i = 1 ; i <= 1000000 ; i++)
	prank << i; 
	cout << "HAHA! ENJOY THE NUMBERS IN YOUR FILE!"; //hopefully your computer doesn't crash sorry professor 
}

void temp ()
{
		int d, rt;
		
	cout << "WELCOME TO TEMPERATURE CALCU-wait how'd this get here...? why did you press 7 when it was only 1 to 5?\n--------------------------------------------------------------------------------\n";
	cout << "Please insert how many days you would like to track: ";
	cin >> d;
	int temp[d];
	rt = 0;
	for (int i=0 ; i < d ; i++ )
	{cout << "\nNow please insert the temperature on day " << (i+1) << ": ";
	cin >> temp[i];
	rt = rt + temp[i];
	}
	cout << "\n----------------------------------------------------\nThe average temperature of the following days is: " << rt/d;
	int low = temp[0], high = temp[0];
	for (int c = 0 ; c < d ; c++ ) {
		if (temp [c] < low) low = temp[c];
		if (temp [c] > high) high = temp[c];  
	}
	 cout << "\n------------------------------------------------\nLowest Temperature out of the following days: " << low;
	 cout << "\n-------------------------------------------------\nHighest temperature out of the following days: " << high;
	 cout << "\n\n";
}





