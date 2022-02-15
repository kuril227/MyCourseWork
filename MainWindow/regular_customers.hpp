#ifndef REGULAR_CUSTOMERS_HPP_
#define REGULAR_CUSTOMERS_HPP_

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QSqlTableModel>
#include <QTableView>

namespace Ui { class RegularCustomers; }

class RegularCustomers : public QWidget {
Q_OBJECT

public:
    explicit RegularCustomers(QWidget *parent = nullptr);

    ~RegularCustomers() noexcept;

public:
    void createUi();

    void setupModel(const QStringList &);

private slots:

    void OnBackClicked();

private:
    Ui::RegularCustomers *ui;
    QSqlTableModel *model;
//    DataBaseInterface db;
};


#endif // REGULAR_CUSTOMERS_HPP_
