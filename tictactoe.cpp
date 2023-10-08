//Tic Tac Toe Game in C++

//Importing the inbuild libraries in CPP
#include <iostream>
#include <stdlib.h>
using namespace std;
#include <string>



int space [3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int row, column;
char token = 'X';
char turn = 'O';
bool draw;


void functionOne(){
string n1;
string n2;
cout << "Player 1, enter your name: \n";
getline(cin, n1);
cout << "Player 2, enter your name: \n";
getline(cin, n2);
cout << n1 << " Is player 1 so he can start first. \n ";
cout << n2 << " Is player 2 so he can start after first one. \n";
cout << "   |    |   \n";
cout << "  "<<space [0][0]<<"|  " <<space [0][1]<<" | " <<space [0][2]<<"\n";
cout << "___|____|____\n";
cout << "   |    |   \n";
cout << " "<<space [1][0]<<" |  " <<space [1][1]<<" | " <<space [1][2]<<"\n";
cout << "   |    |   \n";
cout << "___|____|____\n";
cout << " "<<space [2][0]<<" |  " <<space [2][1]<<"  | " <<space [2][2]<<"\n";
}

void functionTwo(){

int digit;
if (token == 'X') {
    cout << "Player 1, enter a number: \n";
    cin >> digit;
    }
if (token == 'O') {
    cout << "Player 2, enter a number: \n";
    cin >> digit;
    }
  if (digit == 1){
    row = 0;
    column = 0;
  }

  if (digit == 2){
    row = 0;
    column = 1;
    }
  if (digit == 3){
    row = 0;
    column = 2;
}  

if (digit == 4){
    row = 1;
    column = 0;
  }

if (digit == 5){
    row = 1;
    column = 1;
}
if (digit == 6){
    row = 1;
    column = 2;
}

if (digit == 7){
    row = 2;
    column = 0;
  }

if (digit == 8){
    row = 2;
    column = 1;
}
if (digit == 9){
    row = 2;
    column = 2;
}

else {
    cout << "Invalid move \n";
}

if (token == 'X' && space[row][column] != 'X' && space[row][column] != 'O') {
    // Podmínka kontroluje, zda je hráč 'X' na tahu, a zda je vybrané políčko prázdné (není obsazeno 'X' ani 'O').

    space[row][column] = 'X';
    // Pokud je podmínka splněna, na vybrané políčko se umístí symbol 'X' (hráč 'X' provádí tah).

    token = 'O';
    // Hráč 'X' provedl tah, takže nyní je na tahu hráč 'O'. Mění se hodnota proměnné 'token' na 'O'.
} else if (token == 'O' && space[row][column] != 'X' && space[row][column] != 'O') {
    // Pokud hráč 'O' je na tahu a vybrané políčko je prázdné, provede se následující:

    space[row][column] = 'O';
    // Symbol 'O' (hráč 'O') se umístí na vybrané políčko.

    token = 'X';
    // Hráč 'O' provedl tah, takže nyní je na tahu hráč 'X'. Mění se hodnota proměnné 'token' zpět na 'X'.
}
else {
    cout << "There is no empty space \n";
    functionTwo();
}

bool functionThree(char space[3][3]) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] ||
            space[0][i] == space[1][i] && space[0][i] == space[2][i]) {
            return true;
        }
    }

    // Check diagonals for a win
    if (space[0][0] == space[1][1] && space[0][0] == space[2][2] ||
        space[0][2] == space[1][1] && space[0][2] == space[2][0]) {
        return true;
    }

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O') {
                return false;
            }
        }
    }


    draw = true;
    return true;
}


//check jestli to neni remizka.

int main (){
while(functionThree() == false)
{
    functionOne();
    functionTwo();
    functionThree();
}

if (token == 'x' && draw == false)
{
    cout << "Player 2 wins! \n";
}
else if (token == 'O' && draw == false)
{
    cout << "Player 1 wins! \n";
}
else {
    cout << "It's a draw! \n";
}

