#include "mainwindow.h"
#include "ui_mainwindow.h"

#define REF			5.08

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DEV_Module_Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    UDOUBLE ADC[10];
    UDOUBLE adc1;
    int k=0;
    ADS1263_SetMode(0);

    if(ADS1263_init_ADC1(ADS1263_1200SPS) == 1) {

        DEV_Module_Exit();
        qDebug()<<"in1";

        exit(0);
    }

    //ADS1263_GetAll(ADC);
    while(1) {
        //reading all channel
        /*
        ADS1263_GetAll(ADC);
        for(int i=0; i<1; i++) {
            if((ADC[i]>>31) == 1)
                qDebug()<<k<<" "<<i<<" "<<(REF*2 - ADC[i]/2147483648.0 * REF);
            else
                qDebug()<<k<<" "<<i<<" "<<(ADC[i]/2147483648.0 * REF);
            k++;
        }
        */

        //reading one channel

        adc1=ADS1263_GetChannalValue(0);
        qDebug()<<k<<" "<<adc1;
        k++;

    }
}
