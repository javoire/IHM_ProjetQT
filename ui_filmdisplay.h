/********************************************************************************
** Form generated from reading UI file 'filmdisplay.ui'
**
** Created: Fri May 11 22:10:47 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILMDISPLAY_H
#define UI_FILMDISPLAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilmDisplay
{
public:
    QLabel *labelTitle;
    QFrame *line;
    QLabel *label;
    QLabel *labelRating;
    QLabel *label_2;
    QLabel *labelGenre;
    QLabel *label_3;
    QLabel *labelLength;
    QFrame *line_2;
    QFrame *line_3;
    QPushButton *buttonClose;

    void setupUi(QWidget *FilmDisplay)
    {
        if (FilmDisplay->objectName().isEmpty())
            FilmDisplay->setObjectName(QString::fromUtf8("FilmDisplay"));
        FilmDisplay->resize(561, 220);
        labelTitle = new QLabel(FilmDisplay);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setGeometry(QRect(10, 20, 541, 61));
        labelTitle->setStyleSheet(QString::fromUtf8("font:bold 23pt \"Helvetica\";"));
        line = new QFrame(FilmDisplay);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 70, 541, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(FilmDisplay);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 90, 51, 21));
        labelRating = new QLabel(FilmDisplay);
        labelRating->setObjectName(QString::fromUtf8("labelRating"));
        labelRating->setGeometry(QRect(60, 90, 21, 21));
        labelRating->setStyleSheet(QString::fromUtf8("font:bold 12pt \"Helvetica\";"));
        label_2 = new QLabel(FilmDisplay);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 130, 51, 21));
        labelGenre = new QLabel(FilmDisplay);
        labelGenre->setObjectName(QString::fromUtf8("labelGenre"));
        labelGenre->setGeometry(QRect(60, 130, 491, 21));
        labelGenre->setStyleSheet(QString::fromUtf8("font:bold 12pt \"Helvetica\";"));
        label_3 = new QLabel(FilmDisplay);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 90, 61, 21));
        labelLength = new QLabel(FilmDisplay);
        labelLength->setObjectName(QString::fromUtf8("labelLength"));
        labelLength->setGeometry(QRect(150, 90, 191, 21));
        labelLength->setStyleSheet(QString::fromUtf8("font:bold 12pt \"Helvetica\";"));
        line_2 = new QFrame(FilmDisplay);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 110, 541, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(FilmDisplay);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 150, 541, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        buttonClose = new QPushButton(FilmDisplay);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));
        buttonClose->setGeometry(QRect(10, 170, 541, 41));

        retranslateUi(FilmDisplay);

        QMetaObject::connectSlotsByName(FilmDisplay);
    } // setupUi

    void retranslateUi(QWidget *FilmDisplay)
    {
        FilmDisplay->setWindowTitle(QApplication::translate("FilmDisplay", "Form", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("FilmDisplay", "Title", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FilmDisplay", "Rating:", 0, QApplication::UnicodeUTF8));
        labelRating->setText(QApplication::translate("FilmDisplay", "5", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FilmDisplay", "Genre:", 0, QApplication::UnicodeUTF8));
        labelGenre->setText(QApplication::translate("FilmDisplay", "Horror, Drama, Comedy, Adult", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FilmDisplay", "Length:", 0, QApplication::UnicodeUTF8));
        labelLength->setText(QApplication::translate("FilmDisplay", "120 min", 0, QApplication::UnicodeUTF8));
        buttonClose->setText(QApplication::translate("FilmDisplay", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FilmDisplay: public Ui_FilmDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILMDISPLAY_H
