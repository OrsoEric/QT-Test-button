//This is trickier than it looks.
//>The handler has to be declared as private slot:
//>The class that do the connect must inherit QMainWindow
//>Generating own signals (not the case here) requires the macro Q_OBJECT
//>QT uses it's own string class. You need to use bridge class to make it compatible with c++ std::string class.
//>QT by default makes a stupid number of build folders. To stop it
//  Project(left tabs) -> build settings -> uncheck "shadow build"
//PROBLEM: standalone exe won't start on it's own. It seems it's a bug with 64b version of QT. What a mess.
//https://forum.qt.io/topic/32797/solved-the-application-was-unable-to-start-correctly-0xc000007b
//
//In general you can access to the controls with ui-> that works well. I like it a lot!


#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QCoreApplication>

//Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Very dark magic
    ui->setupUi(this);

    //Initialize private vars
    g_cnt = 0;

    //Setup text control content
    ui->txt1->setText("0");

    //Test call button handler
    //btn1_handler();

    //Very dark magic.
    connect(ui->btn1, SIGNAL(released()), this, SLOT(btn1_handler()));
}

//Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

//Handler of button press
//CARE!!! This has to be a private slot:
void MainWindow::btn1_handler( void )
{
        ///Local Vars
    //declare a c++ string variable
    std::string str;
    //Declare a QT string variable
    QString qstr;

        ///Body
    //Increment private var. It's my counter for the increment
    g_cnt++;
    //Convert from number to a c++ string
    str = std::to_string( g_cnt );
    //Convert from c++ string to QT string
    qstr = QString::fromStdString(str);

        ///Update Text Control
    //Update the text control with the string I just created
    ui->txt1->setText(qstr);

    return;
    //A magic moment here str and qstr are deleted
}
