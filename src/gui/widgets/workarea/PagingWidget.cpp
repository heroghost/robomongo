#include "PagingWidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include "GuiRegistry.h"

using namespace Robomongo;

PagingWidget::PagingWidget()
{
    _skipEdit = new QLineEdit;
    _limitEdit = new QLineEdit;
    _skipEdit->setAlignment(Qt::AlignHCenter);
    _skipEdit->setToolTip("Skip");
    _limitEdit->setAlignment(Qt::AlignHCenter);
    _limitEdit->setToolTip("Limit");

    QFontMetrics metrics = _skipEdit->fontMetrics();
    int width = metrics.boundingRect("000000").width();
    _skipEdit->setFixedWidth(width);
    _limitEdit->setFixedWidth(width);

    QPushButton *leftButton = createButtonWithIcon(GuiRegistry::instance().leftIcon());
    QPushButton *rightButton = createButtonWithIcon(GuiRegistry::instance().rightIcon());

    QHBoxLayout *layout = new QHBoxLayout();
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    layout->addWidget(leftButton);
    layout->addSpacing(0);
    layout->addWidget(_skipEdit);
    layout->addSpacing(1);
    layout->addWidget(_limitEdit);
    layout->addSpacing(0);
    layout->addWidget(rightButton);
    setLayout(layout);
}

void PagingWidget::setSkip(int skip)
{
    _skipEdit->setText(QString::number(skip));
}

void PagingWidget::setLimit(int limit)
{
    _limitEdit->setText(QString::number(limit));
}

QPushButton *PagingWidget::createButtonWithIcon(const QIcon &icon)
{
    QPushButton *button = new QPushButton;
    button->setIcon(icon);
    button->setFixedSize(24, 24);
    button->setFlat(true);
    return button;
}


