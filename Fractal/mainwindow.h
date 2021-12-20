#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int NOR = 1;
    std::string cur_Line(int NOR);
    void Painting(int NOR, std::string Line);
    QGraphicsScene* scene;

private slots:
    void on_Button_Plus_clicked();

    void on_Button_Minus_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
