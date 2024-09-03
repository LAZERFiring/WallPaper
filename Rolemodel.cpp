#include "Rolemodel.h"

RoleModel::RoleModel()
{

}

void RoleModel::addframe(const QString &filename)
{
    m_pixmaps.append(filename);
}

int RoleModel::size()
{
    return m_pixmaps.size();
}

bool RoleModel::empty()
{
    return m_pixmaps.isEmpty();
}

void RoleModel::clear()
{
    m_pixmaps.clear();
}

QPixmap RoleModel::operator[](int index)
{
    return m_pixmaps[index];

}
