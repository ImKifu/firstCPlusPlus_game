#include <iostream>
#include <time.h>
#include <tuple>
#include <string>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

enum LEVER
{
    Easy = 1,
    Normal = 2,
    Hard = 3
};


enum CellType
{
    CELL_EMPTY = 0,
    CELL_TANK,
    CELL_BOOM = 3,
    CELL_TANKBOOMED = 4
};

const int TANKSIZE = 3 ;
const int TANKHEALTH = 9 ;

const int width = 10 ;
const int height = 10 ;




int ENDGAME = 0;
int BULLETS = 30;


class GAME
{


public:

    int TRUCTOADO[ width +1 ][ height +1 ];
    int MAP10x10_COPY[width][height];
    int MAP10x10[width][height];


    void SETTRUCTOADO()
    {
        for( int i=0; i<=width; i++)
        {
            for( int j=0; j<=height; j++)
            {
                if( i==0 )
                {
                    for( int k=0; k<=width; k++ )
                    {
                        TRUCTOADO[i][k] = k+1 ;
                    }
                }

                if( j==10 )
                {
                    for( int h=0; h<=height; h++ )
                    {
                        TRUCTOADO[h][j] = h;
                    }

                }

                if( i!=0 && j!=11 )
                {
                    for( int i=1; i<=width; i++)
                    {
                        for( int j=0; j<height; j++)
                        {
                            TRUCTOADO[i][j]=CELL_EMPTY ;
                        }
                    }

                }

            }

        }
    }

    void PRINTTRUCTOADO()
    {
        for( int i=0; i<=width; i++ )
        {
            for( int j=0; j<=height; j++)
            {
                cout << TRUCTOADO[i][j] << " " ;
            }
            cout << endl;
        }

    }



    void SETMAP10x10_COPY()
    {
        for( int i=0; i<width; i++)
        {
            for( int j=0; j<height; j++)
            {
                MAP10x10_COPY[i][j]=CELL_EMPTY ;
            }
        }
    }

    void voidPrint10x10MAP_COPY()
    {
        for( int i=0; i<width; i++)
        {
            for( int j=0; j<height; j++)
            {
                cout << MAP10x10_COPY[i][j] << " " ;
            }
            cout << endl;
        }
    }



    void SETMAP10x10()
    {
        for( int i=0; i<width; i++)
        {
            for( int j=0; j<height; j++)
            {
                MAP10x10[i][j]=CELL_EMPTY ;
            }
        }
    }

    void voidPrint10x10MAP()
    {
        for( int i=0; i<width; i++)
        {
            for( int j=0; j<height; j++)
            {
                cout << MAP10x10[i][j] << " " ;
            }
            cout << endl;
        }
    }

    void SETTANK()
    {
        int POSITION_RANDOM_WIDTH, POSITION_RANDOM_HEIGHT ;
        POSITION_RANDOM_WIDTH = rand()%8;
        POSITION_RANDOM_HEIGHT = rand()%8;



        for( int i=0 ; i<TANKSIZE ; i++)
        {
            for( int j=0 ; j<TANKSIZE ; j++)
            {
                MAP10x10[i+POSITION_RANDOM_WIDTH][j+POSITION_RANDOM_HEIGHT]=CELL_TANK;
            }
        }



    }

    struct Position_Guess
    {
        int x ;
        int y ;
    };

    Position_Guess GETPLAYERGUESS()
    {
        Position_Guess pos_guess_player;

        cin >> pos_guess_player.x >> pos_guess_player.y ;

        if(  pos_guess_player.x > width  ||  pos_guess_player.y > height  )
        {
            cout << " You have shooted outside the map. " << endl
                 << " Please be more carefull because you will lose your bullet. " << endl ;
        }
        return pos_guess_player;
    }


    void GETPOSITION()
    {
        Position_Guess pos_guess_player = GETPLAYERGUESS();

        if ( MAP10x10[pos_guess_player.x - 1][pos_guess_player.y - 1] == CELL_EMPTY )
        {

            MAP10x10_COPY[pos_guess_player.x - 1][pos_guess_player.y - 1] = CELL_BOOM;
        }

        if ( MAP10x10[pos_guess_player.x - 1][pos_guess_player.y - 1] == CELL_TANK )
        {
            MAP10x10_COPY[pos_guess_player.x - 1][pos_guess_player.y - 1] = CELL_TANKBOOMED;

//            MAP10x10[pos_guess_player.x - 1][pos_guess_player.y - 1] = CELL_EMPTY ;
            ENDGAME++;
        }

    }


    void GETPOSITION_TRUCTOADO()
    {
        Position_Guess pos_guess_player = GETPLAYERGUESS();

        if ( MAP10x10[pos_guess_player.x - 1][pos_guess_player.y - 1] == CELL_EMPTY )
        {

            TRUCTOADO[pos_guess_player.x ][pos_guess_player.y - 1] = CELL_BOOM;
        }

        if ( MAP10x10[pos_guess_player.x - 1][pos_guess_player.y - 1] == CELL_TANK )
        {
            TRUCTOADO[pos_guess_player.x ][pos_guess_player.y - 1] = CELL_TANKBOOMED;

            MAP10x10[pos_guess_player.x - 1][pos_guess_player.y - 1] = CELL_EMPTY ;
            ENDGAME++;
        }

    }






//    bool END_GAME()
//    {
//        for( int i=0 ; i<width; i++ )
//        {
//            for( int j=0; j<height; j++ )
//            {
//                if( MAP10x10[i][j] == CELL_EMPTY )
//                    return false;
//            }
//        }
//        return true;
//    }

    void BULLETS_STATUS()
    {
        cout << " Bullets left: " << BULLETS << endl;
        cout << " Health Tank Points left: " << TANKHEALTH - ENDGAME << endl ;

    }


    void GAME_STATUS()
    {
        if( ENDGAME == TANKHEALTH )
        {
            cout << " Congratulations <3 <3 <3 " << endl << " You are the winner " ;
        }
        if( BULLETS == 0 )
        {
            cout << " Sorry, you are running out of armor " << endl;
            cout << "You lose :< " ;
        }


    }


};



void clearScreen();


int main()
{



Welcome:

    cout << " Nhap toa do tu 1-10 de ban xe tang " << endl
         << " So dau tien se la hang doc" << endl
         << " So tiep theo se la hang ngang" << endl
         << " Neu ban vao o trong se hien ra so 3" << endl
         << " Neu ban vao o co xe tang se hien ra so 4" << endl;
    cout << endl;
    cout << " Co ba muc do kho de ban lua chon " << endl;
    cout << " Nhap vao so tu 1-3 de chon muc do" << endl ;
    cout << endl;

    cout << "Easy   = 1" << endl
         << "Normal = 2" << endl
         << "Hard   = 3" << endl
         << "Please enter your choice" <<  endl;

    int option;
    cin >> option;
    switch( option )
    {
    case 1:
    {
        int *c = &BULLETS;
        *c = 40;
        break;
    }
    case 2:
    {
        int *c = &BULLETS;
        *c = 30;
        break;
    }
    case 3:
    {
        int *c = &BULLETS;
        *c = 20;
        break;
    }

    }
    if ( option == 1 || option == 2 || option == 3 )
    {
        goto run;
    }
    else goto Welcome;


run:

    srand(time(0));
    GAME MAP;

    MAP.SETMAP10x10();
    MAP.SETTANK();
    MAP.voidPrint10x10MAP();

    clearScreen();





    MAP.SETTRUCTOADO();
    MAP.PRINTTRUCTOADO();

    cout << endl;

//    MAP.END_GAME();

    do
    {

        MAP.BULLETS_STATUS();
//        MAP.GETPOSITION();
        MAP.GETPOSITION_TRUCTOADO();

        BULLETS-- ;
        clearScreen();

//        MAP.voidPrint10x10MAP_COPY();
        MAP.PRINTTRUCTOADO();
//        MAP.voidPrint10x10MAP();
        cout << endl;

        MAP.GAME_STATUS();

    }
    while ( ENDGAME < TANKHEALTH && BULLETS != 0 );
}

void clearScreen()
{
    const int PATCH_LINES = 20;
    for (int i = 0; i < PATCH_LINES; i++) cout << endl;
}


//void gotoxy(short x,short y)
//{
//HANDLE hConsoleOutput;
//COORD Cursor_an_Pos = { x,y};
//hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
//}
