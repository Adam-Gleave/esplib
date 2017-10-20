TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    src/esplib.cpp

HEADERS += \
    src/esptypes.hpp \
    src/esplib.hpp \
    src/json.hpp

DISTFILES +=
