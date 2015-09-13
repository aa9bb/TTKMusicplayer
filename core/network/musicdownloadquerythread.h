#ifndef MUSICDOWNLOADQUERYTHREAD_H
#define MUSICDOWNLOADQUERYTHREAD_H

/* =================================================
 * This file is part of the Music Player project
 * Copyright (c) 2014 - 2015 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QObject>
#include <QNetworkReply>
#include "musiclibexportglobal.h"
#include "musicobject.h"

class QNetworkAccessManager;

enum QueryType{ MusicQuery, MVQuery };

class MUSIC_CORE_EXPORT MusicDownLoadQueryThread : public QObject
{
    Q_OBJECT
public:
    explicit MusicDownLoadQueryThread(QObject *parent = 0);
    ~MusicDownLoadQueryThread();

    void deleteAll();
    void startSearchSong(QueryType type, const QString &text);
    void setSearchQuality(const QString &qual) { m_searchQuality = qual;}
    inline int getSongIdIndex() const { return m_musicSongInfo.size() + 1;}
    inline const MStringLists& getMusicSongInfo(){ return m_musicSongInfo;}

signals:
    void clearAllItems();
    void creatSearchedItems(const QString &songname,
                            const QString &artistname, const QString &time);

public slots:
    void searchFinshed();
    void replyError(QNetworkReply::NetworkError error);

protected:
    QNetworkAccessManager *m_manager;
    QNetworkReply *m_reply;
    MStringLists m_musicSongInfo;
    QString m_searchText;
    QueryType m_currentType;
    QString m_searchQuality;

};

#endif // MUSICDOWNLOADQUERYTHREAD_H
