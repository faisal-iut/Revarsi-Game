#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include <time.h>
#define SIZE 6
#define SIZE1 4

const char compc=1;
const char playerc=2;

void SetColor(int ForgC);
void display2();
void write(int users,int coms);
void read();
void display(char board[][SIZE]);
void menu(void);
void savegame(int compscores,int userscores);
void playgame(void);
void clearhistory();
void again_play_menu(int compscore,int userscore);
void gamerule(void);
int validmoves(char board[][SIZE],bool moves[][SIZE],char player);
void makemove(char board[][SIZE],int row,int col,char player);
void compmove(char board[][SIZE],bool moves[][SIZE],char player);
int bestmove(char board[][SIZE],bool moves[][SIZE],char player);
int getscore(char board[][SIZE],char player);

struct record
{
    char name[30];
    int userscore;
    int comscore;
    int hour;
    int mint;
    int sec;
    int day;
    int month;
    int year;
};


int main()
{
    display2();
     //system("cls");
    menu();
}

void playgame(void)
{
    char board[SIZE][SIZE]= {0};
    int row=0,col=0;
    int noofmoves=0;
    int invalidmoves=0;
    int noofgames=0;
    int compscore=0;
    int userscore=0;
    int x=0;
    char y=0;
    char again=0;
    bool nextplayer=true;
    //int mid=6/2;
    bool moves[SIZE][SIZE]= {false};


    system("cls");
    // display(board);

    int i=0,j,k;
    char ch,bh,ah;
    int a,b,c,d;
    a=1;
    b=0;
    c=0;
    bh=' ';
    //gotoxy(b,c);


    //board();
    b=14;
    c=2+2;
    // do
    //{/*
    nextplayer=!nextplayer;
    noofmoves=4;

    for(row=0; row<SIZE; row++)
        for(col=0; col<SIZE; col++)board[row][col]=' ';
    int iSecret,igause;
    igause=1;
    srand ( time(NULL) );
    iSecret = rand() % 10 + 1;
    if(iSecret>5)
    {
        igause=2;
        iSecret=10-iSecret;
    }

    if(iSecret<1)iSecret=3;

    int mid=iSecret;
    if(SIZE<6)
    {
        igause=1;
        mid=SIZE/2;
    }
    if(igause==1)
    {
        board[mid-1][mid-1]=board[mid][mid]=1;
        board[mid-1][mid]=board[mid][mid-1]=2;
    }
    else
    {

        board[mid][mid]=board[mid-1][mid+1]=1;
        board[mid-1][mid]=board[mid][mid+1]=2;
    }


    do
    {
        display(board);
        // if(i%2!=0)Sleep(2000);
        //Sleep(1000);
        if(i%2!=0)
        {
            //system("cls");

            gotoxy(51,10);
            printf("COMPUTER'S TURN ");
            for(j=0; j<8; j++)
            {
                printf(".");
                Sleep(300);
            }

        }
        i++;
        if(nextplayer=!nextplayer)
        {
            //player turn;
            if(validmoves(board,moves,playerc))
            {
                for(;;)
                {
                    //printf("\n\tPLEASE ENTER YOUR MOVE [ROW COLAMN] : ");


                    gotoxy(b,c);

                    do
                    {

                        ch=getch();
                        if(ch==27)menu();
                        if(ch==72)
                        {
                            c=c-3;
                            if(c<=2+2)c=2+2;
                            gotoxy(b,c);
                            //printf("%d",ch);

                        }
                        else if(ch==80)
                        {
                            c=c+3;
                            if(c>=17+2)c=17+2;
                            gotoxy(b,c);
                            //printf("%d",ch);


                        }
                        if(ch==75)
                        {
                            b=b-5;
                            if(b<=14)b=14;
                            gotoxy(b,c);
                            //printf("%d",ch);

                        }
                        if(ch==77)
                        {
                            b=b+5;
                            if(b>=39)b=39;

                            gotoxy(b,c);
                            // printf("%d",ch);

                        }


                        // board();




                    }
                    while(ch!=13);



                    x=(c-2)/3;
                    y=(b-14)/5;


                    //scanf("%d%c",&x,&y);
                    //y=tolower(y)-'a';
                    //x--;

                    if(x>=0&&y>=0&&x<SIZE&&y<SIZE&&moves[x][y])
                    {
                        makemove(board,x,y,playerc);
                        noofmoves++;
                        break;
                    }
                    else
                    {
                        gotoxy(51,10);
                        printf("NOT A VALID MOVE");
                        gotoxy(54,12);
                        printf("TRY AGAIN");
                        gotoxy(b,c);

                    }

                }
            }
            else

                if(++invalidmoves<2)
                {
                    gotoxy(51,10);
                    printf("YOU HAVE TO PASS");
                    gotoxy(54,12);
                    printf("PRESS ENTER");
                    Sleep(1000);
                    do
                    {
                        again=getch();
                    }
                    while(again!=13);
                    //continue;
                    // break;
                }
                else printf("\nNEITHER OF US CAN GO .. SO THE GAME IS OVER\n");

        }

        else
        {
            //computer turn;
            if(validmoves(board,moves,1))
            {
                invalidmoves=0;
                compmove(board,moves,1);
                noofmoves++;
            }
            else
            {
                if(++invalidmoves<2)
                {
                    gotoxy(51,10);
                    printf("I HAVE TO PASS");
                    gotoxy(54,12);
                    printf("YOUR GO");
                    Sleep(1000);

                }
                else
                {
                    gotoxy(51,10);
                    printf("NEITHER OF US CAN GO..");
                    gotoxy(54,12);
                    printf("SO THE GAME IS OVER");
                    Sleep(1000);
                }


            }
        }

        system("cls");

    }
    while(noofmoves<SIZE*SIZE&&invalidmoves<2);

    /*game is over*/

    //show final board;

    display(board);

    compscore=userscore=0;

    for(row=0; row<SIZE; row++)
        for(col=0; col<SIZE; col++)
        {
            compscore+=board[row][col]==compc;
            userscore+=board[row][col]==playerc;

        }



    gotoxy(50,9);
    printf("    FINAL SCORE");
    gotoxy(47,10);
    printf("______________________________");
    gotoxy(49,12);
    printf(" COMPUTER-%d       USER-%d",compscore,userscore);
    gotoxy(47,13);
    printf("______________________________");
    gotoxy(54,15);
    //printf("    %d         %d",compscore,userscore);
    if(compscore>userscore)printf(" WINNER : COMPUTER");
    else if(compscore<userscore)printf("  WINNER : USER");
    else printf("    D R A W");
    int cnt;
    gotoxy(47,16);
    printf("______________________________");
    for(cnt=1; cnt<=6; cnt++)
    {
        gotoxy(47,10+cnt);
        printf("|");

    }
    for(cnt=1; cnt<=3; cnt++)
    {
        gotoxy(64,10+cnt);
        printf("|");

    }
    for(cnt=1; cnt<=6; cnt++)
    {
        gotoxy(76,10+cnt);
        printf("|");

    }

    do
    {
        again=getch();
        if(again==27)menu();
    }
    while(again!=13);
    system("cls");

    //compscore=20;
    //userscore=21;
    again_play_menu(compscore,userscore);
    //printf("DO YOU WANT TO PLAY AGAIN(Y/N): ");
    //scanf("%c",&again);

    //}
    //while(tolower(again)=='y');


    // printf("\n\nGOOD BYE\n\n");
    //return 0;


}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),coord );
}

void again_play_menu(int compscore,int userscore)
{
    int choice;
    char turn;

UPDATE:

    choice=1;
    int i;

    do
    {
        system("cls");
        gotoxy(10,2);
        printf("______________________________________________________________");

        gotoxy(10,21);
        printf("______________________________________________________________");
        for(i=0; i<=20; i++)
        {
            gotoxy(70,2+i);
            printf("|");
        }
        for(i=0; i<=20; i++)
        {
            gotoxy(11,2+i);
            printf("|");
        }
        gotoxy(18,5);
        printf("%c%c%c%c%c USE UP-DOWN ARROW TO CHOICE OPTION %c%c%c%c%c\n\n\n",215,219,178,177,176,176,177,178,219,215);

        gotoxy(28,10);
        //printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        if(choice==1)printf("%c%c%c%c SAVE GAME DATA %c%c%c%c\n",219,178,177,176,176,177,178,219);
        else printf("     SAVE GAME DATA\n");

        gotoxy(28,12);
        if(choice==2)printf("%c%c%c%c PLAY GAME AGAIN %c%c%c%c\n",219,178,177,176,176,177,178,219);
        else printf("     PLAY GAME AGAIN\n");

        gotoxy(28,14);
        if(choice==3)printf("%c%c%c%c QUIT TO MAIN MENU %c%c%c%c\n",219,178,177,176,176,177,178,219);
        else printf("     QUIT TO MAIN MENU\n");



        turn=getch();
        if(turn==72)choice--;
        else if(turn==80)choice++;

        if(choice==4)choice=3;
        else if(choice==0)choice=1;


    }
    while(turn!=13);

    switch(choice)
    {
    case 1:
        system("cls");
        savegame(compscore,userscore);
        goto UPDATE;
        break;

    case 2:
        system("cls");
        playgame();
        break;

    case 3:
        system("cls");
        menu();
        break;



    }





}

void savegame(int compscores,int userscores)
{
    FILE *fp;
    char *filename,ch,temp;
    int user,com,i;
    user=userscores;
    com=compscores;
    filename="C:\\5.txt";
    write(user,com);
    // scanf("%c",&temp);
    //getchar();
    system("cls");
    printf("\n\n\t\t\tG A M E   D A T A   S A V E D\n\n\t\t");
    for(i=0; i<4; i++)
    {
        printf("...........");
        Sleep(500);
    }

    //getchar();


    //read();

}

void clearhistory()
{
    int userscore,compscore;
    userscore=0;
    compscore=0;
    write(userscore,compscore);

}


void write(int users,int coms)
{
    FILE *fp;
    char *filename,ch,temp[10];
    int i;
    filename="C:\\5.txt";
    if(users==0&&coms==0)
    {
        fp=fopen(filename,"w+");
        printf("\n\n\n\n\t\t\tG A M E   D A T A   C L E A R E D\n\t\t  ");
        //Sleep(2000);
        for(i=0; i<4; i++)
        {
            printf("...........");
            Sleep(500);
        }

        fclose(fp);
        menu();
    }



    struct record data;

    fp=fopen(filename,"ab+");



    printf("\n\n\n\n\t\t\tYOUR NAME : ");
    fflush(stdout);
    if(fgets(data.name,sizeof data.name,stdin)!=NULL)
    {
        char *newline = strchr(data.name, '\n');
        if ( newline != NULL )
        {
            *newline = '\0';
        }
        //getchar()
    }
    //scanf("%s",temp);

    time_t rawtime;
    struct tm*  time_;
    time(&rawtime);
    time_ = localtime(&rawtime);

    data.userscore=users;
    data.comscore=coms;
    data.hour=time_->tm_hour;
    data.mint=time_->tm_min;
    data.sec=time_->tm_sec;
    data.day=time_->tm_mday;
    data.month=time_->tm_mon+1;
    data.year=time_->tm_year+1900;

    fwrite(&data,sizeof data,1,fp);

    fclose(fp);


}

void read()
{
    FILE *fp;
    char *filename,ch,temp[10];
    filename="C:\\5.txt";




    FILE *file = fopen(filename, "rb+");
    if ( fp != NULL )
    {
        struct record data;
        while ( fread(&data, sizeof data, 1, file) == 1 )
        {
            printf("%-10s : %-2d COMPUTER : %-2d\t\t", data.name, data.userscore,data.comscore);
            printf("TIME=%-2d:%-2d:%-2d    %d\/%d\/%d \n",data.hour,data.mint,data.sec,data.day,data.month,data.year);

        }

    }

    // fclose(fp);

}

void gamerule(void)
{
    int row,col,i,j;
    //int SIZE1=4;
    char kk;
    char board[SIZE1][SIZE1]= {0};

    // Sleep(1000);
    // system("cls");

    // scanf("%c",&kk);
    //system("cls");
RULES:

    for(i=0; i<4; i++)
    {
        if(i==0)
        {
            printf("\n ||\tINITIALLY THERE ARE FOUR COUNTERS\n ||\tTWO FOR YOURS\n ||\tTWO FOR OPOSITE TEAM\n\n\n");


        }
        else if(i==1)
        {
            printf("\n\n ||\tYOU CAN PLACE YOUR COUNTER-----------\n\n \t============================\n\n \t||\tLEFT       <-\n \t____________________________\n\n \t||\tRIGHT      ->");
            printf("\n \t____________________________");
            printf("\n\n \t||\tDIAGONALLY  /  ");
            printf("\n \t____________________________");
            printf("\n   \t\t            ^  ");
            printf("\n \t||\tUP          |  ");
            printf("\n \t____________________________");
            printf("\n\n \t||\tDOWN        |  ");
            printf("\n   \t\t            -  ");
            printf("\n \t============================     PRESS ENTER TO MOVE.....\n\n\t\t\t\t\t PRESS ESC TO GO MENU....\n\n");
            //scanf("%c",&kk);
            do
            {
                kk=getch();
                if(kk==27)menu();
            }
            while(kk!=13);
            system("cls");
            printf("\n\n\n");

        }

        else if((i==2)||(i==3))printf("\n\n\n");

        for(row=0; row<SIZE1; row++)
            for(col=0; col<SIZE1; col++)
            {
                board[row][col]=' ';
                board[1][1]=board[2][2]=1;
                board[1][2]=board[2][1]=2;
            }
        printf("\t\t");
        for(row=0; row<SIZE1; row++)printf("  %2c ",'a'+row);
        if(i==1)
        {
            printf("\nLIKE THIS -->");
            board[0][1]=2;

        }
        else if(i==2)
        {
            printf("\n[2b]becomes->%c",2);
            board[0][1]=2;
            board[1][1]=2;
        }
        else if(i==3)
        {
            printf("\n\t");
            board[0][1]=2;
            board[1][1]=2;
            board[0][2]=1;
            board[1][2]=1;
        }

        else printf("\n\t");

        for(row=0; row<SIZE1; row++)
        {
            //if(row==0&&i==1)printf("LIKE THIS+");
            printf(" \t +");

            for(col=0; col<SIZE1; col++)printf("====+");
            if((row==2&&i==1)||(row==2&&i==2))printf("\tHERE I PLACED COUNTER %c at     [1b]",2);
            if(row==3&&i==2)printf(" AND AS A RESULLT OPPONENT [2b] BECOMES %c",2);
            if(row==2&&i==3)printf("   LIKE THIS I CAN PLACE UP RIGHT LEFT");
            if(row==3&&i==3)printf("  DIAGONALLY AND OPOSITE %c WILL CHANGE",1);
            //SetColor(74);
            printf("\n\t\t%d|",row+1);


            for(col=0; col<SIZE1; col++)printf(" %2c |",board[row][col]);
            printf("\n\t\t |");

            for(col=0; col<SIZE1; col++)printf("    |");

            printf("\n\t");
            //SetColor(34);


        }
        printf("\t +");
        for(col=0; col<SIZE1; col++)printf("====+");
        printf("\n\n\t\t\t\tPRESS ENTER TO MOVE.....\n\n\t\t\t\tPRESS ESC TO GO MENU......");


        do
        {
            kk=getch();
            if(kk==27)menu();

        }
        while(kk!=13);
        system("cls");


    }

    int choice;
    char turn;
    choice=1;
    do
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if(choice==1)printf("\n\t\t\t\t%c%c%c%c QUIT TO MAIN MENU %c%c%c%c\n",219,178,177,176,176,177,178,219);
        else printf("\n\t\t\t\t     QUIT TO MAIN MENU\n");

        if(choice==2)printf("\n\t\t\t\t%c%c%c%c SEE GAME RULES AGAIN %c%c%c%c\n",219,178,177,176,176,177,178,219);
        else printf("\n\t\t\t\t     SEE GAME RULES AGAIN\n");
        turn=getch();
        if(turn==72)choice--;
        else if(turn==80)choice++;

        if(choice==3)choice=2;
        else if(choice==0)choice=1;


    }
    while(turn!=13);

    switch(choice)
    {
    case 1:
        system("cls");
        menu();
        break;

    case 2:
        system("cls");
        goto RULES;




    }



}

void menu(void)
{

    int option,a,b,c,d,i;
    char temp;
    char turner;
    option=1;
    int optionl;
    char turnerl;
    optionl=1;


UPDATE:
    do
    {
        system("cls");
        gotoxy(10,2);
        printf("______________________________________________________________");

        gotoxy(10,21);
        printf("______________________________________________________________");
        for(i=0; i<=20; i++)
        {
            gotoxy(70,2+i);
            printf("|");
        }
        for(i=0; i<=20; i++)
        {
            gotoxy(11,2+i);
            printf("|");
        }
        gotoxy(18,5);
        printf("%c%c%c%c%c USE UP-DOWN ARROW TO CHOICE OPTION %c%c%c%c%c\n\n\n",215,219,178,177,176,176,177,178,219,215);

        gotoxy(28,10);
        if(option==1)
        {
            printf("%c%c%c%c P L A Y   G A M E %c%c%c%c\n",219,178,177,176,176,177,178,219);
        }
        else printf("      PLAY GAME\n");

        gotoxy(28,12);
        if(option==2)printf("%c%c%c%c G A M E   R U L E S %c%c%c%c\n",219,178,177,176,176,177,178,219);
        else printf("      GAME RULES\n");

        gotoxy(28,14);
        if(option==3)printf("%c%c%c%c H I S T O R Y %c%c%c%c\n",219,178,177,176,176,177,178,219);
        else printf("      HISTORY\n");

        gotoxy(28,16);
        if(option==4)printf("%c%c%c%c C L E A R   H I S T O R Y %c%c%c%c\n",219,178,177,176,176,177,178,219);
        else printf("      CLEAR HISTORY\n");

        gotoxy(28,18);
        if(option==5)printf("%c%c%c%c Q U I T   G A M E %c%c%c%c\n",219,178,177,176,176,177,178,219);
        else printf("      QUIT GAME\n");



        turner=getch();
        if(turner==72)option--;
        else if(turner==80)option++;

        if(option==6)option=5;
        else if(option==0)option=1;


    }
    while(turner!=13);

    switch(option)

    {
    case 1:
        system("cls");
        playgame();
        break;

    case 2:
        system("cls");
        gamerule();
        break;

    case 3:

        system("cls");
        read();
        do
        {
            temp=getch();
        }
        while(temp!=13);
        goto UPDATE;
        break;

    case 4:
    {
        system("cls");
        /*printf("\n\tShutting down");
        for(i=0; i<5; i++)
        {
            Sleep(1000);
            printf(".");
        }
        exit(0);*/
        clearhistory();
        break;
    }

    case 5:

    {



        do
        {
            system("cls");
            gotoxy(10,2);
            printf("______________________________________________________________");

            gotoxy(10,21);
            printf("______________________________________________________________");
            for(i=0; i<=20; i++)
            {
                gotoxy(70,2+i);
                printf("|");
            }
            for(i=0; i<=20; i++)
            {
                gotoxy(11,2+i);
                printf("|");
            }
            gotoxy(18,5);
            printf("%c%c%c%c%c USE RIGHT-LEFT ARROW TO CHOICE OPTION %c%c%c%c%c\n\n\n",215,219,178,177,176,176,177,178,219,215);

            gotoxy(28,10);
            printf("DO YOY WANT TO QUIT THE GAME ? \n");


            gotoxy(25,15);
            if(optionl==1)printf("%c%c%c%c YES %c%c%c%c\n",219,178,177,176,176,177,178,219);

            else printf("     YES\n");
            gotoxy(50,15);
            if(optionl==2)printf("%c%c%c%c NO %c%c%c%c\n",219,178,177,176,176,177,178,219);
            else printf("     NO\n");
            turnerl=getch();
            if(turnerl==75)optionl--;
            else if(turnerl==77)optionl++;

            if(optionl==3)optionl=2;
            else if(optionl==0)optionl=1;

        }
        while(turnerl!=13);

        switch(optionl)
        {
        case 1:
        {
            system("cls");
            printf("\n\tG O O D    B Y E");
            for(i=0; i<5; i++)
            {
                Sleep(1000);
                printf(".");
            }
            exit(0);

            break;

        }
        case 2:
            goto UPDATE;

        }



    }


    }




}

int validmoves(char board[][SIZE],bool moves[][SIZE],char player)
{


    int rowdlta=0,coldlta=0,x=0,y=0,noofmoves=0,row,col;

    char opponent=(player==playerc)?compc:playerc;

    for(row=0; row<SIZE; row++)
        for(col=0; col<SIZE; col++)moves[row][col]=false;


    for(row=0; row<SIZE; row++)
        for(col=0; col<SIZE; col++)
        {
            if(board[row][col]!=' ')continue;

            for(rowdlta=-1; rowdlta<=1; rowdlta++)
                for(coldlta=-1; coldlta<=1; coldlta++)
                {
                    if(row+rowdlta<0||row+rowdlta>=SIZE||col+coldlta<0||col+coldlta>=SIZE||(rowdlta==0&&coldlta==0))continue;

                    if(board[row+rowdlta][col+coldlta]==opponent)
                    {
                        x=row+rowdlta;
                        y=col+coldlta;

                        for(;;)
                        {
                            x+=rowdlta;
                            y+=coldlta;

                            if(x<0||x>=SIZE||y<0||y>=SIZE)break;

                            if(board[x][y]==' ')break;
                            if(board[x][y]==player)
                            {
                                moves[row][col]=true;
                                noofmoves++;
                                break;
                            }


                        }



                    }
                }

        }

    return noofmoves;


}

void makemove(char board[][SIZE],int row,int col,char player)
{
    int rowdlta=0;
    int coldlta=0;
    int x=0;
    int y=0;

    char opponent=(player==playerc)?compc:playerc;

    board[row][col]=player;

    for(rowdlta=-1; rowdlta<=1; rowdlta++)
        for(coldlta=-1; coldlta<=1; coldlta++)
        {
            if(row+rowdlta<0||row+rowdlta>=SIZE||col+coldlta<0||col+coldlta>=SIZE||(rowdlta==0&&coldlta==0))continue;

            if(board[row+rowdlta][col+coldlta]==opponent)
            {
                x=row+rowdlta;
                y=col+coldlta;

                for(;;)
                {
                    x+=rowdlta;
                    y+=coldlta;

                    if(x<0||x>=SIZE||y<0||y>=SIZE)break;
                    if(board[x][y]==' ')break;

                    if(board[x][y]==player)
                    {
                        while(board[x-=rowdlta][y-=coldlta]==opponent)
                        {
                            //if(player==1)SetColor(74);

                            board[x][y]=player;
                        }

                        break;

                    }


                }


            }

        }
}

int getscore(char board[][SIZE],char player)
{
    int row;
    int col;
    int score=0;
    char opponent=(player==playerc)?compc:playerc;

    for(row=0; row<SIZE; row++)
        for(col=0; col<SIZE; col++)
        {
            score-=board[row][col]==opponent;
            score-=board[row][col]==player;
        }

    return score;

}

int bestmove(char board[][SIZE],bool moves[][SIZE],char player)
{
    int row;
    int col;
    char newboard[SIZE][SIZE]= {0};
    int score=0;
    int newscore=0;
    char opponent=(player==playerc)?compc:playerc;


    for(row=0; row<SIZE; row++)
        for(col=0; col<SIZE; col++)
        {

            if(!moves[row][col])continue;

            memcpy(newboard,board,sizeof(newboard));//copy the board;

            makemove(newboard,row,col,player);//make move on the board copy;

            newscore=getscore(newboard,player);

            if(score<newscore)score=newscore;


        }

    return score;

}

void compmove(char board[][SIZE],bool moves[][SIZE],char player)
{
    int bestrow=0;
    int bestcol=0;
    int newscore=0;
    int score=100;
    char tempboard[SIZE][SIZE];
    bool tempmoves[SIZE][SIZE];
    char opponent=(player==playerc)?compc:playerc;
    int row;
    int col;



    for(row=0; row<SIZE; row++)
        for(col=0; col<SIZE; col++)
        {
            if(!moves[row][col])continue;

            memcpy(tempboard,board,sizeof(tempboard));

            makemove(tempboard,row,col,player);

            validmoves(tempboard,tempmoves,opponent);
            newscore=bestmove(tempboard,tempmoves,opponent);

            if(newscore<score)
            {
                score=newscore;
                bestrow=row;
                bestcol=col;
            }

        }


    makemove(board,bestrow,bestcol,player);

}

void display(char board[][SIZE])
{
    int row,col,i;
    int compscore=0;
    int userscore=0;
    //char board[10][10];
    compscore=userscore=0;

    for(row=0; row<SIZE; row++)
        for(col=0; col<SIZE; col++)
        {
            compscore+=board[row][col]==compc;
            userscore+=board[row][col]==playerc;

        }



    SetColor(95);

    printf("\t  ");
    //for(row=0; row<SIZE; row++)printf("  %2c ",'a'+row);
    printf("\n\n\n");


    for(row=0; row<SIZE; row++)
    {
        printf("\t   +");

        for(col=0; col<SIZE; col++)printf("====+");
        //if(row==2)printf("\t\t-[USER     : %d]-",userscore);
        //if(row==3)printf("\t\t-[COMPUTER : %d]-",compscore);

        //SetColor(74);
        printf("\n\t  %d|",row+1);


        for(col=0; col<SIZE; col++)
        {
            if(board[row][col]==1)SetColor(74);
            else SetColor(76);
            printf(" %2c",board[row][col]);
            SetColor(95);
            printf(" |");
        }
        printf("\n\t   |");

        for(col=0; col<SIZE; col++)printf("    |");

        printf("\n");
        //SetColor(34);


    }
    printf("\t   +");
    for(col=0; col<SIZE; col++)printf("====+");
    printf("\n\n");

    gotoxy(49,2);
    printf(" USER %c",playerc);
    gotoxy(64,2);
    printf("COMPUTER %c",compc);
    gotoxy(49,4);
    printf(" SCORE");
    gotoxy(65,4);
    printf(" SCORE");
    gotoxy(51,6);
    printf(" %d",userscore);
    gotoxy(67,6);
    printf("%d",compscore);
    gotoxy(47,0);
    printf("_____________________________");
    gotoxy(47,7);
    printf("____________________________");
    gotoxy(47,17);
    printf("______________________________");
    gotoxy(49,19);
    printf("PRESS \"ESC\"   PRESS \"ENTER\"");

    gotoxy(49,21);
    printf("TO QUIT GAME   TO PROCEED");
    gotoxy(48,22);
    printf("_____________________________");
    for(i=1; i<=5; i++)
    {
        gotoxy(47,i+17);
        printf("|");
    }
    for(i=1; i<=5; i++)
    {
        gotoxy(62,i+17);
        printf("|");
    }
    for(i=1; i<=5; i++)
    {
        gotoxy(76,i+17);
        printf("|");
    }
    for(i=1; i<=7; i++)
    {
        gotoxy(47,i);
        printf("|");
    }
    for(i=1; i<=7; i++)
    {
        gotoxy(47,i);
        printf("|");
    }
    for(i=1; i<=7; i++)
    {
        gotoxy(75,i);
        printf("|");
    }
    for(i=1; i<=7; i++)
    {
        gotoxy(60,i);
        printf("|");
    }





}

void display2()
{
    int i,j,k,l;
   /* printf("\n\t\t");
    //int i;
    char ar2[]= {32,32,32,32,32,32,32,32,95,
                 95,95,95,95,95,95,95,95,95,95,
                 95,10,32,32,32,32,32,32,32,47,
                 92,32,32,95,95,95,95,95,95,95,
                 95,32,92,10,32,32,32,32,32,32,
                 47,32,32,92,32,92,95,95,95,95,
                 95,95,47,92,32,92,10,32,32,32,
                 32,32,47,32,47,92,32,92,32,92,
                 32,32,47,32,47,92,32,92,32,92,
                 10,32,32,32,32,47,32,47,32,47,
                 92,32,92,32,92,47,32,47,32,47,
                 92,32,92,32,92,10,32,32,32,47,
                 32,47,32,47,95,95,92,32,92,32,
                 92,47,95,47,95,95,92,95,92,32,
                 92,95,95,95,95,95,95,95,95,95,
                 95,10,32,32,47,32,47,95,47,95,
                 95,95,95,92,32,92,95,95,95,95,
                 95,95,95,95,95,95,32,32,95,95,
                 95,95,95,95,95,95,32,92,10,32,
                 32,92,32,92,32,92,95,95,95,95,
                 47,32,47,32,95,95,95,95,95,95,
                 95,95,47,92,32,92,95,95,95,95,
                 95,95,47,92,32,92,10,32,32,32,
                 92,32,92,32,92,32,32,47,32,47,
                 32,47,92,32,92,32,32,47,32,47,
                 92,32,92,32,92,32,32,47,32,47,
                 92,32,92,32,92,10,32,32,32,32,
                 92,32,92,32,92,47,32,47,32,47,
                 92,32,92,32,92,47,32,47,32,47,
                 92,32,92,32,92,47,32,47,32,47,
                 92,32,92,32,92,10,32,32,32,32,
                 32,92,32,92,47,32,47,32,47,95,
                 95,92,95,92,47,32,47,32,47,95,
                 95,92,32,92,32,92,47,95,47,95,
                 95,92,95,92,32,92,10,32,32,32,
                 32,32,32,92,32,32,47,95,47,95,
                 95,95,95,95,95,92,47,95,47,95,
                 95,95,95,92,32,92,95,95,95,95,
                 95,95,95,95,95,95,95,92,10,32,
                 32,32,32,32,32,47,32,32,92,32,
                 92,95,95,95,95,95,95,47,92,32,
                 92,95,95,95,95,47,32,47,32,95,
                 95,95,95,95,95,95,95,32,32,47,
                 10,32,32,32,32,32,47,32,47,92,
                 32,92,32,92,32,32,47,32,47,92,
                 32,92,32,92,32,32,47,32,47,32,
                 47,92,32,92,32,32,47,32,47,32,
                 47,10,32,32,32,32,47,32,47,32,
                 47,92,32,92,32,92,47,32,47,32,
                 47,92,32,92,32,92,47,32,47,32,
                 47,92,32,92,32,92,47,32,47,32,
                 47,10,32,32,32,47,32,47,32,47,
                 95,95,92,32,92,32,92,47,95,47,
                 95,95,92,95,92,47,32,47,32,47,
                 95,95,92,95,92,47,32,47,32,47,
                 10,32,32,47,32,47,95,47,95,95,
                 95,95,92,32,92,95,95,95,95,95,
                 95,95,95,95,92,47,32,47,95,95,
                 95,95,95,95,92,47,32,47,10,32,
                 32,92,32,92,32,92,95,95,95,95,
                 47,32,47,32,95,95,95,95,95,95,
                 95,95,32,32,95,95,95,95,95,95,
                 95,95,95,95,47,10,32,32,32,92,
                 32,92,32,92,32,32,47,32,47,32,
                 47,92,32,92,32,32,47,32,47,32,
                 47,10,32,32,32,32,92,32,92,32,
                 92,47,32,47,32,47,92,32,92,32,
                 92,47,32,47,32,47,10,32,32,32,
                 32,32,92,32,92,47,32,47,32,47,
                 95,95,92,95,92,47,32,47,32,47,
                 10,32,32,32,32,32,32,92,32,32,
                 47,32,47,95,95,95,95,95,95,92,
                 47,32,47,10,32,32,32,32,32,32,
                 32,92,47,95,95,95,95,95,95,95,
                 95,95,95,95,47,10,10,-99
                };

    for(j=0; j<7; j++)
    {
        SetColor(64+(j+10));

        if(j>=0) printf("\n\t\t");
        for(i=0;; i++)
        {
            if(ar2[i]==-99) break;
            else if(ar2[i]==10)
            {
                printf("\n\t\t");
                continue;
            }
            putchar(ar2[i]);
            if(j==0&&ar2[i]==47)Sleep(1);
        }
        Sleep(300);
        system("cls");
    }
*/
    //system("cls");
    SetColor(95);

  /*  printf("\n");
    char ar[]= {95,124,95,95,95,124,95,95,95,
                124,95,95,95,124,95,95,95,124,95,
                95,95,124,95,95,95,124,95,95,95,
                124,95,95,95,124,95,95,95,124,95,
                95,95,124,95,95,95,124,95,95,95,
                124,95,95,95,95,95,95,124,95,95,
                95,124,95,95,95,124,95,95,95,124,
                95,95,95,124,95,95,95,124,95,95,
                95,10,95,95,95,124,95,95,95,124,
                95,95,95,124,95,95,95,124,95,95,
                95,124,95,95,95,124,95,95,95,124,
                95,95,95,124,95,95,95,124,95,95,
                95,124,95,95,95,124,95,95,95,124,
                95,95,95,124,95,95,95,124,95,95,
                95,124,95,95,95,124,95,95,95,124,
                95,95,95,124,95,95,95,124,95,95,
                95,124,10,95,124,95,95,95,124,95,
                95,95,124,95,95,95,124,95,95,95,
                124,95,95,95,124,95,95,95,124,95,
                95,95,124,95,95,95,124,95,95,95,
                124,95,95,95,124,95,95,95,124,95,
                95,95,124,95,95,95,124,95,95,95,
                124,95,95,95,124,95,95,95,124,95,
                95,95,124,95,95,95,124,95,95,95,
                124,95,95,10,-99
               };

    for(i=0;; i++)
    {
        if(ar[i]==-99) break;
        putchar(ar[i]);
        Sleep(1);
    }*/

    printf("\n\n\t\t");

    //int i;
    char ar1[]= {32,95,95,95,95,95,32,32,95,
                 95,95,95,95,95,95,95,32,32,32,
                 32,32,32,95,95,95,95,95,95,95,
                 95,32,95,95,95,95,95,32,32,32,
                 95,95,95,95,95,32,95,95,95,95,
                 95,32,10,124,32,32,95,95,32,92,
                 124,32,32,95,95,95,95,92,32,92,
                 32,32,32,32,47,32,47,32,32,95,
                 95,95,95,124,32,32,95,95,32,92,
                 32,47,32,95,95,95,95,124,95,32,
                 32,32,95,124,10,124,32,124,95,95,
                 41,32,124,32,124,95,95,32,32,32,
                 92,32,92,32,32,47,32,47,124,32,
                 124,95,95,32,32,124,32,124,95,95,
                 41,32,124,32,40,95,95,95,32,32,
                 32,124,32,124,32,32,10,124,32,32,
                 95,32,32,47,124,32,32,95,95,124,
                 32,32,32,92,32,92,47,32,47,32,
                 124,32,32,95,95,124,32,124,32,32,
                 95,32,32,47,32,92,95,95,95,32,
                 92,32,32,124,32,124,32,32,10,124,
                 32,124,32,92,32,92,124,32,124,95,
                 95,95,95,32,32,32,92,32,32,47,
                 32,32,124,32,124,95,95,95,95,124,
                 32,124,32,92,32,92,32,95,95,95,
                 95,41,32,124,95,124,32,124,95,32,
                 10,124,95,124,32,32,92,95,92,95,
                 95,95,95,95,95,124,32,32,32,92,
                 47,32,32,32,124,95,95,95,95,95,
                 95,124,95,124,32,32,92,95,92,95,
                 95,95,95,95,47,124,95,95,95,95,
                 95,124,10,10,32,32,32,32,32,32,
                 32,32,32,32,32,32,10,32,32,32,
                 32,32,32,32,32,32,32,32,32,32,
                 32,32,32,32,32,32,32,32,32,32,
                 32,32,32,32,32,32,32,32,32,32,
                 32,32,32,32,32,32,32,32,32,32,
                 32,32,32,32,32,32,32,32,10,32,
                 32,32,32,32,32,32,95,95,95,95,
                 95,32,32,32,32,32,32,32,32,32,
                 32,95,95,32,32,95,95,32,95,95,
                 95,95,95,95,32,10,32,32,32,32,
                 32,32,47,32,95,95,95,95,124,32,
                 32,32,47,92,32,32,32,124,32,32,
                 92,47,32,32,124,32,32,95,95,95,
                 95,124,10,32,32,32,32,32,124,32,
                 124,32,32,95,95,32,32,32,47,32,
                 32,92,32,32,124,32,92,32,32,47,
                 32,124,32,124,95,95,32,32,32,10,
                 32,32,32,32,32,124,32,124,32,124,
                 95,32,124,32,47,32,47,92,32,92,
                 32,124,32,124,92,47,124,32,124,32,
                 32,95,95,124,32,32,10,32,32,32,
                 32,32,124,32,124,95,95,124,32,124,
                 47,32,95,95,95,95,32,92,124,32,
                 124,32,32,124,32,124,32,124,95,95,
                 95,95,32,10,32,32,32,32,32,32,
                 92,95,95,95,95,95,47,95,47,32,
                 32,32,32,92,95,92,95,124,32,32,
                 124,95,124,95,95,95,95,95,95,124,-99
                };

    for(i=0;; i++)
    {
        if(ar1[i]==-99) break;
        else if(ar1[i]==10)
        {
            printf("\n\t\t");
            continue;
        }
        putchar(ar1[i]);
        Sleep(0);
    }

    //system("cls");
    printf("   LOADING");
    for(i=0; i<7; i++)
    {
        printf(".");
        Sleep(1000);
    }

    system("cls");

}

void SetColor(int ForgC)
{
    WORD wColor;
    //We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}



