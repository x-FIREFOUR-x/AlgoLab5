#ifndef WINDOWSWORKER_H
#define WINDOWSWORKER_H

class MainWindow;
class PresettingWindow;
class GameWindow;
//class WindowRules;
class SaveWindow;
class DownloadWindow;

#include "gamewindow.h"
#include "mainwindow.h"
#include "presettingwindow.h"
//#include "windowrules.h"
#include "savewindow.h"
#include "downloadwindow.h"

class WindowsWorker
{
private:
            //вказівники на відповідні вікна
    static MainWindow* window_main;
    static PresettingWindow* window_presetting;
    static GameWindow* window_game;
   // static WindowRules* window_rules;
    static SaveWindow* window_save;
    static DownloadWindow* window_download;

public:
    WindowsWorker();

    static MainWindow* get_MainWindow();
    static PresettingWindow* get_PresettingWindow();
    static GameWindow* get_GameWindow();
    //static WindowRules* get_WindowRules();



            // методи закриття і відкриття відповідних вікон

    static void open_MainWindow();
    static void close_MainWindow();

    static void open_PresettingWindow();
    static void close_PresettingWindow();

    static void open_GameWindow();
    static void open_GameWindow(bool g_with_pc);
    static void open_GameWindow(bool g_with_pc, bool pc_first, int level_dif);
    static void close_GameWindow();

    static void open_WindowRules();
    static void close_WindowRules();

    static void open_SaveWindow();
    static void close_SaveWindow();

    static void open_DownloadWindow();
    static void close_DownloadWindow();



            //методи приховання і показу вікна WindowGame
    static void hide_WindowGame();
    static void show_WindowGame();
};

#endif // WINDOWSWORKER_H
