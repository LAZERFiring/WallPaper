#ifndef ROLEMODEL_H
#define ROLEMODEL_H

#include <QString>
#include <QPixmap>
class RoleModel
{
public:
    RoleModel();
    void addframe(const QString& filename);
    int size();
    bool empty();
    void clear();
    QPixmap operator[](int index);
private:
    QList<QPixmap> m_pixmaps;
};

#endif // ROLEMODEL_H
