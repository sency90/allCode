
#include <qmouse_qws.h>

//#ifdef _WS_QWS_

#include <qwidget.h>
#include <qpixmap.h>

class QTimer;

class Calibrate : public QWidget
{
    Q_OBJECT
public:
    Calibrate(QWidget* parent=0, const char * name=0, WFlags=0);
    ~Calibrate();

private:
    QPoint fromDevice( const QPoint &p );
    bool sanityCheck();
    void moveCrosshair( QPoint pt );
    void paintEvent( QPaintEvent * );
    void mousePressEvent( QMouseEvent * );
    void mouseReleaseEvent( QMouseEvent * );

private slots:
    void timeout();

private:
    QWSPointerCalibrationData cd;
    QWSPointerCalibrationData::Location location;
    QPoint crossPos;
    QPoint penPos;
    QPixmap saveUnder;
    QTimer *timer;
    int dx;
    int dy;
};

//#endif // _WS_QWS_

