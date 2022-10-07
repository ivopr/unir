package com.pdm.rivaldalocaliza.room;

import androidx.room.Database;
import androidx.room.RoomDatabase;

import com.pdm.rivaldalocaliza.room.dao.UserDAO;
import com.pdm.rivaldalocaliza.room.dao.UserSessionDAO;
import com.pdm.rivaldalocaliza.room.models.User;
import com.pdm.rivaldalocaliza.room.models.UserSession;

@Database(entities = {UserSession.class, User.class}, version = 1)
public abstract class AppDb extends RoomDatabase {
	public abstract UserSessionDAO getUserSessionDAO();
	public abstract UserDAO getUserDAO();
}
