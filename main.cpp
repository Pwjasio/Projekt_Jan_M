#include <iostream>
using namespace std;
int susceptible = 80;
int infected = 10;
int recovered = 10;
int day = 0;
double infectionRate = 0.20;
double recoveryRate = 0.10;
void menu();
void rateChange(double& infectionRate, double& recoveryRate);
void simulateDay();
void showPopulation (int day, int susceptible, int infected, int recovered);
bool checkPopulation (int susceptible, int infected, int recovered);

int main(){  // Tutaj wyświetla się wszystko do konsoli 
    menu();
    checkPopulation(susceptible, infected, recovered);
};

void showPopulation (int day, int susceptible, int infected, int recovered){ //tutaj zmienia się populacja
        cout << "Day: "<< day << endl;
    cout << "Susceptible: "<< susceptible <<endl;
    cout << "Infected: "<< infected <<endl;
    cout << "Recovered: "<< recovered <<endl;
    cout << "Total: " << susceptible + infected + recovered << endl;
   
};
void menu(){ // Wyświetla menu wyboru
        int menuW;
        int Wopcja;
        do{
            showPopulation(day, susceptible, infected, recovered);
            cout << endl;
            cout << "=== Epidemic Simulator ==="<< endl;
            cout << "1. Simulate next day" << endl;
            cout << "2. Change model parameters" << endl;
            cout << "3. Exit" << endl;
            cout << "Your choice:" << endl;
            cin >> menuW;
            switch(menuW){
            case 1:
                simulateDay();
                if (!checkPopulation(susceptible, infected, recovered)) {
                    cout << "Invalid population state!" << endl;
                };
                cout << endl;
                break;
            case 2:
                rateChange(infectionRate, recoveryRate);
                break;
            case 3:
                break;
            default:
                cout << endl;
                cout << "!!! Nie podano poprawnej wartosci z przedzialu 1-3 !!!" << endl;
                cout << endl;
                break;
        }
    }while (menuW != 3);
};
void simulateDay(){ //symulacja dnia
    //zapamietanie liczby
    int initialInfected = infected;
    // obliczbanie liczby
    int newInfected = initialInfected * infectionRate;
    int newRecovered = initialInfected * recoveryRate;
    if (newInfected > susceptible) {
        newInfected = susceptible;
    }// to na gorze i dole ogranicza liczbe podatnych
    if (newRecovered > initialInfected) {
        newRecovered = initialInfected;
    }
    //Przypisanie nowych wartości
    susceptible -= newInfected;
    infected = infected + newInfected - newRecovered;
    recovered += newRecovered;
    //dodanie dnia o jeden
    day++;
    cout << endl << "!!! New Day !!!" << endl; 
};
bool checkPopulation(int susceptible, int infected, int recovered){

    if(susceptible < 0 || infected < 0 || recovered < 0){
        return false;
    };
    if (susceptible + infected + recovered != 100){
        return false;
    }
    return true;
};
void rateChange(double& infectionRate, double& recoveryRate){ // zmiany wartości
    double newInf, newRec;
    cout << "Enter infection rate (0-1): ";
    cin >> newInf;
    cout << "Enter recovery rate (0-1): ";
    cin >> newRec;

    if (newInf >= 0.0 && newInf <= 1.0 && newRec >= 0.0 && newRec <= 1.0) {
        infectionRate = newInf;
        recoveryRate = newRec;
        cout << "Parameters updated." << endl;
    } else {
        cout << "Liczby nie są z przedziału 0-1" << endl;
    };
};