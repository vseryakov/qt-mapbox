# QtLocation mapbox plugin

Supports new format "@2x.png" for ios Retina displays

# Build

## Mac
  
    qmake

## iPhone

    qmake 
# Usage

    Plugin {
        name: "mapbox"
        PluginParameter { name: "mapbox.map_id"; value: "mapbox.streets" }
        PluginParameter { name: "mapbox.access_token"; value: "TOKEN" }
        PluginParameter { name: "mapbox.format"; value: "@2x.png" }
    }

# Authors

Vlad Seryakov


