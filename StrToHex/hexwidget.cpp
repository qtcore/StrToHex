#include "hexwidget.h"
#include "ui_hexwidget.h"
#include <QDebug>
#include <QString>
#include <QByteArray>

HexWidget::HexWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HexWidget)
{
    ui->setupUi(this);

    ui->textEdit->setReadOnly(true);                              //设置textEdit控件--不可编辑
    connect(ui->pushButton,SIGNAL(clicked(bool)), SLOT(send()));  //点击发送数据按钮，触发槽函数send()



}

HexWidget::~HexWidget()
{
    delete ui;
}

//发送十六进制数据，并显示在TextEdit控件上
void HexWidget::send()
{

    //获取lineEdit控件输入的字符串内容
    QString str = ui->lineEdit->text();

    //使用Qt自带的函数---转换为支持中文并大写的十六进制的字节数组 数据
    QByteArray hex = str.toUtf8().toHex().toUpper();


    //使用hex.right(2)函数，将字符串最后两个字符提取出来，避免每两个字符添加一个空格时，最后字符串末尾会多出一个空格
    QByteArray str2 = hex.right(2);

    //创建一个新的字节数组对象，用于存储拼接的字符串
    QByteArray strbyte;



    //循环遍历字符串内容,这里hex.length()-2，是因为已将字符串最后两个字符提取出去了
    //因为间隔两个字符，所以遍历计数每次自增2
    for(int i=0; i<hex.length()-2;i+=2)
    {
        QByteArray st = hex.mid(i,2);  //hex.mid(i,2) 循环取字符串str的从位置i=0开始,每次取2位字符

        //每两个字符，加上一个空格，进行字符串拼接
        strbyte += st;
        strbyte += " ";
    }

    //以每两个字符加上一个空格的字符串，再加上提前提取出来的字符串末尾的两位字符，进行拼接
    strbyte = strbyte + str2;


    qDebug() << strbyte + '\n';       //在调试窗口显示十六进制数据

    ui->textEdit->append(strbyte);   //在textEdit控件里面显示十六进制数据

}


