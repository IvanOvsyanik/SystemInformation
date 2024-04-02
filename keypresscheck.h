#ifndef KEYPRESSCHECK_H
#define KEYPRESSCHECK_H

#include <QObject>

class Keypresscheck : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString resultText READ resultText WRITE setResultText NOTIFY resultTextChanged)

public:
    explicit Keypresscheck(QObject *parent = nullptr);

    QString resultText() const;
    void setResultText(const QString &text);

signals:
    void resultTextChanged();

public slots:
    void keypress();

private:
    QString m_resultText;
};

#endif // KEYPRESSCHECK_H
