#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    proc.setReadChannelMode(QProcess::MergedChannels);
    //connect(&proc, SIGNAL(readyRead()), this, SLOT(on_readyRead()));
    connect(&proc, SIGNAL(readyReadStandardOutput()), this, SLOT(on_readyRead()));
    connect(&proc, SIGNAL(readyReadStandardError()), this, SLOT(on_readyRead()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rubBtn_clicked()
{
    QStringList command = ui->cmdEdit->text().split(" ");
    QString cmd = command[0];
    command.pop_front();
    proc.start(cmd, command);
    //proc.execute(cmd, command);
}

void MainWindow::on_readyRead()
{
    QByteArray res = proc.readAll();
    ui->out->append(QString(res));
}
