/********************************************************************************
** Form generated from reading UI file 'windowrules.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWRULES_H
#define UI_WINDOWRULES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowRules
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *NumberPage;
    QPushButton *PreviousPageButton;
    QPushButton *NextPageButton;
    QPushButton *CloseRuleButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WindowRules)
    {
        if (WindowRules->objectName().isEmpty())
            WindowRules->setObjectName(QString::fromUtf8("WindowRules"));
        WindowRules->resize(900, 530);
        centralwidget = new QWidget(WindowRules);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 900, 470));
        NumberPage = new QLabel(centralwidget);
        NumberPage->setObjectName(QString::fromUtf8("NumberPage"));
        NumberPage->setGeometry(QRect(430, 470, 40, 40));
        NumberPage->setStyleSheet(QString::fromUtf8("font: 12pt \"MS Shell Dlg 2\";"));
        NumberPage->setLineWidth(1);
        NumberPage->setAlignment(Qt::AlignCenter);
        PreviousPageButton = new QPushButton(centralwidget);
        PreviousPageButton->setObjectName(QString::fromUtf8("PreviousPageButton"));
        PreviousPageButton->setGeometry(QRect(350, 470, 80, 40));
        NextPageButton = new QPushButton(centralwidget);
        NextPageButton->setObjectName(QString::fromUtf8("NextPageButton"));
        NextPageButton->setGeometry(QRect(470, 470, 80, 40));
        CloseRuleButton = new QPushButton(centralwidget);
        CloseRuleButton->setObjectName(QString::fromUtf8("CloseRuleButton"));
        CloseRuleButton->setGeometry(QRect(30, 470, 150, 40));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(560, 470, 321, 31));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Calibri\";font-weight: 560;"));
        label->setAlignment(Qt::AlignCenter);
        WindowRules->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WindowRules);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 26));
        WindowRules->setMenuBar(menubar);
        statusbar = new QStatusBar(WindowRules);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WindowRules->setStatusBar(statusbar);

        retranslateUi(WindowRules);

        QMetaObject::connectSlotsByName(WindowRules);
    } // setupUi

    void retranslateUi(QMainWindow *WindowRules)
    {
        WindowRules->setWindowTitle(QCoreApplication::translate("WindowRules", "MainWindow", nullptr));
        NumberPage->setText(QCoreApplication::translate("WindowRules", "1", nullptr));
        PreviousPageButton->setText(QCoreApplication::translate("WindowRules", "\320\237\320\276\320\277\320\265\321\200\320\265\320\264\320\275\321\217", nullptr));
        NextPageButton->setText(QCoreApplication::translate("WindowRules", "\320\235\320\260\321\201\321\202\321\203\320\277\320\275\320\260", nullptr));
        CloseRuleButton->setText(QCoreApplication::translate("WindowRules", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\320\270\321\201\321\217 \320\275\320\260\320\267\320\260\320\264", nullptr));
        label->setText(QCoreApplication::translate("WindowRules", "\320\240\320\276\320\267\321\200\320\276\320\261\320\275\320\270\320\272: \320\236\320\273\320\265\320\272\321\201\320\260\320\275\320\264\321\200 \320\237\320\260\321\201\320\260\320\273\321\214\321\201\321\214\320\272\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowRules: public Ui_WindowRules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWRULES_H
