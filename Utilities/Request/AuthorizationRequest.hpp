#ifndef AUTHORIZATIONREQUEST_HPP
#define AUTHORIZATIONREQUEST_HPP

#include "AbstractRequest.hpp"
#include <QtCore/QString>

namespace Messenger
{

class AuthorizationRequest : public AbstractRequest
{
public:
    AuthorizationRequest(const RequestType pRequestType, const QString pLogin, const QString pPassword);
    virtual ~AuthorizationRequest();
    virtual QString GetLogin() const;
    virtual QString GetPassword() const;

protected:
    QString mLogin = 0;
    QString mPassword = 0;

};

} // namespace Messenger

#endif // AUTHORIZATIONREQUEST_HPP
