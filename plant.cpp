#include "plant.h"
#include "zombie.h"

plant::plant()
{
    hp=state=atk=counter=time=0;
    mQMovie=nullptr;
}

plant::~plant()
{
    delete mQMovie;
}
void plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawImage(boundingRect(),mQMovie->currentImage());

}
void plant::setMovie(QString path)
{
    if(mQMovie)
        delete mQMovie;
    mQMovie=new QMovie(path);
    mQMovie->start();
}
QRectF plant::boundingRect()const
{
    return QRect(-35,-35,70,70);
}
bool plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode)const
{
    Q_UNUSED(mode);
    return other->type() == zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;

}
int plant::type()const
{
    return Type;
}
