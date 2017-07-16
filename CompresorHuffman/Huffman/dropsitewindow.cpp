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

#include <iostream>
#include <string>
#include <QtWidgets>

#include "dropsitewindow.h"
#include "huffman.h"

DropSiteWindow::DropSiteWindow()
{
    /*!
    \brief Labels, drop area, display table, and buttons are created for the main layout in that order.
    */
    abstractLabel = new QLabel(tr("Drag a .txt or .huf file to the square area below. The program will detect the extensions "
                                  "and compress or decompress depending on it."));
    abstractLabel->setWordWrap(true);
    abstractLabel->adjustSize();

    dropArea = new DropArea;
    connect(dropArea, &DropArea::changed,
            this, &DropSiteWindow::updateFormatsTable);

    QStringList labels;
    labels << tr("Action") << tr("Extension");

    formatsTable = new QTableWidget;
    formatsTable->setColumnCount(2);
    formatsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    formatsTable->setHorizontalHeaderLabels(labels);
    formatsTable->horizontalHeader()->setStretchLastSection(true);

    clearButton = new QPushButton(tr("Clear"));
    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(clearButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(quitButton, &QAbstractButton::pressed, this, &QWidget::close);
    connect(clearButton, &QAbstractButton::pressed, dropArea, &DropArea::clear);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(abstractLabel);
    mainLayout->addWidget(dropArea);
    mainLayout->addWidget(formatsTable);
    mainLayout->addWidget(buttonBox);

    setWindowTitle(tr("Huffman Compressor"));
    setMinimumSize(350, 500);
}

bool DropSiteWindow::addressInputIsValid( std::string addressInput )
{
    char ext = addressInput.length() - 3;

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

void DropSiteWindow::updateFormatsTable(const QMimeData *mimeData)
{
    /*!
    \brief Format table is updated depending on signals from the drop area. It displays information when needed.
    */
    formatsTable->setRowCount(0);
    if (!mimeData)
        return;

    foreach (QString format, mimeData->formats()) {
        QTableWidgetItem *formatItem = new QTableWidgetItem(format);
        formatItem->setFlags(Qt::ItemIsEnabled);
        formatItem->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);

        QString text;
        QString text1;
        QList<QUrl> urlList = mimeData->urls();
        for (int i = 0; i < urlList.size() && i < 32; ++i)
            text1.append(urlList.at(i).toString() + QLatin1Char(' '));

        char direccionEntradaTemp [1024];
        char direccionEntrada [1024];
        strcpy(direccionEntradaTemp, text1.toStdString().c_str() );

        int i;
        for( i = 7; direccionEntradaTemp[i] != ' '; i++ )
        {
            direccionEntrada[i-7] = direccionEntradaTemp[i];
        }
        direccionEntrada[i-7] = '\0';

        if( addressInputIsValid(direccionEntrada) )
        {
            text = (direccionEntrada[i-10] + direccionEntrada[i-9] + direccionEntrada[i-8] == 352)?".txt":".huf" ;
            format = (direccionEntrada[i-10] + direccionEntrada[i-9] + direccionEntrada[i-8] == 352)?"Compression":"Decompression" ;
        }else
        {
            text ="Data extension is invalid";
            format = "NA";
        }

        int row = formatsTable->rowCount();
        formatsTable->insertRow(row);
        formatsTable->setItem(row, 0, new QTableWidgetItem(format));
        formatsTable->setItem(row, 1, new QTableWidgetItem(text));
    }

    formatsTable->resizeColumnToContents(0);
}
