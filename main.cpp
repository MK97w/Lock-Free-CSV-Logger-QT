
#include <QCoreApplication>
#include <QDir>
#include "xlsxdocument.h"
#include "qDebug.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include "directory_manager.h"
#include "date_time.h"


using namespace QXlsx;
directory_manager dirMan;
date_time dt;

void setExcelSheet(QXlsx::Document& doc)
{
    for(auto i = 2; i<14; i++)
    {
        doc.write(1,i, [=](){
                    QString res{};
                    if(0 == i% 4)
                       res+="Type 3 ";
                    else if(1 == i% 4)
                       res+="Type 4 ";
                    else if(2 == i% 4)
                       res+="Type 1 ";
                    else
                        res+="Type 2 ";

                    if(i<5)
                        res+="- Option 1";
                    else if(i<9)
                        res+="- Option 2";
                    else
                        res+="- Option 3";
                    return res;

        }());
        doc.setColumnWidth(i,16); //found with error and trial
    }
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QXlsx::Document xlsx;

    dirMan.createNewDirUnderMain(dt.today());

    //setExcelSheet(xlsx);
    //xlsx.write("A1", "Hello Qt!"); // write "Hello Qt!" to cell(A,1). it's shared string.
    //xlsx.saveAs(formattedTime+".xlsx"); // save the document as 'Test.xlsx'

    return 0;
    //return a.exec();
}
