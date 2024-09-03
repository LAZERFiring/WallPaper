#include "WallPaper.h"
#include "finddektophwnd.h"
#include <QString>

WallPaper::WallPaper(QWidget *parent)
    :QLabel(parent)
{
    showFullScreen();
    //将此控件设置为桌面的孩子，达到桌面壁纸的效果
    FindDektopHwnd* FDTH=new FindDektopHwnd;
    FDTH->SetParent(this,nullptr);
}

void WallPaper::setWallPaper(const QString& filename)
{
    if(!filename.isEmpty())
    {
        setPixmap(filename);
    }

}
