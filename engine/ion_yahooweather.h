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

#ifndef ION_YAHOOWEATHER_H
#define ION_YAHOOWEATHER_H

#include <QtXml/QXmlStreamReader>
#include <QRegExp>
#include <QtCore/QStringList>
#include <QDateTime>
#include <QDebug>
#include <kio/job.h>
#include <plasma/dataengine.h>
#include <plasma/weather/weatherutils.h>
#include <plasma/weather/ion.h>

/**
 * A KDE Plasma weather DataEngine that provides data from the
 * Yahoo! Weather service <http://developer.yahoo.com/weather/>
 */
class KDE_EXPORT YahooWeatherIon : public IonInterface
{
    Q_OBJECT

public:
    YahooWeatherIon(QObject *parent, const QVariantList &args);
    ~YahooWeatherIon();
    void init();  // Setup the city location, fetching the correct URL name.
    bool updateIonSource(const QString& source);

public slots:
    virtual void reset();

private slots:
    void slotDataArrived(KIO::Job *job, const QByteArray &data);
    void slotJobFinished(KJob *);

private:
    /**
     * A struct to hold the yahoo weather parsed data feed contents.
     */
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

    QMap<KJob *, QXmlStreamReader*> m_jobXml;
    QMap<KJob *, QString> m_jobList;
    QMap<QString, ConditionIcons> dayConditionList;
    QMap<QString, ConditionIcons> nightConditionList;

    // Methods
    QString getWindDirection(int angle);
    QTime getTime(QString time);

    // Load and Parse the place search XML listings
    void getXMLData(const QString& source);
    bool parseXMLData(QXmlStreamReader& xml, WeatherData& data);

    void updateWeather(const QString& source, const WeatherData& data);
};

K_EXPORT_PLASMA_DATAENGINE(yahooweather, YahooWeatherIon)

#endif
