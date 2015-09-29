#include <QApplication>
#include <QHBoxLayout>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QLineEdit>
#include <QPushButton>
#include <QSignalMapper>

#include <iostream>

#include <mainwindow.h>
#include "./test.h"
#include "./directoryoperation.h"


void function() {
    // std::cout << ledit->text().toStdString() << std::endl;
    std::cout << "test" << std::endl;
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    DirectoryOPeration dirOperation("D:\\Qt\\project\\widget_test\\log");
    dirOperation.iteratorDirectory();
    /*
    MainWindow *main = new MainWindow;
    main->show();
    */
  //   QWidget *pwin = new QWidget;
  //   pwin->setWindowTitle("ENTER YOU AGE");
  //   pwin->show();
  //
  //   QLineEdit *ledit = new QLineEdit;
  //   ledit->setParent(pwin);
  //   ledit->show();
  //
  //   QPushButton *pbtn = new QPushButton("push");
  //   pbtn->setParent(pwin);
  //   pbtn->setGeometry(50, 50, 100, 100);
  //   pbtn->show();
  //
  //   TEST *pt = new TEST;
  //   // QObject::connect(pbtn, SIGNAL(clicked(bool)), pt, SLOT(someSlots()));
  //
  //   QSignalMapper *psm = new QSignalMapper(pt);
  //   QObject::connect(pbtn, SIGNAL(clicked(bool)), psm, SLOT(map()));
  //   //psm->setMapping(pbtn, "success");
  //   //QObject::connect(psm, SIGNAL(mapped(QString)), pt, SLOT(someSlots(QString)));
  //   psm->setMapping(pbtn, (QObject *)ledit);
  //   QObject::connect(psm, SIGNAL(mapped(QObject*)), pt, SLOT(someSlots(QObject*)));
  //
  //
  //   QMainWindow mainwindow;
  //   mainwindow.show();


    return app.exec();
}
