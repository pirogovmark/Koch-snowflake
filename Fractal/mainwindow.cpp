#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <algorithm>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    MainWindow::Painting(NOR, cur_Line(NOR));
}

std::string MainWindow::cur_Line(int NOR) {
    std::string line = "F++F++F", F_change = "F-F++F-F", result = "";
    int size = 0;
    for (int ii = 1; ii < NOR; ++ii) {
        size = line.size();
        for (int ind = 0; ind < size; ++ind) {
            if (line[ind] == 'F') {
                result += F_change;
                continue;
            }
            result += line[ind];
        }
        line = result;
        result = "";
    }
    return line;
}

void MainWindow::Painting(int NOR, std::string Line) {
    double length = 500 / std::pow(3, --NOR);
    double Pi = 3.14159265359;
    int angle = 0, size;
    double x = 0, y = 0, nxt_x = 0, nxt_y = 0;
    scene->clear();
    size = Line.size();
    for (int ii = 0; ii < size; ++ii) {
        if (Line[ii] == '+') {
            angle += 60;
        } else if (Line[ii] == '-') {
            angle -= 60;
        } else {
            nxt_x = x + length * cos(angle * Pi / 180);
            nxt_y = y + length * sin(angle * Pi / 180);
            scene->addLine(x, y, nxt_x, nxt_y);
            x = nxt_x;
            y = nxt_y;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_Plus_clicked()
{
    if (NOR < 8) {
        ++NOR;
        MainWindow::Painting(NOR, cur_Line(NOR));
    }
}

void MainWindow::on_Button_Minus_clicked()
{
    if (NOR > 1) {
        --NOR;
        MainWindow::Painting(NOR, cur_Line(NOR));
    }
}
