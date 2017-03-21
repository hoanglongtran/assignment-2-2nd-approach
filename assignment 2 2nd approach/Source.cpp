/*ASSIGNMENT 2:
Program description: Prompt users to input the text file's name and its directory, the program then will calculate and create a frequency table, ranging from <=0 to >=10. Finally, the
program will calculate the median of the table as well as its mode*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int tem, middleNum, num;																			//Creating neccessary variables
	int a = 0, mode = 0, noNum = 0, N = 0;
	int previousN = 0;
	int tuna = 0;
	float median;
	bool flag = true;
	bool key = false;
	bool check;
	int frequency[11] = { 0,0,0,0,0,0,0,0,0,0,0 };

	string fileName, fileDirectory, asking;
	ifstream abc;


		do {
			check = false;
			cout << "Please enter file name with .txt extension (eg: aaa.txt): ";						//Prompt users to input information about the text file
			getline(cin, fileName);
			if (fileName == "-1") {
				return 0;
			}
			cout << "PLease enter the directory that the file is stored: ";
			getline(cin, fileDirectory);
			abc.open((fileDirectory + "/" + fileName).c_str());

			if (abc.is_open()) {																		//Check if the file exists, if yes, continute, if no, repeat the process or give users ability to stop the program
				cout << "File found! Press ENTER key to countinute" << endl;
				cin.get();
			}
			else {
				cout << "File not found, please enter the file name and the file directory again or type -1 to exit!" << endl;
				check = true;
			}
		} while (check);
		cout << "This is the frequency table of numbers input from the text file" << endl;				//Condition to repeat the process

		cout << "Class" << "     |   " << "Frequency" << endl;
		cout << "__________|____________" << endl;

		while (abc >> tem) {
			if (tem <= 0) {
				frequency[0]++;
			}
			if (tem == 1) {
				frequency[1]++;
			}
			if (tem == 2) {
				frequency[2]++;
			}
			if (tem == 3) {
				frequency[3]++;
			}
			if (tem == 4) {
				frequency[4]++;
			}
			if (tem == 5) {
				frequency[5]++;
			}
			if (tem == 6) {
				frequency[6]++;
			}
			switch (tem)
			{
			case 7:
				frequency[7]++;
				break;
			case 8:
				frequency[8]++;
				break;
			case 9:
				frequency[9]++;
				break;
			default:
				break;
			}
			if (tem >= 10) {
				frequency[10]++;
			}
		}
		for (a = 0; a < 10; a++) {
			cout << "   " << a << "      |       " << frequency[a] << endl;
			cout << "----------|------------" << endl;
		}
}