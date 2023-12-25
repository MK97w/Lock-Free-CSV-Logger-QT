#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <QObject>
#include <QDateTime>


class date_time : public QObject
{
    Q_OBJECT
public:
    explicit date_time(QObject *parent = nullptr);

    QString today();
    QString now();

signals:

};

#endif // DATE_TIME_H
