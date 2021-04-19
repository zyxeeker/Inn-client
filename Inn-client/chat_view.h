#pragma once
#include <QScrollArea>
#include <QVBoxLayout>
#include <QTimer>

class ChatView:public QWidget {
	Q_OBJECT
public:
	ChatView(QWidget *parent);
	void appendChatItem(QWidget* item);
private slots:
	void onVScrollBarMoved(int min, int max);
private:
	void initStyleSheet();
private:
	QVBoxLayout* m_v_layout;
	QScrollArea* m_scroll_area;
	bool isAppended;
};