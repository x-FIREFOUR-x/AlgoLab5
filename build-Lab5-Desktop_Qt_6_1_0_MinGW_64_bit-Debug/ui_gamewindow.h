/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "logic/gameboard.h"

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QAction *CloseEnd;
    QAction *SaveAs;
    QAction *Save;
    QAction *Rules;
    QWidget *centralwidget;
    GameBoard *graphicsView;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(500, 550);
        CloseEnd = new QAction(GameWindow);
        CloseEnd->setObjectName(QString::fromUtf8("CloseEnd"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/image/icon/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        CloseEnd->setIcon(icon);
        SaveAs = new QAction(GameWindow);
        SaveAs->setObjectName(QString::fromUtf8("SaveAs"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/image/icon/saveAs.png"), QSize(), QIcon::Normal, QIcon::Off);
        SaveAs->setIcon(icon1);
        Save = new QAction(GameWindow);
        Save->setObjectName(QString::fromUtf8("Save"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/image/icon/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        Save->setIcon(icon2);
        Rules = new QAction(GameWindow);
        Rules->setObjectName(QString::fromUtf8("Rules"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/image/icon/rules.png"), QSize(), QIcon::Normal, QIcon::Off);
        Rules->setIcon(icon3);
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new GameBoard(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 500, 500));
        GameWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(GameWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GameWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(GameWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        GameWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(CloseEnd);
        menu->addAction(SaveAs);
        menu->addAction(Save);
        menu->addAction(Rules);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "MainWindow", nullptr));
        CloseEnd->setText(QCoreApplication::translate("GameWindow", "\320\227\320\260\320\272\321\200\320\270\321\202\320\270 \320\263\321\200\321\203", nullptr));
        SaveAs->setText(QCoreApplication::translate("GameWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \321\217\320\272", nullptr));
        Save->setText(QCoreApplication::translate("GameWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270", nullptr));
        Rules->setText(QCoreApplication::translate("GameWindow", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260", nullptr));
        menu->setTitle(QCoreApplication::translate("GameWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
