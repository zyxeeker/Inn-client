#include "chat_view.h"
#include <QScrollBar>
#include <QEvent>

ChatView::ChatView(QWidget* parent) :QWidget(parent), isAppended(false) {
	QVBoxLayout* pMainLayout = new QVBoxLayout();
	this->setLayout(pMainLayout);
	pMainLayout->setMargin(0);

	m_scroll_area = new QScrollArea();
	pMainLayout->addWidget(m_scroll_area);

	QWidget* w = new QWidget(this);
	w->setPalette(QColor(215, 215, 215));
	w->setAutoFillBackground(true);

	QVBoxLayout* pHLayout_1 = new QVBoxLayout();
	pHLayout_1->addWidget(new QWidget(), 100000);
	w->setLayout(pHLayout_1);
	m_scroll_area->setWidget(w);

	m_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	QScrollBar* pVScrollBar = m_scroll_area->verticalScrollBar();
	connect(pVScrollBar, &QScrollBar::rangeChanged, this, &ChatView::onVScrollBarMoved);

	QHBoxLayout* pHLayout_2 = new QHBoxLayout();
	pHLayout_2->addWidget(pVScrollBar, 0, Qt::AlignRight);
	pHLayout_2->setMargin(0);
	m_scroll_area->setLayout(pHLayout_2);
	pVScrollBar->setHidden(true);

	m_scroll_area->setWidgetResizable(true);
	m_scroll_area->installEventFilter(this);
	initStyleSheet();
}

void ChatView::appendChatItem(QWidget* item) {
	QVBoxLayout* vl = qobject_cast<QVBoxLayout*>(m_scroll_area->widget()->layout());
	vl->insertWidget(vl->count() - 1, item);
	isAppended = true;
}

void ChatView::onVScrollBarMoved(int min, int max)
{
	if (isAppended) //添加item可能调用多次
	{
		QScrollBar* pVScrollBar = m_scroll_area->verticalScrollBar();
		pVScrollBar->setSliderPosition(pVScrollBar->maximum());
		//500毫秒内可能调用多次
		QTimer::singleShot(500, [this]()
		{
			isAppended = false;
		});
	}
}

void ChatView::initStyleSheet() {
	QScrollBar* scrollBar = m_scroll_area->verticalScrollBar();
	scrollBar->setStyleSheet("QScrollBar{background:transparent;}"
		"QScrollBar:vertical{background:transparent;width:8px;}"
		"QScrollBar::handle:vertical{background:red; border-radius:4px;min-height:20px;}"
		"QScrollBar::add-line:vertical{height:0px}"
		"QScrollBar::sub-line:vertical{height:0px}"
		"QScrollBar::add-page:vertical {background:transparent;}"
		"QScrollBar::sub-page:vertical {background:transparent;}");
}