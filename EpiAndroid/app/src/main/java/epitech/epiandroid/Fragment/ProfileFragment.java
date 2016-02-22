package epitech.epiandroid.Fragment;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

import cz.msebera.android.httpclient.Header;
import com.loopj.android.http.JsonHttpResponseHandler;
import com.loopj.android.http.RequestParams;

import org.json.JSONObject;

import java.io.InputStream;
import java.util.LinkedList;
import java.util.List;

import epitech.epiandroid.Service.ApiService;
import epitech.epiandroid.Model.AuthModel;
import epitech.epiandroid.Model.UserModel;
import epitech.epiandroid.Model.MessagesModel;
import epitech.epiandroid.R;

public class ProfileFragment extends Fragment {

    private ApiService  _api;
    private AuthModel _auth;
    FragmentManager     _fManager;

    public View         _view;
    public View         _progressView;
    private View        _infosView;
    private TextView    _title;
    private TextView    _login;
    private ImageView   _img;
    private Bitmap      _bitmap;
    private TextView    _location;
    private TextView    _semester;
    private TextView    _promo;
    private TextView    _log;
    public ListView     _listMessagesview;

    /**
     * ProfileFragment
     */
    public static ProfileFragment newInstance(AuthModel auth, FragmentManager fManager) {
        ProfileFragment pf = new ProfileFragment();
        pf._auth = auth;
        pf._fManager = fManager;
        return (pf);
    }

    /**
     * onCreateView
     */
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        _view = inflater.inflate(R.layout.fragment_profile, container, false);

        _infosView = _view.findViewById(R.id.infosLayout);
        _progressView = _view.findViewById(R.id.progressLayout);

        _title = (TextView) _view.findViewById(R.id.title);
        _login = (TextView) _view.findViewById(R.id.login);
        _img = (ImageView) _view.findViewById(R.id.img);
        _location = (TextView) _view.findViewById(R.id.location);
        _semester = (TextView) _view.findViewById(R.id.semester);
        _promo = (TextView) _view.findViewById(R.id.promo);
        _log = (TextView) _view.findViewById(R.id.log);
        _listMessagesview = (ListView) _view.findViewById(R.id.listMessagesView);

        _infosView.setVisibility(View.VISIBLE);
        _progressView.setVisibility(View.VISIBLE);

        // Request user informations
        _api = new ApiService();
        _api.initializeApi(getString(R.string.api_url));
        try {
            RequestParams requestParams = new RequestParams();
            requestParams.add("token", _auth.get_token());
            requestParams.add("user", _auth.get_login());
            _api.getRequest("user", requestParams, responseHandlerUserInfos);
        } catch (Exception e) {
        }

        // Request last messages
        _api = new ApiService();
        _api.initializeApi(getString(R.string.api_url));
        try {
            RequestParams requestParams = new RequestParams();
            requestParams.add("token", _auth.get_token());
            _api.getRequest("messages", requestParams, responseHandlerMessagesList);
        } catch (Exception e) {
        }
        return _view;
    }

    /**
     * Bitmap converter
     */
    protected Bitmap convertImg(String... URL) {

        String imageURL = URL[0];

        Bitmap bitmap = null;
        try {
            // Download Image from URL
            InputStream input = new java.net.URL(imageURL).openStream();
            // Decode Bitmap
            bitmap = BitmapFactory.decodeStream(input);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return bitmap;
    }

    /**
     * JsonHttpResponseHandler for UserInfos
     */
    public JsonHttpResponseHandler responseHandlerUserInfos = new JsonHttpResponseHandler() {
        @Override
        public void onSuccess(int statusCode, Header[] headers, JSONObject response) {
            super.onSuccess(statusCode, headers, response);
            try {
                UserModel userModel = new UserModel(response, _auth.get_token());
                _title.setText(" User : " + userModel.get_title());
                _login.setText(" Login : " + userModel.get_login());
                //_bitmap = convertImg(userModel.get_img());
                //_img.setImageBitmap(_bitmap);
                _location.setText(" Location : " + userModel.get_location());
                _semester.setText(" Semester : " + userModel.get_semester());
                _promo.setText(" Promotion : " + userModel.get_promo());
                _log.setText(" Log time : " + userModel.get_log());
                _progressView.setVisibility(View.INVISIBLE);
                _infosView.setVisibility(View.VISIBLE);
            }
            catch (Exception e) {
            }
        }

        @Override
        public void onFailure(int statusCode, Header[] headers, Throwable throwable, JSONObject errorResponse) {
            super.onFailure(statusCode, headers, throwable, errorResponse);
        }
    };

    /**
     * JsonHttpResponseHandler for MessagesList
     */
    public JsonHttpResponseHandler responseHandlerMessagesList = new JsonHttpResponseHandler() {
        @Override
        public void onSuccess(int statusCode, Header[] headers, JSONObject response) {
            super.onSuccess(statusCode, headers, response);
            try
            {
                int i = 0;
                JSONObject objMsg;
                List<MessagesModel> listMessages = new LinkedList<MessagesModel>();

                while (i < response.length())
                {
                    MessagesModel msg = new MessagesModel();
                    objMsg = response.getJSONObject(String.valueOf(i));
                    System.out.println(objMsg);
                    msg.setTitle(objMsg.getString("title"));
                    msg.setContent(objMsg.getString("content"));
                    msg.setDate(objMsg.getString("date"));
                    System.out.println(msg.getTitle());
                    System.out.println(msg.getContent());
                    System.out.println(msg.getDate());
                    listMessages.add(msg);
                    i++;
                }
                ArrayAdapter<MessagesModel> adapter = new ArrayAdapter<>(_view.getContext(),
                        android.R.layout.simple_list_item_1,android.R.id.text1, listMessages);
                _listMessagesview.setAdapter(adapter);
                _listMessagesview.setVisibility(View.VISIBLE);
            }
            catch (Exception e) {}
        }

        @Override
        public void onFailure(int statusCode, Header[] headers, Throwable throwable, JSONObject errorResponse) {
            super.onFailure(statusCode, headers, throwable, errorResponse);
        }
    };
}
