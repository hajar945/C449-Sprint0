//sources
// https://github.com/gammasoft71/Examples_Qt/tree/master/Qt.Widgets/Controls
// https://zetcode.com/gui/qt5/painting/#:~:text=Colours,filled%20with%20nine%20different%20colours.&text=%23pragma%20once%20%23include%20class%20Colours%20:%20public,This%20is%20the%20header%20file.&text=We%20draw%20nine%20rectangles%20with,to%20specify%20a%20colour%20value.&text=This%20is%20the%20main%20file.,-Figure:%20Colours
#pragma once
#include <QFrame>
#include <QMainWindow>
#include <QRadioButton>
#include <QLabel>
#include <QWidget>
#include <QPainter>
#include <QCheckBox>

namespace Examples {
    class Window1 : public QMainWindow {
        Q_OBJECT
    public:
        
        Window1() {
		// Radio buttons
            radioButton1.setText("Radio 1");
            radioButton1.move(30, 50);
            radioButton1.setChecked(true);

            radioButton2.setText("Radio 2");
            radioButton2.move(30, 80);

            radioButton3.setText("Radio 3");
            radioButton3.move(30, 110);

            setCentralWidget(&frame);
            
            resize(300, 300);

        // horizontal line
            QMainWindow *parent = 0;

        // Label
            label1.setText("This is a line of text.");
            label1.move(10, 20);

            setCentralWidget(&frame);
            
            resize(300, 300);

        // checkboxes
            checkBox1.setText("check box");
            checkBox1.move(30, 140);
            checkBox1.setCheckState(Qt::CheckState::Unchecked);
            connect(&checkBox1, &QCheckBox::checkStateChanged, [&] {
                checkBox1.resize(checkBox1.sizeHint());
                });

           

            setCentralWidget(&frame);
            

        }
    protected:
        Window1(QMainWindow* parent);
        void paintEvent(QPaintEvent* event);
        void drawLines(QPainter* qp);

    private:


        QFrame frame;
        QRadioButton radioButton1{ &frame };
        QRadioButton radioButton2{ &frame };
        QRadioButton radioButton3{ &frame };
        
        QLabel label1{ &frame };
      
        QCheckBox checkBox1{ &frame };
       
    

    };

}
