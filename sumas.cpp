#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void operation(int m){
	cout << "Introduce the amount of numbers to operate" << endl;
	int amount_numbers;
	cin >> amount_numbers;
	long long numbers[amount_numbers]; //Be careful!!!
	cout << "Introduce the amount of digits" << endl;
	int amount_digits;
	cin >> amount_digits;
	cout << "If you want to stop playing introduce 0" << endl;
    amount_digits = pow(10,amount_digits);
	int exit = 1;
	while(exit == 1){
        int result = 0;
        srand (time(NULL));
		for(int i=0; i < amount_numbers; i++){
			numbers[i] = rand() % amount_digits;
            if(i < (amount_numbers-1)){          
                cout << numbers[i];                
                switch(m){
                    case 1: cout << " + ";
                            result = result + numbers[i];
                            break;
                    default: cout << "error";
                }
            }
            else{
                cout << numbers[i];
                switch(m){
                    case 1: result = result + numbers[i];break;
                    default: cout << "error";              
                }
            }
		}
        
        cout << endl;
        cout << "Introduce your answer = ";
        long long answer;
        cin >> answer;
        while(answer != 0 && answer != result){
            cout << "Try again" << endl;
            cout << "Introduce your answer = ";
            cin >> answer;
        }
        if(answer == 0) exit = 0;
        else{
            cout << "Good answer" << endl;
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
        //(1)add
		case 1: operation(1);break;
        case 0: cout << "I hope you enjoy it stupid Camilo!!!" << endl; break;
		default: cout << "No valid option" << endl;
	}
}


int main(){
	int option_menu;
	do{
		print_menu();
		cin >> option_menu;
        menu(option_menu);
	}
	while(option_menu!=0);
}
