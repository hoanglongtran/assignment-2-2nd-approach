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
	int previous = 0;
	int tuna = 0;
	int x = 0;
	float median;
	bool flag = true;
	bool key = false;
	bool key1 = true;
	bool check;
	int frequency[11] = { 0,0,0,0,0,0,0,0,0,0,0 };														//Declare an array to count the frequency

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
				check = true;																			//Condition to repeat the input process, if file is not found, boolean "check" will become true and the condition for do-while loop is met
			}
		} while (check);																				
		cout << "This is the frequency table of numbers input from the text file" << endl;				
		cout << "Class" << "       |   " << "Frequency" << endl;
		cout << "____________|______________" << endl;

		while (abc >> tem) {
			noNum++;
			if (tem <= 0) {																				//Run through the file and check with each condition to put the number into the array
				frequency[0]++;
			}
			if (tem >= 10) {
				frequency[10]++;
			}
			switch (tem){
			case 1:
				frequency[1]++;
				break;
			case 2:
				frequency[2]++;
				break;
			case 3:
				frequency[3]++;
				break;
			case 4:
				frequency[4]++;
				break;
			case 5:
				frequency[5]++;
				break;
			case 6:
				frequency[6]++;
				break;
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
		}
		if (noNum % 2 != 0) {
			middleNum = (noNum + 1) / 2;																//Calculate the middle number
		}
		else {
			middleNum = (noNum / 2);
		}
		for (a = 0; a < 11; a++) {
			if (a == 0) {
				cout << " <=0" << "        |       " << frequency[0] << endl;								//Print out the frequency table
				cout << "------------|--------------" << endl;
			}
			else if (a == 10) {
				cout << " >=10" << "       |       " << frequency[10] << endl;
				cout << "------------|--------------" << endl;
			}
			else {
				cout << "   " << a << "        |       " << frequency[a] << endl;
				cout << "------------|--------------" << endl;
			}
			if (frequency[a] > previous) {																//compare the current frequency with the previous one, if large, replace the mode and put it into the previous
				mode = a;
				previous = frequency[a];
			}
			x = x + frequency[a];																		//Calculate the total number at the moment

			if (key && flag && frequency[a] != 0) {
				median = ((float)tuna + (float)a) / 2;
				flag = false;
			}
			if (x >= middleNum && noNum % 2 != 0 && flag) {												//Calculate the median by comparing the total number at the moment with middle number
				median = a;																				//since the total number changes along with the class numbers in the table, if the total at that moment is bigger, that mean the median is
				flag = false;																			//the current number in the table
			}																							//The boolean "flag" is to run the code only once after the condition is met
			else if (x > middleNum && noNum % 2 == 0 && flag) {
				median = a;
				flag = false;
			}
			else if (x == middleNum && noNum % 2 == 0 && flag && key1) {
				tuna = a;
				key = true;
				key1 = false;
			}
		}
		cout << "The mode is: " << mode << endl;														//Display the mode and the median
		cout << "The median is: " << median << endl;
}