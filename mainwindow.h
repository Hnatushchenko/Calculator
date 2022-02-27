#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cmath>
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QWidget *centralWidget;
    QLabel *label;
    QGridLayout *grid;
    QPushButton * buttons[20];

    QString label_text = "0";
    QString sign = "";
    double numberInMemory = 0;

    void digitButtonClicked(QString text);
    void signButtonClicked(QString sign);
    void calculate();

private slots:
    void slotButton0();
    void slotButton1();
    void slotButton2();
    void slotButton3();
    void slotButton4();
    void slotButton5();
    void slotButton6();
    void slotButton7();
    void slotButton8();
    void slotButton9();
    void slotButtonPlus();
    void slotButtonMinus();
    void slotButtonDivision();
    void slotButtonMultiplication();
    void slotButtonEqual();
    void slotButtonClear();
    void slotButtonSqrt();
    void slotButtonPoint();
    void slotButtonErase();
    void slotButtonPlusMinus();

};
#endif // MAINWINDOW_H
