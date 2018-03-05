#include "funcbtn.h"

funcBtn::funcBtn(QWidget *parent, funcBtn::FuncBtnType type, int index)
    : QPushButton(parent)
{
    m_type = type;
    m_index = index;

    if (type == FuncBtnType::DELETE){
        setText(tr("X"));
    } else if (type == FuncBtnType::UP){
        setText(tr("up"));
    }
    setFixedWidth(50);
}

void funcBtn::getClick()
{
    emit sendIndex(m_index);
}
