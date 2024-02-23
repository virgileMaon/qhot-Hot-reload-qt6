import QtQuick
import ProvidesSomething 1.0

Window {
    id: window

    title: "QHot"
    visible: true

    Connections {
        function onFilePathChanged() {
            var path = ProvidesSomething.filePath + "?t=" + Date.now();
            loader.source = path;
        }

        target: ProvidesSomething
    }
    Loader {
        id: loader

        //anchors.fill: parent
        focus: true
    }
}
