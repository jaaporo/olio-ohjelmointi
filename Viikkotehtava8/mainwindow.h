#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timeout();

private slots:

    void on_btnStart_clicked();
    void on_btnStop_clicked();
    void setGameTime120();
    void setGameTime300();
    void switchPlayer1();
    void switchPlayer2();
     void updateProgressbar();
    void setGameInfoText(QString, short fontSize);
private:
    Ui::MainWindow *ui;
    QTimer *objectTimer;

    short x=0;

    short player1Time=0;
    short player2Time=0;
    short currentPlayer=1;
    short gameTime=0;



};

#endif // MAINWINDOW_H
