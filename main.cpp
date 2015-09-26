#include <QApplication>
#include <QHBoxLayout>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QWidget *pwin = new QWidget;
    pwin->setWindowTitle("ENTER YOU AGE");

    QSpinBox *pSpinbox = new QSpinBox;
    QSlider  *pSlider = new QSlider(Qt::Horizontal);
    pSpinbox->setRange(0, 130);
    pSlider->setRange(0, 130);
    pSpinbox->setValue(35);

    QObject::connect(pSpinbox, SIGNAL(valueChanged(int)), pSlider, SLOT(setValue(int)));
    QObject::connect(pSlider, SIGNAL(valueChanged(int)), pSpinbox, SLOT(setValue(int)));

    QHBoxLayout *playout = new QHBoxLayout;
    playout->addWidget(pSpinbox);
    playout->addWidget(pSlider);
    pwin->setLayout(playout);

    pwin->show();
    return app.exec();
}
