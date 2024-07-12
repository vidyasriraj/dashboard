/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *connectsym;
    QLabel *connectText;
    QPushButton *menu;
    QPushButton *connectIcon;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1050, 750);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(900, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #071C27, stop:0.95 #000000);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 331, 751));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,30);"));
        frame = new QFrame(widget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 70, 271, 71));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,30);\n"
"border: 2px solid transparent;\n"
"outline: none;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        connectsym = new QLabel(frame);
        connectsym->setObjectName("connectsym");
        connectsym->setMinimumSize(QSize(50, 0));
        connectsym->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(connectsym);

        connectText = new QLabel(frame);
        connectText->setObjectName("connectText");
        connectText->setMinimumSize(QSize(50, 0));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        connectText->setFont(font);

        horizontalLayout->addWidget(connectText);

        menu = new QPushButton(widget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(0, 0, 71, 51));
        menu->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,30);\n"
"border: 2px solid transparent;\n"
"outline: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logos/Menu.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        menu->setIcon(icon);
        menu->setIconSize(QSize(40, 64));
        connectIcon = new QPushButton(widget);
        connectIcon->setObjectName("connectIcon");
        connectIcon->setGeometry(QRect(50, 150, 221, 201));
        connectIcon->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,30);\n"
"border: 2px solid transparent;\n"
"outline: none;"));
        connectIcon->setIconSize(QSize(221, 201));
        connectIcon->setCheckable(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        connectsym->setText(QString());
        connectText->setText(QString());
        menu->setText(QString());
        connectIcon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
