#include "../include/session_base.hpp"

//---------------------------------- SessionBase Class ----------------------------------

//-------------------- setters --------------------
void SessionBase::setCreatedAt(time_t createdAt)
{
    _createdAt = createdAt;
}
void SessionBase::setLastTimeLogin(time_t lastTimeLogin)
{
    _lastTimeLogin = lastTimeLogin;
}
void SessionBase::setStatus(SessionStatus status)
{
    _status = status;
}

//-------------------- getters --------------------
time_t SessionBase::setCreatedAt()
{
    return _createdAt;
}
time_t SessionBase::setLastTimeLogin()
{
    return _lastTimeLogin;
}
SessionStatus SessionBase::setStatus()
{
    return _status;
}
