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

#include "ion_yahooweather.h"

/**
 * Constructor
 */
YahooWeatherIon::YahooWeatherIon(QObject *parent, const QVariantList &args)
        : IonInterface(parent, args)

{
    Q_UNUSED(args);

    /**
     * Set up the name mapping between the weather condition codes as obtained by the Yahoo weather
     * service, and the icon names used by the WeatherEngine for the day and night time.
     *
     * @see Weather condition codes are described at <http://developer.yahoo.com/weather/#codes>
     */

    /*
      IonInterface::ConditionIcons

      ClearDay, FewCloudsDay, PartlyCloudyDay, Overcast,
      Rain, LightRain, Showers, ChanceShowersDay, Thunderstorm, Hail,
      Snow, LightSnow, Flurries, FewCloudsNight, ChanceShowersNight,
      PartlyCloudyNight, ClearNight, Mist, Haze, FreezingRain,
      RainSnow, FreezingDrizzle, ChanceThunderstormDay, ChanceThunderstormNight,
      ChanceSnowDay, ChanceSnowNight, NotAvailable
    */
    QMap<QString, ConditionIcons> commonConditionList;

    commonConditionList["0"] = Thunderstorm;    // tornado
    commonConditionList["1"] = Thunderstorm;    // tropical storm
    commonConditionList["2"] = Thunderstorm;    // hurricane
    commonConditionList["3"] = Thunderstorm;    // severe thunderstorms
    commonConditionList["4"] = Thunderstorm;    // thunderstorms
    commonConditionList["5"] = RainSnow;        // mixed rain and snow
    commonConditionList["6"] = FreezingRain;    // mixed rain and sleet
    commonConditionList["7"] = RainSnow;        // mixed snow and sleet
    commonConditionList["8"] = FreezingDrizzle; // freezing drizzle
    commonConditionList["9"] = LightRain;       // drizzle
    commonConditionList["10"] = FreezingRain;   // freezing rain
    commonConditionList["11"] = Showers;        // showers
    commonConditionList["12"] = Showers;        // showers
    commonConditionList["13"] = Flurries;       // snow flurries
    commonConditionList["14"] = LightSnow;      // light snow showers
    commonConditionList["15"] = Snow;           // blowing snow
    commonConditionList["16"] = Snow;           // snow
    commonConditionList["17"] = Hail;           // hail
    commonConditionList["18"] = Hail;           // sleet
    commonConditionList["19"] = Haze;           // dust
    commonConditionList["20"] = Mist;           // foggy
    commonConditionList["21"] = Haze;           // haze
    commonConditionList["22"] = Haze;           // smoky
    commonConditionList["23"] = Overcast;       // blustery
    commonConditionList["27"] = Overcast;       // mostly cloudy (night)
    commonConditionList["28"] = Overcast;       // mostly cloudy (day)
    commonConditionList["35"] = FreezingRain;   // mixed rain and hail
    commonConditionList["41"] = Snow;           // heavy snow
    commonConditionList["43"] = Snow;           // heavy snow
    commonConditionList["45"] = Showers;            // thundershowers
    commonConditionList["46"] = RainSnow;           // snow showers
    commonConditionList["3200"] = NotAvailable;     // not available

    dayConditionList = commonConditionList;
    dayConditionList["24"] = ClearDay;       // windy
    dayConditionList["25"] = ClearDay;       // cold
    dayConditionList["26"] = FewCloudsDay;   // cloudy
    dayConditionList["29"] = PartlyCloudyDay;    // partly cloudy (night)
    dayConditionList["30"] = PartlyCloudyDay;    // partly cloudy (day)
    dayConditionList["31"] = ClearDay;       // clear (night)
    dayConditionList["32"] = ClearDay;       // sunny
    dayConditionList["33"] = FewCloudsDay;    // fair (night)
    dayConditionList["34"] = FewCloudsDay;    // fair (day)
    dayConditionList["36"] = ClearDay;       // hot
    dayConditionList["37"] = ChanceShowersDay;// isolated thunderstorms
    dayConditionList["38"] = ChanceShowersDay;// (ChanceThunderstormDay misisng) scattered thunderstorms
    dayConditionList["39"] = ChanceShowersDay;// (ChanceThunderstormDay misisng) scattered thunderstorms
    dayConditionList["40"] = ChanceShowersDay;       // scattered showers
    dayConditionList["42"] = ChanceSnowDay;  // scattered snow showers
    dayConditionList["44"] = PartlyCloudyDay;    // partly cloudy
    dayConditionList["47"] = ChanceShowersDay;   // isolated thundershowers

    nightConditionList = commonConditionList;
    nightConditionList["24"] = ClearNight;       // windy
    nightConditionList["25"] = ClearNight;       // cold
    nightConditionList["26"] = FewCloudsNight;   // cloudy
    nightConditionList["29"] = PartlyCloudyNight;    // partly cloudy (night)
    nightConditionList["30"] = PartlyCloudyNight;    // partly cloudy (day)
    nightConditionList["31"] = ClearNight;       // clear (night)
    nightConditionList["32"] = ClearNight;       // sunny
    nightConditionList["33"] = FewCloudsNight;    // fair (night)
    nightConditionList["34"] = FewCloudsNight;    // fair (day)
    nightConditionList["36"] = ClearNight;       // hot
    nightConditionList["37"] = ChanceShowersNight; // isolated thunderstorms
    nightConditionList["38"] = ChanceShowersNight; // (ChanceThunderstormDay misisng) scattered thunderstorms
    nightConditionList["39"] = ChanceShowersNight; // (ChanceThunderstormDay misisng) scattered thunderstorms
    nightConditionList["40"] = ChanceShowersNight;       // scattered showers
    nightConditionList["42"] = ChanceSnowNight;  // scattered snow showers
    nightConditionList["44"] = PartlyCloudyNight;    // partly cloudy
    nightConditionList["47"] = ChanceShowersNight;   // isolated thundershowers
}

/**
 * Destructor
 */
YahooWeatherIon::~YahooWeatherIon()
{
}

/**
 * Initializes the ion
 *
 * @todo figure out if it's possible to prefetch a list of possible location ID's from Yahoo
 */
void YahooWeatherIon::init()
{
    setInitialized(true);
}

/**
 * Reset any expirable data and send notification
 */
void YahooWeatherIon::reset()
{
    emit(resetCompleted(this, true));
}

/**
 * Either validates the location specified by the source, fetches the weather for the specified
 * location.
 *
 * @todo Since Yahoo does not currently supply an API to validate the location, no
 *       validation of the location is done and we always return the location as valid.
 *       USA users can use the zip-code for their location; all other users should obtain
 *       a valid location ID from http://weather.yahoo.com
 *
 * @param source the name of the source that should be updated. We expect the applet
 * to send the source in the following tokenization:
 *    "yahooweather|validate|locationID" - Triggers validation of specifed location
 *    "yahooweather|weather|locationID" - Triggers fetching of weather for specifed location
 */
bool YahooWeatherIon::updateIonSource(const QString& source)
{
    QStringList sourceAction = source.split('|');

    // Guard: if the size of array is not 3 then we have bad data, return an error
    if (sourceAction.size() < 3) {
        setData(source, "validate", "yahooweather|malformed");
        return true;
    }

    if (sourceAction[1] == "validate" && sourceAction.size() >= 3) {
        // (Look for places to match) Ignore and return any location as valid.
        setData(source, "validate",
                QString("yahooweather|valid|single|place|%1").arg(sourceAction[2]));
        return true;
    } else if (sourceAction[1] == "weather" && sourceAction.size() >= 3) {
        // Weather summary requested

        if (sourceAction.count() >= 3) {
            if (sourceAction[2].isEmpty()) {
                setData(source, "validate", "yahooweather|malformed");
                return true;
            }
            getXMLData(source);
            return true;
        } else {
            return false;
        }
    } else {
        setData(source, "validate", "yahooweather|malformed");
        return true;
    }
    return false;
}

/**
 * Fetches the weather data for the specified location for the Yahoo weather feed
 *
 * @param source containing the location ID as well as the requesting source string
 */
void YahooWeatherIon::getXMLData(const QString& source)
{
    QString locationID = QString(source).remove("yahooweather|weather|");

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

/**
 * Continuously saves the weather XML feed data as it's recieved piecewise
 *
 * @param job owning transfer job
 * @param data data recieved
 */
void YahooWeatherIon::slotDataArrived(KIO::Job *job, const QByteArray &data)
{
    if (data.isEmpty() || !m_jobXml.contains(job)) {
        return;
    }

    // Send to xml.
    m_jobXml[job]->addData(data);
}

/**
 * Parses and updates the weather once the XML feed has been completely recieved
 *
 * @param job owning transfer job
 */
void YahooWeatherIon::slotJobFinished(KJob *job)
{
    WeatherData weatherData;

    QXmlStreamReader *reader = m_jobXml[job];
    if (reader && parseXMLData(*reader, weatherData)) {
        updateWeather(m_jobList[job], weatherData);
    }
    else
    {
        // Clear the current data. so that the user knows an error occured.
        setData(m_jobList[job], Data());
    }

    delete reader;
    m_jobList.remove(job);
    m_jobXml.remove(job);
}

/**
 * Parses the XML feed into a WeatherData object
 *
 * @param xml stream containing recieved weather data
 * @param weatherData object to to hold contents of the parsed weather data
 */
bool YahooWeatherIon::parseXMLData(QXmlStreamReader& xml, WeatherData& weatherData)
{
    while (!xml.atEnd()) {

        xml.readNext();

        if (xml.isStartElement()) {
            if (xml.name() == "ttl") {
                weatherData.ttl = xml.readElementText();
            } else if (xml.name() == "location") {
                weatherData.location.country = xml.attributes().value("country").toString();
                weatherData.location.region = xml.attributes().value("region").toString();
                weatherData.location.city = xml.attributes().value("city").toString();
            } else if (xml.name() == "units") {
                weatherData.units.temperature = xml.attributes().value("temperature").toString();
                weatherData.units.distance = xml.attributes().value("distance").toString();
                weatherData.units.pressure = xml.attributes().value("pressure").toString();
                weatherData.units.speed =  xml.attributes().value("speed").toString();
            } else if (xml.name() == "wind") {
                weatherData.wind.chill = xml.attributes().value("chill").toString();
                weatherData.wind.direction = xml.attributes().value("direction").toString();
                weatherData.wind.speed =  xml.attributes().value("speed").toString();
            } else if (xml.name() == "atmosphere") {
                weatherData.atmosphere.humidity = xml.attributes().value("humidity").toString();
                weatherData.atmosphere.visibility = xml.attributes().value("visibility").toString();
                weatherData.atmosphere.pressure =  xml.attributes().value("pressure").toString();
                weatherData.atmosphere.rising =  xml.attributes().value("rising").toString();
            } else if (xml.name() == "astronomy") {
                weatherData.astronomy.sunrise = xml.attributes().value("sunrise").toString();
                weatherData.astronomy.sunset =  xml.attributes().value("sunset").toString();
            } else if (xml.name() == "lat") {
                weatherData.location.latitude = xml.readElementText();
            } else if (xml.name() == "long") {
                weatherData.location.longitude =  xml.readElementText();
            } else if (xml.name() == "condition") {
                weatherData.condition.text = xml.attributes().value("text").toString();
                weatherData.condition.code = xml.attributes().value("code").toString();
                weatherData.condition.temp =  xml.attributes().value("temp").toString();
                weatherData.condition.dateTime =  xml.attributes().value("date").toString();
            } else if (xml.name() == "forecast") {
                WeatherData::Forecast forecast;

                forecast.date = xml.attributes().value("date").toString();
                forecast.low = xml.attributes().value("low").toString();
                forecast.high =  xml.attributes().value("high").toString();
                forecast.text =  xml.attributes().value("text").toString();
                forecast.code = xml.attributes().value("code").toString();

                weatherData.forecasts.append(forecast);
            }
        }
    }

    /* If the XML was malformed or the returned data was invalid (e.g. the locationID was invalid)
     * return false.  We are assuming all feeds will at least have a valid ttl field (arbitrary)
     */
    if(xml.error() != QXmlStreamReader::NoError || weatherData.ttl.isEmpty())
        return false;
    else
        return true;    // Succesfully parsed data
}

/**
 * Updates the weather engine source with the parsed weather data
 *
 * @param source the name of the source that should be updated
 * @param weatherData weather data used to update the source
 */
void YahooWeatherIon::updateWeather(const QString& source, const WeatherData& weatherData)
{
    Plasma::DataEngine::Data data;

    data.insert("Country", weatherData.location.country);
    data.insert("Place", weatherData.location.city + ", " + weatherData.location.region);
    data.insert("Station", "Yahoo Weather");
    data.insert("Latitude", weatherData.location.latitude);
    data.insert("Longitude", weatherData.location.longitude);
    data.insert("Observation Period", weatherData.condition.dateTime);
    data.insert("Current Conditions", weatherData.condition.text);

    // Obtain time information.  Yahoo already provides us the sunset and sunrise time.
    QTime sunriseTime = getTime(weatherData.astronomy.sunrise);
    QTime sunsetTime = getTime(weatherData.astronomy.sunset);
    QTime currentTime = QDateTime::currentDateTime().time();

    // Provide mapping for the condition-type to the icons to display
    if (currentTime > sunriseTime && currentTime < sunsetTime) {
        data.insert("Condition Icon", getWeatherIcon(dayConditionList, weatherData.condition.code));
    } else {
        data.insert("Condition Icon", getWeatherIcon(nightConditionList, weatherData.condition.code));
    }

    data.insert("Humidity", weatherData.atmosphere.humidity);
    data.insert("Humidity Field", QString::number(WeatherUtils::NoUnit)); // Todo: Change to Percent

    data.insert("Visibility", weatherData.atmosphere.visibility);
    data.insert("Visibility Unit", QString::number(WeatherUtils::Miles));

    data.insert("Temperature", weatherData.condition.temp);
    data.insert("Temperature Unit", QString::number(WeatherUtils::Fahrenheit));

    data.insert("Pressure", weatherData.atmosphere.pressure);
    data.insert("Pressure Unit", QString::number(WeatherUtils::InchesHG));
    QString pressureTendencies[] = {i18nc("pressure tendency", "steady"),
                                    i18nc("pressure tendency", "rising"),
                                    i18nc("pressure tendency", "falling")};
    data.insert("Pressure Tendency",pressureTendencies[weatherData.atmosphere.rising.toInt()]);

    data.insert("Windchill", weatherData.wind.chill);
    data.insert("Wind Speed", weatherData.wind.speed);
    data.insert("Wind Speed Unit", QString::number(WeatherUtils::MilesPerHour));
    data.insert("Wind Direction", getWindDirection(weatherData.wind.direction.toInt()));

    // Set number of forecasts per day/night supported
    data.insert("Total Weather Days", weatherData.forecasts.count());

    int dayIndex = 0;
    foreach(WeatherData::Forecast forecast, weatherData.forecasts) {

        QString iconName = getWeatherIcon(dayConditionList, forecast.code);

        // Get the short day name for the forecast
        QDate forecastDate = QDate::fromString(forecast.date, "d MMM yyyy");
        int weekday = forecastDate.dayOfWeek();
        QString shortDayName = QDate::shortDayName(weekday);

        data.insert(QString("Short Forecast Day %1").arg(dayIndex), QString("%1|%2|%3|%4|%5|%6") \
                .arg(shortDayName).arg(iconName).arg(forecast.text).arg(forecast.high) \
                .arg(forecast.low).arg("N/U"));
        dayIndex++;
    }

    data.insert("Credit", i18n("Data provided by Yahoo! Weather"));
    data.insert("Credit Url", "http://weather.yahoo.com");

    setData(source, data);
}

/**
 * Gets the wind direction given an angle
 * North is between 0 - 11.25 and 360 - 348.75 degrees
 *
 * @param angle the angle of the wind vector with North being 0 degrees
 */
QString YahooWeatherIon::getWindDirection(int angle)
{
    QString directions[] = {"N", "NNE", "NE", "ENE", "E", "SSE", "SE", "ESE", "S", "NNW", "NW",
                            "WNW", "W", "SSW", "SW", "WSW"};

    // Offest the ange by 11.25 degrees
    if(angle > (360 - 11.25))
        angle = 0;
    else
        angle += 11.25;

    int directionIndex = angle / 22.5;

    return directions[directionIndex];
}

/**
 * Parses a time string and returns the representative time
 *
 * Note: Meridem means "am" or "pm"
 *
 * @param time desired in the format [hh:mm meridiem]
 */
QTime YahooWeatherIon::getTime(QString time)
{
    QStringList list =  time.split(QRegExp("[:\\s]"));
    int hour = list[0].toInt();
    int minute = list[1].toInt();
    QString meridiem = list[2];

    if(meridiem == "pm" && hour < 12)
        hour += 12;

    return QTime(hour, minute);
}

#include "ion_yahooweather.moc"
