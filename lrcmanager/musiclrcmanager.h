#ifndef MUSICLRCMANAGER_H
#define MUSICLRCMANAGER_H

#include <QLabel>
#include <QMouseEvent>
#include <QMenu>
#include <QTimer>
#include <QAction>
#include <QPainter>
#include "../core/musiclibexportglobal.h"

#define LRC_PER_TIME 30

namespace LrcColorTable
{   //Color table
    const QColor CL_Origin = QColor(14,179,255);
    const QColor CL_Red    = QColor(214,51,44);
    const QColor CL_Orange = QColor(230,130,52);
    const QColor CL_Yellow = QColor(243,209,0);
    const QColor CL_Green  = QColor(62,164,140);
    const QColor CL_Blue   = QColor(76,147,193);
    const QColor CL_Indigo = QColor(29,237,235);
    const QColor CL_Purple = QColor(156,115,155);
    const QColor CL_White  = QColor(255,255,255);
    const QColor CL_Black  = QColor(0,0,0);
    const QColor CL_Mask   = QColor(222,54,4);

    enum LrcColorType{ Origin, Red, Orange, Yellow, Green,
                       Blue, Indigo, Purple, White, Black,
                       Mask };
}

enum LrcSizeTable{ Smaller = 13, Small = 14, Middle = 15, Big = 16, Bigger = 17};

class MUSIC_EXPORT MusicLRCManager : public QLabel
{
    Q_OBJECT
public:
    explicit MusicLRCManager(QWidget *parent = 0);
    virtual ~MusicLRCManager();

    void startTimerClock();
    void startLrcMask(qint64 intervaltime);
    void stopLrcMask();
    void setLinearGradientColor(QColor = LrcColorTable::CL_Origin);
    void setMaskLinearGradientColor(QColor = LrcColorTable::CL_Mask);
    void setLrcFontSize(LrcSizeTable);
    void setFontFamily(int);
    void setFontType(int);
    inline void setFontTransparent(int t) { m_transparent = t;}

signals:

public slots:
    void setTimeOut();
    void setText(const QString &);

protected:
    QLinearGradient m_linearGradient;
    QLinearGradient m_maskLinearGradient;
    QFont m_font;
    QTimer* m_timer;
    qreal m_lrcMaskWidth;
    qreal m_lrcMaskWidthInterval;
    qreal m_intervalCount;

    int m_lrcPerWidth;
    int m_transparent;
    int m_speedLeve;
    QPoint m_geometry;

};

#endif // MUSICLRCMANAGER_H
