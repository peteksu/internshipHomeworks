#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>
#include <fstream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

const char wall = '#';
const char path = ' ';
const char start = 'S';
const char finish = 'F';

const char maze[20][20]={{wall,start,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
                       {wall,path,path,path,path,path,path,path,path,wall,wall,path,path,path,path,path,path,path,path,wall},
                       {wall,wall,path,wall,wall,path,wall,wall,path,wall,wall,path,wall,wall,wall,path,wall,wall,path,wall},
                       {wall,wall,path,path,wall,path,wall,wall,path,wall,wall,path,wall,wall,wall,path,wall,wall,path,wall},
                       {wall,wall,wall,path,wall,path,wall,wall,path,path,path,path,path,path,path,path,wall,wall,path,wall},
                       {wall,wall,wall,path,path,path,path,path,path,wall,wall,wall,wall,path,wall,path,wall,wall,path,wall},
                       {wall,wall,wall,path,wall,wall,wall,wall,path,wall,wall,wall,wall,path,wall,path,wall,wall,path,wall},
                       {wall,wall,wall,path,wall,wall,wall,wall,path,wall,wall,wall,wall,path,wall,path,wall,wall,path,wall},
                       {wall,path,path,path,path,path,path,path,path,path,path,path,path,path,wall,path,wall,wall,path,wall},
                       {wall,wall,wall,path,wall,wall,wall,wall,wall,wall,wall,path,wall,path,path,path,path,path,path,wall},
                       {wall,wall,wall,path,wall,wall,wall,wall,path,wall,wall,path,wall,wall,path,wall,wall,path,wall,wall},
                       {wall,wall,wall,path,wall,wall,wall,wall,path,wall,wall,path,wall,wall,path,wall,wall,path,wall,wall},
                       {wall,path,path,path,path,path,path,path,path,path,path,path,path,path,path,wall,wall,path,wall,wall},
                       {wall,path,wall,path,wall,wall,path,wall,wall,wall,wall,path,wall,wall,path,wall,wall,path,wall,wall},
                       {wall,path,wall,path,wall,wall,path,wall,wall,wall,wall,path,wall,wall,path,wall,wall,path,wall,wall},
                       {wall,path,wall,wall,wall,wall,path,wall,wall,wall,wall,path,wall,wall,path,wall,wall,path,wall,wall},
                       {wall,path,wall,path,path,path,path,path,path,path,path,path,path,path,path,path,path,path,path,wall},
                       {wall,path,wall,path,wall,wall,wall,path,wall,wall,path,wall,wall,path,wall,wall,path,wall,wall,wall},
                       {wall,path,path,path,wall,wall,wall,path,path,path,path,wall,wall,path,wall,wall,path,path,path,finish},
                       {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall}

};
void ClearConsole(){
    system("CLS");
}
void PlayersInputHandle(char moveInput, char up, char down, char right, char left, int &positionX, int &positionY){
    int mazeSize = sizeof(maze)/sizeof(maze[0]);
    moveInput=getch();
        if(moveInput == up || moveInput == KEY_UP){
            if( positionY-1 >= 0 ){
                if(maze[positionY-1][positionX] != wall){
                positionY--;
                }
            }
        }
        if(moveInput == down || moveInput == KEY_DOWN){
            if( positionY+1 <= mazeSize-1 ){
                if(maze[positionY+1][positionX] != wall){
                    positionY++;
                }
            }
        }
        if(moveInput == right || moveInput == KEY_RIGHT){
            if( positionX+1 <= mazeSize-1 ){
                if(maze[positionY][positionX+1] != wall){
                    positionX++;
                }
            }
        }
        if(moveInput == left || moveInput == KEY_LEFT){
            if( positionX-1 >= 0 ){
                if(maze[positionY][positionX-1] != wall){
                    positionX--;
                }
            }
        }
}
void DisplayMaze(int &positionX, int &positionY){
    char Player = 'P';
    int mazeSize = sizeof(maze)/sizeof(maze[0]);
    for(int i=0;i<mazeSize;i++){
        for(int j=0;j<mazeSize;j++){
            if(j==positionX && i==positionY){
                cout<<Player<<" ";
                continue;
            }
            cout<<maze[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool isGameFinish(int &positionX, int &positionY){
    if(positionX==19 && positionY ==18){
        return true;
    }
    return false;
}
char settings(char &upKey, char &downKey, char &rightKey, char &leftKey ){
    cout<<"Choose a key to move up:\n";
    cin>>upKey;
    cout<<"Choose a key to move down:\n";
    cin>>downKey;
    cout<<"Choose a key to move right:\n";
    cin>>rightKey;
    cout<<"Choose a key to move left:\n";
    cin>>leftKey;
    return upKey, downKey, rightKey, leftKey;
}
void gameInformation(){
    cout<<"Hello player! This is a maze game.\n";
    cout<<" S: Start Point\n #: Wall\n F: Finish Point\n P: Player\n";
    cout<<"You can use the arrow keys or the arrow keys of your choice on the keyboard to move the player.\n";
    cout<<"You can set the keys you want to use from the settings option.\n";
    cout<<"You must remember that the player cannot pass through walls!\n";
    cout<<"If you can reach the finish point, you will have finished the game.\n";
    cout<<"Don't forget, if your number of moves exceeds 45, you will lose the game!GOOD LUCK!\n\n";
}
void menu(int &selection){
    cout<<"------------MENU------------\n";
    cout<<"Press 1 for settings.\n";
    cout<<"Press 2 for information about the game.\n";
    cout<<"Press 3 to play the game.\n";
    cout<<"Press 4 to go back to menu.\n";
    cout<<"Press 5 to see last scores.\n";
    cout<<"Press 0 to exit!\n";
    cout<<"-----------------------------\n";
    cin>>selection;
}
void saveScoreToFile(int score){
    FILE *targetFile = fopen("score.txt", "a");
    fprintf(targetFile, "%d \n", score );
    fclose(targetFile);
}
void readScoreFromFile(){
    int line;
    FILE *targetFile = fopen("score.txt", "r+");
    if(targetFile == NULL)
        return;
    int counter;
    for(counter = 0; counter<100; counter++){
        fscanf(targetFile, "%d \n", &line);
        if(line>=45){
            printf("\n->%d -> BAD SCORE-LOST THE GAME\n",line );
        }else{
            printf("\n->%d -> GOOD SCORE-WIN THE GAME\n",line );
        }
        if(feof(targetFile))
            break;
    }
    fclose(targetFile);
}
int main(){
    system("color 3");
    int playerPosX=1;
    int playerPosY=0;
    int selectionOfPlayer;
    char movement;
    char up;
    char down;
    char right;
    char left;
    int moveCounter=0;

    cout<<"   WELCOME TO MAZE GAME!\n\n\n";

    while(true){
        menu(selectionOfPlayer);
        ClearConsole();
        if(selectionOfPlayer == 1){
            settings(up,down,right,left);
            cout<<"\nSETTINGS SAVED!\n";
            Sleep(1200);
            ClearConsole();
        }else if (selectionOfPlayer == 2){
            gameInformation();
        }else if (selectionOfPlayer == 3){
            while(!isGameFinish(playerPosX,playerPosY)){//if player is not in the finish, loop
                DisplayMaze(playerPosX, playerPosY);//Show current maze
                PlayersInputHandle(movement, up, down, right, left, playerPosX, playerPosY);//take input
                ClearConsole();//Clear the console
                moveCounter=moveCounter+1;
                }

                if(moveCounter >= 45){
                    cout<<"Your score : "<<moveCounter;
                    cout<<"\n\nYour number of moves has exceeded 45! YOU LOST THE GAME!\n\n\n";
                }else{
                    cout<<"Your score : "<<moveCounter;
                    cout<<"\n\nCONGRATULATIONS! YOU HAVE SUCCESSFULLY FINISHED THE MAZE GAME!\n\n\n";
                }
                saveScoreToFile(moveCounter);
        }else if(selectionOfPlayer == 4){
            menu(selectionOfPlayer);
            break;
        }else if(selectionOfPlayer == 5){
            cout<<"Your past scores are as follows:";
            readScoreFromFile();
        }else{
            exit(0);
        }
    }
}

