TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp
        INCLUDEPATH += C:\SDL2-2.0.22\i686-w64-mingw32\include
        LIBS += -L"C:\SDL2-2.0.22\i686-w64-mingw32\lib" \
        -lmingw32\
        -lSDL2main\
        -lSDL2\
