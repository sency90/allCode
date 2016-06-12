/****************************************************************************
** Form interface generated from reading ui file 'config.ui'
**
** Created: 금  6월 3 20:49:03 2016
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.2.3   edited May 19 14:22 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONFIG_H
#define CONFIG_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class GammaView;
class QButtonGroup;
class QRadioButton;
class QPushButton;
class QCheckBox;
class QGroupBox;
class QLabel;
class QSlider;
class QSpinBox;
class QComboBox;

class Config : public QDialog
{
    Q_OBJECT

public:
    Config( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Config();

    QButtonGroup* ButtonGroup2;
    QRadioButton* depth_1;
    QRadioButton* depth_4gray;
    QRadioButton* depth_8;
    QRadioButton* depth_12;
    QRadioButton* depth_16;
    QRadioButton* depth_32;
    QPushButton* buttonOk;
    QPushButton* buttonCancel;
    QCheckBox* touchScreen;
    QGroupBox* GroupBox1;
    QLabel* TextLabel3;
    QSlider* bslider;
    QLabel* blabel;
    QLabel* TextLabel2;
    QSlider* gslider;
    QLabel* glabel;
    QLabel* TextLabel7;
    QLabel* TextLabel8;
    QSlider* gammaslider;
    QLabel* TextLabel1_2;
    QLabel* rlabel;
    QSlider* rslider;
    QPushButton* PushButton3;
    GammaView* MyCustomWidget1;
    QButtonGroup* ButtonGroup1;
    QRadioButton* size_240_320;
    QRadioButton* size_320_240;
    QRadioButton* size_640_480;
    QRadioButton* size_custom;
    QSpinBox* size_width;
    QSpinBox* size_height;
    QRadioButton* size_skin;
    QComboBox* skin;
    QLabel* TextLabel1;

protected:
    QGridLayout* ConfigLayout;
    QHBoxLayout* Layout1;
    QGridLayout* GroupBox1Layout;
    QVBoxLayout* ButtonGroup1Layout;
    QHBoxLayout* Layout1_2;
    QHBoxLayout* Layout8;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // CONFIG_H
