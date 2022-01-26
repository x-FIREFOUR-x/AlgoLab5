#include "windowsworker.h"

MainWindow* WindowsWorker::window_main = nullptr;
PresettingWindow* WindowsWorker::window_presetting = nullptr;
GameWindow* WindowsWorker::window_game = nullptr;
WindowRules* WindowsWorker::window_rules = nullptr;
SaveWindow* WindowsWorker::window_save = nullptr;
DownloadWindow* WindowsWorker::window_download = nullptr;


WindowsWorker::WindowsWorker()
{
}




MainWindow* WindowsWorker::get_MainWindow()
{
    return window_main;
}
PresettingWindow* WindowsWorker::get_PresettingWindow()
{
    return window_presetting;
}
GameWindow* WindowsWorker::get_GameWindow()
{
    return window_game;
}

WindowRules* WindowsWorker::get_WindowRules()
{
    return window_rules;
}





void WindowsWorker::open_MainWindow()
{
    window_main = new MainWindow();
    window_main->setWindowTitle("Domineering 8x8");
    window_main->show();
}

void WindowsWorker::close_MainWindow()
{
    window_main->close();
    delete window_main;
    window_main = nullptr;
}


void WindowsWorker::open_PresettingWindow()
{
    window_presetting = new PresettingWindow();
    window_presetting->setWindowTitle("Domineering 8x8");
    window_presetting->show();
}
void WindowsWorker::close_PresettingWindow()
{
    window_presetting->close();
    delete window_presetting;
    window_presetting = nullptr;
}

void WindowsWorker::open_GameWindow()
{
    window_game = new GameWindow();
    window_game->setWindowTitle("Domineering 8x8");
    window_game->show();
}
void WindowsWorker::open_GameWindow(bool g_with_pc)
{
    window_game = new GameWindow(g_with_pc);
    window_game->setWindowTitle("Domineering 8x8");
    window_game->show();
}

void WindowsWorker::open_GameWindow(bool g_with_pc, bool pc_first, int level_dif)
{
    window_game = new GameWindow(g_with_pc, pc_first, level_dif);
    window_game->setWindowTitle("Domineering 8x8");
    window_game->show();
}

void WindowsWorker::close_GameWindow()
{
    window_game->close();
    delete window_game;
    window_game = nullptr;
}



void WindowsWorker::open_WindowRules()
{
    window_rules = new WindowRules();
    window_rules->setWindowTitle("Останній гравець");
    window_rules->show();
}
void WindowsWorker::close_WindowRules()
{
    window_rules->close();
    delete window_rules;
    window_rules = nullptr;
}

void WindowsWorker::open_SaveWindow()
{
    window_save = new SaveWindow();
    window_save->setWindowTitle("Domineering 8x8");
    window_save->show();
}
void WindowsWorker::close_SaveWindow()
{
    window_save->close();
    delete window_save;
    window_save = nullptr;
}

void WindowsWorker::open_DownloadWindow()
{
    window_download = new DownloadWindow();
    window_download->setWindowTitle("Domineering 8x8");
    window_download->show();
}
void WindowsWorker::close_DownloadWindow()
{
    window_download->close();
    delete window_download;
    window_download = nullptr;
}


void WindowsWorker::hide_WindowGame()
{
    window_game->hide();
}
void WindowsWorker::show_WindowGame()
{
    window_game->show();
}
