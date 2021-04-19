#include "chat_frame.h"


chat_frame::chat_frame(QWidget *parent):QFrame(parent), m_margin(3) {
	m_pHLayout = new QHBoxLayout();
	m_pHLayout->setContentsMargins(m_margin, m_margin, 8 + m_margin, m_margin);

	this->setLayout(m_pHLayout);
}

void chat_frame::setMargin(int margin) {

}

void chat_frame::setWidget(QWidget* w) {
	if (m_pHLayout->count() > 0)
		return;
	else {
		m_pHLayout->addWidget(w);
	}
}

QRect chat_frame::bubble(QPainter& painter, QColor& color, int x, int y, int width, int height) {
	QRect bk_rect = QRect(x, y, width, height);
	painter.drawRoundedRect(bk_rect, 5, 5);
	return bk_rect;
}

void chat_frame::triangle(QRect& bk_rect, QPainter& painter, int x, int y, int width, int height) {
	QPointF points[3] = {
	QPointF(bk_rect.x(), 12),
	QPointF(bk_rect.x(), 10 + 8 + 2),
	QPointF(bk_rect.x() - 8, 10 + 8 - 8 / 2),
	};
	painter.drawPolygon(points, 3);
}

void chat_frame::paintEvent(QPaintEvent* e) {
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	QColor bk_color(Qt::blue);
	QRect rect = bubble(painter, bk_color, 8, 0, this->width() - 8, this->height());
	triangle(rect, painter,0,0,0,0);
	return QFrame::paintEvent(e);
}