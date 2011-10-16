/***************************************************************************
 *   Copyright (C) 2010 by Abhishek Patil <abhishek@thezeroth.net>         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#include "OpenGLWidget.h"
#include <QKeyEvent>

struct OpenGLWidgetData
{
    GLfloat angle;
};

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    d = new OpenGLWidgetData;
    d->angle = 0;
}

OpenGLWidget::~OpenGLWidget()
{
    delete d;
}

void OpenGLWidget::initializeGL()
{
    glClearColor(0, 0, 0, 1);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(d->angle, 0, 0, 1);

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0, 1, 0); // Color
        glVertex2f(0.1, 0.1);
        glVertex2f(0.0, 0.2);
        glVertex2f(-0.1, 0.1);
        glVertex2f(-0.2, 0);
        glVertex2f(-0.1, -0.1);
        glVertex2f(0, -0.2);
        glVertex2f(0.1, -0.1);
        glVertex2f(0.2, 0);
        glVertex2f(0.1, 0.1);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1, 0, 0); // Color
        glVertex2f(0, 0);// Center
        glVertex2f(0.1, 0.1);
        glVertex2f(-0.1, 0.1);
        glVertex2f(-0.1, -0.1);
        glVertex2f(0.1, -0.1);
        glVertex2f(0.1, 0.1);
    glEnd();
}

void OpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glOrtho(-1, 1, -1, 1, -1, 1);

    updateGL();
}

void OpenGLWidget::keyPressEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_A)
    {
        d->angle += 10;
        updateGL();
    }
}
