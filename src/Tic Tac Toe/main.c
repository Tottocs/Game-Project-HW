//
//  main.c
//  Tic Tac Toe
//
//  Created by Torin Stanton-Andersson on 2024-03-19.
//
#include <stdio.h>
#include <stdbool.h>

#define FIRMWARE_VERSION "v1.0.0"
#define PLAYER_1 1
#define PLAYER_2 2
#define PLAYER_1_MOVE 'X'   //Player 1 is the Xs
#define PLAYER_2_MOVE 'O'   //Player 2 is the Os

#define SIDE 3                      //Number of columns and rows there are
#define MIN_MOVE_VALUE 1            //Minimum cell value
#define MAX_MOVE_VALUE SIDE*SIDE    //Maximum cell value (9)
#define MAX_NUM_MOVES SIDE*SIDE     //Number of maximum moves which is the cell count (9)

#define ASCII_TABLE_CONVERTER '0' //Converts a number from 0-9 to the charcter version when added to the number

#define MIN_LENGTH 0            //The start of the for loops and the min length of the columns and rows
#define MIDDLE_LENGTH SIDE-2    //Middle length for columns and rows
#define MAX_LENGTH SIDE-1       //Matrix max side length
#define LINE_LENGTH_MAX 10      //Number of short lines under used in the initialisation


//Printing the board
void Board(char BoardValues[][SIDE])
{
    printf("\n\n\t\t_____________");
    printf("\n\t\t| %c | %c | %c |",
           BoardValues[MIN_LENGTH][MIN_LENGTH],
           BoardValues[MIN_LENGTH][MIDDLE_LENGTH],
           BoardValues[MIN_LENGTH][MAX_LENGTH]);
    printf("\n\t\t-------------");
    printf("\n\t\t| %c | %c | %c |",
           BoardValues[MIDDLE_LENGTH][MIN_LENGTH],
           BoardValues[MIDDLE_LENGTH][MIDDLE_LENGTH],
           BoardValues[MIDDLE_LENGTH][MAX_LENGTH]);
    printf("\n\t\t-------------");
    printf("\n\t\t| %c | %c | %c |",
           BoardValues[MAX_LENGTH][MIN_LENGTH],
           BoardValues[MAX_LENGTH][MIDDLE_LENGTH],
           BoardValues[MAX_LENGTH][MAX_LENGTH]);
    printf("\n\t\t-------------\n\n");
}

//Initialise board and set all spaces to blank
void InitialiseBoard(char BoardValues[][SIDE])
{
    for(int Column=MIN_LENGTH;Column<=MAX_LENGTH;Column++){
        for(int Row=MIN_LENGTH;Row<=MAX_LENGTH;Row++){
            BoardValues[Column][Row]=' ';
        }
    }
}

//Showing the instructions for Tic Tac Toe
void ShowInstructions(void)
{
    int CellNumber=MIN_MOVE_VALUE;
    char BoardValues[SIDE][SIDE];
    //Short lines over the board
    for (int LineLength=MIN_LENGTH;
         LineLength<=LINE_LENGTH_MAX;
         LineLength++) printf("\t__");
    
    printf("\n\t\tTic Tac Toe");
    //Adding in number on the board for demonstration
    for(int Row=MIN_LENGTH;Row<=MAX_LENGTH;Row++){
        for(int Column=MIN_LENGTH;
            Column<=MAX_LENGTH;Column++)
        {
            BoardValues[Row][Column]=
            (CellNumber)+ASCII_TABLE_CONVERTER; //Converting the int numbers to char numbers
            CellNumber++;
        }
    }
    Board(BoardValues);
    printf("\n\nThis is a 2 player game. Player 1 starts.");
    printf("\n\n Choose a cell from 1 to 9.\n");
    //Short lines under the board
    for (int LineLength=MIN_LENGTH;
         LineLength<=LINE_LENGTH_MAX;
         LineLength++) printf("\t__");
}

//Checking if a the current player has created a line in a row
bool RowCheck(char BoardValues[][SIDE],int *PlayerTurn)
{
    char PlayerVal=PLAYER_1_MOVE; //Changing what to check for depending which player's turn it is
    if (*PlayerTurn==PLAYER_2) PlayerVal=PLAYER_2_MOVE;


    for (int RowNum=MIN_LENGTH; RowNum<SIDE; RowNum++)
    {
        int Column=MIN_LENGTH;
        if (BoardValues[RowNum][Column++]==PlayerVal &&
            BoardValues[RowNum][Column++]==PlayerVal &&
            BoardValues[RowNum][Column]==PlayerVal )
        {
            return true;
        }
    }
    return false;
}

//Checking if a the current player has created a line in a column

bool ColumnCheck(char BoardValues[][SIDE], int *PlayerTurn)
{
    char PlayerVal=PLAYER_1_MOVE;
    if (*PlayerTurn==PLAYER_2) PlayerVal=PLAYER_2_MOVE;

    for (int ColumnNum=MIN_LENGTH; ColumnNum<SIDE; ColumnNum++)
    {
        int Row=MIN_LENGTH;
        if (BoardValues[Row++][ColumnNum]==PlayerVal &&
            BoardValues[Row++][ColumnNum]==PlayerVal &&
            BoardValues[Row][ColumnNum]==PlayerVal)
        {
            return true;
        }

    }
    return false;

}

//Checking if a the current player has created a line on a diagonal
bool DiagonalCheck(char BoardValues[][SIDE], int *PlayerTurn)
{
    char PlayerVal=PLAYER_1_MOVE;
    if (*PlayerTurn==PLAYER_2) PlayerVal=PLAYER_2_MOVE;
    
    if ((BoardValues[MIN_LENGTH][MIN_LENGTH]==PlayerVal &&
        BoardValues[MIDDLE_LENGTH][MIDDLE_LENGTH]==PlayerVal &&
        BoardValues[MAX_LENGTH][MAX_LENGTH]==PlayerVal) ||
        (BoardValues[MIN_LENGTH][MAX_LENGTH]==PlayerVal &&
        BoardValues[MIDDLE_LENGTH][MIDDLE_LENGTH]==PlayerVal &&
        BoardValues[MAX_LENGTH][MIN_LENGTH]==PlayerVal))
    {
        return true;
    }
    return false;
    
}

//Checking if the current player has won
bool GameOverCheck(char BoardValues[][SIDE], int *PlayerTurn)
{
    if ((DiagonalCheck((BoardValues), PlayerTurn)) ||
        RowCheck((BoardValues), PlayerTurn) ||
        ColumnCheck((BoardValues), PlayerTurn))
    {
        return true; //Returns true if the current player has won
    }
    else
    {
        return false; //Otherwise returns false
    }
}

//Declaring the winner at the end of the game
void DeclareWinner(int *PlayerTurn, 
                   int *MoveNum,
                   char BoardValues[][SIDE])
{   //Checking if the game is drawn
    if (*MoveNum==MAX_NUM_MOVES &&
        !GameOverCheck(BoardValues, PlayerTurn))
    {
        printf("\n\nThe game is drawn.");
    }
    else
    {
        printf("\n\nPlayer %d has won the game!", *PlayerTurn);
    }
}


//Changing Board Values after move is made if the cell does not contain a value
bool ChangeBoard(int *PlayerValue, 
                 int *PlayerMove,
                 char (BoardValues[][SIDE]))
{
    int Column, Row;
    Row=(*PlayerMove-1)/SIDE; //Converting move to board coordinates
    Column=(*PlayerMove-1)%SIDE;
    if (BoardValues[Row][Column]==' ')
    {
        BoardValues[Row][Column]=*PlayerValue;
        return true;
    }
    else
    {   //Returns false if there already is a value at the specified location
        return false;
    }
}
//Playing Tic Tac Toe
void TicTacToe(void)
{
    //Creating board matrix
    char BoardValues[SIDE][SIDE];
    
    int PlayerMove, PlayerTurn=PLAYER_1,
    PlayerValue=PLAYER_1_MOVE,MoveNum;
    
    ShowInstructions();
    InitialiseBoard(BoardValues);
    
    for (MoveNum=MIN_MOVE_VALUE;
         MoveNum<=MAX_NUM_MOVES;
         MoveNum++)
    { //Asks for a value between 0 and 10 until an appropriate value is specified
        printf("\nPlayer %d. Enter an "
               "appropriate value from 1 to 9:", PlayerTurn);
        while (scanf("%d", &PlayerMove) != true)
        {
            printf("\nInvalid.");
            scanf("%*[^\n]");
            printf("\nPlayer %d. Enter an "
                   "appropriate value from 1 to 9:", PlayerTurn);
        }
        //Checking if the value is from 1 to 9 and if the
        if ((PlayerMove>=MIN_MOVE_VALUE) &&
            (PlayerMove<=MAX_MOVE_VALUE) &&
            (ChangeBoard(&PlayerValue, &PlayerMove, BoardValues)))
        {}
        else
        {
            //If not give error message
            printf("\n\nInvalid.");
            MoveNum--;
            continue;
        } //Tell player what has been placed where
        printf("\nPlayer %d has placed %c in cell %d.",
               PlayerTurn, PlayerValue, PlayerMove);
        //Show the board status
        Board(BoardValues);
        //Checking if anyone has won yet
        if (GameOverCheck(BoardValues,&PlayerTurn))
        {
            break;
        }
        //Changing player turn
        if (PlayerTurn==PLAYER_1)
        {
            PlayerTurn=PLAYER_2;
            PlayerValue=PLAYER_2_MOVE;
        }
        else
        {
            PlayerTurn=PLAYER_1;
            PlayerValue=PLAYER_1_MOVE;
        }
    }
    MoveNum--; //MoveNum = number of turns + 1
    DeclareWinner(&PlayerTurn, &MoveNum, BoardValues);
}

//Calling the game
int main(void)
{
    int PlayAgain=1;
    while (true)
    {
        if (PlayAgain==1)
        {
            TicTacToe();
        }
        //Asking if player wants to play again
        printf("\n\nDo you wish to play again. "
               "Enter 1 for YES. 0 for NO:");
        while (scanf("%d", &PlayAgain)!=1)
        {
            printf("\n\nInvalid. Enter either 1 or 0.");
            scanf("%*[^\n]");
            printf("\n\nDo you wish to play again. "
                   "Enter 1 for YES. 0 for NO:");
        }
        if (PlayAgain==1)
        {
            continue;
        }
        else if (PlayAgain==0)
        {
            printf("\n\nBye\n");
            break;
        }
        else
        {
            printf("\n\nInvalid. Enter either 1 or 0.");
        }
    }
}
