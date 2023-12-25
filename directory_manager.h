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

signals:


private:
    const QString mainDirectory;
    QString currentDir{};
};

#endif // DIRECTORY_MANAGER_H
