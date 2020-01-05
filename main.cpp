// Izzy Ehnes
// CS 10B, Section 3031
// a7_2.cpp
// 10/8/18
//
// DESCRIPTION:
// This program reads a sequence of characters entered by the user, 
// and is only terminated when the user enters a period ('.'). It uses 
// a struct array to store each letter of the alphabet, as well as each letter's 
// corresponding number of appearences in the user entered text. 
// It then sorts and displays each letter by its frequency.



#include <iostream>
#include <iomanip>
using namespace std;



struct Letter
{
	char letter;
	int frequency;
};



int main()
{
	Letter letters[26] = 
	{
		{'a', 0}, {'b', 0}, {'c', 0},
		{'d', 0}, {'e', 0}, {'f', 0}, 
		{'g', 0}, {'h', 0}, {'i', 0}, 
		{'j', 0}, {'k', 0}, {'l', 0}, 
		{'m', 0}, {'n', 0}, {'o', 0}, 
		{'p', 0}, {'q', 0}, {'r', 0}, 
	    {'s', 0}, {'t', 0}, {'u', 0}, 
		{'v', 0}, {'w', 0}, {'x', 0}, 
		{'y', 0}, {'z', 0},
	};
							 
	char ch;
	
	cout << "Enter a sequence of characters (end with '.'): ";
	cin >> ch;
	
	if (isalpha(ch))
	{
		ch = tolower(ch);
		letters[ch - 97].frequency++;
	}
	
	while (ch != '.') 
	{
		cin >> ch;
		
		if (isalpha(ch))
		{
			ch = tolower(ch);
			letters[ch - 97].frequency++;
		}
	}
	
	bool swap;
	Letter temp;

	do  // sorts the array by letter's frequency
	{
	    swap = false;
	    for (int count = 0; count < 24; count++)
	    {
	        if (letters[count].frequency < letters[count + 1].frequency)
	        {
	        	temp = letters[count];
	            letters[count] = letters[count + 1];
	            letters[count + 1] = temp;
	            swap = true;
	        }
	    }
	} while (swap);
	
	
	cout << "\nLetter:    Number of Occurences:\n";
	
	for (int count = 0; count < 26; count++)  // displays each letter appearing in the user entered
	{                                         // text, as well as its number of appearances
		if (letters[count].frequency != 0)
		{
			cout << setw(7) << letters[count].letter << setw(5) << letters[count].frequency << endl;
		}
	}
	
	return 0;
}

/* SAMPLE OUTPUT:

Enter a sequence of characters (end with '.'):  sHe $3lls sEa
SheL
ls.by the seA shore

Letter:    Number of Occurences:
      s    5
      l    4
      e    3
      h    2
      a    1

*/