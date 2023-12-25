#ifndef DIRECTORY_MANAGER_H
#define DIRECTORY_MANAGER_H

#include <QObject>
#include <QDir>

class directory_manager : public QObject
{
    Q_OBJECT
public:
    explicit directory_manager(QObject *parent = nullptr);
    QString get_dirName();
    void createNewDirUnderMain(QString);

signals:


private:
    const QString m_mainDirName;
    QString currentPath{};
    QDir mainDir;
};

#endif // DIRECTORY_MANAGER_H
