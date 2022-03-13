#include <iostream>
using namespace std;

char board[10] = {'o','1','2','3','4','5','6','7','8','9'}; //array for board

int wcheck();       // function to check victory
void boardsetup();  // function to setup the board

int main()
{
    int player = 1; // variable to store player number
    int result;     // variable to store result from wcheck function
    int input;      // variable to store input of player
    char pSymbol;   // variable to store X or O symbol used by player

    /* used 'do while' function to make changes to the board using player input */
    do
    {
        boardsetup();           					// invoked boardsetup function
        player=(player%2)?1:2; 					        // ternary operator for selecting the player
        pSymbol=(player == 1) ? 'X' : 'O';  				// ternary operator for selecting the symbol used by the player
        
        cout << "Player " << player << "[" << pSymbol << "], turn:  ";  // prompt user for input 
        cin >> input;                               			// receive input         

        if (input == 1 && board[1] == '1')

            board[1] = pSymbol;
        else if (input == 2 && board[2] == '2')

            board[2] = pSymbol;
        else if (input == 3 && board[3] == '3')

            board[3] = pSymbol;
        else if (input == 4 && board[4] == '4')

            board[4] = pSymbol;
        else if (input == 5 && board[5] == '5')

            board[5] = pSymbol;
        else if (input == 6 && board[6] == '6')

            board[6] = pSymbol;
        else if (input == 7 && board[7] == '7')

            board[7] = pSymbol;
        else if (input == 8 && board[8] == '8')

            board[8] = pSymbol;
        else if (input == 9 && board[9] == '9')

            board[9] = pSymbol;
        else
        {
            cout<<"Invalid move ";     // invalid move in case of invalid player input

            player--;
            cin.ignore();              // this function ignores the last input 
            cin.get();                  
        }
        result=wcheck();    // check for victory after every input

        player++;           // player variable changes value (effectively switches player turn)
    }while(result==-1);     // keeps boardsetup running while game in progress
    boardsetup();
    if(result==1)           

        cout << "\aPlayer " <<--player<< " wins ";  // in case of victory by a player (\a escape character used to send alert) 
    else
        cout << "\aGame draw";                      // in case of draw (\a escape character used to send alert) 

    cin.ignore();
    cin.get();
    return 0;
}

/* function that checks whether a player has won the game or not by comparing arrays of the board
returns 1 for victory of either player 
returns 0 for draw 
returns -1 for game in progress
*/

int wcheck()
{
    /* conditions for victory*/	
    if      (board[1] == board[2] && board[2] == board[3])

        return 1;
    else if (board[4] == board[5] && board[5] == board[6])

        return 1;
    else if (board[7] == board[8] && board[8] == board[9])

        return 1;
    else if (board[1] == board[4] && board[4] == board[7])

        return 1;
    else if (board[2] == board[5] && board[5] == board[8])

        return 1;
    else if (board[3] == board[6] && board[6] == board[9])

        return 1;
    else if (board[1] == board[5] && board[5] == board[9])

        return 1;
    else if (board[3] == board[5] && board[5] == board[7])

        return 1;
    /* conditions for draw*/
    else if    (board[1] != '1' && board[2] != '2' && board[3] != '3' 
             && board[4] != '4' && board[5] != '5' && board[6] != '6' 
             && board[7] != '7' && board[8] != '8' && board[9] != '9')

        return 0;     
    else
        return -1;
}

/*function to set up the board with player symbols
values from the array are assigned to form a square grid resembling a tic tac toe board*/

void boardsetup()
{
    system("cls");      // system function used to clear the screen to refresh after every player input
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << endl;

    cout << "     |     |     " << endl << endl;
}
