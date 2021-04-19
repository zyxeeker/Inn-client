#pragma once

#include <QFrame>
#include <QHBoxLayout>
#include <QPainter>

class chat_frame:public QFrame {
	Q_OBJECT
public:
	chat_frame(QWidget *parent);

	void setMargin(int margin);

	void setWidget(QWidget *w);
protected:
	void paintEvent(QPaintEvent* e);
	void triangle(QRect & bk_rect, QPainter& painter, int x, int y, int width, int height);
	QRect bubble(QPainter& painter, QColor& color, int x, int y, int width, int height);
private:
	int m_margin;
	QHBoxLayout* m_pHLayout;
};