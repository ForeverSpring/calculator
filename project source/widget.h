#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    int get_seq(char x);
    QString cal(QString str);
    bool check(QString str);
    void pre_treatment(QString str);
    ~Widget();

private slots:
    void on_button_about_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
