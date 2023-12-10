
#include <QCoreApplication>
#include "xlsxdocument.h"
#include "qDebug.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QXlsx::Document xlsx;



    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("Log_hh_mm");
    //QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();

    xlsx.write("A1", "Hello Qt!"); // write "Hello Qt!" to cell(A,1). it's shared string.
    xlsx.saveAs(formattedTime+".xlsx"); // save the document as 'Test.xlsx'

    return 0;
    //return a.exec();
}
