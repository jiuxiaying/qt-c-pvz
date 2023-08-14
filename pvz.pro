QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basiczombie.cpp \
    card.cpp \
    cherry.cpp \
    game.cpp \
    loading.cpp \
    main.cpp \
    Mainwindow.cpp \
    map.cpp \
    other.cpp \
    pea.cpp \
    peashot.cpp \
    plant.cpp \
    potato.cpp \
    repeater.cpp \
    shop.cpp \
    shovel.cpp \
    snowpea.cpp \
    startpage.cpp \
    sun.cpp \
    sunflower.cpp \
    wallnut.cpp \
    zombie.cpp \
    mower.cpp \
    bucketzombie.cpp \
    conezombie.cpp \
    footballzombie.cpp \
    screenzombie.cpp

HEADERS += \
    Mainwindow.h \
    basiczombie.h \
    card.h \
    cherry.h \
    game.h \
    loading.h \
    map.h \
    other.h \
    pea.h \
    peashot.h \
    plant.h \
    potato.h \
    repeater.h \
    shop.h \
    shovel.h \
    snowpea.h \
    startpage.h \
    sun.h \
    sunflower.h \
    wallnut.h \
    zombie.h \
    mower.h \
    bucketzombie.h \
    conezombie.h \
    footballzombie.h \
    screenzombie.h

FORMS += \
    Mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images/imges.qrc \
    sound/sound.qrc
