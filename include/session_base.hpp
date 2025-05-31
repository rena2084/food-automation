#ifndef SESSION_BASE_HPP
#define SESSION_BASE_HPP

#include <iostream>
#include <time.h>
#include "session_status.hpp"

using namespace std;

class SessionBase{
protected:
    time_t _createdAt;
    time_t _lastTimeLogin;
    SessionStatus _status;

    virtual void load_session() = 0;
    virtual void save_session() = 0;

public:
    virtual void login(string, string) = 0;
    virtual void logout() = 0;

    //----- setters -----
    void setCreatedAt(time_t);
    void setLastTimeLogin(time_t);
    void setStatus(SessionStatus);


    //----- getters -----
    time_t setCreatedAt();
    time_t setLastTimeLogin();
    SessionStatus setStatus();
};


#endif // SESSION_BASE_HPP
