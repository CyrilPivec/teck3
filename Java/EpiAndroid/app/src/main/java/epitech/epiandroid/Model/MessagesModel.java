package epitech.epiandroid.Model;

import android.text.Html;

public class MessagesModel {

    private String _title;
    private String _content;
    private String _date;

    public String getTitle() {
        return _title;
    }

    public void setTitle(String title) { this._title = title; }

    public String getContent() {
        return _content;
    }

    public void setContent(String content) {
        this._content = content;
    }

    public String getDate() {
        return _date;
    }

    public void setDate(String date) {
        this._date = date;
    }

    @Override
    public String toString() {
        return Html.fromHtml(this._title).toString();
    }
}