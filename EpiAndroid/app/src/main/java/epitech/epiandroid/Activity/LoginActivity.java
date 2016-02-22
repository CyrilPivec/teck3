package epitech.epiandroid.Activity;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.annotation.TargetApi;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.loopj.android.http.JsonHttpResponseHandler;
import com.loopj.android.http.RequestParams;
import org.json.JSONObject;
import cz.msebera.android.httpclient.Header;
import epitech.epiandroid.R;
import epitech.epiandroid.Service.ApiService;
import epitech.epiandroid.Model.AuthModel;

/**
 * A login screen that offers login via login/password.
 */
public class LoginActivity extends AppCompatActivity {

    /**
     * Keep track of the login task to ensure we can cancel it if requested.
     */
    private ApiService _api;

    private String _login;
    private String _password;

    private UserLoginTask _authTask = null;

    private EditText _loginView;
    private EditText _passwordView;
    private View _progressView;
    private View _loginFormView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        _loginView = (AutoCompleteTextView) findViewById(R.id.login);
        _passwordView = (EditText) findViewById(R.id.password);

        _api = new ApiService();
        _api.initializeApi(getString(R.string.api_url));

        Button mLoginButton = (Button) findViewById(R.id.login_button);
        mLoginButton.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                attemptLogin();
            }
        });

        _loginFormView = findViewById(R.id.login_form);
        _progressView = findViewById(R.id.login_progress);
    }

    /**
     * Attempts to sign in or register the account specified by the login form.
     */
    private void attemptLogin() {
        if (_authTask != null) {
            return;
        }

        _loginView.setError(null);
        _passwordView.setError(null);

        String login = _loginView.getText().toString();
        String password = _passwordView.getText().toString();

        boolean cancel = false;
        View focusView = null;

        if (TextUtils.isEmpty(login)) {
            _loginView.setError(getString(R.string.error_field_required));
            focusView = _loginView;
            cancel = true;
        }
        if (TextUtils.isEmpty(password)) {
            _passwordView.setError(getString(R.string.error_field_required));
            focusView = _passwordView;
            cancel = true;
        }

        if (cancel) {
            focusView.requestFocus();
        } else {
            showProgress(true);
            _authTask = new UserLoginTask(login, password);
            _authTask.execute((Void) null);
        }
    }

    /**
     * Shows the progress UI and hides the login form.
     */
    @TargetApi(Build.VERSION_CODES.HONEYCOMB_MR2)
    private void showProgress(final boolean show) {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB_MR2) {
            int shortAnimTime = getResources().getInteger(android.R.integer.config_shortAnimTime);

            _loginFormView.setVisibility(show ? View.GONE : View.VISIBLE);
            _loginFormView.animate().setDuration(shortAnimTime).alpha(
                    show ? 0 : 1).setListener(new AnimatorListenerAdapter() {
                @Override
                public void onAnimationEnd(Animator animation) {
                    _loginFormView.setVisibility(show ? View.GONE : View.VISIBLE);
                }
            });

            _progressView.setVisibility(show ? View.VISIBLE : View.GONE);
            _progressView.animate().setDuration(shortAnimTime).alpha(
                    show ? 1 : 0).setListener(new AnimatorListenerAdapter() {
                @Override
                public void onAnimationEnd(Animator animation) {
                    _progressView.setVisibility(show ? View.VISIBLE : View.GONE);
                }
            });
        } else {
            _progressView.setVisibility(show ? View.VISIBLE : View.GONE);
            _loginFormView.setVisibility(show ? View.GONE : View.VISIBLE);
        }
    }

    /**
     * Represents an asynchronous login/registration task used to authenticate the user.
     */
    public class UserLoginTask extends AsyncTask<Void, Void, Boolean> {

        UserLoginTask(String login, String password) {
            _login = login;
            _password = password;
        }

        @Override
        protected Boolean doInBackground(Void... params) {
            // Attempt authentification to Epitech API.
            try {
                RequestParams requestParams = new RequestParams();
                requestParams.add("login", _login);
                requestParams.add("password", _password);
                _api.postRequest("login", requestParams, responseHandler);
            } catch (Exception e) {
                return false;
            }
            return true;
        }
    }

    /**
     * JsonHttpResponseHandler.
     */
    public JsonHttpResponseHandler responseHandler = new JsonHttpResponseHandler() {

        @Override
        public void onSuccess(int statusCode, Header[] headers, JSONObject response) {
            super.onSuccess(statusCode, headers, response);
            try {
                Toast.makeText(getBaseContext(), getString(R.string.success_connect), Toast.LENGTH_LONG).show();
                AuthModel auth = new AuthModel(response, _login, _password);
                Intent goMainActivity = new Intent(LoginActivity.this, MainActivity.class);
                goMainActivity.putExtra("token", auth.get_token());
                goMainActivity.putExtra("login", auth.get_login());
                startActivityForResult(goMainActivity, 1);
            }
            catch (Exception e) {
            }
        }

        @Override
        public void onFailure(int statusCode, Header[] headers, Throwable throwable, JSONObject errorResponse) {
            super.onFailure(statusCode, headers, throwable, errorResponse);
            Toast.makeText(getBaseContext(), getString(R.string.fail_connect), Toast.LENGTH_LONG).show();
            showProgress(false);
            finish();
            startActivity(getIntent());
        }
    };
}