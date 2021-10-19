//
// Created by zyx on 2021/10/18.
//

#include "dev_widget.h"
#include <QTextEdit>
#include <QDebug>

DevWidget::DevWidget(QWidget *parent) : QMainWindow(parent) {
    m_app = new QWidget(this);
    m_layout = new QVBoxLayout(m_app);
    m_cef = new CefWidget(m_app);
    m_devTool = new QDockWidget(tr("DEV TOOL"), this);
    InitUi();
    connect(m_cef, &CefWidget::OpenDevTools, this, &DevWidget::OnDevTools);
}

void DevWidget::InitUi() {
    m_layout->addWidget(m_cef);
    m_devTool->setFeatures(
            QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    setCentralWidget(m_cef);
    m_devTool->setAllowedAreas(Qt::AllDockWidgetAreas);
    m_devTool->setFeatures(
            QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);
    m_devTool->setMinimumWidth(300);
}

void DevWidget::OnDevTools() {
    if (!m_hasDevTools) {
        m_tools = new CefDevTools(m_cef->GetInstance());
        m_devTool->setWidget(m_tools);
        addDockWidget(Qt::LeftDockWidgetArea, m_devTool);
        m_devTool->show();
        m_hasDevTools = true;
    } else {
        m_devTool->close();
        m_tools->close();
        m_hasDevTools = false;
    }
}