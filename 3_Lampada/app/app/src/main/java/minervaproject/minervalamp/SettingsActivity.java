package minervaproject.minervalamp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class SettingsActivity extends AppCompatActivity {

    private TextView server_input;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);

        server_input = (TextView) findViewById(R.id.server_inp);
        server_input.setText(MainActivity.serverAddress);
    }

    public void onSave(View view){
        MainActivity.serverAddress = server_input.getText().toString();
        Toast.makeText(this, getResources().getString(R.string.success), Toast.LENGTH_SHORT).show();
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
        finish();
    }
}
