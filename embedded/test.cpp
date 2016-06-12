#include <QLabel>
#include <QLCDNumber>

int main() {
    QLabel *lbl[2];

    lbl[0] = new QLabel("I love Qt programming", this);
    lbl[0]->setGeometry(10, 30, 200, 40);

    QPixmap pix = QPixmap("resources/browser.png");

    lbl[1] = new QLabel(this);
    lbl[1]->setPixmap(pix);
    lbl[1]->setGeometry(10, 70, 100, 100);
    return 0;
}
