/*******************************************************************************************
 *    Group Project :TIC TAC TOE       DATE PROJECT WAS BY THE GROUP  ENDED: 2018/27/12    *
 *     Group Leader:Qiji                                                                   *
 *     Assistant Group Leader:Alrony                                                       *
 *     Team Members:Osiujjaman                                                             *
 *    Team Members:Himel                                                                   *
 ******************************************************************************************/


//HIMEL => START
#include<iostream>
#include<conio.h>

using namespace std;

char board[3][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};     	// Setting up players movement on the
//board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char turn;                                                         //For SETTING players Turn
int row,colum,i;                                                  //Defining varaibles that will be used for  implementing the arrays
bool draw = false;                                               //For game over cases



// MOVEMENT INITIALIZATION PHASE
/* Character variable K  for telling the array on how to start counting [K++]
in the array setup [i][j]:For how many times the array will move to the next
array starting with X*/

void init()
{

    char k = '1';

    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            board[i][j] = k ++;
        }
    }
    turn ='X';
}


/*Setting Up the Board for Display*/

void display_board()
{
    //For Color design background:3-RED &TEXT COLOR 4-BLUE
    system("color 34");

    /*To Clear the screen after Game Over*/
    system ("cls");



    //Setting up Game Title
    cout<<"\n\t\t             T i c k   C r o s s    G a m e"<<endl;
    cout<<"\n\t\t            Player 1[X] \t  Player 2[0]\n\n";

    /*For Placing the Array[3][3] in their right position in other for the player to move correctly*/
    cout<<"\t\t\t\t|| =====  =====  ===== ||\n";
    cout<<"\t\t\t\t||      ||     ||      ||\n";
    cout<<"\t\t\t\t||   "<<board[0][0]<<"  ||  "<<board[0][1]<<"  ||  "<<board[0][2]<<"   ||  \n";
    cout<<"\t\t\t\t|| _____||_____||_____ ||\n";
    cout<<"\t\t\t\t|| -----  -----  ----- ||\n";
    cout<<"\t\t\t\t||      ||     ||      ||\n";
    cout<<"||==============================||   "<<board[1][0]<<"  ||  "<<board[1][1]<<"  ||  "<<board[1][2]<<"   || =============================|| \n";
    cout<<"\t\t\t\t|| _____||_____||_____ ||\n";
    cout<<"\t\t\t\t|| -----  -----  ----- ||\n";
    cout<<"\t\t\t\t||      ||     ||      ||\n";
    cout<<"\t\t\t\t||   "<<board[2][0]<<"  ||  "<<board[2][1]<<"  ||  "<<board[2][2]<<"   || \n";
    cout<<"\t\t\t\t|| _____||_____||_____ ||\n";
    cout<<"\t\t\t\t|| =====  =====  ===== ||\n";
    cout<<endl;
}


//OSIUJJAMAN => START

/*For players Turn*/

void player_turn()
{
    int choice;        //To make choice of which array position you want play in the game


    if(turn=='X')

        cout<<"\n        \t\t  player1 [X] turn:";


    if(turn=='0')
        cout<<"\n\t\t\t\t  player2 [0] turn:";
    cin>>choice;

    /*The pattern in which the players turn should go without overlapping a played Area*/

    switch(choice)
    {
    case 1:
        row=0;
        colum=0;
        break;
    case 2:
        row=0;
        colum=1;
        break;
    case 3:
        row=0;
        colum=2;
        break;
    case 4:
        row=1;
        colum=0;
        break;
    case 5:
        row=1;
        colum=1;
        break;
    case 6:
        row=1;
        colum=2;
        break;
    case 7:
        row=2;
        colum=0;
        break;
    case 8:
        row=2;
        colum=1;
        break;
    case 9:
        row=2;
        colum=2;
        break;

    default:
        cout<<"\t\t\tInvalid choice\a";
        break;
    }

    /*This if For Specifying which player is next*/

    if (turn =='X'&&board[row][colum]!='X' && board[row][colum]!='0')

        //For if X plays 0 trun to play [turn=o]
    {
        board[row][colum]='X';
        turn='0';
    }

    else if(turn =='0'&&board[row][colum]!='X' && board[row][colum]!='0')

        //For if 0 plays 0 trun to play [turn=X]
    {
        board[row][colum]='0';
        turn='X';
    }


    else
    {
        cout<<"\t\t\tBOX ALREADY FILLED!\n\t\t\t PLEASE TRY AGAIN!!\n\a";   //\a FOR ALERT

        /*To continue Playing after the alert */
        player_turn();
    }

    display_board();

}


//ALRONY=>START
bool gameover()
{
    // check for the  winner: For the Cases which winning should be true

    //WINNING  cases
    for (int i=0; i<3; i++)
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][0] == board[2][0])
        return false;

    //DRAW cases
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if(board[i][j]!='X'&& board[i][j]!='0')
                return true;

    draw =true;
    return false;
}
//QIJI => START
//Main Function: this holds every procedure or function together  &  for playing again

main()
{

    //Nested while flag represents the PLAYERS CHOICE ON WHETHTER TO RESTART OR STOP THE GAME :
    //	Flag has the option of initializing the game and ignoring the while(gameover()) due to its bool definition

    int i= 1;
    bool flag = true;   //For playing again

    while(flag)
    {
        init();      //MOVEMENT INITIALIZATION

        while(gameover())    //After game is over
        {

            display_board();
            player_turn();
            gameover();
            i++;        //For restarting movement
        }



        //For announcing the player that won the game

        if(turn == '0'&& draw == false)
        {

            cout<<"\t\t\tplayer1 [X] wins!! congratulations\a\n";

        }
        else if(turn == 'X' && draw == false)
        {

            cout<<"\t\t\tplayer2 [0] wins!! congratulations\a\n";

        }

        getch();

//For Restarting or ending game if players doesn't want to play the game  again or wants to play again

        cout <<"\n\n\t\t if you want to play again? Yes (Y) or No(N)" <<endl;


//The Flag initialization
        char c;
        cin >> c;
        if(c=='Y'&&c=='N')
        {

            if(c == 'Y')
            {
                flag =true;
            }
            else if (c=='N')
            {
                flag=false;
            }
        }
        else
        {
            cout<<"Invalid Choice\a";   //If PlAYER PICKS WRONG CHARACTER
        }
        system("cls");     //To clear the screen for the START AGAIN

    }

}
