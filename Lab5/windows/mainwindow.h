#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void style();       //стилізація вікна

private slots:
        // слот кнопки ButtonStart початок нової гри(відкриває вікно GameWindow)
    void on_ButtonStart_clicked();

        // слот кнопки ButtonEnd закриття програми
    void on_ButtonEnd_clicked();

        //слот кнопки ButtonDownload відкриття вікна загрузки гри (DownloadWindow)
    void on_ButtonDownload_clicked();

    void on_ButtonRules_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
