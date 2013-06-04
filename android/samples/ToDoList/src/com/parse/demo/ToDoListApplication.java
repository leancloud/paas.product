package com.parse.demo;

import com.parse.*;

import android.app.Application;

public class ToDoListApplication extends Application {

	@Override
	public void onCreate() {
		super.onCreate();

        // Your application id and Application Key
		Parse.initialize(this, YOUR_APP_ID, YOUR_APP_KEY);

		ParseUser.enableAutomaticUser();
		ParseACL defaultACL = new ParseACL();
		// Optionally enable public read access.
		// defaultACL.setPublicReadAccess(true);
		//ParseACL.setDefaultACL(defaultACL, true);
	}

}
