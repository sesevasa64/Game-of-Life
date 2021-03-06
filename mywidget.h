#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>
#include <QTimer>
#include <QElapsedTimer>
#include "grid.h"

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent);
    ~MyWidget();
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent * event) override;
public slots:
    void tick();
    void swapTime();
    void eraseAll();
    void speedUp();
    void speedDown();
    void setColor();
    void saveColony();
    void loadColony();
signals:
    void sizeChanged(int size);
    void newGeneration(int i);
    void scaleChanged(double scale);
    void statusChanged(QString str);
    void menuStatusChanged(QString str);
    void intervalChanged(int interval);
private:
    QTimer *colony_timer;
    QTimer *render_timer;
    Camera *camera;
    Colony *colony;
    Grid *grid;
    QElapsedTimer timer;
};

#endif // MYWIDGET_H
