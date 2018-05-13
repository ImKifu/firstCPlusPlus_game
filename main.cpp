#include <iostream>
#include <time.h>
#include <tuple>
#include <string>
#include <stdio.h>

using namespace std;

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

//    int TRUCTOADO[ width +1 ][ height +1 ];
//
//    void SETTRUCTOADO()
//    {
//        for( int i=0; i<=width; i++)
//        {
//            for( int j=0; j<=height; j++)
//            {
//                if( i==0 )
//                {
//                    for( int k=0; k<=width; k++ )
//                    {
//                        TRUCTOADO[i][k] = k;
//                    }
//                }
//
//                if( j==0 )
//                {
//                    for( int h=0; h<=height; h++ )
//                    {
//                        TRUCTOADO[h][j] = h;
//                    }
//
//                }
//
//                if( i!=0 && j!=0 )
//                {
//                    for( int i=1; i<=width; i++)
//                    {
//                        for( int j=1; j<=height; j++)
//                        {
//                            TRUCTOADO[i][j]=CELL_EMPTY ;
//                        }
//                    }
//
//                }
//
//            }
//
//        }
//    }
//
//    void PRINTTRUCTOADO()
//    {
//        for( int i=0; i<=width; i++ )
//        {
//            for( int j=0; j<=height; j++)
//            {
//                cout << TRUCTOADO[i][j] << " " ;
//            }
//            cout << endl;
//        }
//
//    }

    int MAP10x10_COPY[width][height];

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

    int MAP10x10[width][height];

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

        if(  pos_guess_player.x > width  ||  pos_guess_player.y > height  ){
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

    bool END_GAME()
    {
        for( int i=0 ; i<width; i++ )
        {
            for( int j=0; j<height; j++ )
            {
                if( MAP10x10[i][j] == CELL_EMPTY )
                    return false;
            }
        }
        return true;


    }

    void BULLETS_STATUS()
    {
        cout << " Bullets left: " << BULLETS << endl;

    }


    void GAME_STATUS()
    {
        if( ENDGAME == TANKHEALTH ){
            cout << " Congratulations <3 <3 <3 " << endl << " You are the winner " ;
        }
        if( BULLETS == 0 ){
            cout << " Sorry, You lose :< " ;
        }


    }


};



void clearScreen();


int main()
{
    srand(time(0));

    GAME MAP;
    MAP.SETMAP10x10();
    MAP.SETTANK();
//    MAP.voidPrint10x10MAP();
//    cout << endl;

    clearScreen();

    MAP.SETMAP10x10_COPY();
    MAP.voidPrint10x10MAP_COPY();

    cout << endl;

    MAP.END_GAME();

    do
    {

        MAP.BULLETS_STATUS();
        MAP.GETPOSITION();
        BULLETS-- ;
        clearScreen();

        MAP.voidPrint10x10MAP_COPY();
        cout << endl;



        MAP.GAME_STATUS();




    } while ( ENDGAME < TANKHEALTH && BULLETS != 0 );
}

void clearScreen() {
    const int PATCH_LINES = 15;
	for (int i = 0; i < PATCH_LINES; i++) cout << endl;
}


//void gotoxy(short x,short y)
//{
//HANDLE hConsoleOutput;
//COORD Cursor_an_Pos = { x,y};
//hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
//}




