#include "providessomething.h"
#include <QDirIterator>
#include <QQmlEngine>
#include "urlinterceptor.h"

ProvidesSomething::ProvidesSomething()
{
    connect(UrlInterceptor::self(), &UrlInterceptor::newFile, this, [this](const QUrl &path) {
        _fileSystemWatcher.addPath(path.toLocalFile());
    });

    connect(&_fileSystemWatcher, &QFileSystemWatcher::fileChanged, this, [this](const QString &path) {
        Q_UNUSED(path)
        qDebug() << "changed";
        m_engine->clearComponentCache();
        emit filePathChanged();
    });
}

void ProvidesSomething::setEngine(QQmlEngine* engine)
{
    m_engine = engine;
}

QObject* ProvidesSomething::qmlSingletonRegister(QQmlEngine* engine, QJSEngine* scriptEngine)
{
    Q_UNUSED(scriptEngine)

    engine->setObjectOwnership(self(), QQmlEngine::CppOwnership);
    return self();
}

ProvidesSomething* ProvidesSomething::self()
{
    static ProvidesSomething self;
    return &self;
}

ProvidesSomething::~ProvidesSomething() = default;
