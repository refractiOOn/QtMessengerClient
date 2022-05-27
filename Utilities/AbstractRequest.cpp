#include "AbstractRequest.hpp"

Messenger::AbstractRequest::AbstractRequest(const RequestType pRequestType) :
    mRequestType(pRequestType)
{

}

Messenger::RequestType Messenger::AbstractRequest::GetType() const
{
    return mRequestType;
}

Messenger::AuthorizationRequest::AuthorizationRequest(const RequestType pRequestType, QStringView pLogin, QStringView pPassword) :
    AbstractRequest(pRequestType),
    mLogin(pLogin.toString()),
    mPassword(pPassword.toString())
{

}

QString Messenger::AuthorizationRequest::GetLogin() const
{
    return mLogin;
}

QString Messenger::AuthorizationRequest::GetPassword() const
{
    return mPassword;
}

Messenger::RegistrationRequest::RegistrationRequest(const RequestType pRequestType, const QString pLogin,
                                                    const QString pPassword, const QString pName, const QString pSurname) :
    AuthorizationRequest(mRequestType, pLogin, pPassword),
    mName(pName),
    mSurname(pSurname)
{

}

QString Messenger::RegistrationRequest::GetName() const
{
    return mName;
}

QString Messenger::RegistrationRequest::GetSurname() const
{
    return mSurname;
}

Messenger::NewMessageRequest::NewMessageRequest(const RequestType pRequestType, QStringView pMessage, const QDateTime &pTime) :
    AbstractRequest(pRequestType),
    mMessage(pMessage.toString()),
    mTime(pTime)
{

}

QString Messenger::NewMessageRequest::GetMessage() const
{
    return mMessage;
}

QDateTime Messenger::NewMessageRequest::GetTime() const
{
    return mTime;
}

Messenger::NetworkDataRequest::NetworkDataRequest(const RequestType pRequestType, const QHostAddress pAddress, const quint16 pPort) :
    AbstractRequest(pRequestType),
    mAddress(pAddress),
    mPort(pPort)
{

}

QHostAddress Messenger::NetworkDataRequest::GetAddress() const
{
    return mAddress;
}

quint16 Messenger::NetworkDataRequest::GetPort() const
{
    return mPort;
}
