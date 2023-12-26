#include "date_time.h"

date_time::date_time(QObject *parent)
    : QObject{parent}
{

}

QString date_time::today()
{
    return  QDateTime::currentDateTime().toString("dd_MM_yyyy");
}

QString date_time::now()
{
    return  QDateTime::currentDateTime().toString("hh:mm");
}

QString date_time::now(int)
{
    return  QDateTime::currentDateTime().toString("hh.mm");
}

void date_time::set_applicationStartTime(QString str_time)
{
    applicationStartTime = str_time;
}

QString date_time::get_applicationStartTime()
{
    return applicationStartTime;
}
