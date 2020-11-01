#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "display.h"

#define FLUSH while(getchar() != '\n');

#define LEFT 0
#define RIGHT 9
#define TOP 0
#define BOTTOM 7

#define UNKNOWN 0
#define SAFE 1
#define MINES -1
#define FLAGSWOMINE 2
#define FLAGSWMINE 3
#define WIN 420
#define LOSE 666

/* *************** Notes *******************
    Unknown = 0
    Safe = 1
    Mines = -1
    Flags w/o Mine = 2
    Flags w/ Mine = 3
    Win = 420
    Lose = 666
***************************************** */

int main() {
    
    srand(time(0));

    char input;

    char difficulty;
    int gamePlaying = 0, gameFinished = 0, playAgain = 0;
    int num_Mines = 0, num_Flags = 0;
    int max_Mines;
    int win_col, win_row;
    int TIMMY_x, TIMMY_y;

    int tiles[BOTTOM+1][RIGHT+1];
    int mines[BOTTOM+1][RIGHT+1];

    int score = 0;

    menu(&difficulty);
    
    while(1) {

        /* Game Reset (Play Again) */
        while(playAgain == 1) {
            for(int row = 0; row <= BOTTOM; row++) {
                for(int col = 0; col <= RIGHT; col++) {
                    if(mines[row][col] == MINES && tiles[row][col] != 3 && tiles[row][col] != 666) {
                        tiles[row][col] = -1;
                        show_glif(MINE, row, col, 0);
                    }  
                }
            }

            input = getchar();
            if(input != 'y' && input != 'Y') {
                gameFinished = 1;
                break;
            }
            else
                playAgain = 0;
        }

        if(gameFinished == 1) break;

        TIMMY_x = 0; 
        TIMMY_y = 0;
        num_Mines = 0;
        score = 0;

        /* Initialize Board Tiles */
        for(int i = 0; i <= BOTTOM; i++) {
            for(int j = 0; j <= RIGHT; j++) {
                tiles[i][j] = 0;
            }
        }

        draw_board();

        /* Difficulty */
        if(difficulty == '2') {
            max_Mines = 11;
            num_Flags = 11;
        } else if(difficulty == '3') {
            max_Mines = 16;
            num_Flags = 16;
        } else if(difficulty == '4') {
            max_Mines = 20;
            num_Flags = 20;
        } else {
            max_Mines = 6;
            num_Flags = 6;
        }

        /* Initialize Safe Spots */
        for(int row = 0; row <= BOTTOM; row++) {
            tiles[row][0] = 1;
            if(rand() % 2 == 0)
                tiles[row][1] = 1;
        }

        /* Initialize Win Spot */
        win_row = rand() % (BOTTOM+1);
        win_col = rand() % (RIGHT+1-2) + 2;
        tiles[win_row][win_col] = 420;

        /* Initialize Mines */
        for(int i = 0; i <= BOTTOM; i++) {
            for(int j = 0; j <= RIGHT; j++) {
                mines[i][j] = 0;
            }
        }
        while(num_Mines < max_Mines) {
            for(int row = 0; row <= BOTTOM; row++) {
                for(int col = 1; col <= RIGHT; col++) {
                    if( num_Mines < max_Mines && tiles[row][col] == 0 && mines[row][col] == 0 && rand() % 10 == 0 ) {
                        mines[row][col] = -1;
                        num_Mines++;
                        //show_glif(MINE, row, col, 0);
                    }
                }
            }
        }
                
        gamePlaying = 1;

        while(gamePlaying == 1) {

            /* Win Detection */
            if(TIMMY_x == win_col && TIMMY_y == win_row) {
                write_message(0, "Play Again?");
                write_message(5, "Congratulations!");
                write_message(6, "  you made it through.");
                score += 10;
                gamePlaying = 0;
                playAgain = 1;
                update_score(score);
            }

            /* Lose Detection */
            if(mines[TIMMY_y][TIMMY_x] == -1) {
                write_message(0, "Play Again?");
                write_message(5, "We're gonna need");
                write_message(6, "  another Timmy!");
                show_glif(EXPLODE, TIMMY_y, TIMMY_x, 0);
                gamePlaying = 0;
                playAgain = 1;
                tiles[TIMMY_y][TIMMY_x] = 666;
            } 
            else if(tiles[TIMMY_y][TIMMY_x] == 0)
                score++;

            /* Updating Tiles */
            for(int i = 0; i <= BOTTOM; i++) {
                for(int j = 0; j <= RIGHT; j++) {

                    if(tiles[i][j] == 1) {
                        int adjCount = 0;
                        for(int adjRow = i-1; adjRow <= i+1; adjRow++) {
                            for(int adjCol = j-1; adjCol <= j+1; adjCol++) {
                                if(adjRow >= TOP && adjRow <= BOTTOM && adjCol >= LEFT && adjCol <= RIGHT && mines[adjRow][adjCol] == -1) {
                                    adjCount++;
                                }
                            }
                        }
                        show_glif(SAFE, i, j, adjCount);
                    }

                    else if(tiles[i][j] == 0 && TIMMY_x == j && TIMMY_y == i)
                            tiles[i][j] = 1;

                    else if(tiles[i][j] == -1) 
                        show_glif(MINE, i, j, 0);

                    else if(tiles[i][j] == 2)
                        show_glif(FLAG, i, j, 0);

                    else if(tiles[i][j] == 3)
                        show_glif(FL_MINE, i, j, 0);
                    
                }
            }

            /* Break if Win/Lose After Updating Tiles */
            if(playAgain == 1) break;

            int adjCurr = 0;
            for(int adjRow = TIMMY_y-1; adjRow <= TIMMY_y+1; adjRow++) {
                for(int adjCol = TIMMY_x-1; adjCol <= TIMMY_x+1; adjCol++) {
                    if(adjRow >= TOP && adjRow <= BOTTOM && adjCol >= LEFT && adjCol <= RIGHT && mines[adjRow][adjCol] == -1) {
                        adjCurr++;
                    }
                }
            }
            show_glif(TIMMY, TIMMY_y, TIMMY_x, adjCurr);

            /* Update Scores */
            update_mines(num_Mines);
            update_flags(num_Flags);
            update_score(score);

            /* User Inputs */
            input = getchar();
            write_message(0, "  "); //Clear existing msg after new input
            write_message(1, "  ");

            if(input == 27){        //esc to quit/reset anytime
                gamePlaying = 0;
                gameFinished = 0;   //set 0 for reset/play again. set 1 for quit
                break;
            }
            
            if(input == 'k') {
                if(TIMMY_x == RIGHT)
                    write_message(0, "Stay in Bounds!");
                else {
                    TIMMY_x++;
                }
            } 
            else if(input == 'h') {
                if(TIMMY_x == LEFT)
                    write_message(0, "Stay in Bounds!");
                else {
                    TIMMY_x--;
                }
            }
            else if(input == 'u') {
                if(TIMMY_y == TOP)
                    write_message(0, "Stay in Bounds!");
                else {
                    TIMMY_y--;
                }
            }
            else if(input == 'm') {
                if(TIMMY_y == BOTTOM)
                    write_message(0, "Stay in Bounds!");
                else {
                    TIMMY_y++;
                }
            }
            else if(input == 'y') {
                if(TIMMY_y == TOP || TIMMY_x == LEFT)
                    write_message(0, "Stay in Bounds!");
                else {
                    TIMMY_x--;
                    TIMMY_y--;
                }
            }
            else if(input == 'i') {
                if(TIMMY_y == TOP || TIMMY_x == RIGHT)
                    write_message(0, "Stay in Bounds!");
                else {
                    TIMMY_x++;
                    TIMMY_y--;
                }
            }
            else if(input == 'n') {
                if(TIMMY_y == BOTTOM || TIMMY_x == LEFT)
                    write_message(0, "Stay in Bounds!");
                else {
                    TIMMY_x--;
                    TIMMY_y++;
                }
            }
            else if(input == ',') {
                if(TIMMY_y == BOTTOM || TIMMY_x == RIGHT)
                    write_message(0, "Stay in Bounds!");
                else {
                    TIMMY_x++;
                    TIMMY_y++;
                }
            }

            /* FLAGS */
            else if(input == 'K'){
                if(num_Flags == 0)
                    write_message(0, "No more flags gg");
                else{ 
                    num_Flags--;
                    if(TIMMY_x == RIGHT)
                        write_message(0, "Dont throw away flags!");   
                    else if(tiles[TIMMY_y][TIMMY_x+1] == 1 || tiles[TIMMY_y][TIMMY_x+1] == 2 || tiles[TIMMY_y][TIMMY_x+1] == 3) {
                        write_message(0, "Cannot put a flag there,");
                        write_message(1, "  you lose it.");
                    }
                    else if(mines[TIMMY_y][TIMMY_x+1] == -1) {
                        tiles[TIMMY_y][TIMMY_x+1] = 3;
                        score += 2;
                        num_Mines--;
                    }
                    else {
                        tiles[TIMMY_y][TIMMY_x+1] = 2;
                        score--;
                    }
                }
            }
            else if(input == 'H'){
                if(num_Flags == 0)
                    write_message(0, "No more flags gg");
                else{ 
                    num_Flags--;
                    if(TIMMY_x == LEFT)
                        write_message(0, "Dont throw away flags!");
                    else if(tiles[TIMMY_y][TIMMY_x-1] == 1 || tiles[TIMMY_y][TIMMY_x-1] == 2 || tiles[TIMMY_y][TIMMY_x-1] == 3) {
                        write_message(0, "Cannot put a flag there,");
                        write_message(1, "  you lose it.");
                    }
                    else if(mines[TIMMY_y][TIMMY_x-1] == -1) {
                        tiles[TIMMY_y][TIMMY_x-1] = 3;
                        score += 2;
                        num_Mines--;
                    }
                    else {
                        tiles[TIMMY_y][TIMMY_x-1] = 2;
                        score--;
                    }
                }
            }
            else if(input == 'U'){
                if(num_Flags == 0)
                    write_message(0, "No more flags gg");
                else{ 
                    num_Flags--;
                    if(TIMMY_y == TOP)
                        write_message(0, "Dont throw away flags!");
                    else if(tiles[TIMMY_y-1][TIMMY_x] == 1 || tiles[TIMMY_y-1][TIMMY_x] == 2 || tiles[TIMMY_y-1][TIMMY_x] == 3) {
                        write_message(0, "Cannot put a flag there,");
                        write_message(1, "  you lose it.");
                    }
                    else if(mines[TIMMY_y-1][TIMMY_x] == -1) {
                        tiles[TIMMY_y-1][TIMMY_x] = 3;
                        score += 2;
                        num_Mines--;
                    }
                    else {
                        tiles[TIMMY_y-1][TIMMY_x] = 2;
                        score--;
                    }
                }
            }
            else if(input == 'M'){
                if(num_Flags == 0)
                    write_message(0, "No more flags gg");
                else{ 
                    num_Flags--;
                    if(TIMMY_y == BOTTOM)
                        write_message(0, "Dont throw away flags!");
                    else if(tiles[TIMMY_y+1][TIMMY_x] == 1 || tiles[TIMMY_y+1][TIMMY_x] == 2 || tiles[TIMMY_y+1][TIMMY_x] == 3) {
                        write_message(0, "Cannot put a flag there,");
                        write_message(1, "  you lose it.");
                    }
                    else if(mines[TIMMY_y+1][TIMMY_x] == -1) {
                        tiles[TIMMY_y+1][TIMMY_x] = 3;
                        score += 2;
                        num_Mines--;
                    }
                    else {
                        tiles[TIMMY_y+1][TIMMY_x] = 2;
                        score--;
                    }
                }
            }
            else if(input == 'Y'){
                if(num_Flags == 0)
                    write_message(0, "No more flags gg");
                else{ 
                    num_Flags--;
                    if(TIMMY_y == TOP || TIMMY_x == LEFT)
                        write_message(0, "Dont throw away flags!");
                    else if(tiles[TIMMY_y-1][TIMMY_x-1] == 1 || tiles[TIMMY_y-1][TIMMY_x-1] == 2 || tiles[TIMMY_y-1][TIMMY_x-1] == 3) {
                        write_message(0, "Cannot put a flag there,");
                        write_message(1, "  you lose it.");
                    }
                    else if(mines[TIMMY_y-1][TIMMY_x-1] == -1) {
                        tiles[TIMMY_y-1][TIMMY_x-1] = 3;
                        score += 2;
                        num_Mines--;
                    }
                    else {
                        tiles[TIMMY_y-1][TIMMY_x-1] = 2;
                        score--;
                    }
                }
            }
            else if(input == 'I'){
                if(num_Flags == 0)
                    write_message(0, "No more flags gg");
                else{ 
                    num_Flags--;
                    if(TIMMY_y == TOP || TIMMY_x == RIGHT)
                        write_message(0, "Dont throw away flags!");
                    else if(tiles[TIMMY_y-1][TIMMY_x+1] == 1 || tiles[TIMMY_y-1][TIMMY_x+1] == 2 || tiles[TIMMY_y-1][TIMMY_x+1] == 3) {
                        write_message(0, "Cannot put a flag there,");
                        write_message(1, "  you lose it.");
                    }
                    else if(mines[TIMMY_y-1][TIMMY_x+1] == -1) {
                        tiles[TIMMY_y-1][TIMMY_x+1] = 3;
                        score += 2;
                        num_Mines--;
                    }
                    else {
                        tiles[TIMMY_y-1][TIMMY_x+1] = 2;
                        score--;
                    }
                }
            }
            else if(input == 'N'){
                if(num_Flags == 0)
                    write_message(0, "No more flags gg");
                else{ 
                    num_Flags--;
                    if(TIMMY_y == BOTTOM || TIMMY_x == LEFT)
                        write_message(0, "Dont throw away flags!");
                    else if(tiles[TIMMY_y+1][TIMMY_x-1] == 1 || tiles[TIMMY_y+1][TIMMY_x-1] == 2 || tiles[TIMMY_y+1][TIMMY_x-1] == 3) {
                        write_message(0, "Cannot put a flag there,");
                        write_message(1, "  you lose it.");
                    }
                    else if(mines[TIMMY_y+1][TIMMY_x-1] == -1) {
                        tiles[TIMMY_y+1][TIMMY_x-1] = 3;
                        score += 2;
                        num_Mines--;
                    }
                    else {
                        tiles[TIMMY_y+1][TIMMY_x-1] = 2;
                        score--;
                    }
                }
            }
            else if(input == '<'){
                if(num_Flags == 0)
                    write_message(0, "No more flags gg");
                else{ 
                    num_Flags--;
                    if(TIMMY_y == BOTTOM || TIMMY_x == RIGHT)
                        write_message(0, "Dont throw away flags!");
                    else if(tiles[TIMMY_y+1][TIMMY_x+1] == 1 || tiles[TIMMY_y+1][TIMMY_x+1] == 2 || tiles[TIMMY_y+1][TIMMY_x+1] == 3) {
                        write_message(0, "Cannot put a flag there,");
                        write_message(1, "  you lose it.");
                    }
                    else if(mines[TIMMY_y+1][TIMMY_x+1] == -1) {
                        tiles[TIMMY_y+1][TIMMY_x+1] = 3;
                        score += 2;
                        num_Mines--;
                    }
                    else {
                        tiles[TIMMY_y+1][TIMMY_x+1] = 2;
                        score--;
                    }
                }
            }
        }
    }
    clear_screen();
}