project(plasma-yahooion)

find_package(KDE4 REQUIRED)
include(KDE4Defaults)
include(MacroOptionalAddSubdirectory)

add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(
   ${CMAKE_SOURCE_DIR}
   ${CMAKE_BINARY_DIR}
   ${KDE4_INCLUDES}
   )

set(yahooion_SRCS ion_yahoo.cpp ion_yahoo.h)

kde4_add_plugin(plasma_engine_yahooion ${yahooion_SRCS})

target_link_libraries(plasma_engine_yahooion ${KDE4_PLASMA_LIBS}
                            ${KDE4_KDECORE_LIBS}
                            ${KDE4_SOLID_LIBS}
                            ${KDE4_KIO_LIBS}
                            weather_ion
    )

install(TARGETS plasma_engine_yahooion
        DESTINATION ${PLUGIN_INSTALL_DIR})

install(FILES plasma-engine-yahooion.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})
