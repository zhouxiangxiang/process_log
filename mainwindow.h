#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>

#include <QHBoxLayout>
#include <QSignalMapper>

#include <cstdlib>
#include "./processinginfo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    // void xhanlde();

    void hanldeInput(QObject* ptr);

private:
    Ui::MainWindow  *ui;
    QWidget         *mp_mainWidget;
    QHBoxLayout     *mp_layout;

    QLabel          *mp_labInputfile;
    QLabel          *mp_labOutputfile;
    QLineEdit       *mp_ldtInputfile;
    QLineEdit       *mp_ldtOutputfile;

    QLabel          *mp_labRoomid;
    QLabel          *mp_labInterval;
    QLineEdit       *mp_ldtRoomid;
    QLineEdit       *mp_ldtInterval;

    QPushButton     *mp_btnProcess;
    QSignalMapper   *mp_sgnMapper;
    QPlainTextEdit  *mp_pttConsole;

};

#endif // MAINWINDOW_H
