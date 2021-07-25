#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<math.h>

using namespace std;
//https://edabit.com/challenge/jjGkEpXWSJ9ZowL9M

int scoreIt(string& user_input)
{
	int nested_level = 0;
	int cur_value = 0;
	int total=0;

	//   use a loop to go through every character in userinput string
	for (char c : user_input)
	{
		//checks if character is a number between 0-9
		if (c >= '0' && c <= '9')
		{
			// if so add it to the cur_value
			//if there is numbers higher then 9
			// multiply the cur value by a base of 10
			cur_value *= 10;
			cur_value += c - '0';

		}
		else
		{
			//if the character is not a number add that value to the total by multipling it with the nested level
			//reset cur value
			if (cur_value != 0)
			{
				total += cur_value * nested_level;
				cur_value = 0;
			}

			if (c == '(')
			{
				nested_level++;

			}
			else if (c == ')')
			{
				nested_level--;
			}
		}
	}
	return total;
}
int main()
{
	string input;
	int total;
	cout << "Enter an expression " << endl;
	cin >> input;
	
	total = scoreIt(input);
	cout << input << " " << total << endl;
	
	system("PAUSE");
}