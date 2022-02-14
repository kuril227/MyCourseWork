#include "booking.hpp"
#include "ui_booking.h"

Booking::Booking(QWidget *parent) : QWidget(parent), ui(new Ui::Booking) {
    ui->setupUi(this);
}

Booking::~Booking() {
    delete ui;
}

void Booking::createUi() {
    ui->tableView->setModel(model);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

void Booking::setupModel(const QStringList &Headers) {
    model = new QSqlTableModel(this);
    model->setTable("Booking");
    model->select();
    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, Headers[j]);
    }
}

void Booking::OnBackClicked() {
    this->close();
}

void Booking::slotUpdateModel() {
    model->select();
}

void Booking::OnAddClicked() {
    booking_dialog_add *add_dialog = new booking_dialog_add();
    QObject::connect(add_dialog, &booking_dialog_add::AcceptClicked, this, &Booking::slotUpdateModel);
    add_dialog->setWindowTitle(trUtf8("Add booking"));
    add_dialog->exec();
}

