package epitech.epiandroid.Service;

import com.loopj.android.http.*;

public class ApiService {
    private static String _url;
    private static int _timeout = 100000;
    private static AsyncHttpClient _client = new AsyncHttpClient();

    public static void initializeApi(String url) {
        _url = url;
        _client.setMaxRetriesAndTimeout(0, _timeout);
    }

    public static void postRequest(String section, RequestParams requestParams, JsonHttpResponseHandler responseHandler) {

        if (requestParams == null) {
            requestParams = new RequestParams();
        }
        _client.post(_url + section, requestParams, responseHandler);
    }

    public static void getRequest(String section, RequestParams requestParams, JsonHttpResponseHandler responseHandler) {

        if (requestParams == null) {
            requestParams = new RequestParams();
        }
        _client.get(_url + section, requestParams, responseHandler);
    }
}