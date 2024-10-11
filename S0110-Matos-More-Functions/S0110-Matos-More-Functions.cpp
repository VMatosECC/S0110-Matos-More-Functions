// S0110-Matos-More-Functions.cpp 

//Preprocessor declarations -----------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
using namespace std;


//Prototypes --------------------------------------------
void experiment01();
void experiment02();
void experiment03();
double getPrice();
double getMarkupPct();
int getFileSize(string fileName);
void readAndShow(string fileName, string& bestTeam, int& bestPct);

int main()
{
    //experiment01();
    experiment02();
    //experiment03();

    cout << "\nAll done!\n";
}

//User-Defined Functions ----------------------------------
void experiment01()
{
    //Markup Problem
    double wholeSalePrice = getPrice();
    double markupPct = getMarkupPct() / 100;
    double retailPrice = wholeSalePrice + wholeSalePrice * markupPct;
    cout << "The retail price is " << retailPrice << endl;

}

double getPrice()
{
    double value;
    do {
        cout << "Enter price [positive!]: ";
        cin >> value;
        if (value < 0) {
            cout << "Invalid data - try again \n";
        }
    } while (value < 0);
    return value;
}


double getMarkupPct()
{
    double value;
    do {
        cout << "Enter markup percentage [e.g. 15%]: ";
        cin >> value;
        if (value < 0) {
            cout << "Invalid data - try again \n";
        }
    } while (value < 0);
    return value;
}

//-------------------------------------------------------------
void experiment02()
{
    //Process the disk file baseball2024.txt
    string fileName = "c:/temp/baseball2024.txt";
    int numLines = getFileSize(fileName);
    cout << "The file " << fileName << " contains " << numLines << " lines \n";

    string bestTeam = "**DUMMY**";
    int    bestPct = 0;

    readAndShow(fileName, bestTeam, bestPct);
    cout << "Best Team:           " << bestTeam << endl;
    cout << "Best WPCT:           " << bestPct << endl;
}

int getFileSize(string fileName)
{
    ifstream myfile(fileName);
    if (!myfile) {
        cout << "ERROR - file not found\n";
        exit(1);
    }

    int counter = 0;
    string line;
    while (getline(myfile, line)) {
        counter++;
    }
    myfile.close();
    return counter;
}
//----------------------------------------------------
void readAndShow(string fileName, string& bestTeam, int& bestPct)
{
    ifstream myfile(fileName);
    if (!myfile) {
        cout << "ERROR - File not found\n";
        exit(2);
    }

    string line;
    int countTeam = 0;
    int countPlayers = 0;

    string cTeam;
    while (getline(myfile, line)) {
        cout << "Team name:        " << line << endl;
        countTeam++;
        cTeam = line;

        getline(myfile, line);
        cout << "Division:         " << line << endl;
        getline(myfile, line);
        int wpct = stod(line) * 1000;
        if (wpct > bestPct) {
            bestPct = wpct;
            bestTeam = cTeam;
        }
        cout << "W. Percentage     " << wpct << endl;

        while (getline(myfile, line)) {
            if (line == "#") break;
            cout << "Player:           " << line << endl;
            countPlayers++;
        }
        cout << "\n\n";
    }
    myfile.close();
    cout << "\nTotal teams:      " << countTeam << endl;
    cout << "Total players:       " << countPlayers << endl;

}
