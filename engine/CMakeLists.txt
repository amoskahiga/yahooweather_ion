project(yahooweather)

set(yahooweather_SRCS ion_yahooweather.cpp)

kde4_add_plugin(ion_yahooweather ${yahooweather_SRCS})

target_link_libraries(ion_yahooweather ${KDE4_KDEUI_LIBS} ${KDE4_KIO_LIBS} ${KDE4_PLASMA_LIBS} weather_ion)

install(TARGETS ion_yahooweather DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES ion-yahooweather.desktop DESTINATION ${SERVICES_INSTALL_DIR})