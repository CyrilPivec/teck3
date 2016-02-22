package epitech.epiandroid.Model;

import org.json.JSONObject;

public class AuthModel {
    private String  _token;
    private String  _login;
    private String  _password;

    public AuthModel() {
        this._token = "";
        this._login = "";
        this._password = "";
    }

    public AuthModel(JSONObject result, String login, String password) {
        try {
            this._token = result.getString("token");
            this._login = login;
            this._password = password;
        }
        catch (Exception e) {
        }
    }

    public String get_token() {
        return _token;
    }

    public String get_login() {
        return _login;
    }

    public void set_token(String token) {
        this._token = token;
    }

    public void set_login(String login) {
        this._login = login;
    }
}