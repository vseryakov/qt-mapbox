# QtLocation mapbox plugin

Supports new format "@2x.png" for ios Retina displays

# Build

## Mac

    qmake
    make
    cp plugins/geoservices/* $QT_HOME/5.6/clang_64/plugins/geoservices

## iPhone

    $QT_HOME/5.6/ios/bin/qmake -r -spec macx-ios-clang CONFIG+=release CONFIG+=iphoneos CONFIG+=device
    make
    cp plugins/geoservices/* $QT_HOME/5.6/ios/plugins/geoservices

## Android

    export ANDROID_NDK_TOOLCHAIN_VERSION=4.9 
    export ANDROID_SDK_ROOT=$ANDROID_HOME
    export ANDROID_NDK_ROOT=$NDK_HOME
    $QT_HOME/5.6/android_armv7/bin/qmake -r -spec android-g++ CONFIG+=release 
    make
    cp plugins/geoservices/* $QT_HOME/5.6/android_armv7/plugins/geoservices

# Usage

    Plugin {
        name: "mapbox"
        PluginParameter { name: "mapbox.map_id"; value: "mapbox.streets" }
        PluginParameter { name: "mapbox.access_token"; value: "TOKEN" }
        PluginParameter { name: "mapbox.format"; value: "@2x.png" }
    }

# Authors

Vlad Seryakov

