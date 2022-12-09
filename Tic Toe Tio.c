
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<time.h>

char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int level[10]= {0,5,3,7,9,1,2,4,6,8};
int index=1;

int choiceForGameType;

int scoreBoard[2]= {0,0};
char firstPlayerName[100];
char secondPlayerName[100];


void delay(int seconds)
{
    unsigned long int count=333333333,i,j;
    for(i=0; i<seconds; i++)
        for(j=0; j<count; j++);
}



void showDrawMessage()
{
    printf("\n\n\t\t ( # Final Result #)\n");
    printf("\t\t MATCH DRAW\n\n");
}


void showScoreBoard()
{
    system("cls");
    printf("\n\n");
    printf("\t\t --------------------------------------------\n");
    printf("\t\t| Round Score Board |\n");
    printf("\t\t --------------------------------------------\n");
    printf("\t\t| Player 1: %s | Player 2: %s |\n",firstPlayerName,secondPlayerName);
    printf("\t\t --------------------------------------------\n");
    printf("\t\t| | |\n");
    printf("\t\t| %d | %d |\n",scoreBoard[0],scoreBoard[1]);
    printf("\t\t| | |\n");
    printf("\t\t --------------------------------------------\n");
}

void showFinalScoreBoard()
{
    system("cls");
    printf("\n\n");
    printf("\t\t----------------------------------------------\n");
    printf("\t\t| Final Score Board |\n");
    printf("\t\t---------------------------------------------\n");
    printf("\t\t| Player 1: %s | Player 2: %s |\n",firstPlayerName,secondPlayerName);
    printf(" \t\t---------------------------------------------\n");
    printf("\t\t| | |\n");
    printf("\t\t| %d | %d |\n",scoreBoard[0],scoreBoard[1]);
    printf("\t\t| | |\n");
    printf("\t\t----------------------------------------------\n");
    printf("\n\n\n");
    printf("\n\n\t\t\t GAME ENDED\n\n");
}


void clearBoard()
{
    square[0]='0';
    square[1]='1';
    square[2]='2';
    square[3]='3';
    square[4]='4';
    square[5]='5';
    square[6]='6';
    square[7]='7';
    square[8]='8';
    square[9]='9';
}


int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]!= '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return - 1;
}


void board()
{
    system("cls");
    system("color 3");
    printf("\n\n\t\t\t Tic---Tac---Toe \n");
    printf("\t\t\t ----------------------\n\n");
    printf("Player 1 (X) - Player 2 (O)\n\n\n");
    printf("\t\t\t | | \n");
    printf("\t\t\t %c | %c | %c \n", square[1], square[2], square[3]);
    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t | | \n");
    printf("\t\t\t %c | %c | %c \n", square[4], square[5], square[6]);
    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t | | \n");
    printf("\t\t\t %c | %c | %c \n", square[7], square[8], square[9]);
    printf("\t\t\t | | \n\n");
}


int gameModule()
{
    printf(" \n\n\t1. Human vs Human\n");
    printf(" \t2. Human vs Computer(Medium level)\n");
    printf("\t3. Human vs Computer(Hard level)\n");
    delay(1);
    printf(" Press enter to begin( 1 or 2 or 3 ) : ");
    scanf("%d", &choiceForGameType);
    if(choiceForGameType==1)
    {
        printf("\nEnter first player name: ");
        scanf("%s", firstPlayerName);
        printf("First player symbol is 'x'\n");
        printf("\nEnter second player name: ");
        scanf("%s", secondPlayerName);
        printf("Second player symbol is 'o'\n");
    }

    if(choiceForGameType==2)
    {
        printf("\nEnter first player name: ");
        scanf("%s", firstPlayerName);
        printf("First player symbol is 'x'\n");
        strcpy(secondPlayerName,"Computer");
        printf("Computer symbol is 'o'\n");
    }

    if(choiceForGameType == 3)
    {
        printf("\nEnter first player name: ");
        scanf("%s", firstPlayerName);
        printf("First player symbol is 'x'\n");
        strcpy(secondPlayerName,"Computer");
        printf("Computer symbol is 'o'\n");
    }
    loading();
    return choiceForGameType;
}


int humanVsHuman()
{
    int player = 1, i, choice;
    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;
        printf("Player %d\n Select a shell: ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            printf("Invalid move ");
            player--;
            getch();
        }
        i = checkwin();
        player++;
    }
    while (i == - 1);
    board();
    if (i == 1)
    {
        printf("\t\t\t==>\aPlayer %d win ", --player);
        return player;
    }
    else
        printf("\t\t\t==>\aGame draw");
    return 0;
    getch();
}


int validIndex()
{
    int val;
    while(1)
    {
        val = rand()%9 + 1;
        if(square[val]==(val+'0')) break;
    }
    return val;
}


int humanVsComputer()
{
    int player = 1, i, choice;
    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;
        printf("Player %d\n Select a sell: ", player);
        if(player == 1)scanf("%d", &choice);
        else
        {
            printf("COMPUTER INPUT\n");
            choice=validIndex();
            printf("CHOICE: %d\n",choice);
        }
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            printf("Invalid move ");
            player--;
            getch();
        }
        i = checkwin();
        player++;
    }
    while (i == - 1);
    board();
    if (i == 1)
    {
        printf("\t\t\t==>\aPlayer %d win ", --player);
        return player;
    }
    else
        printf("\t\t\t==>\aGame draw");
    return 0;
    getch();
}
int validMove()
{
    int val;
    for(int i=1; i<10; i++)
    {
        val = level[i];
        if(square[val]!=(val+'0'))continue;
        else break;
    }
    return val;
}
int levelUpHumanVsComputer()
{
    int player = 1, i, choice;
    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;
        printf("Player %d\n Select a sell: ", player);
        if(player == 1)scanf("%d", &choice);
        else
        {
            printf("COMPUTER INPUT\n");
            choice = validMove();
            printf("CHOICE: %d\n",choice);
        }
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            printf("Invalid move ");
            player--;
            getch();
        }
        i = checkwin();
        player++;
    }
    while (i == - 1);
    board();
    if (i == 1)
    {
        printf("\t\t\t==>\aPlayer %d win ", --player);
        return player;
    }
    else
        printf("\t\t\t==>\aGame draw");
    return 0;
    getch();
}
void introduction()
{
    printf("\n\n\n\n\n");
    printf("\t\t\t\t # TIC---TAC----TOE #");
    printf("\n\t\t\t\t----------------------");
    delay(2);
    printf("\n\n Developer: 1)Joy Biswas\n\t 2)Israt Jahan\n\t 3)Mohammad Al-amin");
    delay(1);
    printf("\n\n\n\n\n\n\n");
    system("cls");
}
void loading()
{
    int i,j, a;
    printf("\n\n\n\n\n\n\t\t\t\t\t LOADING");
    for(i=0; i<=13; i++)
    {
        for(j=0 ; j<100000000 ; j++);
        a=j;
        printf(".");
    }
}
int main()
{
    system("color 90");
    introduction();
    printf("\n\n\t\t\t------->> *** Welcome in tic tac toe GAME ***") ;
    int gameTypeChoice=gameModule();
    if(gameTypeChoice==1)
    {
        int confirmation;
        for(int i=1; i<=3; i++)
        {
            int player = humanVsHuman();
            if(player==1)scoreBoard[0]++;
            else if(player==2)scoreBoard[1]++;
            else if(player==0)
            {
                scoreBoard[0]++;
                scoreBoard[1]++;
            }
            clearBoard();
            showScoreBoard();
            if(i<3)
            {
                printf(" Next Round game will be started after pressing enter (0): ");
                scanf(" %d", &confirmation);
            }
        }
        if(scoreBoard[0]==scoreBoard[1])
        {
            showDrawMessage();
            printf("/n/n/n/n/");
            printf("Want to play another round enter (0): ");
            scanf("%d", &confirmation);
            if(confirmation==0)
            {
                int player = humanVsHuman();
                if(player==1)scoreBoard[0]++;
                else if(player==2)scoreBoard[1]++;
                else if(player==0)
                {
                    scoreBoard[0]++;
                    scoreBoard[1]++;
                }
                clearBoard();
                showScoreBoard();
            }
        }
        showFinalScoreBoard();
    }
    if(gameTypeChoice==2)
    {
        int confirmation;
        for(int i=1; i<=3; i++)
        {
            int player = humanVsComputer();
            if(player==1)scoreBoard[0]++;
            else if(player==2)scoreBoard[1]++;
            else if(player==0)
            {
                scoreBoard[0]++;
                scoreBoard[1]++;
            }
            clearBoard();
            showScoreBoard();
            if(i<3)
            {
                printf(" Next Round game will be started after pressing enter (0): ");
                scanf(" %d", &confirmation);
            }
        }
        if(scoreBoard[0]==scoreBoard[1])
        {
            showDrawMessage();
            printf("Want to play another round enter (0): ");
            scanf("%d", &confirmation);
            if(confirmation==0)
            {
                int player = humanVsComputer();
                if(player==1)scoreBoard[0]++;
                else if(player==2)scoreBoard[1]++;
                else if(player==0)
                {
                    scoreBoard[0]++;
                    scoreBoard[1]++;
                }
                clearBoard();
                showScoreBoard();
            }
        }
        showFinalScoreBoard();
    }
    if(gameTypeChoice==3)
    {
        int confirmation;
        for(int i=1; i<=3; i++)
        {
            int player = levelUpHumanVsComputer();
            if(player==1)scoreBoard[0]++;
            else if(player==2)scoreBoard[1]++;
            else if(player==0)
            {
                scoreBoard[0]++;
                scoreBoard[1]++;
            }
            clearBoard();
            showScoreBoard();
            if(i<3)
            {
                printf(" Next Round game will be started after pressing enter (0): ");
                scanf(" %d", &confirmation);
            }
        }
        if(scoreBoard[0]==scoreBoard[1])
        {
            showDrawMessage();
            printf("Want to play another round enter (0): ");
            scanf("%d", &confirmation);
            if(confirmation==0)
            {
                int player = levelUpHumanVsComputer();
                if(player==1)scoreBoard[0]++;
                else if(player==2)scoreBoard[1]++;
                else if(player==0)
                {
                    scoreBoard[0]++;
                    scoreBoard[1]++;
                }
                clearBoard();
                showScoreBoard();
            }
        }
        showFinalScoreBoard();
    }
    return 0;
}
