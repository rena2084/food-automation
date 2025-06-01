#include "../include/admin_session_manager.hpp"
using namespace AdminSession;

//-------------------------------- SessionManager Class ---------------------------------

//--------------------- namespace AdminSession  ---------------------
void AdminSession::SessionManager::load_session()
{

}
void AdminSession::SessionManager::save_session()
{

}
void AdminSession::SessionManager::login(string, string)
{

}
void AdminSession::SessionManager::logout()
{

}
Admin AdminSession::SessionManager::currentAdmin()
{

}
SessionManager AdminSession::SessionManager::instance()
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
