#ifndef ADMIN_SESSION_MANAGER_HPP
#define ADMIN_SESSION_MANAGER_HPP

#include "session_base.hpp"
#include "admin.hpp"

namespace AdminSession{
    class SessionManager : public SessionBase{
    private:
        Admin *_currentAdmin;
        int _adminID;
    public:
        void load_session()override;
        void save_session()override;
        void login(string, string)override;
        void logout()override;
        Admin currentAdmin();
        static SessionManager instance();


        //----- getters -----
        Admin getCurrentAdmin();
        int getAdminID();


    };
}
#endif // ADMIN_SESSION_MANAGER_HPP
