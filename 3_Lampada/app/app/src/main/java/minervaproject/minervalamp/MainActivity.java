package minervaproject.minervalamp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import java.util.HashMap;
import java.util.Map;

import static minervaproject.minervalamp.R.id.response;
import static minervaproject.minervalamp.R.styleable.CompoundButton;

public class MainActivity extends AppCompatActivity {

    private TextView myResponse;
    private TextView myConnection;
    private Switch mySwitch;
    static public String serverAddress;
    private String serverAddressPrefix = "/api/v1.0/";
    private RequestQueue queue;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        myResponse = (TextView) findViewById(response);
        myConnection = (TextView) findViewById(R.id.connection);
        mySwitch = (Switch) findViewById(R.id.switch_onoff);
        queue = Volley.newRequestQueue(this);

        if(serverAddress == null)
            myConnection.setText(getResources().getString(R.string.details));
        else
            myConnection.setText(getResources().getString(R.string.connected_on) + " " + serverAddress + serverAddressPrefix);

        mySwitch.setOnCheckedChangeListener(new android.widget.CompoundButton.OnCheckedChangeListener() {

            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(isChecked)
                    turnOn();
                else
                    turnOff();
            }

        });
    }

    private String url(){
        return serverAddress + serverAddressPrefix;
    }

    public void turnOn(){
        StringRequest postRequest = new StringRequest(Request.Method.POST, url(),
                new Response.Listener<String>(){
                    @Override
                    public void onResponse(String response){}
                },
                new Response.ErrorListener(){
                    @Override
                    public void onErrorResponse(VolleyError error){}
                }
        ) {
            @Override
            protected Map<String, String> getParams(){
                Map<String, String> params = new HashMap<String, String>();
                params.put("switchOn", "on");
                return params;
            }
        };
        queue.add(postRequest);
    }

    public void turnOff(){
        StringRequest postRequest = new StringRequest(Request.Method.POST, url(),
                new Response.Listener<String>(){
                    @Override
                    public void onResponse(String response){}
                },
                new Response.ErrorListener(){
                    @Override
                    public void onErrorResponse(VolleyError error){}
                }
        ){
            @Override
            protected Map<String, String> getParams(){
                Map<String, String> params = new HashMap<String, String>();
                params.put("switchOn", "off");
                return params;
            }
        };
        queue.add(postRequest);
    }

    public void getInfo(){
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url(),
                new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        myResponse.setText(response);
                    }
                }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                myResponse.setText(error.getMessage());
            }
        });
        queue.add(stringRequest);
    }

    public void onSettings(View view){
        Intent intent = new Intent(this, SettingsActivity.class);
        startActivity(intent);
    }
}
