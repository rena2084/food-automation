#include "../include/session_manager.hpp"
using namespace AdminSession;

//-------------------------------- SessionManager Class ---------------------------------

//--------------------- namespace AdminSession  ---------------------
void AdminSession::SessionManager::load_session()override
{

}
void AdminSession::SessionManager::save_session()override
{

}
void AdminSession::SessionManager::login(string, string)override
{

}
void AdminSession::SessionManager::logout()override
{

}
Admin AdminSession::SessionManager::currentAdmin()
{

}
static SessionManager AdminSession::SessionManager::instance()
{

}

//-------------------- getters --------------------
Admin AdminSession::SessionManager::getCurrentAdmin()
{
    return *_currentAdmin;
}
int AdminSession::SessionManager::getAdminID()
{
    return _adminID;
}

//-------------------- namespace StudentSession  --------------------
void StudentSession::SessionManager::load_session()override
{

}
void StudentSession::SessionManager::save_session()override
{

}
void StudentSession::SessionManager::login(string, string)override
{

}
void StudentSession::SessionManager::logout()override
{

}
Student StudentSession::SessionManager::currentStudent()
{

}
ShoppingCart StudentSession::SessionManager::shoppingCart()
{

}
static StudentSession::SessionManager::SessionManager instance()
{

}

//-------------------- getters --------------------

Student StudentSession::SessionManager::getCurrentAdmin()
{
    return *_currentStudent;
}
ShoppingCart StudentSession::SessionManager::getShoppingCart()
{
    return *_shopping_cart;
}
int StudentSession::SessionManager::getAdminID()
{
    return _StudentID;
}

