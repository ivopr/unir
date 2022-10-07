package com.pdm.rivaldalocaliza.room.dao;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import com.pdm.rivaldalocaliza.room.models.UserSession;

import java.util.List;

@Dao
public interface UserSessionDAO {
	@Insert
	public void insert(UserSession... userSessions);

	@Update
	public void update(UserSession... userSessions);

	@Delete
	public void delete(UserSession userSession);

	@Query("SELECT * FROM user_session")
	public List<UserSession> getSessions();
}
