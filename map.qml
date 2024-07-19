// import QtQuick 2.15
// import QtLocation 5.11
// import QtPositioning 5.11

// Rectangle {
//     width: 700
//     height: 600
//     color: "#1c1919"

//     Plugin {
//         id: mapPlugin
//         name: "osm"
//         PluginParameter { name: "osm.mapping.providersrepository.address"; value: "https://tile.thunderforest.com/atlas/{z}/{x}/{y}.png?apikey=be3b0e1c0bc0486ea78281988ad8d3c2" }
//         PluginParameter { name: "osm.mapping.highdpi_tiles"; value: true }
//     }

//     Map {
//         anchors.fill: parent
//         plugin: mapPlugin
//         center: QtPositioning.coordinate(28.6139, 77.2090) // Set to the desired coordinates
//         zoomLevel: 2 // Set a zoom level to show the entire world
//         activeMapType: supportedMapTypes[3]

//         // Disable gestures to make the map static
//         // gesture.enabled: false

//         // Custom marker to highlight the coordinate
//         MapQuickItem {
//             coordinate: QtPositioning.coordinate(28.6139, 77.2090) // Set to the desired coordinates
//             anchorPoint.x: markerImage.width / 2
//             anchorPoint.y: markerImage.height

//             sourceItem: Image {
//                 id: markerImage
//                 source: "qrc:/logos/marker.png" // Replace with the path to your large marker image
//                 width: 64 // Adjust width for a larger marker
//                 height: 64 // Adjust height for a larger marker
//             }

//             // Make sure the marker is centered when the window size changes
//             anchors.centerIn: parent
//         }
//     }
// }

import QtQuick 2.15
import QtWebEngine 1.8

Rectangle {
    width: 800
    height: 700

    WebEngineView {
        id: webView
        anchors.fill: parent
        url: "qrc:/mapCustomize.html"
    }
}
