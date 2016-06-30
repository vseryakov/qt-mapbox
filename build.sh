#!/bin/bash

make distclean
qmake
make
cp plugins/geoservices/* $QT_HOME/5.6/clang_64/plugins/geoservices

make distclean
$QT_HOME/5.6/ios/bin/qmake -r -spec macx-ios-clang CONFIG+=release CONFIG+=iphoneos CONFIG+=device
make
cp plugins/geoservices/* $QT_HOME/5.6/ios/plugins/geoservices

make distclean
$QT_HOME/5.6/android_armv7/bin/qmake -r -spec android-g++ CONFIG+=release
make
cp plugins/geoservices/* $QT_HOME/5.6/android_armv7/plugins/geoservices

