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
    return  QDateTime::currentDateTime().toString("hh_mm");
}
