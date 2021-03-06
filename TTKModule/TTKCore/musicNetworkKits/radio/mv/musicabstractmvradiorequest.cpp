#include "musicabstractmvradiorequest.h"
#include "musickgqueryinterface.h"

MusicAbstractMVRadioRequest::MusicAbstractMVRadioRequest(QObject *parent)
    : MusicAbstractQueryRequest(parent)
{
    m_queryText = "1";
}

void MusicAbstractMVRadioRequest::startToSearch(QueryType type, const QString &text)
{
    Q_UNUSED(type);

    deleteAll();
    m_queryText = text.isEmpty() ? "1" : text;

    QNetworkRequest request;
    request.setUrl(MusicUtils::Algorithm::mdII(MV_CATEGORY_URL, false));
    request.setRawHeader("User-Agent", MusicUtils::Algorithm::mdII(KG_UA_URL, ALG_UA_KEY, false).toUtf8());
    MusicObject::setSslConfiguration(&request);

    m_reply = m_manager->get(request);
    connect(m_reply, SIGNAL(finished()), SLOT(downLoadFinished()));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(replyError(QNetworkReply::NetworkError)));
}
