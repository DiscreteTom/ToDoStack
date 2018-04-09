#ifndef FUNCBTN_H
#define FUNCBTN_H

#include <QWidget>
#include <QPushButton>

class funcBtn : public QPushButton
{
	Q_OBJECT
public:
	enum FuncBtnType{DELETE, UP};

	funcBtn(QWidget * parent = NULL, FuncBtnType type = funcBtn::FuncBtnType::DELETE, int index = 0);

	FuncBtnType m_type;
	int m_index;//from 0, from top
public slots:
	void getClick();

signals:
	void sendIndex(int index);
};

#endif // FUNCBTN_H
