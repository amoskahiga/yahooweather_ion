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


#include "ion_yahoo.h"

/**
 * Constructor
 */
YahooIon::YahooIon(QObject *parent, const QVariantList &args)
        : IonInterface(parent, args)

{
    Q_UNUSED(args);
}

/**
 * Destructor
 */
YahooIon::~YahooIon()
{
}

/**
 * Initialize the ion.
 * @todo figure out if it's possible to prefetch a list of possible location ID's fro yahoo.
 */
void YahooIon::init()
{
    setInitialized(true);
}

/**
 * Sets up the name mapping between the weather condition summary as obtained by the yahoo weather
 * service, and
 * the icon names used by the WeatherEngine.
 */
QMap<QString, IonInterface::ConditionIcons> YahooIon::setupDayIconMappings(void) const
{
    /*ClearDay, FewCloudsDay, PartlyCloudyDay, Overcast,
      Rain, LightRain, Showers, ChanceShowersDay, Thunderstorm, Hail,
      Snow, LightSnow, Flurries, FewCloudsNight, ChanceShowersNight,
      PartlyCloudyNight, ClearNight, Mist, Haze, FreezingRain,
      RainSnow, FreezingDrizzle, ChanceThunderstormDay, ChanceThunderstormNight,
      ChanceSnowDay, ChanceSnowNight, NotAvailable
    */
    QMap<QString, ConditionIcons> dayList;

    dayList["tornado"] = Thunderstorm;
    dayList["tropical storm"] = Thunderstorm;
    dayList["hurricane"] = Thunderstorm;
    dayList["severe thunderstorms"] = Thunderstorm;
    dayList["thunderstorms"] = Thunderstorm;

    dayList["mixed rain and snow"] = RainSnow;
    dayList["mixed rain and sleet"] = RainSnow;
    dayList["mixed snow and sleet"] = RainSnow;

    dayList["freezing drizzle"] = FreezingDrizzle;
    dayList["drizzle"] = Mist;
    dayList["freezing rain"] = FreezingRain;
    dayList["snow flurries"] = Flurries;
    dayList["light snow showers"] = LightSnow;
    dayList["blowing snow"] = Snow;
    dayList["snow"] = Snow;
    dayList["hail"] = Hail;
    dayList["sleet"] = Hail;
    dayList["dust"] = NotAvailable;
    dayList["foggy"] = Mist;
    dayList["haze"] = NotAvailable;
    dayList["smoky"] = NotAvailable;
    dayList["blustery"] = NotAvailable;
    dayList["windy"] = NotAvailable;

    dayList["cold"] = NotAvailable;
    dayList["cloudy"] = Overcast;
    dayList["mostly sunny"] = PartlyCloudyDay;
    dayList["mostly cloudy (day)"] = Overcast;
    dayList["mostly cloudy"] = Overcast;
    dayList["partly cloudy (day)"] = PartlyCloudyDay;
    dayList["partly cloudy"] = PartlyCloudyDay;
    dayList["fair (day)"] = FewCloudsDay;
    dayList["fair"] = FewCloudsDay;
    dayList["mixed rain and hail"] = FreezingRain;

    dayList["hot"] = NotAvailable;
    dayList["isolated thunderstorms"] = ChanceThunderstormDay;
    dayList["scattered thunderstorms"] = ChanceThunderstormDay;
    dayList["scattered showers"] = ChanceShowersDay;
    dayList["heavy snow"] = NotAvailable;
    dayList["scattered snow showers"] = NotAvailable;
    dayList["heavy snow"] = Snow;
    dayList["thundershowers"] = Thunderstorm;
    dayList["snow showers"] = Snow;
    dayList["isolated thundershowers"] = Thunderstorm;
    dayList["not available"] = NotAvailable;

    return dayList;
}

QMap<QString, IonInterface::ConditionIcons> YahooIon::setupNightIconMappings(void) const
{
    /*ClearDay, FewCloudsDay, PartlyCloudyDay, Overcast,
      Rain, LightRain, Showers, ChanceShowersDay, Thunderstorm, Hail,
      Snow, LightSnow, Flurries, FewCloudsNight, ChanceShowersNight,
      PartlyCloudyNight, ClearNight, Mist, Haze, FreezingRain,
      RainSnow, FreezingDrizzle, ChanceThunderstormDay, ChanceThunderstormNight,
      ChanceSnowDay, ChanceSnowNight, NotAvailable
    */
    QMap<QString, ConditionIcons> nightList;

    nightList["tornado"] = Thunderstorm;
    nightList["tropical storm"] = Thunderstorm;
    nightList["hurricane"] = Thunderstorm;
    nightList["severe thunderstorms"] = Thunderstorm;
    nightList["thunderstorms"] = Thunderstorm;

    nightList["mixed rain and snow"] = RainSnow;
    nightList["mixed rain and sleet"] = RainSnow;
    nightList["mixed snow and sleet"] = RainSnow;

    nightList["freezing drizzle"] = FreezingDrizzle;
    nightList["drizzle"] = Mist;
    nightList["freezing rain"] = FreezingRain;
    nightList["snow flurries"] = Flurries;
    nightList["light snow showers"] = LightSnow;
    nightList["blowing snow"] = Snow;
    nightList["snow"] = Snow;
    nightList["hail"] = Hail;
    nightList["sleet"] = Hail;
    nightList["dust"] = NotAvailable;
    nightList["foggy"] = Mist;
    nightList["haze"] = NotAvailable;
    nightList["smoky"] = NotAvailable;
    nightList["blustery"] = NotAvailable;
    nightList["windy"] = NotAvailable;

    nightList["cold"] = NotAvailable;
    nightList["cloudy"] = Overcast;
    nightList["mostly cloudy (night)"] = Overcast;
    nightList["mostly cloudy"] = Overcast;
    nightList["partly cloudy (night)"] = PartlyCloudyNight;
    nightList["partly cloudy"] = PartlyCloudyNight;
    nightList["clear (night)"] = ClearNight;
    nightList["clear"] = ClearNight;
    nightList["fair (night)"] = FewCloudsNight;
    nightList["fair"] = FewCloudsNight;
    nightList["mixed rain and hail"] = FreezingRain;

    nightList["hot"] = NotAvailable;
    nightList["isolated thunderstorms"] = ChanceThunderstormNight;
    nightList["scattered thunderstorms"] = ChanceThunderstormNight;
    nightList["scattered showers"] = ChanceShowersNight;
    nightList["heavy snow"] = NotAvailable;
    nightList["scattered snow showers"] = NotAvailable;
    nightList["heavy snow"] = Snow;
    nightList["thundershowers"] = Thunderstorm;
    nightList["snow showers"] = Snow;
    nightList["isolated thundershowers"] = Thunderstorm;
    nightList["not available"] = NotAvailable;

    return nightList;
}

QMap<QString, IonInterface::ConditionIcons> const& YahooIon::dayIcons(void) const
{
    static QMap<QString, ConditionIcons> const dval = setupDayIconMappings();
    return dval;
}

QMap<QString, IonInterface::ConditionIcons> const& YahooIon::nightIcons(void) const
{
    static QMap<QString, ConditionIcons> const nval = setupNightIconMappings();
    return nval;
}

// Get a specific Ion's data
bool YahooIon::updateIonSource(const QString& source)
{
    // We expect the applet to send the source in the following tokenization:
    // ionname|validate|place_name - Triggers validation of place
    // ionname|weather|place_name - Triggers receiving weather of place

    QStringList sourceAction = source.split('|');

    // Guard: if the size of array is not 3 then we have bad data, return an error
    if (sourceAction.size() < 3) {
        setData(source, "validate", "yahooion|malformed");
        return true;
    }

    if (sourceAction[1] == "validate" && sourceAction.size() >= 3) {
        // Look for places to match
        setData(source, "validate", QString("yahooion|valid|single|place|%1").arg(sourceAction[2]));
        return true;
    } else if (sourceAction[1] == "weather" && sourceAction.size() >= 3) {
        if (sourceAction.count() >= 3) {
            if (sourceAction[2].isEmpty()) {
                setData(source, "validate", "yahooion|malformed");
                return true;
            }
            getXMLData(source);
            return true;
        } else {
            return false;
        }
    } else {
        setData(source, "validate", "yahooion|malformed");
        return true;
    }
    return false;
}

// Gets specific city XML data
void YahooIon::getXMLData(const QString& source)
{
    QString locationID = QString(source).remove("yahooion|weather|");

    KUrl url = "http://weather.yahooapis.com/forecastrss?p=" + locationID;

    KIO::TransferJob * const m_job = KIO::get(url.url(), KIO::Reload, KIO::HideProgressInfo);

    m_jobXml.insert(m_job, new QXmlStreamReader);
    m_jobList.insert(m_job, source);

    if (m_job) {
        connect(m_job, SIGNAL(data(KIO::Job *, const QByteArray &)), this,
                SLOT(slotDataArrived(KIO::Job *, const QByteArray &)));
        connect(m_job, SIGNAL(result(KJob *)), this, SLOT(slotJobFinished(KJob *)));
    }
}

void YahooIon::slotDataArrived(KIO::Job *job, const QByteArray &data)
{
    if (data.isEmpty() || !m_jobXml.contains(job)) {
        return;
    }

    // Send to xml.
    m_jobXml[job]->addData(data);
}

void YahooIon::slotJobFinished(KJob *job)
{
    WeatherData data;

    QXmlStreamReader *reader = m_jobXml[job];
    if (reader) {
        parseXMLData(*reader, data);
        updateWeather(m_jobList[job], data);
    }

    delete reader;
    m_jobList.remove(job);
    m_jobXml.remove(job);
}

bool YahooIon::parseXMLData(QXmlStreamReader& xml, WeatherData& data)
{
    while (!xml.atEnd()) {

        xml.readNext();

        if (xml.isStartElement()) {
            if (xml.name() == "ttl") {
                data.ttl = xml.readElementText();
            } else if (xml.name() == "location") {
                data.location.country = xml.attributes().value("country").toString();
                data.location.region = xml.attributes().value("region").toString();
                data.location.city = xml.attributes().value("city").toString();
            } else if (xml.name() == "units") {
                data.units.temperature = xml.attributes().value("temperature").toString();
                data.units.distance = xml.attributes().value("distance").toString();
                data.units.pressure = xml.attributes().value("pressure").toString();
                data.units.speed =  xml.attributes().value("speed").toString();
            } else if (xml.name() == "wind") {
                data.wind.chill = xml.attributes().value("chill").toString();
                data.wind.direction = xml.attributes().value("direction").toString();
                data.wind.speed =  xml.attributes().value("speed").toString();
            } else if (xml.name() == "atmosphere") {
                data.atmosphere.humidity = xml.attributes().value("humidity").toString();
                data.atmosphere.visibility = xml.attributes().value("visibility").toString();
                data.atmosphere.pressure =  xml.attributes().value("pressure").toString();
                data.atmosphere.rising =  xml.attributes().value("rising").toString();
            } else if (xml.name() == "astronomy") {
                data.astronomy.sunrise = xml.attributes().value("sunrise").toString();
                data.astronomy.sunset =  xml.attributes().value("sunset").toString();
            } else if (xml.name() == "lat") {
                data.location.latitude = xml.readElementText();
            } else if (xml.name() == "long") {
                data.location.longitude =  xml.readElementText();
            } else if (xml.name() == "condition") {
                data.condition.text = xml.attributes().value("text").toString();
                data.condition.code = xml.attributes().value("code").toString();
                data.condition.temp =  xml.attributes().value("temp").toString();
                data.condition.dateTime =  xml.attributes().value("date").toString();
            } else if (xml.name() == "forecast") {
                WeatherData::Forecast forecast;

                forecast.date = xml.attributes().value("date").toString();
                forecast.low = xml.attributes().value("low").toString();
                forecast.high =  xml.attributes().value("high").toString();
                forecast.text =  xml.attributes().value("text").toString();
                forecast.code = xml.attributes().value("code").toString();

                data.forecasts.append(forecast);
            }
        }
    }

    return !xml.error();
}

void YahooIon::updateWeather(const QString& source, const WeatherData& weatherData)
{
    Plasma::DataEngine::Data data;

    data.insert("Country", weatherData.location.country);
    data.insert("Place", weatherData.location.city + ", " + weatherData.location.region);
    data.insert("Station", "Yahoo Weather");
    data.insert("Latitude", weatherData.location.latitude);
    data.insert("Longitude", weatherData.location.longitude);
    data.insert("Observation Period", weatherData.condition.dateTime);

    QStringList list =  weatherData.astronomy.sunrise.split(QRegExp("[:\\s]"));
    int sunriseHour = list[0].toInt();
    int sunriseMinute = list[1].toInt();
    QString sunriseMeridiem = list[2];

    if(sunriseMeridiem == "pm" && sunriseHour < 12)
        sunriseHour += 12;

    QTime sunriseTime(sunriseHour, sunriseMinute);

    list.clear();
    list =  weatherData.astronomy.sunset.split(QRegExp("[:\\s]"));
    int sunsetHour = list[0].toInt();
    int sunsetMinute = list[1].toInt();
    QString sunsetMeridiem = list[2];

    if(sunsetMeridiem == "pm" && sunsetHour < 12)
        sunsetHour += 12;

    QTime sunsetTime(sunsetHour, sunsetMinute);

    list.clear();
    list =  weatherData.condition.dateTime.split(QRegExp("[\\s:]"));
    int observationHour = list[4].toInt();
    int observationMinute = list[5].toInt();
    QString observationMeridiem = list[6];

    if(observationMeridiem == "pm" && observationHour < 12)
        observationHour += 12;

    QTime observationTime(observationHour, observationMinute);

    // Tell applet which icon to use for conditions and provide mapping for condition type to the icons to display
    if (observationTime > sunriseTime && observationTime < sunsetTime) {
        kDebug() << "After sunrise - Using daytime icons: " << getWeatherIcon(dayIcons(), weatherData.condition.text.toLower()) << observationTime;
        data.insert("Condition Icon", getWeatherIcon(dayIcons(), weatherData.condition.text.toLower()));
    } else {
        kDebug() << "Before sunrise - using night icons: " << getWeatherIcon(nightIcons(), weatherData.condition.text.toLower()) << observationTime;
        data.insert("Condition Icon", getWeatherIcon(nightIcons(), weatherData.condition.text.toLower()));
    }

    data.insert("Humidity", weatherData.atmosphere.humidity);
    data.insert("Humidity Field", QString::number(WeatherUtils::Fahrenheit));

    data.insert("Visibility", weatherData.atmosphere.visibility);
    data.insert("Visibility Unit", QString::number(WeatherUtils::Miles));

    data.insert("Temperature", weatherData.condition.temp);
    data.insert("Temperature Unit", QString::number(WeatherUtils::Fahrenheit));

    data.insert("Pressure", weatherData.atmosphere.pressure);
    data.insert("Pressure Unit", QString::number(WeatherUtils::InchesHG));

    data.insert("Windchill", weatherData.wind.chill);
    data.insert("Wind Speed", weatherData.wind.speed);
    data.insert("Wind Speed Unit", QString::number(WeatherUtils::Miles));
    //data.insert("Wind Direction", getWindDirection(weatherData.wind.direction));

    // Set number of forecasts per day/night supported
    data.insert("Total Weather Days", weatherData.forecasts.count());

    int dayIndex = 0;
    foreach(WeatherData::Forecast forecast, weatherData.forecasts) {

        QString iconName = getWeatherIcon(dayIcons(), forecast.text.toLower());

        data.insert(QString("Short Forecast Day %1").arg(dayIndex), QString("%1|%2|%3|%4|%5|%6") \
                .arg(forecast.date).arg(iconName).arg(forecast.text).arg(forecast.high) \
                .arg(forecast.low).arg("N/U"));
        dayIndex++;
    }

    data.insert("Credit", i18n("Data provided by Yahoo! Weather"));
    data.insert("Credit Url", "http://weather.yahoo.com");

    setData(source, data);
}

void YahooIon::reset()
{
    emit(resetCompleted(this, true));
}

#include "ion_yahoo.moc"
