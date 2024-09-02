#include <fstream>
#include <iostream>
using namespace std;



//**************************************************************************************************** */
// I had problems running this in vscode but when I ran it in an online complier "onlinegdb.com"
// I was able to run all of my functions without issue.
//***************************************************************************************************** */

// Had problems compiling using MAXCOLS and MAXROWS so
// I just made a different const
const int MAXITER = 10;

// Function that loads a matrix with a file name and array
void LoadImage(const std::string imagefile, int image[MAXITER][MAXITER]) {

	// Opening file
	ifstream infile(imagefile);

	// Open Check
	if (!infile.is_open()) {
		cerr << "Failed to open file for reading.\n";
	}

	// Ignores file name at top
	infile.ignore(MAXITER, '\n');

	// Fills array with values from text files
	for(int i = 0; i<MAXITER; ++i) {
		for (int j = 0; j<MAXITER; ++j) {
			infile >> image[i][j];
		}
	}

	// Closing the file
	infile.close();

}

//Swaps columns with rows
void Transpose(int image[MAXITER][MAXITER]) {
	int temp[MAXITER][MAXITER];
	for (int i = 0; i < MAXITER; ++i) {
		for (int j = 0; j < MAXITER; ++j) {
			temp[i][j] = image[j][i];
		}
	}
	//Setting temp array to image
	for(int i=0; i<MAXITER; i++) {
		for(int j=0; j<MAXITER; j++) {
			image[i][j]=temp[i][j];
		}
	}
}


void FlipHorizontal(int image[MAXITER][MAXITER]) {
	for (int i = 0; i < MAXITER; i++) {
		int left = 0;
		int right = MAXITER - 1;
		//Used left and right to check from both ends of the array columns
		while (left < right) {
			int temp = image[i][left];
			image[i][left] = image[i][right];
			image[i][right] = temp;
			left++;
			right--;
		}
	}

}

void FlipVertical(int image[MAXITER][MAXITER]) {
	for(int i = 0; i<MAXITER; i++) {
		int up = 0;
		int down = MAXITER - 1;
		//Used Up and down to check from both ends of the array rows
		while(up < down) {
			int temp = image[up][i];
			image[up][i] = image[down][i];
			image[down][i] = temp;
			up++;
			down--;
		}
	}

}

void RotateCW(int image[MAXITER][MAXITER]) {
	//Using transpose to invert the array (step one)
	Transpose(image);
	//Reverse the columns to finish the rotation(step two)
	FlipHorizontal(image);
}

void RotateCCW(int image[MAXITER][MAXITER]) {
	//Using transpose to invert the array (step one)
	Transpose(image);
	//Reverse the rows to finish the rotation(step two)
	FlipVertical(image);
}



// int main()
// {
// 	// Initial load and print
// 	int testArray[MAXITER][MAXITER];
// 	LoadImage("test.txt",testArray);
// 	Print(testArray);
// 	cout<< endl;

// 	Transpose(testArray);
// 	Print(testArray);
// 	cout<< endl;

// 	FlipHorizontal(testArray);
// 	Print(testArray);
// 	cout<< endl;

// 	FlipVertical(testArray);
// 	Print(testArray);
// 	cout<< endl;

// 	RotateCW(testArray);
// 	Print(testArray);
// 	cout<< endl;

// 	RotateCCW(testArray);
// 	Print(testArray);
// 	cout<< endl;

// 	return 0;
// }