#include "user.h"

User::User() {}
User::User(string p_username, string p_pass) {
    populateUser(p_username, p_pass);
}

void User::populateUser(string p_username, string p_pass) {
    username = p_username;
    pass     = p_pass;
}
