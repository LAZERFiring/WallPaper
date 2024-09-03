#include "Settings.h"
#include "EventFilterObject.h"
#include <QButtonGroup>
#include <QFileDialog>
Settings::Settings(QWidget *parent)
    : QWidget{parent}
    , SetWidget(new Ui::Form)
{
    installEventFilter(new EventfilterObject(this));
    this->setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
    SetWidget->setupUi(this);
    init();
    addShadowEffect(this);
    SetWidget->rolemodegirl->setChecked(true);
}

void Settings::init()
{
    btngroup=new QButtonGroup(this);
    btngroup->setExclusive(true);
    btngroup->addButton(SetWidget->rolemodeboy);
    btngroup->addButton(SetWidget->rolemodegirl);
    btngroup->addButton(SetWidget->rolemodeblack);

    connect(btngroup,&QButtonGroup::buttonToggled,this,[=](QAbstractButton* btn,bool check)
    {
        if(!check)
            return;
        if(btn==SetWidget->rolemodeboy)
        {
            emit currentmodelchange("littleBoy");
        }
        else if(btn==SetWidget->rolemodegirl)
        {
            emit currentmodelchange("summerGril");
        }
        else if(btn==SetWidget->rolemodeblack)
        {
            emit currentmodelchange("BlackGirl/happy");
        }
    });
}

void Settings::on_modelbtn_clicked()
{
    SetWidget->stackedWidget->setCurrentIndex(0);
}


void Settings::on_setbtn_clicked()
{
    SetWidget->stackedWidget->setCurrentIndex(3);
}


void Settings::on_modelbtn2_clicked()
{
    SetWidget->stackedWidget->setCurrentIndex(1);
}


void Settings::on_modelbtn3_clicked()
{
    SetWidget->stackedWidget->setCurrentIndex(2);
}


void Settings::on_selectwall_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this);
    if(!filename.isEmpty())
    {
        wallPaper=new WallPaper;
        wallPaper->setWallPaper(filename);
    }
}

