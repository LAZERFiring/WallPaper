#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "Rolemodel.h"
#include <QMap>
#include <QPushButton>
#include <QMouseEvent>
#include "Settings.h"
#include "WallPaper.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void  initMainwindow();
    void mousePressEvent(QMouseEvent* ev)override;
public slots:
    void updateAnimemodel();
    void settingsShow();
    void closeexe();
private:
    Ui::MainWindow *ui;
    QLabel* rolemodel;
    int index=0;
    int frames=0;
    QMap<QString,RoleModel> m_roleModels;
    QPushButton* closebtn;
    QPushButton* settingsbtn;
    Settings* setWidget;
    QString modename;
};
#endif // MAINWINDOW_H
