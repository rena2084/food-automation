#ifndef SESSION_MANAGER_HPP
#define SESSION_MANAGER_HPP

#include "session_base.hpp"
#include "admin.hpp"
#include "student.hpp"
#include "shopping_cart.hpp"

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
namespace StudentSession{
    class SessionManager : public SessionBase{
    private:
        Student *_currentStudent;
        ShoppingCart *_shopping_cart;
        int _StudentID;
    public:
        void load_session()override;
        void save_session()override;
        void login(string, string)override;
        void logout()override;
        Student currentStudent();
        ShoppingCart shoppingCart();
        static SessionManager instance();


        //----- getters -----
        Student getCurrentAdmin();
        ShoppingCart getShoppingCart();
        int getAdminID();
    };
}


#endif // SESSION_MANAGER_HPP
