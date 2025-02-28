#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectTimer = new QTimer(this);

    connect(objectTimer, &QTimer::timeout, this, &MainWindow::timeout);

    connect(ui->btnSet120, &QPushButton::clicked, this, &MainWindow::setGameTime120);
    connect(ui->btnSet300, &QPushButton::clicked, this, &MainWindow::setGameTime300);

    connect(ui->btnStart, &QPushButton::clicked, this, &MainWindow::on_btnStart_clicked);

    connect(ui->btnSwitchPlayer1, &QPushButton::clicked, this, &MainWindow::switchPlayer1);
    connect(ui->btnSwitchPlayer2, &QPushButton::clicked, this, &MainWindow::switchPlayer2);

    connect(ui->btnStop, &QPushButton::clicked, this, &MainWindow::on_btnStop_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectTimer;
    objectTimer=nullptr;
}
void MainWindow::setGameTime120()
{
    gameTime=120;
    player1Time=player2Time=gameTime;
    x=0;
    updateProgressbar();
    setGameInfoText("Peliaika 120 sekuntia. paina START GAME",14);

}

void MainWindow::setGameTime300()
{
    gameTime=300;
    player1Time=player2Time=gameTime;
    x=0;
    updateProgressbar();
    setGameInfoText("Peliaika 300 sekuntia. paina START GAME",14);

}


void MainWindow::on_btnStart_clicked()
{
    if(gameTime==0){
        setGameInfoText("Valitse peliaika",14);
        return;
    }
    if (!objectTimer->isActive()) {
        if (currentPlayer == 1) {
            player1Time = gameTime;
            player2Time = gameTime;
            setGameInfoText("Pelaaja 1 aloittaa", 14);
        } else if (currentPlayer == 2) {
            player1Time = gameTime;
            player2Time = gameTime;
            setGameInfoText("Pelaaja 2 aloittaa", 14);
        }
        objectTimer->start(1000);  // Aloitetaan ajastin
    }
}

void MainWindow::on_btnStop_clicked()
{
    objectTimer->stop();
    setGameInfoText("Peli pysaytetty",14);

    player1Time=player2Time=gameTime; //nollataan ajat
    updateProgressbar();
}

void MainWindow::switchPlayer1()
{
    if(gameTime==0){
        setGameInfoText("Aloita peli",14);
        return;
    }
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    setGameInfoText("Vuoro vaihdettu",14);

    if (!objectTimer->isActive()) {
        objectTimer->start(1000);

    }
}
void MainWindow::switchPlayer2()
{
    if(gameTime==0){
        setGameInfoText("Aloita peli",14);
        return;
    }
    currentPlayer = (currentPlayer == 2) ? 1 : 2;
    setGameInfoText("Vuoro vaihdettu",14);

    if (!objectTimer->isActive()) {
        objectTimer->start(1000);

    }
}
void MainWindow::timeout()
{
    if(currentPlayer==1){
        if(player1Time>0){
            player1Time--;
        }
    }else if(currentPlayer==2){
        if(player2Time>0){
            player2Time--;
    }
}
    updateProgressbar();

    if(player1Time==0||player2Time==0){
        objectTimer->stop();
        setGameInfoText("Peli paattyi.",14);
    }
}

    void MainWindow::updateProgressbar()
    {
        int player1progress = static_cast<int>((static_cast<float>(player1Time) / gameTime) * 100);
        ui->progressBarPlayer1->setValue(player1progress);



        int player2progress= static_cast<int>((static_cast<float>(player2Time)/gameTime)*100);
        ui->progressBarPlayer2->setValue(player2progress);

    }

    void MainWindow::setGameInfoText(QString text, short size)
    {
        ui->label->setText(text);
        QFont font = ui->label->font();
        font.setPointSize(size);
        ui->label->setFont(font);
    }
