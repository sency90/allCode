/****************************************************************************
** $Id: qt/tictac.h   3.3.3   edited May 27 2003 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#ifndef TICTAC_H
#define TICTAC_H


#include <qpushbutton.h>
#include <qptrvector.h>
#include <string.h>
#define SIZE 12

class QComboBox;
class QLabel;

// --------------------------------------------------------------------------
// TicTacButton implements a single tic-tac-toe button
//

class TicTacButton : public QPushButton {
    Q_OBJECT
public:
    int getX() {return x;}
    int getY() {return y;}
    void setXY(int x, int y) {this->x=x; this->y=y;}
    TicTacButton( QWidget *parent );

    enum Type { Blank, Circle, Cross, Triangle, Rectangle, ReverseTriangle, RJoin, LJoin, Join, Strange };
    Type getType(int type);
    static int getType(Type t);
    Type type() const { return t; }
    void setType( Type type ) { t = type; repaint(); }
    void setType( int type );

    QSizePolicy sizePolicy() const { return QSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred ); }
    QSize sizeHint() const { return QSize( 80, 100 ); }
    QSize minimumSizeHint() const { return QSize( 52, 30 ); }
protected:
    void drawButtonLabel( QPainter * );
private:
    Type t;
    int x, y;
};

// Using template vector to make vector-class of TicTacButton.
// This vector is used by the TicTacGameBoard class defined below.

typedef QPtrVector<TicTacButton> TicTacButtons;
typedef QMemArray<int> TicTacArray;
typedef QMemArray<int> vi;

/*
struct BoardSet{
    int p; //pallete
    Type t;
};
*/

class BlockInfo {
public:
    void init();
    BlockInfo();
    ~BlockInfo();
public:
    TicTacButton::Type type() {return t;}
    void setType(TicTacButton::Type t) {this->t=t;}
    void setPal(int p) {palInfo=p;}
    int getPal() {return palInfo;}
    //void setXY(int x, int y) { this->x=x; this->y=y; }
    void setIdx(int idx) {this->idx=idx;}
    //int getX() {return x;}
    //int getY() {return y;}
    int getIdx() {return idx;}
private:
    //int x, y;
    int idx;
    int palInfo;
    TicTacButton::Type t;
};

// --------------------------------------------------------------------------
// TicTacGameBoard implements the tic-tac-toe game board.
// TicTacGameBoard is a composite widget that contains N x N TicTacButtons.
// N is specified in the constructor.
//

class TicTacGameBoard : public QWidget {
    Q_OBJECT
public:
    TicTacGameBoard( int n, QWidget *parent=0, const char *name=0 );
   ~TicTacGameBoard();
    enum State { Init, HumansTurn, HumanWon, ComputerWon, NobodyWon };
    State state() const { return st; }
    void computerStarts( bool v );
    void newGame();
    bool dfsStart(int x, int y, int xe, int ye, int s, int prevDir);
    void dfs(int x, int y, int xe, int ye, int s, int pd);
signals:
    void finished();			// game finished
private slots:
    void buttonClicked();
private:
    int *dx, *dy;
    int **chk;
    void setState( State state ) { st = state; }
    void updateButtons();
    int checkBoard( TicTacArray * );
    //void computerMove();
    State st;
    int nBoard;
    bool comp_starts;
    TicTacArray *btArray;
    TicTacButtons *buttons;
    QMemArray<int> *v;
    //BoardSet initBoardSet[SIZE+2][SIZE+2];
    BlockInfo *pb;
    bool hasAns;
};


// --------------------------------------------------------------------------
// TicTacToe implements the complete game.
// TicTacToe is a composite widget that contains a TicTacGameBoard and
// two push buttons for starting the game and quitting.
//

class TicTacToe : public QWidget {
    Q_OBJECT
public:
    TicTacToe( int boardSize=3, QWidget *parent=0, const char *name=0 );
private slots:
    void newGameClicked();
    void gameOver();
private:
    void newState();
    QComboBox *whoStarts;
    QPushButton *newGame;
    QPushButton *quit;
    QLabel *message;
    TicTacGameBoard *board;
};


#endif // TICTAC_H
