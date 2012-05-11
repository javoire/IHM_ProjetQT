/********************************************************************************
** Form generated from reading UI file 'filterform.ui'
**
** Created: Fri May 11 21:56:46 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERFORM_H
#define UI_FILTERFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterForm
{
public:
    QGraphicsView *graphicsView;
    QGroupBox *groupBoxTitle;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelYearMin;
    QLabel *fromto;
    QLabel *labelYearMax;
    QWidget *layoutWidget1;
    QVBoxLayout *yearSliderLayout;
    QFrame *line;
    QFrame *line_2;
    QWidget *layoutWidget2;
    QVBoxLayout *checkBoxesLeft;
    QWidget *layoutWidget_2;
    QVBoxLayout *checkBoxesRight;
    QPushButton *Search;
    QFrame *frame;
    QLineEdit *titleInput;
    QFrame *titleLine;
    QLabel *titel;
    QLabel *descr;
    QTextBrowser *textBrowser;
    QLabel *titleLabel;
    QFrame *line_3;
    QPushButton *buttonPopup;

    void setupUi(QWidget *FilterForm)
    {
        if (FilterForm->objectName().isEmpty())
            FilterForm->setObjectName(QString::fromUtf8("FilterForm"));
        FilterForm->resize(960, 570);
        graphicsView = new QGraphicsView(FilterForm);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 711, 531));
        groupBoxTitle = new QGroupBox(FilterForm);
        groupBoxTitle->setObjectName(QString::fromUtf8("groupBoxTitle"));
        groupBoxTitle->setGeometry(QRect(730, 140, 221, 401));
        QFont font;
        font.setFamily(QString::fromUtf8("Helvetica"));
        font.setPointSize(13);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        groupBoxTitle->setFont(font);
        groupBoxTitle->setStyleSheet(QString::fromUtf8(""));
        groupBoxTitle->setFlat(false);
        groupBoxTitle->setCheckable(false);
        layoutWidget = new QWidget(groupBoxTitle);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 90, 201, 21));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelYearMin = new QLabel(layoutWidget);
        labelYearMin->setObjectName(QString::fromUtf8("labelYearMin"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Myriad Pro"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        labelYearMin->setFont(font1);
        labelYearMin->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Myriad Pro\";\n"
"color: rgb(88, 88, 88);"));

        horizontalLayout->addWidget(labelYearMin);

        fromto = new QLabel(layoutWidget);
        fromto->setObjectName(QString::fromUtf8("fromto"));
        fromto->setLayoutDirection(Qt::RightToLeft);
        fromto->setAutoFillBackground(false);
        fromto->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Myriad Pro\";\n"
"color: rgb(88, 88, 88);"));
        fromto->setTextFormat(Qt::RichText);
        fromto->setScaledContents(false);
        fromto->setAlignment(Qt::AlignCenter);
        fromto->setMargin(0);
        fromto->setOpenExternalLinks(false);

        horizontalLayout->addWidget(fromto);

        labelYearMax = new QLabel(layoutWidget);
        labelYearMax->setObjectName(QString::fromUtf8("labelYearMax"));
        labelYearMax->setLayoutDirection(Qt::RightToLeft);
        labelYearMax->setAutoFillBackground(false);
        labelYearMax->setStyleSheet(QString::fromUtf8("font: italic 9pt \"Myriad Pro\";\n"
"color: rgb(88, 88, 88);"));
        labelYearMax->setTextFormat(Qt::RichText);
        labelYearMax->setScaledContents(false);
        labelYearMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelYearMax->setMargin(0);
        labelYearMax->setOpenExternalLinks(false);

        horizontalLayout->addWidget(labelYearMax);

        layoutWidget1 = new QWidget(groupBoxTitle);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 60, 201, 21));
        yearSliderLayout = new QVBoxLayout(layoutWidget1);
        yearSliderLayout->setSpacing(2);
        yearSliderLayout->setContentsMargins(11, 11, 11, 11);
        yearSliderLayout->setObjectName(QString::fromUtf8("yearSliderLayout"));
        yearSliderLayout->setSizeConstraint(QLayout::SetFixedSize);
        yearSliderLayout->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(groupBoxTitle);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 40, 201, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(groupBoxTitle);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 110, 201, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        layoutWidget2 = new QWidget(groupBoxTitle);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 130, 101, 221));
        checkBoxesLeft = new QVBoxLayout(layoutWidget2);
        checkBoxesLeft->setSpacing(6);
        checkBoxesLeft->setContentsMargins(11, 11, 11, 11);
        checkBoxesLeft->setObjectName(QString::fromUtf8("checkBoxesLeft"));
        checkBoxesLeft->setContentsMargins(0, 0, 0, 0);
        layoutWidget_2 = new QWidget(groupBoxTitle);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(110, 130, 101, 221));
        checkBoxesRight = new QVBoxLayout(layoutWidget_2);
        checkBoxesRight->setSpacing(6);
        checkBoxesRight->setContentsMargins(11, 11, 11, 11);
        checkBoxesRight->setObjectName(QString::fromUtf8("checkBoxesRight"));
        checkBoxesRight->setContentsMargins(0, 0, 0, 0);
        Search = new QPushButton(groupBoxTitle);
        Search->setObjectName(QString::fromUtf8("Search"));
        Search->setGeometry(QRect(0, 360, 221, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Myriad Pro"));
        font2.setPointSize(14);
        Search->setFont(font2);
        Search->setCursor(QCursor(Qt::PointingHandCursor));
        Search->setLayoutDirection(Qt::LeftToRight);
        Search->setDefault(false);
        Search->setFlat(false);
        frame = new QFrame(groupBoxTitle);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 201, 31));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        titleInput = new QLineEdit(frame);
        titleInput->setObjectName(QString::fromUtf8("titleInput"));
        titleInput->setEnabled(true);
        titleInput->setGeometry(QRect(0, 0, 201, 31));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleInput->sizePolicy().hasHeightForWidth());
        titleInput->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Myriad Pro"));
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setItalic(true);
        font3.setWeight(50);
        titleInput->setFont(font3);
        titleInput->setAutoFillBackground(false);
        titleInput->setStyleSheet(QString::fromUtf8("font: italic 20pt \"Myriad Pro\";\n"
"color: rgb(88, 88, 88);\n"
"background-color: rgb(252, 252, 252, 0);\n"
"border-color: rgb(107, 107, 107);"));
        titleInput->setFrame(false);
        titleLine = new QFrame(FilterForm);
        titleLine->setObjectName(QString::fromUtf8("titleLine"));
        titleLine->setGeometry(QRect(750, 60, 181, 21));
        titleLine->setFrameShape(QFrame::HLine);
        titleLine->setFrameShadow(QFrame::Sunken);
        titel = new QLabel(FilterForm);
        titel->setObjectName(QString::fromUtf8("titel"));
        titel->setGeometry(QRect(730, 10, 221, 81));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Helvetica"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        titel->setFont(font4);
        titel->setStyleSheet(QString::fromUtf8("font: oblique bold 20pt \"Helvetica\";"));
        titel->setScaledContents(false);
        titel->setAlignment(Qt::AlignCenter);
        descr = new QLabel(FilterForm);
        descr->setObjectName(QString::fromUtf8("descr"));
        descr->setGeometry(QRect(740, 80, 201, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Helvetica"));
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        descr->setFont(font5);
        descr->setStyleSheet(QString::fromUtf8("font: 10pt \"Helvetica\";"));
        descr->setAlignment(Qt::AlignCenter);
        descr->setWordWrap(true);
        textBrowser = new QTextBrowser(FilterForm);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 540, 701, 21));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        titleLabel = new QLabel(FilterForm);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(740, 130, 59, 16));
        titleLabel->setStyleSheet(QString::fromUtf8("font:oblique 8pt \"Myriad Pro\";"));
        line_3 = new QFrame(FilterForm);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(770, 130, 171, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        buttonPopup = new QPushButton(FilterForm);
        buttonPopup->setObjectName(QString::fromUtf8("buttonPopup"));
        buttonPopup->setGeometry(QRect(140, 80, 92, 27));

        retranslateUi(FilterForm);

        QMetaObject::connectSlotsByName(FilterForm);
    } // setupUi

    void retranslateUi(QWidget *FilterForm)
    {
        FilterForm->setWindowTitle(QApplication::translate("FilterForm", "FilterForm", 0, QApplication::UnicodeUTF8));
        groupBoxTitle->setTitle(QString());
        labelYearMin->setText(QApplication::translate("FilterForm", "TextLabel", 0, QApplication::UnicodeUTF8));
        fromto->setText(QApplication::translate("FilterForm", "from - to", 0, QApplication::UnicodeUTF8));
        labelYearMax->setText(QApplication::translate("FilterForm", "TextLabel ", 0, QApplication::UnicodeUTF8));
        Search->setText(QApplication::translate("FilterForm", "Search", 0, QApplication::UnicodeUTF8));
        titleInput->setProperty("placeholderText", QVariant(QApplication::translate("FilterForm", "Title...", 0, QApplication::UnicodeUTF8)));
        titel->setText(QApplication::translate("FilterForm", "TheFilmUniverse", 0, QApplication::UnicodeUTF8));
        descr->setText(QApplication::translate("FilterForm", "Use the fields below to find the perfect film to see tonight", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("FilterForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Myriad Pro'; font-style:italic;\">Developed by: Alan Ferreir\303\263s, Mauricio Takecita Uehara, Jonatan Dahl - \302\2512012 Paris, France</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("FilterForm", "title", 0, QApplication::UnicodeUTF8));
        buttonPopup->setText(QApplication::translate("FilterForm", "Horfitta", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FilterForm: public Ui_FilterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERFORM_H
