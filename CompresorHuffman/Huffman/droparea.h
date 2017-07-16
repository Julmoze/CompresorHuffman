/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef DROPAREA_H
#define DROPAREA_H

#include <QLabel>

#include <QMimeData>

/*! \class DropArea : public QLabel
    \brief Class for the drop recieving window
*/
class DropArea : public QLabel
{
    Q_OBJECT

public:

    /*! \fn DropArea(QWidget *parent = 0);
        \brief Constructor of the Drop Area
        \param Qwidget *parent Parent of the DropArea made
    */
    DropArea(QWidget *parent = 0);

public slots:


    /*! \fn void clear();
        \brief Slot that recieves a signal to return to the area to a default state
    */
    void clear();

signals:

    /*! \fn void changed(const QMimeData *mimeData = 0);
        \brief Signals if a change has occured in the dropArea
        \param const QMimeData *mimeData Recieves a data to Mimic, Deafult is 0(Nothing)
    */
    void changed(const QMimeData *mimeData = 0);

protected:

    /*! \fn void dragEnterEvent(QDragEnterEvent *event) override;
        \brief Sets the drop area when file is hovering above the drop area. Gives a
    preview.
        \param QDragEnterEvent *event pointer to the event
    */
    void dragEnterEvent(QDragEnterEvent *event) override;

    /*! \fn dragLeaveEvent(QDragLeaveEvent *event) override;
        \brief Resets the drop area to the default state after hovering
        \param QDragEnterEvent *event pointer to the event
    */
   void dragLeaveEvent(QDragLeaveEvent *event) override;

   /*! \fn dropEvent(QDropEvent *event) override;
       \brief Method that gets the file and applies a given function
       \param QDragEnterEvent *event pointer to the event
   */
    void dropEvent(QDropEvent *event) override;

    /*! \fn isValid( std::string addressInput );
        \brief Confirms if a given adress is valid for file management
        \param std::string address Input Address to validate
    */
    bool isValid( std::string addressInput );

private:
    QLabel *label;

};

#endif // DROPAREA_H

