/****************************************************************************
**
** Copyright (C) 2014 Canonical Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtLocation module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qgeotilefetchermapbox.h"
#include "qgeomapreplymapbox.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtLocation/private/qgeotilespec_p.h>
#include <QDebug>

QT_BEGIN_NAMESPACE

QGeoTileFetcherMapbox::QGeoTileFetcherMapbox(QObject *parent)
:   QGeoTileFetcher(parent), m_networkManager(new QNetworkAccessManager(this)),
    m_userAgent("Qt Location based application"),
    m_mapId(""),
    m_format("png"),
    m_replyFormat("png"),
    m_accessToken("")
{
}

void QGeoTileFetcherMapbox::setUserAgent(const QByteArray &userAgent)
{
    m_userAgent = userAgent;
}

void QGeoTileFetcherMapbox::setMapId(const QString &mapId)
{
    m_mapId = mapId;
}

void QGeoTileFetcherMapbox::setFormat(const QString &format)
{
    m_format = format;

    if (m_format == "@2x.png" || m_format == "png" || m_format == "png32" || m_format == "png64" || m_format == "png128" || m_format == "png256")
        m_replyFormat = "png";
    else if (m_format == "jpg70" || m_format == "jpg80" || m_format == "jpg90")
        m_replyFormat = "jpg";
    else
        qWarning() << "Unknown map format " << m_format;
}

void QGeoTileFetcherMapbox::setAccessToken(const QString &accessToken)
{
    m_accessToken = accessToken;
}

QGeoTiledMapReply *QGeoTileFetcherMapbox::getTileImage(const QGeoTileSpec &spec)
{
    QNetworkRequest request;
    request.setRawHeader("User-Agent", m_userAgent);

    request.setUrl(QUrl(QString("http://api.tiles.mapbox.com/v4/%1/%2/%3/%4%5%6?access_token=%7").
                        arg(m_mapId).
                        arg(spec.zoom()).
                        arg(spec.x()).
                        arg(spec.y()). 
                        arg(m_format.indexOf(QLatin1Char('.')) == -1 ? "." : "").
                        arg(m_format).
                        arg(m_accessToken)));

    QNetworkReply *reply = m_networkManager->get(request);

    return new QGeoMapReplyMapbox(reply, spec, m_replyFormat);
}

QT_END_NAMESPACE
