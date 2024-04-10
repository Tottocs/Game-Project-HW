//
//  main.c
//  Tic Tac Toe
//
//  Created by Torin Stanton-Andersson on 2024-03-19.
//
#include <stdio.h>

#define FIRMWARE_VERSION "v0.0.1"
#define PLAYER_1 "X"
#define PLAYER_2 "O"

#define SIDE 3 //Number of columns and rows there are
#define MAX_NUM_MOVES SIDE*SIDE //Number of maximum moves which is the cell count
#define ASCII_TABLE_CONVERTER '0' //Converts a number from 0-9 to the charcter version

#define MAX_LENGTH SIDE-1
#define MIN_LENGTH 0
#define LINE_LENGTH_MAX 10

void Board(char BoardValues[SIDE][SIDE])
{
    printf("\n\t\t_____________");
    printf("\n\t\t| %c | %c | %c |",BoardValues[0][0],
           BoardValues[0][1],BoardValues[0][2]);
    printf("\n\t\t-------------");
    printf("\n\t\t| %c | %c | %c |",BoardValues[1][0],
           BoardValues[1][1],BoardValues[1][2]);
    printf("\n\t\t-------------");
    printf("\n\t\t| %c | %c | %c |",BoardValues[2][0],
           BoardValues[2][1],BoardValues[2][2]);
    printf("\n\t\t-------------\n\n");
}

void InitialiseBoard(char BoardValues[][SIDE])
{
    
    for(int Column=MIN_LENGTH;Column<=MAX_LENGTH;Column++){
        for(int Row=MIN_LENGTH;Row<=MAX_LENGTH;Row++){
            BoardValues[Column][Row]=' ';
        }
    }
    
}

void ShowInstructions(void)
{
    int CellNumber=1;
    char BoardValues[SIDE][SIDE];
    printf("\n\t\tTic Tac Toe");
    printf("\n\n Choose a cell from 1 to 9 ");
    
    for(int Column=MIN_LENGTH;Column<=MAX_LENGTH;Column++){
        for(int Row=MIN_LENGTH;Row<=MAX_LENGTH;Row++){
            BoardValues[Column][Row]=(CellNumber)+ASCII_TABLE_CONVERTER;
            CellNumber++;
        }
    }
    Board(BoardValues);
    for (int LineLength=0;LineLength<=LINE_LENGTH_MAX;LineLength++) printf("\t__");
}

int ColumnCheck(char BoardValues[][SIDE]){
    if ()
    {
        
    }
    
    else{
        retrun 0
    }
}

int RowCheck(char BoardValues[][SIDE]){
    if ()
    {
        
    }
    
    else{
        retrun 0
    }
}

int DiagonalCheck(char BoardValues[][SIDE]){
    if ()
    {
        
    }
    
    else{
        retrun 0
    }
}

int GameOverCheck()
{
    if ((DiagonalCheck(char (*BoardValues)[3]) || RowCheck(),)
    {
        return 0;
    }
    
    else{
        return 1;
    }
}

void Tic_Tac_Toe(void){
    char BoardValues[SIDE][SIDE];
    int Move;
    ShowInstructions();
    InitialiseBoard(BoardValues);
    for(int MoveNum=1; MoveNum<=MAX_NUM_MOVES || !(GameOverCheck()); MoveNum++){
        while (1){
            if (scanf("%d", &Move)==1){
                break;
            }
            printf("\n\nInvalid. Specify a number from 1 to 9:");
        }
        
    }
}


int main(void) {
    while (1) {
        Tic_Tac_Toe();
    }
}
