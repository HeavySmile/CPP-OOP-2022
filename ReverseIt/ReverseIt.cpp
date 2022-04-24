#include <iostream>
#include <fstream>
#include "IntStack.hpp"

using namespace std;

int main()
{
	IntStack stack;
	
	ifstream fileRead("numbers.bin", ios_base::binary);
	ofstream fileWrite("numbers1.bin", ios::out | ios::binary);
	ofstream humanFile("humanFile.txt");
	
	int buffer;
	
	if (fileRead.is_open() && fileWrite.is_open() && humanFile.is_open())
	{
		// filling up stack structure
		while (fileRead.read((char*)&buffer, sizeof(int)))
		{
			stack.push(buffer);
		}

		// writing to bin, txt, console
		while (stack.size() != 0)
		{
			int buffer = stack.top();
			fileWrite.write((char*)&buffer, sizeof(int));
			humanFile << buffer << endl;
			cout << buffer << endl;
			stack.pop();
		}
	}
	else cout << "Files could not be opened" << endl;

	fileRead.close();
	fileWrite.close();
	humanFile.close();
	
	return 0;
}
