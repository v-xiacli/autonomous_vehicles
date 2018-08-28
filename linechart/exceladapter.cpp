#include "exceladapter.h"
#include <iostream>

using std::cout;
using std::endl;

exceladapter::exceladapter()
{

}


void exceladapter::readfile(QString filename, QString sheetname, int colNo)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "excelexport");
	if (!db.isValid())
	{
		return;
	}
	QString dsn = QString("DRIVER={Microsoft Excel Driver (*.xls)};DSN=''; FIRSTROWHASNAMES=1; READONLY=FALSE;CREATE_DB=\"%1\";DBQ=%2").
		arg(filename).arg(filename);
	db.setDatabaseName(dsn);

	if (!db.open())
	{
		return;
	}


	QSqlQuery query(db);
	query.exec("select * from" + sheetname);
	do
	{
		valuelist.append(query.value(colNo));
		QString val = (valuelist.end() - 1)->toString();
		stringlist.append(val);
	} while (query.next());
	db.close();
}
