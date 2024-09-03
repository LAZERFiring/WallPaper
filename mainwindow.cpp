#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "EventFilterObject.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , setWidget(new Settings)
{
    setWidget->hide();
    ui->setupUi(this);
    initMainwindow();
    modename="summerGril";

    QTimer* timer=new QTimer(this);
    timer->callOnTimeout(this,&MainWindow::updateAnimemodel);
    timer->start(500);
    updateAnimemodel();

    //申请内存
    closebtn= new QPushButton(this);closebtn->setObjectName("closebtn");
    settingsbtn=new QPushButton(this);settingsbtn->setObjectName("settingsbtn");

    //样式表设计
    closebtn->setGeometry(130,220,32,32);
    settingsbtn->setGeometry(180,220,32,32);
    closebtn->setStyleSheet(R"(#closebtn{border:none;image:url(':/assets/button/quit.png');background-color:rgba(230,231,232,120);
border-radius:10px;}
#closebtn:hover
{
    background-color:rgba(230,231,232,200)
})");
    settingsbtn->setStyleSheet(R"(#settingsbtn{border:none;image:url(':/assets/button/setting.png');background-color:rgba(230,231,232,120);
border-radius:10px;}
#settingsbtn:hover
{
    background-color:rgba(230,231,232,200)
})");
    connect(closebtn,&QPushButton::clicked,this,&MainWindow::closeexe);
    connect(settingsbtn,&QPushButton::clicked,this,&MainWindow::settingsShow);
    connect(setWidget,&Settings::currentmodelchange,this,[=](const QString& modename)
    {
        this->modename=modename;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainwindow()
{
    installEventFilter(new EventfilterObject(this));
    setFixedSize(350,480);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlag(Qt::WindowType::WindowStaysOnTopHint);//设置窗口顶置

    RoleModel modelrole;
    for (int var = 0; var < 6; ++var) {
        modelrole.addframe(QString(":/assets/desktopRole/blackGril/action1-happy/%1.png").arg(var));
    }
    m_roleModels.insert(QString("BlackGirl/happy"),modelrole);

    modelrole.clear();
    for (int var = 0; var < 6; ++var) {
        modelrole.addframe(QString(":/assets/desktopRole/blackGril/action2-sad/%1.png").arg(var));
    }
    m_roleModels.insert(QString("BlackGirl/sad"),modelrole);

    modelrole.clear();
    for (int var = 0; var < 6; ++var) {
        modelrole.addframe(QString(":/assets/desktopRole/blackGril/action3-naughty/%1.png").arg(var));
    }
    m_roleModels.insert(QString("BlackGirl/naughty"),modelrole);

    modelrole.clear();
    for (int var = 0; var < 6; ++var) {
        modelrole.addframe(QString(":/assets/desktopRole/blackGril/action4-shy/%1.png").arg(var));
    }
    m_roleModels.insert(QString("BlackGirl/shy"),modelrole);

    modelrole.clear();
    for (int var = 0; var < 6; ++var) {
        modelrole.addframe(QString(":/assets/desktopRole/littleBoy/%1.png").arg(var));
    }
    m_roleModels.insert(QString("littleBoy"),modelrole);

    modelrole.clear();
    for (int var = 0; var < 6; ++var) {
        modelrole.addframe(QString(":/assets/desktopRole/summerGril/%1.png").arg(var));
    }
    m_roleModels.insert(QString("summerGril"),modelrole);

    rolemodel= new QLabel(this);
    rolemodel->setGeometry(0,0,350,480);
    //rolemodel->setAttribute(Qt::WA_TranslucentBackground);
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::MouseButton::LeftButton)
    {
        closebtn->setVisible(!closebtn->isVisible());
        settingsbtn->setVisible(!settingsbtn->isVisible());
    }
}

void MainWindow::updateAnimemodel()
{
    frames=m_roleModels[modename].size();
    rolemodel->setPixmap(m_roleModels[modename][index]);
    index=(++index)%frames;

}

void MainWindow::settingsShow()
{

    setWidget->show();
}

void MainWindow::closeexe()
{
    delete setWidget;
    QMainWindow::close();
}

