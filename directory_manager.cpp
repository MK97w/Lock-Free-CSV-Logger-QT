#include "directory_manager.h"
#include "qdebug.h"

directory_manager::directory_manager(QObject *parent)
    : QObject{parent},
      m_mainDirName{"C:/Application_Results"}

{
    mainDir.setPath(m_mainDirName);
    if( !mainDir.exists() )
    {
        mainDir.mkdir(m_mainDirName);
         qDebug()<<"Main dir created";
    }
    else
        qDebug()<<"Main dir already exists";
}

void directory_manager::createNewDirUnderMain(QString newDirName)
{
    currentPath = m_mainDirName+"/"+newDirName;
    QDir newDir( currentPath );
    if( !newDir.exists() )
    {
        newDir.mkdir(currentPath);
        qDebug()<<"New dir created";
    }
    else
        qDebug()<<currentPath<<" already exists";

}
