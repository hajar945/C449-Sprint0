//sources
// https://github.com/gammasoft71/Examples_Qt/tree/master/Qt.Widgets/Controls
// https://zetcode.com/gui/qt5/painting/#:~:text=Colours,filled%20with%20nine%20different%20colours.&text=%23pragma%20once%20%23include%20class%20Colours%20:%20public,This%20is%20the%20header%20file.&text=We%20draw%20nine%20rectangles%20with,to%20specify%20a%20colour%20value.&text=This%20is%20the%20main%20file.,-Figure:%20Colours
#include <QApplication>
#include <QPainter>
#include "QtWidgetsApplication1.h"
#include <QCheckBox>



using namespace Examples;

Window1::Window1(QMainWindow *parent)
    : QMainWindow(parent)
{}

void Window1::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    QPainter qp(this);
    drawLines(&qp);
}

void Window1::drawLines(QPainter *qp) {
    // solid line
    QPen pen(Qt::black, 2, Qt::SolidLine);
    qp->setPen(pen);
    qp->drawLine(20, 40, 250, 40);


    // dashed line
    QVector<qreal> dashes;
    qreal space = 4;

    dashes << 1 << space << 5 << space;

    pen.setStyle(Qt::CustomDashLine);
    pen.setDashPattern(dashes);

    qp->setPen(pen);
    qp->drawLine(20, 240, 250, 240);
}

int main(int argc, char *argv[]) {
	
  auto application = QApplication {argc, argv};
  auto window1 = Window1 {};

  

  window1.show();
  
  

  return application.exec();
}

