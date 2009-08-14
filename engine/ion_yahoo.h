/***************************************************************************
 *   Copyright (C) 2009-2009 by Amos Kariuki <amoskahiga@gmail.com>        *
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
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA          *
 ***************************************************************************/

/* Ion for Yahoo's Weather */

#ifndef ION_YAHOO_H
#define ION_YAHOO_H

#include <QtXml/QXmlStreamReader>
#include <QRegExp>
#include <QtCore/QStringList>
#include <QDateTime>
#include <QDebug>
#include <QHttp>
#include <kio/job.h>
#include <plasma/dataengine.h>
#include <plasma/weather/weatherutils.h>
#include <plasma/weather/ion.h>

class KDE_EXPORT YahooIon : public IonInterface
{
    Q_OBJECT

public:
    YahooIon(QObject *parent, const QVariantList &args);
    ~YahooIon();
    void init();  // Setup the city location, fetching the correct URL name.
    bool updateIonSource(const QString& source);

public slots:
    virtual void reset();

private slots:
    void slotDataArrived(KIO::Job *job, const QByteArray &data);
    void slotJobFinished(KJob *);

private:
    // Members
    struct WeatherData
    {
        QString ttl;

        struct
        {
            QString country;
            QString region;
            QString city;
            QString latitude;
            QString longitude;
        } location;

        struct
        {
            QString temperature;
            QString distance;
            QString pressure;
            QString speed;
        } units;

        struct
        {
            QString chill;
            QString direction;
            QString speed;
        } wind;

        struct
        {
            QString humidity;
            QString visibility;
            QString pressure;
            QString rising;
        } atmosphere;

        struct
        {
          QString sunrise;
          QString sunset;
        } astronomy;

        struct
        {
            QString text;
            QString code;
            QString temp;
            QString dateTime;
        } condition;

        struct Forecast
        {
            QString date;
            QString low;
            QString high;
            QString text;
            QString code;
        };

        QList<Forecast> forecasts;
    };

    int m_requestID;
    QMap<KJob *, QXmlStreamReader*> m_jobXml;
    QMap<KJob *, QString> m_jobList;

    // Methods
    QMap<QString, ConditionIcons> setupDayIconMappings(void) const;
    QMap<QString, ConditionIcons> setupNightIconMappings(void) const;

    QMap<QString, ConditionIcons> const& nightIcons(void) const;
    QMap<QString, ConditionIcons> const& dayIcons(void) const;

    // Load and Parse the place search XML listings
    void getXMLData(const QString& source);
    bool parseXMLData(QXmlStreamReader& xml, WeatherData& data);

    void updateWeather(const QString& source, const WeatherData& data);



};

K_EXPORT_PLASMA_DATAENGINE(yahooion, YahooIon)

#endif
