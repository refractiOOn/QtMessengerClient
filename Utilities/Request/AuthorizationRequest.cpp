#include "AuthorizationRequest.hpp"

Messenger::AuthorizationRequest::AuthorizationRequest(const RequestType pRequestType, const QString pLogin, const QString pPassword) :
    AbstractRequest(pRequestType),
    mLogin(pLogin),
    mPassword(pPassword)
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
