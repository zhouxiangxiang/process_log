#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <iostream>
#include <QLabel>
#include <QLineEdit>

class TEST   : public QObject {
    Q_OBJECT
public slots:
    // void someSlots(QString str) {
    void someSlots(QObject* ptr) {
        QLabel *lab = new QLabel;
        QLineEdit* ple = (QLineEdit *)ptr;
        lab->setText(ple->text());
        lab->show();
    }
};

#endif // TEST_H

