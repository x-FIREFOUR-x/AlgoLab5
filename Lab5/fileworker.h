#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <QFileDialog>
#include <QString>
#include <vector>
#include <fstream>
#include "board.h"

using namespace std;
using typeVec = vector<pair<int,int>>;
class FileWorker
{
private:
    static QString filename;
    static QString type_file ;
    static QString path;
public:
    FileWorker();

    static QString get_filename();              //отримати ім'я файлу
    static QString get_path();                  //отримати шлях до файлів збереження
    static void set_filename(QString fname);    //встановити ім'я файлу
    static void set_path(QString fpath);        //встановити шлях до файлів збереження

    static QStringList list_files();                //отримати список всіх файлів збереження
    static bool is_already_file(QString fname);     //перевірка чи файл вже існує
    static void remove_file(QString);               //видалення файла

                //зберегти необіхідні парметри в файл
    static void save_game_file(bool game_with_pc, bool computer_first, int difficulty, int current_player, bool finished, bool player_win, Board& board);


                //зчитати необіхідні параметри з файлу
    static void download_game_file(bool& game_with_pc, bool& computer_first, int& difficulty, int& current_player, bool& finished, bool& player_win, Board& board);

private:
    static string all_name_file();                              //весь шлях до файлу
    static void input_cells(ifstream& fin, typeVec& cells);
};

#endif // FILEWORKER_H

