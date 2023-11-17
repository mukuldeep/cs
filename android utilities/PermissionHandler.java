package your.package.name.utils;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
/*
    This handles all the permissions required to function the application
    It requests all required permissions inside constructor.
    Public APIs of this class
        1. constructor(Context)
        2. isAllPermissionAllowed()
		
	To add new permission in the list
		1. Add boolean checkPermissionName()
		2. Add String[] permissionNamePermissions()
		3. include checkPermissionName() in isAllPermissionAllowed()
		4. include in requestMissingPermission()
 */
public class PermissionHandler {
    private static final int GENERAL_PERMISSION_REQUEST_CODE = 142;
    Context context=null;

	/*
	 *  checks a single permission is allowed or not
	 */
    private boolean isAllowed(String Permission){
        return ContextCompat.checkSelfPermission(context, Permission) == PackageManager.PERMISSION_GRANTED;
    }
	/*
	 *  Requests a arrays of permissions, and associate a permission code 
	 */
    private void requestPerm(String[] permissions,int permission_code){
        ActivityCompat.requestPermissions((Activity) context,permissions, permission_code);
    }
	
	/*
	 *  Check all included permissions
	 */
    public boolean isAllPermissionAllowed(){
        return checkMediaPermission() && checkFineLocationPermission() && checkNotificationPermission();
    }
	/*
	 *  Requests missing permissions 
	 */
    private void requestMissingPermission(){
        List<String> perms = new ArrayList<>();
        if(!checkMediaPermission()){
            List<String> m_perm = new ArrayList<>(Arrays.asList(mediaPermissions()));
            perms.addAll(m_perm);
        }
        if(!checkFineLocationPermission()){
            List<String> m_perm = new ArrayList<>(Arrays.asList(fineLocationPermissions()));
            perms.addAll(m_perm);
        }
        if(!checkNotificationPermission()){
            List<String> m_perm = new ArrayList<>(Arrays.asList(notificationPermissions()));
            perms.addAll(m_perm);
        }

        requestPerm(perms.toArray(new String[0]),GENERAL_PERMISSION_REQUEST_CODE);
        BatteryOptimizationHelper.checkBatteryOptimization(context);
    }

    /*
	// callback for permission request results
	//
    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == STORAGE_PERMISSION_CODE) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                // Permission granted. You can now access external storage.
                init_after_permission();
            } else {
                // Permission denied. Handle this case (e.g., show a message or request again later).
                Toast.makeText(getApplicationContext(),"App will not work without this permission!",Toast.LENGTH_SHORT).show();
                check_for_permission(context);
            }
        }
    }
     */
	 /*
	  *  Constructor
	  */
    public PermissionHandler(Context context){
        this.context=context;
        requestMissingPermission();
    }


	/*
	 *  Check media permissions
	 */
    private boolean checkMediaPermission(){
        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU){
            return isAllowed( Manifest.permission.READ_MEDIA_VIDEO) && isAllowed( Manifest.permission.READ_MEDIA_AUDIO) && isAllowed( Manifest.permission.READ_MEDIA_IMAGES);
        }else if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.M){
            return isAllowed(Manifest.permission.READ_EXTERNAL_STORAGE) && isAllowed(Manifest.permission.WRITE_EXTERNAL_STORAGE) && isAllowed(Manifest.permission.MANAGE_EXTERNAL_STORAGE);
        }
        return true;
    }

	/*
	 *  Returns arrays of media permissions
	 */
    private String[] mediaPermissions() {
        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU){
            return new String[]{
                                Manifest.permission.READ_MEDIA_VIDEO,
                                Manifest.permission.READ_MEDIA_IMAGES,
                                Manifest.permission.READ_MEDIA_AUDIO};
        }else if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.M){
            return new String[]{
                                Manifest.permission.READ_EXTERNAL_STORAGE,
                                Manifest.permission.WRITE_EXTERNAL_STORAGE};

        }
        return new String[]{};
    }

    private boolean checkFineLocationPermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            return isAllowed(Manifest.permission.ACCESS_FINE_LOCATION);
        }
        return true;
    }

    private String[] fineLocationPermissions() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            return new String[]{Manifest.permission.ACCESS_FINE_LOCATION};
        }
        return new String[]{};
    }

    private boolean checkNotificationPermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
            return isAllowed(Manifest.permission.POST_NOTIFICATIONS);
        }
        return true;
    }

    private String[] notificationPermissions() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
            return new String[]{Manifest.permission.POST_NOTIFICATIONS};
        }
        return new String[]{};
    }


}
