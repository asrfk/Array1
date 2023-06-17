#include "Header.h"

void check(int arr[200]) {
	int input, index;
	bool in = false;
	cout << "what number do you want to find?" << endl;
	cin >> input;//user inputs what number they are looking for
	for (int i = 0; i < 101; i++)
	{
		if (input == arr[i])//goes through entire array to try and find if entry exists
		{
			index = i;
			in = true;//flags if entry exists
		}
	}
	if (in == false)//if flag is not set off
	{
		cout << "Integer " << input << " not in the array" << endl;
	}
	else if (in == true)//flag is set off
	{
		cout << "Integer " << input << " is at index: " << index << endl;
	}
}
void remove(int arr[200]) {
	int input, count=0;
	bool yes = true;
	string cont;
	while (count != 50 && yes == true){//allows for 50 entries to be 'deleted' before exit or if the user wantss to leave before then
		cout << endl;
		cout << "Which index do you want to get rid of" << endl;
		cin >> input;//user inputs an index they want to delete 
		arr[input] = 0; //finds and deletes entry

		for (int i = 0; i < 200; i++)//outputs array to prove it has been deleted
		{
			if (arr[i] > 0)//skips any index with value 0
			{
				cout << arr[i] << " ";
			}
		}
		cout << endl;
		if (count < 50) {// allows program to continue as long as count not > 50
			cout << "Would you like to remove another integer to the array? (Y/N)" << endl;
			cin >> cont;
			if (cont == "n" || cont == "N")
			{
				yes = false;
			}
		}
	}

}

void addition(int arr[200]) {
	bool yes = true;
	string cont;
	int input, count = 0;
	while (count != 50 && yes == true)//allows for 50 repetioton or user input for leaving the loop
	{
		try {//start of try block
			cout << "Enter an integer to add to the array" << endl;
			cin >> input;
			if (cin.fail())//if there is a bad input 
			{
				throw 1;//throw to catch
				cin.clear();//clear the input
			}
			count++;//increases counter 
			arr[99 + count] = input;//appends the end of the array with new value
			if (count < 50) {
				cout << "Would you like to add another integer to the array? (Y/N)" << endl;
				cin >> cont;
				if (cont == "n" || cont == "N")//user determines if loop continues
				{
					yes = false;//flag to tell if loop will continue
				}
			}
		}
		catch (...)//catches the thrown error
		{
			cout << "ENTER A VALID NUMBER" << endl;
			cin.clear();//clears the error
			cin.ignore(10000, '\n');//ignores the initial error
		}
	}
	for (int i = 0; i < 100+count; i++)//outputs entire array as proof
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	remove(arr);

}
void modify(int arr[200]) {
	int input, hold, change, count = 0;
	bool yes = true;
	string cont;
		while (count != 50 && yes == true) //like before
		{
			try
			{
				cout << "Which index in the array would you like to alter (enter index 0-99)" << endl;
				cin >> input;
				if (cin.fail())
				{
					throw 1;
					cin.clear();
				}
				hold = arr[input];//holds old value
				cout << "What would you like to change it to?" << endl;
				cin >> change;
				if (cin.fail())
				{
					throw 1;
					cin.clear();
				}
				arr[input] = change;//assigns new value to old value
				cout << "Old value: " << hold << endl << "New Value:" << change << endl;
				for (int i = 0; i < 100; i++)
				{
					cout << arr[i] << " ";
				}
				if (count < 50) {
					cout << endl << "Would you like to alter another index in the array? (Y/N)" << endl;
					cin >> cont;
					if (cont == "n" || cont == "N")
					{
						yes = false;
					}
				}
			}

			catch (...)
			{
				cout << "ENTER A VALID NUMBER" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}

		}
	cout << endl << endl;
	addition(arr);

}

void read() {
	int array[200], mod;
	ifstream fin;
	fin.open("numbers.txt");//opens and reads txt file
	for (int i = 0; i < 200; i++)
	{
		if (i < 100)//only takes the first 100 inputs
		{
			fin >> array[i];//reads file and ignores spaces placing integers into the array
		}
		else
		{
			array[i] = 0;//to avoid the weird numbers assigning 0 for any index freater than or equal to 100 is easier
		}

	}
	check(array);
	modify(array);
}
