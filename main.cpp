#include <QCoreApplication>
#include "fswatcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FSWatcher w("/home/xlab/Documents/", &a);

    QObject::connect(&w, &FSWatcher::added, [=](QString path, bool is_dir){
       qDebug() << "ADDED:" << path << "(dir:" << is_dir << ")";
    });
    QObject::connect(&w, &FSWatcher::modified, [=](QString path){
       qDebug() << "MODIFIED:" << path;
    });
    QObject::connect(&w, &FSWatcher::deleted, [=](QString path, bool is_dir){
       qDebug() << "REMOVED:" << path << "(dir:" << is_dir << ")";
    });
    QObject::connect(&w, &FSWatcher::moved, [=](QString path1, QString path2, bool is_dir){
       qDebug() << "RENAMED:" << path1 << "=->" << path2 << "(dir:" << is_dir << ")";
    });

    w.watch();
    return a.exec();
}
