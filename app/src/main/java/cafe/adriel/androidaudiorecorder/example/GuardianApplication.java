package cafe.adriel.androidaudiorecorder.example;

import com.parse.Parse;
import com.parse.ParseInstallation;

public class GuardianApplication extends android.app.Application {
    @Override
    public void onCreate() {
        super.onCreate();
        Parse.initialize(this, "key", "pass");
        ParseInstallation.getCurrentInstallation().saveInBackground();
    }
    
    public String getPackage()
    {
        return this.getPackage();
    }
}
