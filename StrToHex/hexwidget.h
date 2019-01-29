#ifndef HEXWIDGET_H
#define HEXWIDGET_H

#include <QWidget>
#include <QByteArray>

namespace Ui {
class HexWidget;
}

class HexWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HexWidget(QWidget *parent = nullptr);
    ~HexWidget();

private slots:
    void send(); //发送十六进制数据，并显示在TextEdit控件上

private:
    Ui::HexWidget *ui;


};

#endif // HEXWIDGET_H
