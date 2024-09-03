#ifndef WALLPAPER_H
#define WALLPAPER_H

#include <QLabel>
class WallPaper:public QLabel
{
    Q_OBJECT
public:
    WallPaper(QWidget* parent=nullptr);
    void setWallPaper(const QString& filename);
signals:

};

#endif // WALLPAPER_H
