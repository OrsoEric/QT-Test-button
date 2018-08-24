#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    //Dark Magic. A macro that's needed for signals for conenct
    Q_OBJECT

    public:
        //Construtor
        explicit MainWindow(QWidget *parent = 0);
        //Destructor
        ~MainWindow();

    //Very very dark magic. Needed for connect to work
    private slots:
        //Handler for btn1
        void btn1_handler( void );

    private:
        //The controls are all linked here. nice and tidy! I like this
        Ui::MainWindow *ui;
        //counter
        int g_cnt;
};

#endif // MAINWINDOW_H
