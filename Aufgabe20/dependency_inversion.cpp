#include <iostream>
#include <string>
#include <array>

using namespace std;

class AuthenticationResult
{
protected:
    const bool _c_is_authenticated;
    const string _c_username;
public:
    AuthenticationResult(bool c_is_authenticated, const string& c_username = "unauthenticated_user")
        : _c_is_authenticated{c_is_authenticated}, _c_username{c_username}
    {
    }
    
    bool get_c_is_authenticated() const
    {
        return _c_is_authenticated;
    }

    string get_c_username() const
    {
        return _c_username;
    }
};

class IAuthenticationProcedure 
{
public:
    virtual ~IAuthenticationProcedure() = default;
    virtual AuthenticationResult authenticate() = 0;
};

class MockAuthentication : public IAuthenticationProcedure
{
public:
    AuthenticationResult authenticate() override
    {
        return AuthenticationResult(true, "Default");
    }
};

class UsernamePassword : public IAuthenticationProcedure
{
public:
    UsernamePassword()
    {}

    AuthenticationResult authenticate() override
    {
        string username, password;

        cout << "Username: \n";
        cin >> username;

        cout << "Password: \n";
        cin >> password;

        if(username == password)
        {
            return AuthenticationResult(true, username);
        }else
        {
            return AuthenticationResult(false);
        }
    }
};

class Certificate : public IAuthenticationProcedure
{
public:
    AuthenticationResult authenticate() override
    {
        string aussteller;

        cout << "Zertifikatsaussteller: \n";
        cin >> aussteller;
        
        if(aussteller == "hs-esslingen")
        {
            return AuthenticationResult(true, "certificate.owner");
        }else
        {
            return AuthenticationResult(false);
        }
    }
};

class Client
{
    IAuthenticationProcedure* _authentication_procedure;
public:
    void set_authentication_procedure(IAuthenticationProcedure* authentication_procedure)
    {
        _authentication_procedure = authentication_procedure;
    }
    void execute()
    {
        if(!_authentication_procedure)
        {
            cout << "Fehler: Authentifizierungsprozedur nicht gesetzt.\n";
            return;
        }

        const AuthenticationResult result = _authentication_procedure->authenticate();

        if(result.get_c_is_authenticated())
        {
            cout << "Das Programm wird ausgeführt für " << result.get_c_username() << ".\n";
        }else
        {
            cout << "Das Programm konnte nicht ausgeführt werden.\n";
        }
    }
};




int main(int argc, char* argv[]) {
    Client client;

    cout << "Authentifizierung über das Authentifizierungsverfahren Mock Authentication" << endl;
    IAuthenticationProcedure* mock_authentication = new MockAuthentication();
    client.set_authentication_procedure(mock_authentication);
    client.execute();

    cout << "Authentifizierung über das Authentifizierungsverfahren Username Password" << endl;
    IAuthenticationProcedure* username_password = new UsernamePassword();
    client.set_authentication_procedure(username_password);
    client.execute();

    cout << "Authentifizierung über das Authentifizierungsverfahren Zertifikat" << endl;
    IAuthenticationProcedure* certificate = new Certificate();
    client.set_authentication_procedure(certificate);
    client.execute();
    return 0;
}

