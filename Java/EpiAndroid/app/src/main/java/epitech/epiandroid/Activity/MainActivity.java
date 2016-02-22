package epitech.epiandroid.Activity;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.NavigationView;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;

import epitech.epiandroid.Fragment.ProfileFragment;
import epitech.epiandroid.Fragment.ScheduleFragment;
import epitech.epiandroid.Model.AuthModel;
import epitech.epiandroid.R;

public class MainActivity extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener {

    public AuthModel _auth;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.setDrawerListener(toggle);
        toggle.syncState();

        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);

        Bundle bundle = getIntent().getExtras();
        _auth = new AuthModel();

        if (bundle.getString("token") != null)
        {
            _auth.set_token(bundle.getString("token"));
        }
        if(bundle.getString("login") != null)
        {
            _auth.set_login(bundle.getString("login"));
        }
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.action_logout) {
            Intent goLoginActivity = new Intent(MainActivity.this, LoginActivity.class);
            finish();
            startActivityForResult(goLoginActivity, 1);
        }
        return super.onOptionsItemSelected(item);
    }

    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        int id = item.getItemId();
        FragmentManager fm = getSupportFragmentManager();
        Fragment fragment = null;

        if (id == R.id.nav_profile) {
            fragment = ProfileFragment.newInstance(_auth, fm);
        }
        else if (id == R.id.nav_schedule) {
            fragment = ScheduleFragment.newInstance(_auth, fm);
        }
        else if (id == R.id.nav_modules) {
        }
        else if (id == R.id.nav_grades) {
        }

        if (fragment != null) {
            fm.beginTransaction().replace(R.id.drawer_layout, fragment).commit();
        }
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }
}
