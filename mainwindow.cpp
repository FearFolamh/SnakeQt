#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(320,370);
    m_gameField = new GameField();
    m_cenralWidget = new QWidget();
    m_helpField = new HelpField();
    connect(m_gameField,&GameField::ChangeTextSignal, m_helpField,&HelpField::ChangeTextSlot);
    m_gridLayout = new QGridLayout();
    m_gridLayout ->addWidget(m_gameField,0,0);
    m_gridLayout ->addWidget(m_helpField,1,0);
    m_cenralWidget ->setLayout(m_gridLayout);
    setCentralWidget(m_cenralWidget);
}

MainWindow::~MainWindow() {}
