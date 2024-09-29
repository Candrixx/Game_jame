#ifndef RE_DOOR_H
#define RE_DOOR_H
#include <iostream>
#include <conio.h>
#include <algorithm>
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define ESC 27
#define SPACE 32
#define CLEAR_SCREEN system("cls")
#define UP2 'W'
#define DOWN2 'S'
#define LEFT2 'A'
#define RIGHT2 'D'

char game_mat[24][46];
char logo[12][18];
int pX = 1;
int pY = 1;

class Piece {
    public:
    int iniX;
    int iniY;
    int xPos;
    int yPos;
    char pieceArr[24];

    Piece() {
        int xPos = 0;
        int yPos = 0;
        int iniX = 0;
        int iniY = 0;
    }

} pieces[9];

void draw_mat(char game_mat[][46]) {
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 46; j++) {
            if (i == 0 && (j >= 1 && j <= 44))
                game_mat[i][j] = '-';
            else if (i == 0 && j == 0)
                game_mat[i][j] = 218;
            else if (i == 0 && j == 45)
                game_mat[i][j] = 191;
            else if ((i >= 1 && i <= 22) && (j == 0 || j == 45))
                game_mat[i][j] = '|';
            else if (i == 23 && j == 0)
                game_mat[i][j] = 192;
            else if (i == 23 && j == 45)
                game_mat[i][j] = 217;
            else if (i == 5 && (j >= 14 && j <= 31))
                game_mat[i][j] = '-';
            else if (i == 5 && j == 13)
                game_mat[i][j] = 218;
            else if (i == 5 && j == 32)
                game_mat[i][j] = 191;
            else if ((i >= 6 && i <= 17) && (j == 13 || j == 32))
                game_mat[i][j] = '|';
            else if (i == 18 && j == 13)
                game_mat[i][j] = 192;
            else if (i == 18 && j == 32)
                game_mat[i][j] = 217;
            else if (i == 18 && j > 13 && j < 32)
                game_mat[i][j] = '-';
            else if (i == 23 && j >= 1 && j <= 44)
                game_mat[i][j] = '-';
            else
                game_mat[i][j] = ' ';
       }
    }
}

void ini_pieces(Piece pieces[]) {

    for (int i = 0; i < 9; i++) {
        pieces[i] = Piece();
    }

    //Pieces 1-3
    pieces[0].xPos = 38; pieces[0].yPos = 2; pieces[1].xPos = 15; pieces[1].yPos = 19; pieces[2].xPos = 2; pieces[2].yPos = 1;
    pieces[0].iniX = 38; pieces[0].iniY = 2; pieces[1].iniX = 15; pieces[1].iniY = 19; pieces[2].iniX = 2; pieces[2].iniY = 1;
    //Piece 1
    std::fill(pieces[0].pieceArr, pieces[0].pieceArr+24, ' ');
    pieces[0].pieceArr[10] = '#'; pieces[0].pieceArr[11] = '#'; 
    pieces[0].pieceArr[14] = '#'; pieces[0].pieceArr[15] = '#'; pieces[0].pieceArr[16] = '#'; pieces[0].pieceArr[17] = '#';
    pieces[0].pieceArr[18] = '#'; pieces[0].pieceArr[19] = '#'; pieces[0].pieceArr[20] = '#'; pieces[0].pieceArr[21] = '#'; pieces[0].pieceArr[22] = '#'; pieces[0].pieceArr[23] = '#';
    //Piece 2
    std::fill(pieces[1].pieceArr, pieces[1].pieceArr+24, '#');
    pieces[1].pieceArr[0] = ' '; pieces[1].pieceArr[5] = ' '; 
    //Piece 3
    std::fill(pieces[2].pieceArr, pieces[2].pieceArr+24, '#');
    pieces[2].pieceArr[0] = ' '; pieces[2].pieceArr[1] = ' '; pieces[2].pieceArr[2] = ' '; pieces[2].pieceArr[3] = ' '; pieces[2].pieceArr[4] = ' '; pieces[2].pieceArr[5] = ' ';
    pieces[2].pieceArr[8] = ' '; pieces[2].pieceArr[9] = ' '; pieces[2].pieceArr[10] = ' '; pieces[2].pieceArr[11] = ' ';
    pieces[2].pieceArr[16] = ' '; pieces[2].pieceArr[17] = ' ';
    //Pieces 4-6
    pieces[3].xPos = 4; pieces[3].yPos = 7; pieces[4].xPos = 35; pieces[4].yPos = 18; pieces[5].xPos = 28; pieces[5].yPos = 1;
    pieces[3].iniX = 4; pieces[3].iniY = 7; pieces[4].iniX = 35; pieces[4].iniY = 18; pieces[5].iniX = 28; pieces[5].iniY = 1;
    //Piece 4
    std::fill(pieces[3].pieceArr, pieces[3].pieceArr+24, '#');
    pieces[3].pieceArr[12] = ' ';
    pieces[3].pieceArr[18] = ' '; pieces[3].pieceArr[19] = ' ';
    //Piece 5
    std::fill(pieces[4].pieceArr, pieces[4].pieceArr+24, '#');
    //Piece 6
    std::fill(pieces[5].pieceArr, pieces[5].pieceArr+24, '#');
    pieces[5].pieceArr[17] = ' ';
    pieces[5].pieceArr[22] = ' '; pieces[5].pieceArr[23] = ' ';
    //Pieces 7-9
    pieces[6].xPos = 2; pieces[6].yPos = 15; pieces[7].xPos = 36; pieces[7].yPos = 10; pieces[8].xPos = 13; pieces[8].yPos = 1;
    pieces[6].iniX = 2; pieces[6].iniY = 15; pieces[7].iniX = 36; pieces[7].iniY = 10; pieces[8].iniX = 13; pieces[8].iniY = 1;
    //Piece 7
    std::fill(pieces[6].pieceArr, pieces[6].pieceArr+24, ' ');
    pieces[6].pieceArr[3] = '#'; pieces[6].pieceArr[4] = '#'; pieces[6].pieceArr[5] = '#';
    pieces[6].pieceArr[11] = '#';
    //Piece 8
    std::fill(pieces[7].pieceArr, pieces[7].pieceArr+24, '#');
    pieces[7].pieceArr[18] = ' '; pieces[7].pieceArr[19] = ' '; pieces[7].pieceArr[22] = ' '; pieces[7].pieceArr[23] = ' ';
    //Piece 9
    std::fill(pieces[8].pieceArr, pieces[8].pieceArr+24, ' ');
    pieces[8].pieceArr[0] = '#'; pieces[8].pieceArr[1] = '#'; pieces[8].pieceArr[2] = '#';
    pieces[8].pieceArr[6] = '#';

}

void draw_piece(Piece piece, int mode, int logoX = 0, int logoY = 0) {

    int y = 0;
    int x = 0;

    if (mode == 1) {
        for (int i = 0; i < 24; i++) {
            game_mat[piece.yPos+y][piece.xPos+x] = piece.pieceArr[i];
            x++;
            if (x == 6) {
                y++;
                x = 0;
            }   
        }
    }
    else if (mode == 2) {
       for (int i = 0; i < 24; i++) {
            logo[logoY+y][logoX+x] = piece.pieceArr[i];
            x++;
            if (x == 6) {
                y++;
                x = 0;
            }   
        } 
    }
}

void delete_piece(int oldX, int oldY) {

    int y = 0;
    int x = 0;

    for (int i = 0; i < 24; i++) {
        game_mat[oldY+y][oldX+x] = ' ';
        x++;
        if (x == 6) {
            y++;
            x = 0;
        }   
    }
}

void print_minigame() {
    std::cout << std::endl << std::endl;
     for (int i = 0; i < 24; i++) {
        std::cout << "\t\t\t\t\t";
        for (int j = 0; j < 46; j++) {
            if (pX == j && pY == i)
                std::cout << '*';
            else
                std::cout << game_mat[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "\t\t\t\t\tArriba: W\tAbajo: S\tAccion: Espacio" << std::endl; 
    std::cout << "\t\t\t\t\tIzquierda: A\tDerecha: D\tSalir: E/Esc" << std::endl;   
}

bool run_re_door() {

    bool minigame_flag = false;
    ini_pieces(pieces);
    draw_mat(game_mat);
    for (int i = 0; i < 9; i++) {
        draw_piece(pieces[i], 1);
    }
    int logoX = 0;
    int logoY = 0;
    bool logo_created = false;
    if (logo_created == false) {
        for (int i = 0; i < 9; i++) {

            draw_piece(pieces[i], 2, logoX, logoY);
            logoX += 6;
            if (logoX > 12) {
                logoX = 0;
                logoY += 4;
            }

        }
    }
    
    char key, select_key;

    while (true) {

        CLEAR_SCREEN;
        print_minigame();
        int selected_piece = -1, oldX = 0, oldY = 0, changeX = 0, changeY = 0;
        int checkX = 14;
        int checkY = 6;

        key = getch();

        if ((key == UP || key == UP2) && pY > 1)
            pY--;
        else if ((key == RIGHT || key == RIGHT2) && pX < 44)
            pX++;
        else if ((key == DOWN || key == DOWN2) && pY < 22)
            pY++;
        else if ((key == LEFT || key == LEFT2) && pX > 1)
            pX--;
        else if (key == SPACE) {
            for (int i = 0; i < 9; i++) {
                if ((pX >= pieces[i].xPos && pX <= pieces[i].xPos+5 && pY >= pieces[i].yPos && pY <= pieces[i].yPos+3)) {
                    selected_piece = i; 
                    oldX = pieces[i].xPos;
                    oldY = pieces[i].yPos;  
                }
            }
            if (selected_piece != -1){   
                pX = 14;
                pY = 6;
                while (true) {
                    CLEAR_SCREEN;
                    print_minigame();
                    select_key = getch();
                    if ((select_key == UP || select_key == UP2) && pY > 6)
                        pY-= 4;
                    else if ((select_key == RIGHT || select_key == RIGHT2) && pX < 26)
                        pX+= 6;
                    else if ((select_key == DOWN || select_key == DOWN2) && pY < 14)
                        pY+= 4;
                    else if ((select_key == LEFT || select_key == LEFT2) && pX > 14)
                        pX-= 6;
                    else if (select_key == SPACE) {
                        for (int i = 0; i < 9; i++) {
                        if ((pX >= pieces[i].xPos && pX <= pieces[i].xPos+5 && pY >= pieces[i].yPos && pY <= pieces[i].yPos+3)) { 
                            pieces[i].xPos = pieces[i].iniX;
                            pieces[i].yPos = pieces[i].iniY;
                            draw_piece(pieces[i], 1);
                            } 
                        }
                        pieces[selected_piece].xPos = pX;
                        pieces[selected_piece].yPos = pY;
                        delete_piece(oldX, oldY);
                        draw_piece(pieces[selected_piece], 1);
                        print_minigame();
                        break;
                    }
                }
            }
            else if (select_key == ESC) {
                CLEAR_SCREEN;
                break;
            }
        }
        else if (key == ESC)
            break;
        if (selected_piece == -1)
            continue;
        
         for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 18; j++) {
                if (logo[i][j] == game_mat[checkY][checkX]) {
                    checkX++;
                    if (checkX == 32) {
                        checkX = 14;
                        checkY++;
                        minigame_flag = true;
                    }
                }
                else {
                    minigame_flag = false;
                    break;
                }
            }
        }
         if (minigame_flag) {
            CLEAR_SCREEN;
            return true;
        }   
    }
    CLEAR_SCREEN;
    return false;
}

#endif