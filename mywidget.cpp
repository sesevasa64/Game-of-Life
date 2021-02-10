#include "mywidget.h"
#include "manager.h"
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QResizeEvent>
#include <QLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , colony_timer(new QTimer)
    , render_timer(new QTimer)
    , camera(new Camera)
    , colony(new Colony)
    , grid(new Grid(camera))
{
    connect(colony_timer, SIGNAL(timeout()), this, SLOT(tick()));
    connect(render_timer, SIGNAL(timeout()), this, SLOT(update()));
    colony_timer->start(1000);
    render_timer->start(1000 / 60.);
    setMouseTracking(true);
    setFocus();

    timer.start();
}

MyWidget::~MyWidget()
{
   delete colony_timer;
   delete render_timer;
   delete grid;
   delete colony;
   delete camera;
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    grid->draw(&painter, colony);

    static int frames = 0;
    frames++;
    if (timer.elapsed() >= 1000) {
        double fps = frames / ((double)timer.elapsed()/1000.0);
        qInfo() << fps;
        frames = 0;
        timer.restart();
    }
}

void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint cursor = mapFromGlobal(QCursor::pos());
    if (event->buttons() == Qt::LeftButton) {
       camera->Move(cursor);
       camera->SetMousePosition(cursor);
    }
    grid->updateBorders(width(), height());
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    Qt::MouseButton button = event->button();
    QPoint cursor = mapFromGlobal(QCursor::pos());
    if (button == Qt::MouseButton::LeftButton)
    {
        camera->SetMousePosition(cursor);
    }
    else if (button == Qt::MouseButton::RightButton)
    {
        vec2d c(cursor.x(), cursor.y());
        vec2i pos = camera->toWorld(c);
        pos.x = floor(pos.x / double(grid->cell_size));
        pos.y = floor(pos.y / double(grid->cell_size));
        if (colony->isExist(pos)) {
            colony->remove(pos);
        }
        else {
            colony->create(pos);
        }
    }
}

void MyWidget::wheelEvent(QWheelEvent *event)
{
    QPoint cursor = mapFromGlobal(QCursor::pos());
    int delta = event->angleDelta().y();
    camera->Zoom(cursor, delta);
    grid->updateBorders(width(), height());
    grid->updateSize(camera->getScale());
    emit scaleChanged(camera->getScale());
}

void MyWidget::resizeEvent(QResizeEvent *event)
{
    QSize size = event->size();
    grid->updateBorders(size.width(), size.height());
}

void MyWidget::keyPressEvent(QKeyEvent * event)
{
    int key = event->key();
    if(key == Qt::Key::Key_P || key == 1047)
    {
        swapTime();
    }
    else if(key == Qt::Key::Key_Equal)
    {
        speedUp();
    }
    else if(key == Qt::Key::Key_Minus)
    {
        speedDown();
    }
}

void MyWidget::tick()
{
    static int i = 0;
    colony->tick();
    emit sizeChanged(colony->size());
    emit newGeneration(++i);
}

void MyWidget::swapTime()
{
    if(colony_timer->isActive())
    {
        colony_timer->stop();
        emit statusChanged("Пауза");
        emit menuStatusChanged("Возобновить");
    }
    else
    {
        colony_timer->start();
        emit statusChanged("Идет симуляция");
        emit menuStatusChanged("Пауза");
    }
}

void MyWidget::speedUp()
{
    int interval = colony_timer->interval() - 250;
    colony_timer->setInterval(interval);
    emit intervalChanged(interval);
}

void MyWidget::speedDown()
{
    int interval = colony_timer->interval() + 250;
    colony_timer->setInterval(interval);
    emit intervalChanged(interval);
}

void MyWidget::setColor()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        grid->setColor(color);
    }
}

void MyWidget::saveColony()
{
    QString filename = QFileDialog::getSaveFileName();
    if (!filename.isEmpty()) {
        Manager::save_colony(*colony, filename);
    }
}

void MyWidget::loadColony()
{
    QString filename = QFileDialog::getOpenFileName();
    if (!filename.isEmpty()) {
        *colony = Manager::load_colony(filename);
    }
}

void MyWidget::eraseAll()
{
    (*colony) = Colony();
}
