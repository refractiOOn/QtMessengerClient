#ifndef ABSTRACTREQUEST_HPP
#define ABSTRACTREQUEST_HPP

#include <QtCore/QString>
#include <QtCore/QStringView>
#include <QtCore/QDateTime>
#include <QtNetwork/QHostAddress>

namespace Messenger
{

enum RequestType
{
    REQUEST_TYPE_AUTHORIZATION,
    REQUEST_TYPE_REGISTRATION,
    REQUEST_TYPE_NEW_MESSAGE,
    REQUEST_TYPE_NEW_COMPANION,
    REQUEST_TYPE_SERVER_DATA
};

class AbstractRequest
{
public:
    virtual ~AbstractRequest() = 0;

    virtual RequestType GetType() const;

protected:
    AbstractRequest(const RequestType pRequestType);

protected:
    RequestType mRequestType;

};

class AuthorizationRequest : public AbstractRequest
{
public:
    AuthorizationRequest(const RequestType pRequestType, QStringView pLogin, QStringView pPassword);
    virtual ~AuthorizationRequest();

    virtual QString GetLogin() const;
    virtual QString GetPassword() const;

protected:
    QString mLogin;
    QString mPassword;

};

class RegistrationRequest : public AuthorizationRequest
{
public:
    RegistrationRequest(const RequestType pRequestType, const QString pLogin, const QString pPassword, const QString pName, const QString pSurname);
    virtual ~RegistrationRequest();

    virtual QString GetName() const;
    virtual QString GetSurname() const;

protected:
    QString mName;
    QString mSurname;

};

class NewMessageRequest : public AbstractRequest
{
public:
    NewMessageRequest(const RequestType pRequestType, QStringView pMessage, const QDateTime& pTime);
    virtual ~NewMessageRequest();

    virtual QString GetMessage() const;
    virtual QDateTime GetTime() const;

protected:
    QString mMessage;
    QDateTime mTime;

};

class NetworkDataRequest : public AbstractRequest
{
public:
    NetworkDataRequest(const RequestType pRequestType, const QHostAddress pAddress, const quint16 pPort = 0);
    virtual ~NetworkDataRequest();

    virtual QHostAddress GetAddress() const;
    virtual quint16 GetPort() const;

protected:
    QHostAddress mAddress;
    quint16 mPort;

};

} // namespace Messenger

#endif // ABSTRACTREQUEST_HPP
