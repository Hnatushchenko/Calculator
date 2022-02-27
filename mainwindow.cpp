#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    grid = new QGridLayout(this);
    grid->setSpacing(2);

    label = new QLabel("0", this);
    label->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setMinimumHeight(70);
    label->setStyleSheet("font-size: 36px; background-color: rgb(230, 230, 230)");
    grid->addWidget(label, 0, 0, 1, 4);

    QString values[] =
    { "√", "C", "⌫", "+",
        "7", "8", "9", "-",
        "4", "5", "6", "÷",
        "1", "2", "3", "•",
        "±", "0", ".", "="
    };

    int index = 0;
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            buttons[index] = new QPushButton(values[index], this);
            buttons[index]->setMinimumWidth(95);
            buttons[index]->setMinimumHeight(60);
            buttons[index]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            buttons[index]->setStyleSheet("font-size: 24px; background-color: rgb(250, 250, 250)");
            grid->addWidget(buttons[index], i+1, j);
            ++index;
        }
    }

    buttons[0]->setStyleSheet("font-size: 24px; background-color: rgb(240, 240, 240)");
    buttons[1]->setStyleSheet("font-size: 24px; background-color: rgb(240, 240, 240)");
    buttons[2]->setStyleSheet("font-size: 24px; background-color: rgb(240, 240, 240)");
    buttons[3]->setStyleSheet("font-size: 24px; background-color: rgb(240, 240, 240)");
    buttons[7]->setStyleSheet("font-size: 24px; background-color: rgb(240, 240, 240)");
    buttons[11]->setStyleSheet("font-size: 24px; background-color: rgb(240, 240, 240)");
    buttons[15]->setStyleSheet("font-size: 24px; background-color: rgb(240, 240, 240)");
    buttons[19]->setStyleSheet("font-size: 24px; background-color: rgb(240, 240, 240)");

    connect(buttons[0], &QPushButton::clicked, this, &MainWindow::slotButtonSqrt);
    connect(buttons[1], &QPushButton::clicked, this, &MainWindow::slotButtonClear);
    connect(buttons[2], &QPushButton::clicked, this, &MainWindow::slotButtonErase);
    connect(buttons[3], &QPushButton::clicked, this, &MainWindow::slotButtonPlus);
    connect(buttons[4], &QPushButton::clicked, this, &MainWindow::slotButton7);
    connect(buttons[5], &QPushButton::clicked, this, &MainWindow::slotButton8);
    connect(buttons[6], &QPushButton::clicked, this, &MainWindow::slotButton9);
    connect(buttons[7], &QPushButton::clicked, this, &MainWindow::slotButtonMinus);
    connect(buttons[8], &QPushButton::clicked, this, &MainWindow::slotButton4);
    connect(buttons[9], &QPushButton::clicked, this, &MainWindow::slotButton5);
    connect(buttons[10], &QPushButton::clicked, this, &MainWindow::slotButton6);
    connect(buttons[11], &QPushButton::clicked, this, &MainWindow::slotButtonDivision);
    connect(buttons[12], &QPushButton::clicked, this, &MainWindow::slotButton1);
    connect(buttons[13], &QPushButton::clicked, this, &MainWindow::slotButton2);
    connect(buttons[14], &QPushButton::clicked, this, &MainWindow::slotButton3);
    connect(buttons[15], &QPushButton::clicked, this, &MainWindow::slotButtonMultiplication);
    connect(buttons[16], &QPushButton::clicked, this, &MainWindow::slotButtonPlusMinus);
    connect(buttons[17], &QPushButton::clicked, this, &MainWindow::slotButton0);
    connect(buttons[18], &QPushButton::clicked, this, &MainWindow::slotButtonPoint);
    connect(buttons[19], &QPushButton::clicked, this, &MainWindow::slotButtonEqual);


    centralWidget = new QWidget;
    centralWidget->setLayout(grid);
    setCentralWidget(centralWidget);
}

void MainWindow::digitButtonClicked(QString text)
{
    if(label_text == "Invalid value" || label_text == "inf") return;

    if(label_text == "0")
    {
        label_text = "";
    }
    label_text += text;
    label->setText(label_text);
}

void MainWindow::signButtonClicked(QString sign)
{
    if(label_text == "Invalid value" || label_text == "inf") return;

    if(label_text != "0")
    {
        numberInMemory = label_text.toDouble();
    }

    this->sign = sign;
    label_text = "0";
}

void MainWindow::calculate()
{
    if(sign == "") return;

    if(label_text == "Invalid value" || label_text == "inf") return;

    double temp = numberInMemory;
    numberInMemory = label_text.toDouble();

    if(sign == "+")
    {
        label_text = QString::number(temp + label_text.toDouble(), 'g', 16);
    }
    else if(sign == "-")
    {
        label_text = QString::number(temp - label_text.toDouble(), 'g', 16);
    }
    else if(sign == "•")
    {
        label_text = QString::number(temp * label_text.toDouble(), 'g', 16);
    }
    else if(sign == "÷")
    {
        label_text = QString::number(temp / label_text.toDouble(), 'g', 16);
    }

    label->setText(label_text);
    sign = "";
    numberInMemory = 0;

}




void MainWindow::slotButton0()
{
    digitButtonClicked("0");
}
void MainWindow::slotButton1()
{
    digitButtonClicked("1");
}
void MainWindow::slotButton2()
{
    digitButtonClicked("2");
}
void MainWindow::slotButton3()
{
    digitButtonClicked("3");
}
void MainWindow::slotButton4()
{
    digitButtonClicked("4");
}
void MainWindow::slotButton5()
{
    digitButtonClicked("5");
}
void MainWindow::slotButton6()
{
    digitButtonClicked("6");
}
void MainWindow::slotButton7()
{
    digitButtonClicked("7");
}
void MainWindow::slotButton8()
{
    digitButtonClicked("8");
}
void MainWindow::slotButton9()
{
    digitButtonClicked("9");
}
void MainWindow::slotButtonMinus()
{
    signButtonClicked("-");
}
void MainWindow::slotButtonDivision()
{
    signButtonClicked("÷");
}
void MainWindow::slotButtonMultiplication()
{
    signButtonClicked("•");
}
void MainWindow::slotButtonPlus()
{
    signButtonClicked("+");
}
void MainWindow::slotButtonEqual()
{
    calculate();
}

void MainWindow::slotButtonClear()
{
    label_text = "0";
    label->setText(label_text);
}

void MainWindow::slotButtonSqrt()
{
    if(label_text == "Invalid value" || label_text == "inf") return;

    double number = label_text.toDouble();
    number = std::sqrt(number);
    label_text = QString::number(number, 'g', 16);
    if(label_text == "nan")
    {
        label_text = "Invalid value";
    }
    label->setText(label_text);
}

void MainWindow::slotButtonPoint()
{
    if(label_text == "Invalid value" || label_text == "inf") return;

    if(!label_text.contains("."))
    {
        label_text += ".";
        label->setText(label_text);
    }

}

void MainWindow::slotButtonErase()
{
    if(label_text == "Invalid value" || label_text.count() == 1 || label_text == "inf")
    {
        label_text = "0";
        label->setText(label_text);
    }
    else
    {
        label_text = label_text.left(label_text.count()-1);
        label->setText(label_text);
    }
}

void MainWindow::slotButtonPlusMinus()
{
    if(label_text == "0" || label_text == "0." || label_text == "Invalid value" || label_text == "inf") return;

    if(label_text[0] == "-")
    {
        label_text = label_text.right(label_text.count()-1);
    }
    else
    {
        label_text.prepend("-");
    }
    label->setText(label_text);
}


MainWindow::~MainWindow()
{
    delete label;
    for(int i = 0; i < 20; ++i)
    {
        delete buttons[i];
    }
    delete grid;
    delete ui;
}

