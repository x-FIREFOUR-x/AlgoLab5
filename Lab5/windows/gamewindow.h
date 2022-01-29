#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QLabel>
#include "logic/gameboard.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::GameWindow *ui;  //Покажчик на інтерфейс вікна

    GameBoard* game_board;  //ігрове поле графічний віджет

public:
        // конструктор створення вікна гри для 2 гравців
    explicit GameWindow(bool g_with_pc, QWidget *parent = nullptr);
        // конструктор створення вікна гри для гри з пк із передачею параметрів
    explicit GameWindow(bool g_with_pc, bool pc_first, int level_dif, QWidget *parent = nullptr);

    explicit GameWindow( QWidget *parent = nullptr);
    ~GameWindow();

    void save_game();               //функція передачі в FileWorker необхідних параметрів збереження гри
    void download_game();           //функція отримання від FileWorker необхідних параметрів збереження гри

private:
    void style();       //стилізація вікна

private slots:
        // слот в menu_bar "Зікінчити гру" закриває вікно GameWindow і повертається MainWindow
    void on_CloseEnd_triggered();
        // слот в menu_bar "Зберегти як" ховає вікно GameWindow і відкриває вікно SaveWindow
    void on_SaveAs_triggered();
        // слот в menu_bar "Зберегти" зберігає дані в встановлений файл або ховає вікно GameWindow і відкриває вікно SaveWindow , якщо файл сейву не встановлений
    void on_Save_triggered();
    void on_Rules_triggered();
};

#endif // GAMEWINDOW_H
