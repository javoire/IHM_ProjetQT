#ifndef GENRECHECKBOX_H
#define GENRECHECKBOX_H

#include <QCheckBox>

class genreCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    explicit genreCheckBox(QWidget *parent = 0);
    
signals:
    void isChecked(bool checked, QString name);
    
public slots:
    void getsChecked(bool checked);
};

#endif // GENRECHECKBOX_H
