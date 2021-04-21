#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QString>
#include<QMessageBox>
#include<QStack>
#include<string>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置screen背景为白色
    QPalette screen_pal;
    screen_pal.setColor(QPalette::Background,QColor(255,255,255));
    ui->screen_widget->setPalette(screen_pal);

    //按键交互设置
    {
        connect(ui->button_num_0,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("0");
            else
            {
                ui->screen->setText(ui->screen->text()+"0");
                qDebug()<<"add 0"<<ui->screen->text();
            }
        });
        connect(ui->button_num_1,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("1");
            else
            {
                ui->screen->setText(ui->screen->text()+"1");
                qDebug()<<"add 1"<<ui->screen->text();
            }
        });
        connect(ui->button_num_2,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("2");
            else
            {
                ui->screen->setText(ui->screen->text()+"2");
                qDebug()<<"add 2"<<ui->screen->text();
            }
        });
        connect(ui->button_num_3,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("3");
            else
            {
                ui->screen->setText(ui->screen->text()+"3");
                qDebug()<<"add 3"<<ui->screen->text();
            }
        });
        connect(ui->button_num_4,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("4");
            else
            {
                ui->screen->setText(ui->screen->text()+"4");
                qDebug()<<"add 4"<<ui->screen->text();
            }
        });
        connect(ui->button_num_5,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("5");
            else
            {
                ui->screen->setText(ui->screen->text()+"5");
                qDebug()<<"add 5"<<ui->screen->text();
            }
        });
        connect(ui->button_num_6,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("6");
            else
            {
                ui->screen->setText(ui->screen->text()+"6");
                qDebug()<<"add 6"<<ui->screen->text();
            }
        });
        connect(ui->button_num_7,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("7");
            else
            {
                ui->screen->setText(ui->screen->text()+"7");
                qDebug()<<"add 7"<<ui->screen->text();
            }
        });
        connect(ui->button_num_8,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("8");
            else
            {
                ui->screen->setText(ui->screen->text()+"8");
                qDebug()<<"add 8"<<ui->screen->text();
            }
        });
        connect(ui->button_num_9,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("9");
            else
            {
                ui->screen->setText(ui->screen->text()+"9");
                qDebug()<<"add 9"<<ui->screen->text();
            }
        });
        connect(ui->button_logic_or,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("0||");
            else
            {
                ui->screen->setText(ui->screen->text()+"||");
                qDebug()<<"add ||"<<ui->screen->text();
            }
        });
        connect(ui->button_logic_and,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("0&&");
            else
            {
                ui->screen->setText(ui->screen->text()+"&&");
                qDebug()<<"add &&"<<ui->screen->text();
            }
        });
        connect(ui->button_logic_not,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("!");
            else
            {
                ui->screen->setText(ui->screen->text()+"!");
                qDebug()<<"add !"<<ui->screen->text();
            }
        });
        connect(ui->button_opera_plus,&QPushButton::clicked,[=](){
                ui->screen->setText(ui->screen->text()+"+");
                qDebug()<<"add +"<<ui->screen->text();
        });
        connect(ui->button_opera_minus,&QPushButton::clicked,[=](){
                ui->screen->setText(ui->screen->text()+"-");
                qDebug()<<"add -"<<ui->screen->text();
        });
        connect(ui->button_opera_mult,&QPushButton::clicked,[=](){
                ui->screen->setText(ui->screen->text()+"*");
                qDebug()<<"add *"<<ui->screen->text();
        });
        connect(ui->button_opera_div,&QPushButton::clicked,[=](){
                ui->screen->setText(ui->screen->text()+"/");
                qDebug()<<"add /"<<ui->screen->text();
        });
        connect(ui->button_opera_rightpar,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("0");
            else
            {
                ui->screen->setText(ui->screen->text()+")");
                qDebug()<<"add )"<<ui->screen->text();
            }
        });
        connect(ui->button_opera_leftpar,&QPushButton::clicked,[=](){
            if(ui->screen->text()=="0")
                ui->screen->setText("(");
            else
            {
                ui->screen->setText(ui->screen->text()+"(");
                qDebug()<<"add ("<<ui->screen->text();
            }
        });
        connect(ui->button_delete,&QPushButton::clicked,[=](){
            if(ui->screen->text().size()!=1)
            {
                if(ui->screen->text().endsWith("&")||ui->screen->text().endsWith("|"))
                    ui->screen->setText(ui->screen->text().left(ui->screen->text().size()-2));
                else
                    ui->screen->setText(ui->screen->text().left(ui->screen->text().size()-1));
            }
            else
                ui->screen->setText("0");
        });
        connect(ui->button_opera_clear,&QPushButton::clicked,[=](){
            ui->screen->setText("0");
            ui->screen_res->setText("0");
        });
        connect(ui->button_get_res,&QPushButton::clicked,[=](){
            qDebug()<<"button_get_res is clicked";
            pre_treatment(ui->screen->text());
            if(check(ui->screen->text()))
            {
                QString tocal;
                tocal=("#"+ui->screen->text()+"#");
                //remove | from ||,& from &&
                for(int i=0;tocal[i].toLatin1()!=0;i++)
                {
                    if(tocal[i]=='&'||tocal[i]=='|')
                    {
                        tocal.remove(i,1);
                    }
                }
                qDebug()<<"tocal string:"<<tocal;
                ui->screen_res->setText(cal(tocal));
            }
            else
                ui->screen_res->setText("Invalid  Expression!");
        });
    }



}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_button_about_clicked()
{
    QMessageBox msg(this);
    msg.setText("a calculator by HIBIKI \n version: beta 1.0 \n developed on Qt5.14.1");
    msg.setWindowTitle("about");
    msg.exec();
}
void Widget::pre_treatment(QString str)
{
    str='#'+str+'#';
    for(int i=1;str[i]!='#';i++)
    {
        qDebug() <<"now pre_treating char:"<<str[i];
        // () -> (0)
        if(str[i]=='('&&str[i+1]==')')
            str.insert(i+1,QString('0'));
        // )( -> )*(
        if(str[i]==')'&&str[i+1]=='(')
            str.insert(i+1,QString('*'));
        // num( -> num*(
        if((str[i]>='0'&&str[i]<='9')&&str[i+1]=='(')
            str.insert(i+1,QString('*'));
        // )num -> )*num
        if((str[i+1]>='0'&&str[i+1]<='9')&&str[i]==')')
            str.insert(i+1,QString('*'));
    }
    str.remove(0,1);
    str.remove(str.size()-1,1);
    qDebug()<<"pre_treated str:"<<str;
    ui->screen->setText(str);
}

bool Widget::check(QString str1)
{
    qDebug()<<"checking "<<str1;
    QString str(str1);
    //remove | from ||,& from &&
    qDebug()<<"is removing | and &";
    for(int i=0;str[i].toLatin1()!=0;i++)
    {
        if(str[i]=='&'||str[i]=='|')
        {
            str.remove(i,1);
        }
    }
    qDebug() <<"remove process finish";
    qDebug() <<"tocal "<<str;

    //check '(' and ')'
    qDebug() <<"is checking '(' and ')'";
    QStack<char> sta1;
    for(int i=0;str[i].toLatin1()!=0;i++)
    {
        if(str[i]=='('||str[i]==')')
        {
            if(str[i]=='(')
                sta1.push('(');
            else
            {
                if(sta1.empty())
                    return false;
                else
                    sta1.pop();
            }
        }
    }
    if(!sta1.empty())
    {
        qDebug() <<"err of ()";
        return false;
    }
    qDebug() <<"( and ) checked";
    //check first char
    qDebug() <<"is checking first char";
    if(str=="()")
        return false;
    if(str[0].toLatin1()=='+'||str[0].toLatin1()=='-'||str[0].toLatin1()=='*'||str[0].toLatin1()=='/'||str[0].toLatin1()=='|'||str[0].toLatin1()=='&'||str[0].toLatin1()==')')
    {
        qDebug()<<"err13:first char invalid";
        return false;
    }
    qDebug() <<"first char checked";
    //check every char in str
    for(int i=1;i<=str.length()-2;i++)
    {
        qDebug()<<"is checking "<<str[i];
        switch(str[i].toLatin1())
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if(str[i-1].toLatin1()==')')
                {
                    qDebug() <<"err1:left (";
                    return false;
                }
                if(str[i+1].toLatin1()=='('||str[i+1]=='!')
                {
                    qDebug() <<"err2:right ( or !";
                    return false;
                }
                break;
            case '(':
                if(str[i-1].toLatin1()>='0'&&str[i-1].toLatin1()<='9')
                {
                    qDebug()<<"err3:left 0~9";
                    return false;
                }
                if(str[i+1].toLatin1()=='+'||str[i+1].toLatin1()=='-'||str[i+1].toLatin1()=='*'||str[i+1].toLatin1()=='/'||str[i+1].toLatin1()==')'||str[i+1].toLatin1()=='|'||str[i+1].toLatin1()=='&')
                {
                    qDebug()<<"err4:right +-*/)|&";
                    return false;
                }
                break;
            case ')':
                if(str[i-1].toLatin1()=='+'||str[i-1].toLatin1()=='-'||str[i-1].toLatin1()=='*'||str[i-1].toLatin1()=='/'||str[i-1].toLatin1()=='('||str[i-1].toLatin1()=='!'||str[i-1].toLatin1()=='|'||str[i-1].toLatin1()=='&')
                {
                    qDebug()<<"err5:left +-*/(!|&";
                    return false;
                }
                if((str[i+1].toLatin1()>='0'&&str[i+1].toLatin1()<='9')||str[i+1].toLatin1()=='('||str[i+1].toLatin1()=='!')
                {
                    qDebug()<<"err6:right 0~9 (!";
                    return false;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if(str[i-1].toLatin1()=='+'||str[i-1].toLatin1()=='-'||str[i-1].toLatin1()=='*'||str[i-1].toLatin1()=='/'||str[i-1].toLatin1()=='('||str[i-1].toLatin1()=='!'||str[i-1].toLatin1()=='|'||str[i-1].toLatin1()=='&')
                {
                    qDebug()<<"err7:left +-*/(!|&";
                    return false;
                }
                if(str[i+1].toLatin1()=='+'||str[i+1].toLatin1()=='-'||str[i+1].toLatin1()=='*'||str[i+1].toLatin1()=='/'||str[i+1].toLatin1()==')'||str[i+1].toLatin1()=='|'||str[i+1].toLatin1()=='&')
                {
                    qDebug()<<"err8:right +-*/)|&";
                    return false;
                }
                break;
            case '!':
                if((str[i-1].toLatin1()>='0'&&str[i-1].toLatin1()<='9')||str[i-1].toLatin1()==')')
                {
                    qDebug()<<"err9:left 0~9 )";
                    return false;
                }
                if(str[i+1].toLatin1()=='+'||str[i+1].toLatin1()=='-'||str[i+1].toLatin1()=='*'||str[i+1].toLatin1()=='/'||str[i+1].toLatin1()==')'||str[i+1].toLatin1()=='|'||str[i+1].toLatin1()=='&')
                {
                    qDebug()<<"err10:right +-*/)|&";
                    return false;
                }
                break;
            case '&':
            case '|':
                if(str[i-1].toLatin1()=='+'||str[i-1].toLatin1()=='-'||str[i-1].toLatin1()=='*'||str[i-1].toLatin1()=='/'||str[i-1].toLatin1()=='('||str[i-1].toLatin1()=='!'||str[i-1].toLatin1()=='|'||str[i-1].toLatin1()=='&')
                {
                    qDebug()<<"err11:left +-*/(!|&";
                    return false;
                }
                if(str[i+1].toLatin1()=='+'||str[i+1].toLatin1()=='-'||str[i+1].toLatin1()=='*'||str[i+1].toLatin1()=='/'||str[i+1].toLatin1()==')'||str[i+1].toLatin1()=='|'||str[i+1].toLatin1()=='&')
                {
                    qDebug()<<"err12:right +-*/)!|&";
                    return false;
                }
                break;
        }
        qDebug() <<str[i]<<" checked";
    }
    //check last char
    qDebug() <<"is checking last char";
    if(str[str.length()-1].toLatin1()=='+'||str[str.length()-1].toLatin1()=='-'||str[str.length()-1].toLatin1()=='*'||str[str.length()-1].toLatin1()=='/'||str[str.length()-1].toLatin1()=='!'||str[str.length()-1].toLatin1()=='|'||str[str.length()-1].toLatin1()=='&'||str[str.length()-1].toLatin1()=='(')
    {
        qDebug()<<"err14:last char invalid";
        return false;
    }
    qDebug() <<"last char checked";
    qDebug()<<"valid expression";
    return true;





};

int Widget::get_seq(char x)
{
    switch(x)
    {
        case '#':
            return 0;
        case '(':
        case ')':
            return 1;
        case '&':
            return 2;
        case '|':
            return 3;
        case '+':
        case '-':
            return 4;
        case '*':
        case '/':
            return 5;
        case '!':
            return 6;
    default:
        return -1;
    }
};

QString Widget::cal(QString str)
{
    QStack<char> sta1;
    QStack<double> sta2;
    for(int i=0;str[i].toLatin1()!=0;i++)
    {
        if(str[i].toLatin1()>='0'&&str[i].toLatin1()<='9')
        {
            int tmp=str[i].toLatin1()-'0';
            while(str[i+1].toLatin1()>='0'&&str[i+1].toLatin1()<='9')
            {
                tmp=tmp*10+str[i+1].toLatin1()-'0';
                i++;
            }
            sta2.push(tmp);
        }
        else
        {
            if(sta1.empty()||str[i]=='('||get_seq(sta1.top())<get_seq(str[i].toLatin1()))
            {
                sta1.push(str[i].toLatin1());
            }
            else
            {
                while(get_seq(sta1.top())>=get_seq(str[i].toLatin1()))
                {
                    if( (sta1.top()=='('&&str[i]==')') || (sta1.top()=='#'&&str[i]=='#') )
                    {
                        sta1.pop();
                        break;
                    }
                    else
                    {
                        int a=sta2.top();
                        sta2.pop();
                        int b=sta2.top();
                        sta2.pop();
                    switch(sta1.top())
                    {
                        case '+':
                            sta2.push(b+a);
                            break;
                        case '-':
                            sta2.push(b-a);
                            break;
                        case '*':
                            sta2.push(b*a);
                            break;
                        case '/':
                            sta2.push((double)b/a);
                            break;
                        case '&':
                            if(a!=0&&b!=0)
                            sta2.push(1);
                            else
                            sta2.push(0);
                            break;
                        case '|':
                            if(a==0&&b==0)
                            sta2.push(0);
                            else
                            sta2.push(1);
                            break;
                        case '!':
                            sta2.push(b);
                            if(a==0)
                            sta2.push(1);
                            else
                            sta2.push(0);
                            break;
                    }
                    sta1.pop();
                    if(get_seq(str[i].toLatin1())>get_seq(sta1.top()))
                    {
                        sta1.push(str[i].toLatin1());
                        break;
                    }
                    if(sta1.top()=='#'&&str[i]=='#')
                        break;
                    }
                }
            }
        }
    }
    QString res = QString::number(sta2.top());
    qDebug()<<"result:"<<sta2.top();
    return res;
};
