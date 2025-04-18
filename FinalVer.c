#include <stdio.h>
#include <stdlib.h>

void printBoard(int board[][3])		// displays the current condition of the 3x3 Board during the game.
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf(" %d ", board[i][j]);
    }
    printf("\n");
  }
  
}

int sum(int a[])			// Computes the sum of each row and column.
{
    int i, sum = 0;

    for (i = 0; i < 3; i++)
    {
        sum = sum + a[i];
    }
    return sum;
}


int search(int a[], int input)		// Checks if a peg number is already taken.
{
    int i;

    for (i = 0; i < 3; i++)
    {
        if (a[i] == input)
        return 1;
    }
    return 0;
}


int searchRowandCol(int rows[], int rowinput, int cols[], int colinput)		// Checks if the intersection between a row and column is already taken.
{
    int i;
    
    for (i = 0; i < 3; i++)
    {
        if (rows[i] == rowinput && cols[i] == colinput)
        return 1;
    }
    return 0;
}


int main(void)
{
    int peg, over = 0, turn = 0, Occ = 0, ok = 0;

    int row;
    int OccRows[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};		// Variable for checking occupied rows.

    int col;
	int OccCols[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};		// Variable for checking occupied columns.

    int One[3] = {0, 0, 0};			// Variable for the first row.
    int aOne = 0;

	int Two[3] = {0, 0, 0};			// Variable for the second row.
    int aTwo = 0;

	int Three[3] = {0, 0, 0};		// Variable for the third row.
    int aThree = 0;

	int Four[3] = {0, 0, 0};		// Variable for the first column.
    int aFour = 0;

	int Five[3] = {0, 0, 0};		// Variable for the second column.
    int aFive = 0;

	int Six[3] = {0, 0, 0};			// Variable for the third column.
    int aSix = 0;

    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};		// Variable for the 3x3 Board.

    system("cls");
    printf("Welcome to the CCDSTRU 3x3 Numbers Game!\n");
    printf("\nThis Game is made by Carl Justine Alamay, Philipp Matthew Suarez and Ruth Yee\n");		// Start screen that starts the game.
    printf("\nEnter [0] to start!\n");
    scanf("%d", &over);						// User input to start the game.

    while (over != 0)
    {
        system("cls");
        printf("Invalid Input. Enter [0] to start!\n");
        scanf("%d", &over);
    }

    while (over == 0)		// while loop that starts when over variable is 0.
    {
        system("cls");
        printBoard(board);		// 	prints out the 3x3 board into terminal.
        turn = !turn;

        if (turn == 1)						// turn variable value determines whose turn is it to play.
        printf("\nYour turn to play:");

        else if (turn == 0)
        printf("\nYour opponent's turn to play:");

        
        do{
            ok = 0;														// ok variable used for control.
            printf("\nEnter a peg number between 1 to 9: ");
            
            if (scanf("%d", &peg) != 1)			// checks if peg input is valid.
            {
                printf("\nInput a valid peg number: ");
                fflush(stdin);
                ok = 1;
            }

            if (peg < 1 || peg > 9)		// checks if peg input is in between 1 to 9.
            {
                printf("\nEnter a peg number between 1 to 9: ");
            }

            if ((search(One, peg) || search(Two, peg) || search(Three, peg) || search(Four, peg) || search(Five, peg) || search(Six, peg)) && peg != 0)		// checks if the peg input is already in use.
            {
                printf("\nThat peg number is already in use.");
            }
        }while (ok == 1 || peg < 1 || peg > 9 || search(One, peg) || search(Two, peg) || search(Three, peg) || search(Four, peg) || search(Five, peg) || search(Six, peg));

        do{
            do{
                ok = 0;
                printf("Enter row to place peg: ");			// user input for row to place peg number in.

                if (scanf("%d", &row) != 1)			// checks if row input is valid.
                {
                    printf("\nInput valid row placement.");
                    fflush(stdin);
                    ok = 1;
                }

                if (row < 1 || row > 3)			// checks if row input is in between 1 to 3.
                {
                    printf("\nEnter row placement between 1 to 3");
                }
            } while (ok == 1 || row < 1 ||  row > 3);

            do{
                ok = 0;
                printf("\nEnter column to place peg: ");		// user input for column to place peg number in.

                if(scanf("%d", &col) != 1)			// checks if column input is valid.
                {
                    printf("\nInput valid column placement.");
                    fflush(stdin);
                    ok = 1;
                }
                if (col < 1 || col > 3)			// checks if column input is in between 1 to 3.
                {
                    printf("\nEnter column placement between 1 to 3");
                }

            } while (ok == 1 || col < 1 ||  col > 3);

                if(searchRowandCol(OccRows, row, OccCols, col) == 1)		// checks if the intersection between the row and column is already taken.
                {
                    printf("\nPosition is alrady taken.");
                }

        } while (searchRowandCol(OccRows, row, OccCols, col));
        
            OccRows[Occ] = row;		// assigns the row input into OccRows variable.
            OccCols[Occ] = col;		// assigns the column input into OccCols variable.
            Occ++;

        switch (row)		// switch cases for the row input.
        {
          case 1: One[aOne] = peg;
                  aOne++;
                  break;
          case 2: Two[aTwo] = peg;
                  aTwo++;
                  break;
          case 3: Three[aThree] = peg;
                  aThree++;
                  break;
        }

        switch (col)		// switch cases for the column input.
        {
          case 1: Four[aFour] = peg;
                    aFour++;
                    break;
	    	  case 2: Five[aFive] = peg;
                    aFive++;
                    break;
		      case 3: Six[aSix] = peg;
                    aSix++;
                    break;
        }

        board[row-1][col-1] = peg;		// assigns peg into the board variable.

        if (aOne == 3)			// checks if first row is fully occupied and if the sum is less than 15.
        {
            if (sum(One) < 15)
            {
                over = 1;
            }
        }

        if (aTwo == 3)		// checks if second row is fully occupied and if the sum is less than 15.
        {
            if (sum(Two) < 15)
            {
                over = 1;
            }
        }

        if (aThree == 3)	// checks if third row is fully occupied and if the sum is less than 15.
        {
            if (sum(Three) < 15)
            {
                over = 1;
            }
        }

        if (aFour == 3)		// checks if first column is fully occupied and if the sum is less than 15.
        {
            if (sum(One) < 15)
            {
                over = 1;
            }
        }

        if (aFive == 3)		// checks if second column is fully occupied and if the sum is less than 15.
        {
            if (sum(Five) < 15)
            {
                over = 1;
            }
        }

        if (aSix == 3)		// checks if third column is fully occupied and if the sum is less than 15.
        {
            if (sum(Six) < 15)
            {
                over = 1;
            }
            ok = 1;
            turn = !turn;
        }

        // if all rows and columns are complete and have sum 15 each
        if (aOne+aTwo+aThree+aFour+aFive+aSix == 18 && sum(One) ==15 && sum(Two)==15 && sum(Three)==15 && sum(Four)==15 && sum(Five)==15 && sum(Six)==15)
          over = 1;
    }

    system("cls");
    printBoard(board);

    // GameOver(over) : 3rd condition
    if (aOne+aTwo+aThree+aFour+aFive+aSix == 18 && sum(One) ==15 && sum(Two)==15 && sum(Three)==15 && sum(Four)==15 && sum(Five)==15 && sum(Six)==15 && turn)
    printf("\nYour opponent wins!\n");

    // GameOver(over) : 4th condition
    else if (aOne+aTwo+aThree+aFour+aFive+aSix == 18 && sum(One) ==15 && sum(Two)==15 && sum(Three)==15 && sum(Four)==15 && sum(Five)==15 && sum(Six)==15 && !turn)
    printf("\nYou win!\n");
  
    // GameOver(over) : 1st condition
    else if (turn == 1)
    printf("\nYou win!\n");

    // GameOver(over) : 2nd condition 
    else if (turn == 0)
    printf("\nYour opponent wins!\n");

return 0;
}
