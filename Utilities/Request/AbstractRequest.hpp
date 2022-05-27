#ifndef ABSTRACTREQUEST_HPP
#define ABSTRACTREQUEST_HPP

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

} // namespace Messenger

#endif // ABSTRACTREQUEST_HPP
