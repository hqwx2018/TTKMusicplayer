#ifndef MUSICVIDEOVIEW_H
#define MUSICVIDEOVIEW_H

#include <QGraphicsView>
#include <QMediaPlayer>
#include "../core/musiclibexportglobal.h"

class MusicVideoControl;
class QGraphicsVideoItem;

class MUSIC_EXPORT MusicVideoView : public QGraphicsView
{
    Q_OBJECT
public:
    MusicVideoView(QWidget *parent = 0);
    ~MusicVideoView();

signals:
    void movieDoubleClicked();

public slots:
    void play();

private slots:
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void setPosition(int position);
    void volumnChanged(int volumn);

protected:
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void contextMenuEvent(QContextMenuEvent *event);

    QMediaPlayer m_mediaPlayer;
    QGraphicsVideoItem *m_videoItem;
    MusicVideoControl *m_videoControl;

};


#endif // MUSICVIDEOVIEW_H
