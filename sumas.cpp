#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

void operation(int m){
	cout << "Introduce the amont of numbers to operate" << endl;
	int amount_numbers;
	cin >> amount_numbers;
	int numbers[amount_numbers];
	cout << "Introduce the amount of digits" << endl;
	int amount_digits;
	cin >> amount_digits;
	cout << "If you want to stop playing introduce 0" << endl;
	int exit = 1;
	while(exit == 1){
		srand (time(NULL));
		for(int i=0; i<amount_numbers; i++){
			numbers[i] = rand() % amount + 
		}
	}
};

void print_menu(){
	cout << "Basic Math Operations" << endl;
	cout << "---->Press the option you want" << endl;
	cout << "1. Add" << endl;
	cout << "0. Exit" << endl;
};

void menu(int op){
	switch(op){
		case 1: operation(1);break;
		default: cout << "No valid option" << endl;
	}
}


int main(){
	int option_menu;
	do{
		print_menu();
		cin >> option_menu;
	}
	while(option_menu!=0);
}
