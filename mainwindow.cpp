#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

typedef class LIK{
private:
	QString ime, prezime, shifra;
public:
	LIK(){
		ime.append("");
		prezime.append("");
		shifra.append("");
	}
	LIK(QString IME, QString PRE, QString SHIFRA){
		if(IME.length() < 20){
			ime.clear();
			ime.append(IME);
		}else{
			exit(1);
		}
		if(PRE.length() < 20){
			prezime.clear();
			prezime.append(PRE);
		}else{
			exit(1);
		}
		if(SHIFRA.length() < 6){
			shifra.clear();
			shifra.append(SHIFRA);
		}else{
			exit(1);
		}
	}
	QString getIME(){	return ime;		}
	QString getPRE(){	return prezime;	}
	QString getSHI(){	return shifra;	}
	void setIME(QString IME){	ime.clear();	ime.append(IME);		}
	void setPRE(QString PRE){	prezime.clear();	prezime.append(PRE);		}
	void setSHI(QString SHI){	shifra.clear();	shifra.append(SHI);		}

}LIK;

typedef struct node{
	class LIK musht;
	node* next;
}node;

LIK nibbas[10];
int i = 0;

void MainWindow::on_enter_clicked(){
	class LIK bro(ui->IMEedit->text(), ui->PREedit->text(), ui->SHIedit->text());
	nibbas[i] = bro;
	//node newNode;
	//newNode.musht = bro;
	//json j1 = {
	//	{"Ime", nibba.getIME().toStdString()},
	//	{"Prezime", nibba.getPRE().toStdString()},
	//	{"Shifra", nibba.getSHI().toStdString()}
	//};
	ui->StatLabel->setText("DONE");
}

