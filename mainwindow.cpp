#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mp_mainWidget = new QWidget;
    mp_layout = new QVBoxLayout;

    mp_btnProcess = new QPushButton("process");

    mp_labInputfile = new QLabel( "INPUT FILENAME");
    mp_labOutputfile = new QLabel("OUTPUT FILENAME");
    mp_ldtInputfile = new QLineEdit();
    mp_ldtOutputfile = new QLineEdit();

    mp_labRoomid =  new QLabel("ROOM ID");
    mp_labInterval = new QLabel("INTERVAL");
    mp_ldtRoomid  = new QLineEdit;
    mp_ldtInterval = new QLineEdit;

    QHBoxLayout* hlayout = new QHBoxLayout;
    hlayout->addWidget(mp_labInputfile);
    hlayout->addWidget(mp_ldtInputfile);
    mp_layout->addLayout(hlayout);

    QHBoxLayout* hlayout_output = new QHBoxLayout;
    hlayout_output->addWidget(mp_labOutputfile);
    hlayout_output->addWidget(mp_ldtOutputfile);
    mp_layout->addLayout(hlayout_output);

    QHBoxLayout* hlayout_room = new QHBoxLayout;
    hlayout_room->addWidget(mp_labRoomid);
    hlayout_room->addWidget(mp_ldtRoomid);
    mp_layout->addLayout(hlayout_room);

    QHBoxLayout* hlayout_interval = new QHBoxLayout;
    hlayout_interval->addWidget(mp_labInterval);
    hlayout_interval->addWidget(mp_ldtInterval);
    mp_layout->addLayout(hlayout_interval);

    QHBoxLayout* hlayout_process = new QHBoxLayout;
    hlayout_process->addWidget(mp_btnProcess);
    mp_layout->addLayout(hlayout_process);

    mp_mainWidget->setLayout(mp_layout);
    setCentralWidget(mp_mainWidget);


    // signal handling.
    mp_sgnMapper = new QSignalMapper(this);
    QObject::connect(mp_btnProcess, SIGNAL(clicked(bool)), mp_sgnMapper, SLOT(map()));
    mp_sgnMapper->setMapping(mp_btnProcess, (QObject *)mp_ldtInputfile);
    QObject::connect(mp_sgnMapper, SIGNAL(mapped(QObject*)), this, SLOT(hanldeInput(QObject*)));

    // fixme
    // QObject::connect(mp_btnProcess, SIGNAL(clicked(bool)), this, SLOT(xhandle()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mp_btnProcess;

    delete mp_labInputfile;
    delete mp_labOutputfile;
    delete mp_ldtInputfile;
    delete mp_ldtOutputfile;

    delete mp_labRoomid;
    delete mp_labInterval;
    delete mp_ldtRoomid;
    delete mp_ldtInterval;

    delete mp_layout;
    delete mp_sgnMapper;

    delete mp_mainWidget;
}

void MainWindow::hanldeInput(QObject* ptr) {
    // QLineEdit * pedit = (QLineEdit*)ptr;
    // lab->setText(pedit->text());
    ProcessingInfo *prInfo = new ProcessingInfo(mp_ldtInputfile->text().toStdString(),
                                                mp_ldtOutputfile->text().toStdString(),
                                                mp_ldtRoomid->text().toStdString(),
                                                atoi(mp_ldtInterval->text().toStdString().c_str()));

    prInfo->startProcess();
    return;
}
