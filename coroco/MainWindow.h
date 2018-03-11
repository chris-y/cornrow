#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <rpc/client.h>

#include "ZeroconfWrapper.h"
#include "protocol/ProtocolAdaptersV1.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_portBox_valueChanged(int i);

    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_filterComboBox_currentIndexChanged(int i);
    void on_freqSpinBox_valueChanged(double);
    void on_gainSpinBox_valueChanged(double g);
    void on_qSpinBox_valueChanged(double);

    void onServiceDiscovered(QString hostname, QString address, quint16 port);

private:
    void enableFilterWidgets(bool enable);

    Ui::MainWindow *ui;
    ZeroconfWrapper m_zeroconf;
    rpc::client*    m_rpcClient = nullptr;
    v1::ClientProtocolAdapter* m_protocolAdapter = nullptr;

    struct Filter {
        int     f = 68;
        float   g = 0.0;
        int     q = 17;
    };
    std::vector<Filter> m_filters;
};

#endif // MAINWINDOW_H
