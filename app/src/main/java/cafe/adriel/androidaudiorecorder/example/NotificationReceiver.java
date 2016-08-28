package cafe.adriel.androidaudiorecorder.example;

import android.app.Activity;
import android.app.Notification;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.ActivityCompat;
import android.util.Log;

import com.parse.ParsePushBroadcastReceiver;

import org.json.JSONException;
import org.json.JSONObject;

import cafe.adriel.androidaudiorecorder.AudioRecorderActivity;

public class NotificationReceiver extends ParsePushBroadcastReceiver {

    private static final String LOG_TAG = NotificationReceiver.class.getSimpleName();

    @Override
    protected Notification getNotification(Context context, Intent intent) {
        Log.v(LOG_TAG, "getNotification called");
        Bundle extras = intent.getExtras();
        String jsonData = extras.getString("com.parse.Data");
        if (jsonData != null) {
            Log.e("jsonData", jsonData);
            try {
                JSONObject data = new JSONObject(jsonData);
                if (data.getInt("data") == 1) {
                    if(!AudioRecorderActivity.CurrentlyRunning) {
                        Intent intentone = new Intent(context.getApplicationContext(), AudioRecorderActivity.class);
                        intentone.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TASK | Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_NEW_TASK);
                        context.startActivity(intentone);
                    }
                } else if (data.getInt("data") == 2) {
                    if (ActivityCompat.checkSelfPermission(context, android.Manifest.permission.CALL_PHONE) == PackageManager.PERMISSION_GRANTED) {
                        Intent intenttwo = new Intent(Intent.ACTION_CALL, Uri.parse("tel:" + "+19178418611"));
                        intenttwo.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TASK | Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_NEW_TASK);
                        context.startActivity(intenttwo);
                    }
                }
	        }
	        catch(JSONException e){
	            Log.e(LOG_TAG, "Error parsing json data", e);
	        }
	    }
	    else{
	        Log.w(LOG_TAG, "cannot find notification data");
	    }

    	//Log.v(LOG_TAG, "notification for item with id=" + array.toString());



        return null;
    }

    @Override
    protected void onPushOpen(Context context, Intent intent) {
        Log.v(LOG_TAG, "onPushOpen called");

    }

    @Override
    protected Class<? extends Activity> getActivity(Context context, Intent intent) {
        Log.v(LOG_TAG, "getActivity called");
        return super.getActivity(context, intent);
    }

    @Override
    protected void onPushReceive(Context context, Intent intent) {
        Log.v(LOG_TAG, "onPushReceive called");
        super.onPushReceive(context, intent);
    }

    @Override
    public void onReceive(Context context, Intent intent) {
        Log.v(LOG_TAG, "onReceive Called");
        super.onReceive(context, intent);
    }
}