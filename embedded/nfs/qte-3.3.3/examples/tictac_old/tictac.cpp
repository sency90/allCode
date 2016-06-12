#include "tictac.h"
#include <qapplication.h>
#include <qpainter.h>
#include <qdrawutil.h>
#include <qcombobox.h>
#include <qcheckbox.h>
#include <qlabel.h>
#include <qlayout.h>
#include <stdlib.h>				// rand() function
#include <qdatetime.h>				// seed for rand()
//***************************************************************************
//* TicTacButton member functions
//***************************************************************************

// --------------------------------------------------------------------------
// Creates a TicTacButton
TicTacButton::TicTacButton( QWidget *parent ) : QPushButton( parent ) {
    t = Blank;					// initial type
}

// --------------------------------------------------------------------------
// Paints TicTacButton
void TicTacButton::drawButtonLabel( QPainter *p )
{
    QRect r = rect();
    //p->setPen( QPen( blue,2 ) );		// set fat pen
    if ( t == Circle ) {
        p->setPen( QPen(green, 2));
        p->drawEllipse( r.left()+4, r.top()+4, r.width()-8, r.height()-8 );
    } else if ( t == Cross ) {			// draw cross
        p->setPen( QPen(black, 2));
        p->drawLine( r.topLeft()+QPoint(4,4), r.bottomRight()-QPoint(4,4));
        p->drawLine( r.bottomLeft()+QPoint(4,-4), r.topRight()-QPoint(4,-4));
    } else if(t == Triangle) {
        p->setPen( QPen(red, 2));
        p->drawLine( (r.topLeft()+r.topRight())/2 + QPoint(0,4), r.bottomLeft()+QPoint(4,-4));
        p->drawLine( (r.topLeft()+r.topRight())/2 + QPoint(0,4), r.bottomRight()-QPoint(4,4));
        p->drawLine( r.bottomLeft()+QPoint(4,-4), r.bottomRight()-QPoint(4,4));
    } else if(t == Rectangle) {
        //p->drawRect(r, 4, 4);
        p->setPen( QPen(blue, 2));
        p->drawLine( r.topLeft()+QPoint(4,4), r.topRight()-QPoint(4,-4));
        p->drawLine( r.topRight()-QPoint(4,-4), r.bottomRight()-QPoint(4,4));
        p->drawLine( r.bottomLeft()-QPoint(-4,4), r.bottomRight()-QPoint(4,4));
        p->drawLine( r.bottomLeft()-QPoint(-4,4), r.topLeft()+QPoint(4,4));
    } else if(t == ReverseTriangle) {
        p->setPen( QPen(red, 2));
        p->drawLine( (r.bottomLeft()+r.bottomRight())/2 - QPoint(0,4), r.topLeft()+QPoint(4,4));
        p->drawLine( (r.bottomLeft()+r.bottomRight())/2 - QPoint(0,4), r.topRight()-QPoint(4,-4));
        p->drawLine( r.topLeft()+QPoint(4,4), r.topRight()-QPoint(4,-4));
    } else if(t == RJoin) {
        p->setPen( QPen(red, 2));
        p->drawLine( r.topRight()-QPoint(4,-4), r.bottomRight()-QPoint(4,4));
        p->drawLine( r.topLeft()+QPoint(4,4), r.bottomRight()-QPoint(4,4));
        p->drawLine( r.bottomLeft()+QPoint(4,-4), r.topRight()-QPoint(4,-4));
    } else if(t == LJoin) {
        p->setPen( QPen(red, 2));
        p->drawLine( r.bottomLeft()-QPoint(-4,4), r.topLeft()+QPoint(4,4));
        p->drawLine( r.topLeft()+QPoint(4,4), r.bottomRight()-QPoint(4,4));
        p->drawLine( r.bottomLeft()+QPoint(4,-4), r.topRight()-QPoint(4,-4));
    } else if(t == Join) {
        p->setPen( QPen(blue, 2) );
        p->drawLine( r.topRight()-QPoint(4,-4), r.bottomRight()-QPoint(4,4));
        p->drawLine( r.bottomLeft()-QPoint(-4,4), r.topLeft()+QPoint(4,4));
        p->drawLine( r.topLeft()+QPoint(4,4), r.bottomRight()-QPoint(4,4));
        p->drawLine( r.bottomLeft()+QPoint(4,-4), r.topRight()-QPoint(4,-4));
    } else if(t == Strange) {
        p->setPen( QPen(yellow,1) );
        p->drawLine( r.topLeft()+QPoint(4,4), r.topRight()-QPoint(4,-4));
        p->drawLine( r.topRight()-QPoint(4,-4), r.bottomRight()-QPoint(4,4));
        p->drawLine( r.bottomLeft()-QPoint(-4,4), r.bottomRight()-QPoint(4,4));
        p->drawLine( r.bottomLeft()-QPoint(-4,4), r.topLeft()+QPoint(4,4));
        p->drawLine( r.topLeft()+QPoint(4,4), r.bottomRight()-QPoint(4,4));
        p->drawLine( r.bottomLeft()+QPoint(4,-4), r.topRight()-QPoint(4,-4));
        p->drawEllipse( r.left()+4, r.top()+4, r.width()-8, r.height()-8 );
    }
}


//***************************************************************************
//* TicTacGameBoard member functions
//***************************************************************************
void TicTacButton::setType(int type) {
    if(type==0) this->setType(Blank);
    else if(type==1) this->setType(Circle);
    else if(type==2) this->setType(Cross);
    else if(type==3) this->setType(Triangle);
    else if(type==4) this->setType(Rectangle);
    else if(type==5) this->setType(ReverseTriangle);
    else if(type==6) this->setType(RJoin);
    else if(type==7) this->setType(LJoin);
    else if(type==8) this->setType(Join);
    else this->setType(Strange);
}

int TicTacButton::getType(Type t) {
    if(t==Blank) return 0;
    else if(t==Circle) return 1;
    else if(t==Cross) return 2;
    else if(t==Triangle) return 3;
    else if(t==Rectangle) return 4;
    else if(t==ReverseTriangle) return 5;
    else if(t==RJoin) return 6;
    else if(t==LJoin) return 7;
    else if(t==Join) return 8;
    else return 9; // if t==Strange
}


// --------------------------------------------------------------------------
// Creates a game board with N x N buttons and connects the "clicked()"
// signal of all buttons to the "buttonClicked()" slot.
TicTacGameBoard::TicTacGameBoard( int n, QWidget *parent, const char *name ) : QWidget( parent, name ) {
    QTime t = QTime::currentTime();		// set random seed
    srand( t.hour()*12+t.minute()*60+t.second()*60 );

    st = Init;					// initial state
    nBoard = n;
    comp_starts = FALSE;			// human starts
    buttons = new TicTacButtons(n*n);		// create real buttons
    btArray = new TicTacArray(n*n);		// create button model
    QGridLayout * grid = new QGridLayout( this, nBoard, nBoard, 0 );
    QPalette p[]={white,yellow,green,blue,red,black};


    int bs[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,2,0,1,2,1,2,3,0,0,3,1,2,1,2,4,9,3,6,8,0,0,3,6,4,9,7,3,3,7,8,1,0,0,1,2,3,4,5,6,7,8,9,1,0,0,1,2,3,4,5,6,7,8,9,9,0,0,9,2,3,4,5,6,7,8,9,5,0,0,5,7,2,3,1,1,6,1,6,7,0,0,2,3,0,6,6,1,1,3,8,9,0,0,3,1,1,9,5,6,8,5,6,1,0,0,1,2,2,3,3,2,2,7,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int idx = nBoard*i+j;
            TicTacButton *ttb = new TicTacButton( this );
            ttb->setPalette( p[3] );
            ttb->setEnabled( FALSE );
            ttb->setXY(i,j);
            ttb->setType(TicTacButton::Strange);

            connect( ttb, SIGNAL(clicked()), SLOT(buttonClicked()) );
            grid->addWidget(ttb, i, j);
            btArray->at(idx) = TicTacButton::Strange;
            buttons->insert(nBoard*i+j, ttb);
        }
    }
    pb = new BlockInfo[n];
    dx = new int[4];
    dy = new int[4];
    dx[0]=0;dx[1]=0;dx[2]=1;dx[3]=-1;
    dy[0]=1;dy[1]=-1;dy[2]=0;dy[3]=0;
    chk = new int*[SIZE];
    for(int i=0; i<SIZE; i++) {
        chk[i] = new int[SIZE];
    }

}

TicTacGameBoard::~TicTacGameBoard() {
    for(int i=0; i<SIZE; i++) {
        delete chk[i];
    }
    delete chk;
    delete buttons;
    delete btArray;
    delete dx;
    delete dy;
}


// --------------------------------------------------------------------------
// TicTacGameBoard::computerStarts( bool v )
// Computer starts if v=TRUE. The human starts by default.
void TicTacGameBoard::computerStarts( bool v ) {
    comp_starts = v;
}


// --------------------------------------------------------------------------
// TicTacGameBoard::newGame()
// Clears the game board and prepares for a new game
void TicTacGameBoard::newGame() {
    const int bs[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,2,0,1,2,1,2,3,0,0,3,1,2,1,2,4,9,3,6,8,0,0,3,6,4,9,7,3,3,7,8,1,0,0,1,2,3,4,5,6,7,8,9,1,0,0,1,2,3,4,5,6,7,8,9,9,0,0,9,2,3,4,5,6,7,8,9,5,0,0,5,7,2,3,1,1,6,1,6,7,0,0,2,3,0,6,6,1,1,3,8,9,0,0,3,1,1,9,5,6,8,5,6,1,0,0,1,2,2,3,3,2,2,7,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0};

    int idx;
    for(int i=0; i<nBoard; i++) {
        for(int j=0; j<nBoard; j++) {
            idx = i*nBoard+j;
            btArray->at(idx) = bs[idx];
            //shape[i][j]=bs[idx];
        }
    }
    updateButtons();
}


// --------------------------------------------------------------------------
// TicTacGameBoard::buttonClicked()		- SLOT
// This slot is activated when a TicTacButton emits the signal "clicked()",
// i.e. the user has clicked on a TicTacButton.
void BlockInfo::init() {
    t = TicTacButton::Blank;
    //x=-1; y=-1;
    palInfo = 0; //white
    idx=-1;
}

BlockInfo::BlockInfo() {
    this->init();
}


bool TicTacGameBoard::dfsStart(int x, int y, int xe, int ye, int s, int prevDir) {
    bool hasAns = false;
    memset(chk, false, sizeof(chk));
    dfs(x,y,xe,ye,s,prevDir);

        if(hasAns) return true;
    else return false;
}

void TicTacGameBoard::dfs(int x, int y, int xe, int ye, int s, int prevDir) {
    chk[x][y] = true;
    if(x==xe && y==ye) {
        hasAns = true;
        return;
    }

    int nx,ny,ns;
    for(int i=0; i<4; i++) {
        nx = x+dx[i];
        ny = y+dy[i];
        if(prevDir==i) ns=s;
        else ns=s+1;
        if(ns>2) continue;

        if(nx<0||ny<0||nx>=SIZE||ny>=SIZE) continue;
        if(chk[nx][ny]) continue;
        if(btArray->at(nx*nBoard+ny)!=0) {
        //if(shape[nx][ny]!=0) {
            if(nx==xe && ny==ye) {
                dfs(nx,ny,xe,ye,ns,i);
                return ;
            } else continue;
        } else {
            dfs(nx,ny,xe,ye,ns,i);
        }
    }
}

void TicTacGameBoard::buttonClicked() {

    QPalette p[]={white,yellow,green,blue,red,black};
    int idx = buttons->findRef( (TicTacButton*)sender() );
    TicTacButton *b = buttons->at(idx);		// get piece that was pressed

    if(pb->getIdx() != idx) {
        if( (pb->type() == b->type())  &&  (b->type() != TicTacButton::Blank)) {
            //dfs start
            if(dfsStart(pb->getIdx()/nBoard, pb->getIdx()%nBoard, idx/nBoard, idx%nBoard, -1, -1)) {
                //if(dfs .... is true) then,
                btArray->at(idx) = TicTacButton::Blank;
                btArray->at(pb->getIdx()) = TicTacButton::Blank;
                pb->init();
            } else {
                if(pb->getIdx()!=-1) buttons->at(pb->getIdx())->setPalette(p[pb->getPal()]);
            }
        } else {
            //deactivate the previous active button
            if(b->type() != TicTacButton::Blank) b->setPalette(QPalette(0xff39ff));
            if(pb->getIdx()!=-1) buttons->at(pb->getIdx())->setPalette(p[pb->getPal()]);

            pb->setIdx(idx);
            pb->setType(b->type());
            pb->setPal(TicTacButton::getType(b->type())%6);
        }
        updateButtons();
    }
    /*
    //    computerMove();
    int s = checkBoard( btArray );
    if ( s ) {				// any winners yet?
    st = s == TicTacButton::Circle ? HumanWon : ComputerWon;
    emit finished();
    }
    */
}


// --------------------------------------------------------------------------
// TicTacGameBoard::updateButtons()
// Updates all buttons that have changed state
void TicTacGameBoard::updateButtons() {
    int idx;
    QPalette p[]={white,yellow,green,blue,red,black};
    for(int i=0; i<nBoard; i++) {
        for(int j=0; j<nBoard; j++) {
            idx = nBoard*i+j;
            if(buttons->at(idx)->type() != btArray->at(idx)) {
                buttons->at(idx)->setType( btArray->at(idx) );
                buttons->at(idx)->setPalette( p[(btArray->at(idx))%6]);
            }
            buttons->at(idx)->setEnabled(TRUE);
        }
    }
}

// --------------------------------------------------------------------------
// TicTacGameBoard::checkBoard()
//
// Checks if one of the players won the game, works for any board size.
// Returns:
//  - TicTacButton::Cross  if the player with X buttons won
//  - TicTacButton::Circle if the player with O buttons won
//  - Zero (0) if there is no winner yet
int TicTacGameBoard::checkBoard( TicTacArray *a )
{
    int  t = 0;
    int  row, col;
    bool won = FALSE;
    for ( row=0; row<nBoard && !won; row++ ) {	// check horizontal
        t = a->at(row*nBoard);
        if ( t == TicTacButton::Blank )
            continue;
        col = 1;
        while ( col<nBoard && a->at(row*nBoard+col) == t )
            col++;
        if ( col == nBoard )
            won = TRUE;
    }
    for ( col=0; col<nBoard && !won; col++ ) {	// check vertical
        t = a->at(col);
        if ( t == TicTacButton::Blank )
            continue;
        row = 1;
        while ( row<nBoard && a->at(row*nBoard+col) == t )
            row++;
        if ( row == nBoard )
            won = TRUE;
    }
    if ( !won ) {				// check diagonal top left
        t = a->at(0);				//   to bottom right
        if ( t != TicTacButton::Blank ) {
            int i = 1;
            while ( i<nBoard && a->at(i*nBoard+i) == t )
                i++;
            if ( i == nBoard )
                won = TRUE;
        }
    }
    if ( !won ) {				// check diagonal bottom left
        int j = nBoard-1;			//   to top right
        int i = 0;
        t = a->at(i+j*nBoard);
        if ( t != TicTacButton::Blank ) {
            i++; j--;
            while ( i<nBoard && a->at(i+j*nBoard) == t ) {
                i++; j--;
            }
            if ( i == nBoard )
                won = TRUE;
        }
    }
    if ( !won )					// no winner
        t = 0;
    return t;
}

//***************************************************************************
//* TicTacToe member functions
//***************************************************************************

// --------------------------------------------------------------------------
// Creates a game widget with a game board and two push buttons, and connects
// signals of child widgets to slots.
TicTacToe::TicTacToe( int boardSize, QWidget *parent, const char *name ) : QWidget( parent, name ) {
    QVBoxLayout *l = new QVBoxLayout( this, 6 );

    // Create a message label
    message = new QLabel( this );
    message->setFrameStyle( QFrame::WinPanel | QFrame::Sunken );
    message->setAlignment( AlignCenter );
    l->addWidget( message );

    // Create the game board and connect the signal finished() to this
    // gameOver() slot
    board = new TicTacGameBoard( boardSize, this );
    connect( board, SIGNAL(finished()), SLOT(gameOver()) );
    l->addWidget( board );

    // Create a horizontal frame line
    QFrame *line = new QFrame( this );
    line->setFrameStyle( QFrame::HLine | QFrame::Sunken );
    l->addWidget( line );

    // Create the combo box for deciding who should start, and
    // connect its clicked() signals to the buttonClicked() slot
    /*
       whoStarts = new QComboBox( this );
       whoStarts->insertItem( "Computer starts" );
       whoStarts->insertItem( "Human starts" );
       l->addWidget( whoStarts );
       */

    // Create the push buttons and connect their clicked() signals
    // to this right slots.
    newGame = new QPushButton( "New Game!", this );
    connect( newGame, SIGNAL(clicked()), SLOT(newGameClicked()) );
    quit = new QPushButton( "Quit", this );
    connect( quit, SIGNAL(clicked()), qApp, SLOT(quit()) );
    QHBoxLayout *b = new QHBoxLayout;
    l->addLayout( b );
    b->addWidget( newGame );
    b->addWidget( quit );

    newState();
}


// --------------------------------------------------------------------------
// TicTacToe::newGameClicked()			- SLOT
// This slot is activated when the new game button is clicked.
void TicTacToe::newGameClicked() {
    //board->computerStarts( whoStarts->currentItem() == 0 );
    board->newGame();
    newState();
}


// --------------------------------------------------------------------------
// TicTacToe::gameOver()			- SLOT
// This slot is activated when the TicTacGameBoard emits the signal
// "finished()", i.e. when a player has won or when it is a draw.
void TicTacToe::gameOver() {
    newState();					// update text box
}


// --------------------------------------------------------------------------
// Updates the message to reflect a new state.
void TicTacToe::newState() {
    static const char *msg[] = {		// TicTacGameBoard::State texts
        "Click Play to start", "Make your move",
        "You won!", "Computer won!", "It's a draw" };
    message->setText( msg[board->state()] );
    return;
}
