#include <QApplication>
#include <QLabel>
#include <QPushButton>
int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QLabel lab("<h2><i> Hello </i>"
               "<font color=red> Qt </font> </h2>"
               );
    lab.setFixedSize(500, 300);
    //lab.setGeometry(100, 100, 1000, 500);
    lab.show();

    QPushButton* pbtn = new QPushButton;
    pbtn->setText("quit");
    pbtn->setParent(&lab);
    QObject::connect(pbtn, SIGNAL(clicked()), &app, SLOT(quit()));
    pbtn->show();

    return app.exec();
}
