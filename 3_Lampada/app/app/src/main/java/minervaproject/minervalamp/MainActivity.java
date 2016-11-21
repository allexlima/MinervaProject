package minervaproject.minervalamp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.Switch;
import android.widget.TextView;

import static minervaproject.minervalamp.R.styleable.CompoundButton;

public class MainActivity extends AppCompatActivity {

    private TextView myResponse;
    private TextView myConnection;
    private Switch mySwitch;
    static public String serverAddress;
    private String serverAddressPrefix = "/api/v1.0/";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        myResponse = (TextView) findViewById(R.id.response);
        myConnection = (TextView) findViewById(R.id.connection);
        mySwitch = (Switch) findViewById(R.id.switch_onoff);

        if(serverAddress == null)
            myConnection.setText(getResources().getString(R.string.details));
        else
            myConnection.setText(getResources().getString(R.string.connected_on) + " " + serverAddress + serverAddressPrefix);

        mySwitch.setOnCheckedChangeListener(new android.widget.CompoundButton.OnCheckedChangeListener() {

            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(isChecked){
                    myResponse.setText("Switch is currently ON");
                }else{
                    myResponse.setText("Switch is currently OFF");
                }
            }

        });
    }

    public void onSettings(View view){
        Intent intent = new Intent(this, SettingsActivity.class);
        startActivity(intent);
        //finish();
    }
}
