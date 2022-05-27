#include "AbstractRequest.hpp"

Messenger::AbstractRequest::AbstractRequest(const RequestType pRequestType) :
    mRequestType(pRequestType)
{

}

Messenger::RequestType Messenger::AbstractRequest::GetType() const
{
    return mRequestType;
}
