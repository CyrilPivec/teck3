package epitech.epiandroid.Fragment;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.loopj.android.http.JsonHttpResponseHandler;
import com.loopj.android.http.RequestParams;

import org.json.JSONArray;
import org.json.JSONObject;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.LinkedList;
import java.util.List;
import java.util.TimeZone;

import cz.msebera.android.httpclient.Header;
import epitech.epiandroid.Model.AuthModel;
import epitech.epiandroid.Model.ScheduleModel;
import epitech.epiandroid.R;
import epitech.epiandroid.Service.ApiService;

public class ScheduleFragment extends Fragment {
    public View         _view;
    public ListView    _listView;

    private ApiService  _api;
    private AuthModel   _auth;
    FragmentManager     _fManager;
    private String      _date_begin;
    private String      _date_end;

    /**
     * ScheduleFragment
     */
    public static ScheduleFragment newInstance(AuthModel auth, FragmentManager fManager) {
        ScheduleFragment sf = new ScheduleFragment();
        sf._auth = auth;
        sf._fManager = fManager;
        return (sf);
    }

    /**
     * onCreateView
     */
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        _view = inflater.inflate(R.layout.fragment_schedule, container, false);

        _listView = (ListView) _view.findViewById(R.id.listView);

        // Request schedule
        _api = new ApiService();
        _api.initializeApi(getString(R.string.api_url));
        Calendar cal = Calendar.getInstance(TimeZone.getDefault());
        _date_begin = _date_end = new SimpleDateFormat("yyyy-MM-dd").format(cal.getTime());
        try {
            RequestParams requestParams = new RequestParams();
            requestParams.add("token", _auth.get_token());
            requestParams.add("start", _date_begin);
            requestParams.add("end", _date_end);
            _api.getRequest("planning", requestParams, responseHandlerSchedule);
        }
        catch (Exception e) {}
        return _view;
    }

    /**
     * JsonHttpResponseHandler for Schedule
     */
    public JsonHttpResponseHandler responseHandlerSchedule = new JsonHttpResponseHandler() {
        @Override
        public void onSuccess(int statusCode, Header[] headers, JSONArray response) {
            super.onSuccess(statusCode, headers, response);
            List<ScheduleModel> listElem = new LinkedList<ScheduleModel>();
            JSONObject obj;
            int i = 0;

            try {
                while (i < response.length()) {
                    obj = response.getJSONObject(i);
                    if (obj.getString("module_registered") == "true") {
                        ScheduleModel scheduleModel = new ScheduleModel();
                        scheduleModel.set_title(obj.getString("acti_title"));
                        scheduleModel.set_module(obj.getString("titlemodule"));
                        scheduleModel.set_date(obj.getString("start"));
                        scheduleModel.set_validate(obj.getString("event_registered"));
                        scheduleModel.set_token(obj.getString("allow_token"));
                        scheduleModel.set_scolaryear(obj.getString("scolaryear"));
                        scheduleModel.set_codemodule(obj.getString("codemodule"));
                        scheduleModel.set_codeinstance(obj.getString("codeinstance"));
                        scheduleModel.set_codeacti(obj.getString("codeacti"));
                        scheduleModel.set_codeevent(obj.getString("codeevent"));
                        scheduleModel.set_session(_auth.get_token());
                        listElem.add(scheduleModel);
                    }
                    i++;
                }
            } catch (Exception e) {
            }
            ArrayAdapter<ScheduleModel> adapter = new ArrayAdapter<ScheduleModel>(_view.getContext(), android.R.layout.simple_list_item_1, android.R.id.text1, listElem);
            _listView.setAdapter(adapter);
            _listView.setVisibility(View.VISIBLE);
        }
    };
}