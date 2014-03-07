#ifndef FSWATCHER_H
#define FSWATCHER_H

#include <QObject>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <cstring>
#include <errno.h>
#include <assert.h>
#include <inotifytools/inotify.h>
#include <inotifytools/inotifytools.h>

#define DELETE_DELAY 5 // seconds

class FSWatcher : public QObject
{
    Q_OBJECT
public:
    explicit FSWatcher(QString path, QObject *parent = 0);
    void watch();
    ~FSWatcher();
    QString path() {return m_path;}

signals:
    void added(QString path, bool is_dir);
    void modified(QString path);
    void moved(QString path1, QString path2, bool is_dir);
    void deleted(QString path, bool is_dir);

private:
    void handleMovedAwayFile(QString path);
    QString m_path;
    int m_events;

};

#endif // FSWATCHER_H
