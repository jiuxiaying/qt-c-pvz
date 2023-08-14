#include "card.h"
#include "shop.h"

const QMap<QString, int> card::map = {{"SunFlower", 0}, {"Peashooter", 1}, {"CherryBomb", 2}, {"WallNut", 3},
                                      {"SnowPea", 4}, {"PotatoMine", 5}, {"Repeater", 6}};
const QVector<QString> card::name = {"SunFlower", "Peashooter", "CherryBomb", "WallNut",
                                     "SnowPea", "PotatoMine", "Repeater"};
const QVector<int> card::cost = {50, 100, 150, 50, 175, 25, 200};
const QVector<int> card::cool = {227, 227, 606, 606, 227, 606, 227};

card::card(QString s)
{
    text = s;
    counter = 0;
}

QRectF card::boundingRect() const
{
    return QRectF(-50, -30, 100, 60);
}

void card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->scale(0.6, 0.58);
    painter->drawPixmap(QRect(-50, -70, 100, 140), QPixmap(":/new/prefix1/Card.png"));
    painter->drawPixmap(QRect(-35, -42, 70, 70), QPixmap(":/new/prefix1/" + text + ".png"));
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(-30, 60, QString().sprintf("%3d", cost[map[text]]));
    if (counter < cool[map[text]])
    {
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(-48, -68, 98, 132 * (1 - qreal(counter) / cool[map[text]])));
    }
}

void card::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (counter < cool[map[text]])
        ++counter;
}

void card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    if (counter < cool[map[text]])
        event->setAccepted(false);
    shop *sh = qgraphicsitem_cast<shop *>(parentItem());
    if (cost[map[text]] > sh->sunnum)
        event->setAccepted(false);
    setCursor(Qt::ArrowCursor);//默认的鼠标指针形状
}

void card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
        < QApplication::startDragDistance())//检查鼠标点击事件的起点和终点之间的距离是否小于系统设置的开始拖拽的距离阈值。
        //这是为了防止在点击时意外触发拖拽操作。
        return;
    QDrag *drag = new QDrag(event->widget());//创建一个新的拖拽对象QDrag，该对象用于实现拖拽操作。
    QMimeData *mime = new QMimeData;//用于存储要拖拽的数据。
    QImage image(":/new/prefix1/" + text + ".png");
    mime->setText(text);
    mime->setImageData(image);
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image));
    drag->setHotSpot(QPoint(35, 35));
    drag->exec();//执行拖拽操作，开始拖拽。
    setCursor(Qt::ArrowCursor);
}

void card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
}
