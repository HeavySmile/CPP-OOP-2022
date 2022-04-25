#include <iostream>
#include "Vector.hpp"

using namespace std;

int main()
{	
	// If vector.bin is empty
    // writeToFile((Vector){ 0,1,2 });
	// writeToFile((Vector){ 4,5,6 });
	// writeToFile((Vector){ 4,5,6 });
	// writeToFile((Vector){ 0,0,0 });
	// writeToFile((Vector){ 2,2,2 });
	
	Vector* vectors = new Vector[getFileSize("vector.bin")];
	readFromFile("vector.bin", vectors);
	for (int i = 0; i < getFileSize("vector.bin"); i++)
	{
		cout << vectors[i].x << endl;
		cout << vectors[i].y << endl;
		cout << vectors[i].z << endl;
		cout << endl;
	}
	return 0;
}
