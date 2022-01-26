#include "fileworker.h"
#include <iostream>

QString FileWorker::filename = "";
QString FileWorker::path = "\Saves\\";
QString FileWorker::type_file = ".txt";

FileWorker::FileWorker()
{

}
QString FileWorker::get_filename()
{
    return filename;
}
QString FileWorker::get_path()
{
    return path;
}
void FileWorker::set_filename(QString fname)
{
    filename = fname;
}
void FileWorker::set_path(QString fpath)
{
    path = fpath;
}

string FileWorker::all_name_file()
{
    string all_filename;

    string str_path = path.toStdString();
    string str_filename = filename.toStdString();
    string str_type = type_file.toStdString();
    all_filename = str_path + str_filename + str_type;

    return all_filename;
}

QStringList FileWorker::list_files()
{
    QDir directory(FileWorker::get_path());
    QStringList files = directory.entryList(QStringList() << "*.txt" << "*.txt",QDir::Files);

    return files;
}

bool FileWorker::is_already_file(QString fname)
{
    bool file_exist = false;
    QStringList files = FileWorker::list_files();
    foreach(QString filename, files)
    {
        if (filename == fname + type_file)
        {
            file_exist = true;
            break;
        }
    }
    return file_exist;
}
void FileWorker::remove_file(QString fname)
{
    QString all_fname = path + fname + type_file;
    QDir dir;
    dir.remove(all_fname);
}

void FileWorker::save_game_file(bool game_with_pc, bool computer_first, int difficulty, int current_player, bool finished, bool player_win, Board& board)
{
    ofstream fout;
    fout.open(all_name_file());

    fout << "Domineering" << "\n";

    fout << game_with_pc << "\n";
    fout << computer_first << "\n";
    fout <<  difficulty << "\n";
    fout <<  current_player << "\n";

    fout <<  finished << "\n";
    fout <<  player_win << "\n";

    fout << board.get_amount_point_side() << " " << board.get_size() << "\n";
    for(int i =0; i < board.get_size(); i++)
    {
        fout << board.get_index_edj_cells(i) << ":" << board.get_number_player_cells(i) << " ";
    }

    fout.close();
}

void FileWorker::download_game_file(bool& game_with_pc, bool& computer_first, int& difficulty, int& current_player, bool& finished, bool& player_win, Board& board)
{
    ifstream fin;
    fin.open(all_name_file());

    string read_str;
    fin >> read_str;
    if (read_str == "Domineering")
    {

        fin >> read_str;
        game_with_pc = stoi(read_str);

        fin >> read_str;
        computer_first = stoi(read_str);

        fin >> read_str;
        difficulty = stoi(read_str);

        fin >> read_str;
        current_player = stoi(read_str);

        fin >> read_str;
        finished = stoi(read_str);

        fin >> read_str;
        player_win = stoi(read_str);


        fin >> read_str;
        board.set_amount_side(stoi(read_str));

        typeVec cells;
        input_cells(fin, cells);

        board.set_size(cells.size());
        board.set_board(cells);
    }
    fin.close();
}

void FileWorker::input_cells(ifstream& fin, typeVec& cells)
{
    int pos;
    int adj;
    int own;
    string buf;
    string read_str;

    fin >> read_str;
    int amount_cells = stoi(read_str);
    for(int i =0; i< amount_cells; i++)
    {
        fin >> read_str;
        pos = read_str.find(":");

        buf = read_str;
        buf = buf.substr(0, pos);
        adj = stoi(buf);

        buf = read_str;
        buf = buf.substr(pos+1, buf.size() - pos - 1);
        own = stoi(buf);

        cells.push_back(pair<int,int>(adj,own));
    }
}
