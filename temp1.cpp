#include <iostream>
#include <string>

using namespace std;

int GetDigit(int);
int SumOfOddPlace(string);
bool StartsWith(string, string);
bool IsValid(string);
int SumOfEvenPlace(string);
bool ValidateInput(string);

int main() {
	bool stop = 0;
	string cardNumber = "";
	char cont;
	while(!stop) {
		cardNumber = "";
		cout << "Please enter a credit card number: " << endl;
		cin >> cardNumber;
		if(!ValidateInput(cardNumber)) {
			cout << "Invalid input." << endl;
		}
		else {
			if(IsValid(cardNumber)) {
				cout << "This card number is valid." << endl;
			}
			else {
				cout << "This card number is invalid." << endl;
			}
		}
		cout << "Do you wish to validate another card? (y/n)" << endl;
		cin >> cont;
		if(cont != 'y') {
			stop = 1;
		}
	}
	cout << "Goodbye." << endl;
	return 0;
}

int GetDigit(int number) {
	int temp = 0;
	if(number > 9) {
		temp = (number % 10) + (number / 10);
	}
	else {
		temp = number;
	}
	return temp;
}

int SumOfOddPlace(string cardNumber) {
	int temp = 0;
	for(int i = cardNumber.length() - 1; i > -1; i -= 2) {
		temp += ((int)cardNumber[i]) - ((int)'0');
	}
	return temp;
}

bool StartsWith(string cardNumber, string substr) {
	if(cardNumber.find(substr) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

bool IsValid(string cardNumber){
	if((((SumOfEvenPlace(cardNumber) + SumOfOddPlace(cardNumber)) % 10) == 0) && ValidateInput(cardNumber)) {
		return 1;
	}
	else {
		return 0;
	}
}

int SumOfEvenPlace(string cardNumber) {
	int temp = 0;
	for(int i = cardNumber.length() - 2; i > -1; i -= 2) {
		temp += GetDigit((((int)cardNumber[i]) - ((int)'0')) * 2);
	}
	return temp;
}

bool ValidateInput(string cardNumber) {
	string startingNumber[] = {"4", "5", "37", "6"};
	bool temp = 0;
	for(int i = 0; i < (*(&startingNumber + 1) - startingNumber); i++) {
		if(StartsWith(cardNumber, startingNumber[i])) {
			temp = 1;
		}
	}
	if((cardNumber.size() > 12) && (cardNumber.size() < 17) && temp) {
		return 1;
	}
	else {
		return 0;
	}
}