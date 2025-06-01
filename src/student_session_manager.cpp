#include "../include/student_session_manager.hpp"
using namespace StudentSession;

//-------------------- namespace StudentSession  --------------------
void StudentSession::SessionManager::load_session()
{

}
void StudentSession::SessionManager::save_session()
{

}
void StudentSession::SessionManager::login(string, string)
{

}
void StudentSession::SessionManager::logout()
{

}
Student StudentSession::SessionManager::currentStudent()
{

}
ShoppingCart StudentSession::SessionManager::shoppingCart()
{

}
SessionManager StudentSession::SessionManager::instance()
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

