#include "exceladapter.h"
#include <iostream>
//#include "C:\Qt\Qt5.10.1\5.10.1\msvc2017_64\include\ActiveQt\qaxobject.h"
using std::cout;
using std::endl;

exceladapter::exceladapter()
{

}

void exceladapter::readfile2(QString filename, QString sheetname, int colNo)
{
   QFile *file=new QFile(filename);
   file->open(QIODevice::ReadOnly|QIODevice::Text);
   QString data = QString(file->readAll());
   QStringList strList= data.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
   QStringList::iterator it;
   for(it=strList.begin();it!=strList.end();it++)
   {
       stringlist.append(*it);
       valuelist.append(*it);
       cout<<QString(*it).toStdString()<<"1"<<endl;
   }
   cout<<stringlist.length()<<endl;
}


void exceladapter::readfile(QString filename, QString sheetname, int colNo)
{
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "excelexport");
if(!db.isValid())
{
return;
}
QString dsn = QString("DRIVER={Microsoft Excel Driver (*.xls)};DSN=''; FIRSTROWHASNAMES=1; READONLY=FALSE;CREATE_DB=\"%1\";DBQ=%2").
arg(filename).arg(filename);
db.setDatabaseName(dsn);

if(!db.open())
{
return;
}


QSqlQuery query(db);
query.exec("select * from"+sheetname);
while (query.next())
{
valuelist.append(query.value(colNo));
}
db.close();
}
