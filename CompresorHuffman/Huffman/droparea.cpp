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

#include "droparea.h"
#include "huffman.h"

#include <QDragEnterEvent>

#include <iostream>

DropArea::DropArea(QWidget *parent)
    : QLabel(parent)
{
    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAlignment(Qt::AlignCenter);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    clear();
}

void DropArea::dragEnterEvent(QDragEnterEvent *event)
{
    setText(tr("<Drop File Here>"));
    setBackgroundRole(QPalette::Highlight);

    event->acceptProposedAction();
    emit changed(event->mimeData());
}

bool DropArea::isValid( std::string addressInput )
{
    char ext = addressInput.length() - 3;
    /*!
    \brief Only .txt and .huf are accepted. Last three letters of the address are checked to determine this.
    */
    if( tolower(addressInput[ext]) == 'h' && tolower(addressInput[ext+1]) == 'u' && tolower(addressInput[ext+2]) == 'f'  )

    {
        return true;
    }

    if( tolower(addressInput[ext]) == 't' && tolower(addressInput[ext+1]) == 'x' && tolower(addressInput[ext+2]) == 't'  )
    {
        return true;
    }

    return false;
}

void DropArea::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();

    QString text1;
    QList<QUrl> urlList = mimeData->urls();
    for (int i = 0; i < urlList.size() && i < 32; ++i)
        text1.append(urlList.at(i).toString() + QLatin1Char(' '));
    /*!
    \brief File adress is attached to the text.
    */
    char direccionEntradaTemp [1024];
    char direccionEntrada [1024];
    strcpy(direccionEntradaTemp, text1.toStdString().c_str() );
    /*!
    \brief Then it is converted to a c String so the Huffman.cpp can process it correctly, when given to it.
    */
    size_t i;
    for( i = 7; i < text1.toStdString().length() - 1; i++ )
    {
        direccionEntrada[i-7] = direccionEntradaTemp[i];
    }
    direccionEntrada[i-7] = '\0';
    /*!
    \brief Before accepting a compression, the Adress is checked to be valid.
    */
    if( isValid(direccionEntrada) )
    {
        text1 =direccionEntrada;
        Huffman huffmanCom;
        huffmanCom.start(direccionEntrada);
    }else
    {
        text1 ="Data extension is invalid";
    }

    setText( text1 );
    setTextFormat(Qt::PlainText);
    setBackgroundRole(QPalette::Dark);
    event->acceptProposedAction();
}

void DropArea::dragLeaveEvent(QDragLeaveEvent *event)
{
    clear();
    event->accept();
}

void DropArea::clear()
{
    setText(tr("<Drop File Here>"));
    setBackgroundRole(QPalette::Dark);

    emit changed();
}
