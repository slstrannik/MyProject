#include "Form.h"
#include "ui_Form.h"
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>

Form::Form( QWidget * parent ) :
    QWidget( parent ),
    ui( new Ui::Form )
{
    ui->setupUi( this );
    this->db = new DBHandler{ this };
    ui->tableView->setModel( db->getModelIndexDB() );
    ui->tableView->horizontalHeader()->hideSection( 0 );
    ui->tableView->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
    ui->tableView->setSelectionMode( QAbstractItemView::SingleSelection );
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    this->setWindowTitle( "Редактирование базы данных" );
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_2_clicked()
{
    QAbstractItemModel * model = ui->tableView->model();
    ui->tableView->model()->insertRow(model->rowCount());
    QModelIndex modelIndex = ui->tableView->model()->index( model->rowCount() - 1, 1 );
    ui->tableView->selectionModel()->setCurrentIndex( modelIndex, QItemSelectionModel::SelectCurrent);
}

void Form::on_pushButton_clicked()
{
    ui->tableView->currentIndex().row();
    ui->tableView->model()->removeRow(ui->tableView->currentIndex().row());
}
