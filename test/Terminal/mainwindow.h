#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_rubBtn_clicked();

    void on_readyRead();

private:
    Ui::MainWindow *ui;

    QProcess proc;
};

#endif // MAINWINDOW_H
