package epitech.epiandroid.Model;

import org.json.JSONObject;

public class UserModel {
    private String _token;
    private String _login;
    private String _title;
    private String _img;
    private String _promo;
    private String _semester;
    private String _location;
    private String _log;

    public UserModel(JSONObject result, String token) {

        try {
            JSONObject objLog = result.getJSONObject("nsstat");
            this._token = token;
            this._login = result.getString("login");
            this._img = result.getString("picture");
            this._title = result.getString("title");
            this._promo = result.getString("promo");
            this._semester = result.getString("semester");
            this._location = result.getString("location");
            this._log = objLog.getString("active");
        }
        catch (Exception e) {
        }
    }

    public String get_login() {
        return this._login;
    }

    public String get_title() {
        return this._title;
    }
    public String get_img() {
        return this._img;
    }
    public String get_promo() {
        return this._promo;
    }
    public String get_semester() {
        return this._semester;
    }
    public String get_location() {
        return this._location;
    }
    public String get_log() {
        return this._log;
    }
}