#ifndef SETTINGS_H
#define SETTINGS_H
#include<QGraphicsDropShadowEffect>
#include <QWidget>
#include "./ui_SetWidget.h"
#include "WallPaper.h"
namespace Ui {
class Form;
}
class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = nullptr);
    void init();
    void addShadowEffect(QWidget *widget)
    {
        // 创建 QGraphicsDropShadowEffect 对象
        QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(widget);

        // 设置阴影的颜色、偏移量和模糊半径
        shadowEffect->setColor(Qt::black);
        shadowEffect->setOffset(0);
        shadowEffect->setBlurRadius(10);

        // 将阴影效果应用到窗口
        widget->setGraphicsEffect(shadowEffect);
    }
signals:
    void currentmodelchange(const QString& modename);
    void WallPaperchanged(const QString& filename);
private slots:
    void on_modelbtn_clicked();

    void on_setbtn_clicked();

    void on_modelbtn2_clicked();

    void on_modelbtn3_clicked();

    void on_selectwall_clicked();

private:
    Ui::Form* SetWidget;
    QButtonGroup *btngroup;
    WallPaper* wallPaper;
};

#endif // SETTINGS_H
