//
// Created by zyx on 2021/8/16.
//

#include "text_editor.h"

TextEdit::TextEdit() {
    m_menu = new QMenu;
    m_aWidget = new QWidgetAction(m_menu);
    m_menuContainer = new QWidget(this);
    m_menuLayout = new QHBoxLayout;
    m_menuBody = new TextEditContentContextMenu;

    m_menuLayout->setContentsMargins(0, 0, 0, 0);
    m_menuLayout->addWidget(m_menuBody);
    m_menuContainer->setLayout(m_menuLayout);
    m_menuContainer->setMinimumHeight(80);
    m_menuContainer->setMinimumWidth(400);

    m_aWidget->setDefaultWidget(m_menuContainer);
    m_menu->setWindowFlags(Qt::FramelessWindowHint);
    m_menu->setWindowFlag(Qt::Popup, true);
    m_menu->setAttribute(Qt::WA_TranslucentBackground);
    m_menu->setStyleSheet("background:transparent;");
    m_menu->addAction(m_aWidget);
#ifdef Q_OS_WIN
    HWND hwnd = reinterpret_cast<HWND>(m_menu->winId());
    DWORD class_style = ::GetClassLong(hwnd, GCL_STYLE);
    class_style &= ~CS_DROPSHADOW;
    ::SetClassLong(hwnd, GCL_STYLE, class_style);
#endif

}

void TextEdit::contextMenuEvent(QContextMenuEvent *e) {
    if (this->document()->isEmpty())
        m_menuBody->SetBtnGroup(INPUT_AREA_EMPTY);
    else
        m_menuBody->SetBtnGroup(INPUT_AREA_NOT_EMPTY);
    m_menu->exec(QPoint(cursor().pos().x() - 30, cursor().pos().y() - 30));

}


TextEditor::TextEditor() {
    Init();
}

void TextEditor::Init() {
    InitTextBlock();
}

void TextEditor::InitTextBlock() {
    m_editBlock = new TextEdit;
    m_layout = new QHBoxLayout(this);

    m_layout->addWidget(m_editBlock);
    m_editBlock->setMinimumHeight(40);
    m_editBlock->setStyleSheet("QTextEdit{color:white;border-radius:6px;padding:5px;border:1px solid rgb(48, 48, 48);"
                               "color:white;font-family:'Microsoft YaHei UI';font-size:13px;selection-color: rgb(36, 36, 36);"
                               "background-color: rgb(36, 36, 36);selection-background-color: rgb(251, 174, 60);}"
                               "QTextEdit:focus{border-color: rgb(251, 174, 60);/*border-color: rgb(144, 187, 255);*/}");
    m_editBlock->setPlaceholderText("Wanna type something?");
    this->setLayout(m_layout);
}