#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int random_number(int amountD){
    //srand (time(NULL));
    return rand() % amountD;
};

int getting_last_result(int m, int result, int numbers, int amount){
    switch(m){
        case 1: result = result + numbers;break;
        case 2: result-=numbers; break;
        case 3: result = result * numbers;break;
        case 4: while(numbers==0)numbers=random_number(amount);
                result=result/numbers;break;
        default: cout << "error";
    }
    return result;
}

int getting_result(int pos, int m, int result, int numbers, int amount){
    switch(m){
        case 1: cout << " + ";
                result = result + numbers;
                break;
        case 2: cout << " - ";
                if(pos==0) result = numbers - result;
                else result-=numbers;
                break;
        case 3: cout << " * ";
                result = result * numbers;
                break;
        case 4: if(pos==0) result = numbers / result;
                else{
                    while(numbers==0){ numbers = random_number(amount);} //Check 0
                    cout << numbers;
                    cout << " / ";
                    result = result / numbers;
                }
                break;
        default: cout << "error"; //There is nothing if there is an error
    }
    return result;
};

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
        int result;
        if(m!=3 && m!= 4) result = 0; //Add and substract
        else result = 1;
        srand (time(NULL));
		for(int i=0; i < amount_numbers; i++){
			//numbers[i] = rand() % amount_digits;
            numbers[i] = random_number(amount_digits);
            if(i < (amount_numbers-1)){          
                if(m!=4) cout << numbers[i];                
                else{
                    if(i == 0 && m == 4){ 
                        cout << numbers[i];
                        if(amount_numbers > 1) cout << " / ";
                    }
                }
                result = getting_result(i,m,result,numbers[i],amount_digits);
            }
            else{
                cout << numbers[i];
                result = getting_last_result(m,result,numbers[i],amount_digits);
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
        if(answer == 0){
            if(result == 0){
                cout << endl << "Do you want to end the game? (0=No, 1= Yes): ";
                cin >> answer;
                if(answer == 1) exit = 0;
                else cout << "Good answer" << endl;
            }
            else exit = 0;
        }
        else{
            cout << "Good answer" << endl;
        }
	}
};

void print_menu(){
	cout << "Basic Math Operations" << endl;
	cout << "---->Press the option you want" << endl;
	cout << "1. Add" << endl;
    cout << "2. Substract" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
	cout << "0. Exit" << endl;
    cout << "Tap: ";
};

void menu(int op){ //This menu has no sense!!!!
	switch(op){
        //(1)add
		case 1: 
        case 2: 
        case 3: 
        case 4: operation(op); break;
        case 0: cout << "I hope you enjoy it!!!" << endl; break;
		default: cout << "No valid option" << endl;
	}
};


int main(){
	int option_menu;
	do{
		print_menu();
		cin >> option_menu;
        menu(option_menu);
	}
	while(option_menu!=0);
    return 0;
};
